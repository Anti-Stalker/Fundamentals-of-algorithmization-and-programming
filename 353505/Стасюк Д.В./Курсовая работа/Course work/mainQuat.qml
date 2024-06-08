import QtQuick 2.0
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts

import Qt.labs.platform
import QtCore

import QtQuick3D
import QtQuick3D.Helpers
import QtQuick3D.AssetUtils



Window {
    id: windowRoot
    visible: true
    width: 720
    height: 480

    property url importUrl: modelUrl;

    View3D{
        id: view3D
        anchors.fill: parent
        environment: SceneEnvironment {
            id: env
            backgroundMode: SceneEnvironment.SkyBox
            lightProbe: Texture {
                textureData: ProceduralSkyTextureData{}
            }
            InfiniteGrid {
                visible: helper.gridEnabled
                gridInterval: helper.gridInterval
            }
        }

        QtObject {
            id: helper
            property real boundsDiameter: 0
            property vector3d boundsCenter
            property vector3d boundsSize
            property bool orbitControllerEnabled: false
            property bool gridEnabled: false
            property real cameraDistance: orbitControllerEnabled ? orbitCamera.z : wasdCamera.position.length()
            // property real gridInterval: Math.pow(10, Math.round(Math.log10(cameraDistance)) - 1)

            function updateBounds(bounds) {
                boundsSize = Qt.vector3d(bounds.maximum.x - bounds.minimum.x,
                                         bounds.maximum.y - bounds.minimum.y,
                                         bounds.maximum.z - bounds.minimum.z)
                boundsDiameter = Math.max(boundsSize.x, boundsSize.y, boundsSize.z)
                boundsCenter = Qt.vector3d((bounds.maximum.x + bounds.minimum.x) / 2,
                                           (bounds.maximum.y + bounds.minimum.y) / 2,
                                           (bounds.maximum.z + bounds.minimum.z) / 2 )

                // wasdController.speed = boundsDiameter / 1000.0
                // wasdController.shiftSpeed = 3 * wasdController.speed
                // wasdCamera.clipNear = boundsDiameter / 100
                // wasdCamera.clipFar = boundsDiameter * 10
                view3D.resetView()
            }

            function resetController() {
                orbitCameraNode.eulerRotation = Qt.vector3d(0, 0, 0)
                orbitCameraNode.position = boundsCenter
                orbitCamera.position = Qt.vector3d(50, 0, 2 * helper.boundsDiameter)
                orbitCamera.eulerRotation = Qt.vector3d(0, 0, 0)
                // orbitControllerEnabled = true
            }

            // function switchController(useOrbitController) {
            //     if (useOrbitController) {
            //         let wasdOffset = wasdCamera.position.minus(boundsCenter)
            //         let wasdDistance = wasdOffset.length()
            //         let wasdDistanceInPlane = Qt.vector3d(wasdOffset.x, 0, wasdOffset.z).length()
            //         let yAngle = Math.atan2(wasdOffset.x, wasdOffset.z) * 180 / Math.PI
            //         let xAngle = -Math.atan2(wasdOffset.y, wasdDistanceInPlane) * 180 / Math.PI

            //         orbitCameraNode.position = boundsCenter
            //         orbitCameraNode.eulerRotation = Qt.vector3d(xAngle, yAngle, 0)
            //         orbitCamera.position = Qt.vector3d(0, 0, wasdDistance)

            //         orbitCamera.eulerRotation = Qt.vector3d(0, 0, 0)
            //     } else {
            //         wasdCamera.position = orbitCamera.scenePosition
            //         wasdCamera.rotation = orbitCamera.sceneRotation
            //         wasdController.focus = true
            //     }
            //     orbitControllerEnabled = useOrbitController
            // }

        }

        QtObject {
            id: quatHelper


            function angleAxisToQuat(angle, axis) {
                var a = angle * Math.PI / 180.0;
                var s = Math.sin(a * 0.5);
                var c = Math.cos(a * 0.5);
                return Qt.quaternion(c, axis.x * s, axis.y * s, axis.z * s);
            }

            function multiplyQuaternion(q1, q2) {
                return Qt.quaternion(q1.scalar * q2.scalar - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z,
                                     q1.scalar * q2.x + q1.x * q2.scalar + q1.y * q2.z - q1.z * q2.y,
                                     q1.scalar * q2.y + q1.y * q2.scalar + q1.z * q2.x - q1.x * q2.z,
                                     q1.scalar * q2.z + q1.z * q2.scalar + q1.x * q2.y - q1.y * q2.x);
            }

            function eulerToQuaternionXYZ(x, y, z) {
                var quatX = angleAxisToQuat(x, Qt.vector3d(1, 0, 0));
                var quatY = angleAxisToQuat(y, Qt.vector3d(0, 1, 0));
                var quatZ = angleAxisToQuat(z, Qt.vector3d(0, 0, 1));
                return multiplyQuaternion(multiplyQuaternion(quatX, quatY), quatZ)
            }

            function slerp(start, end, t) {

                var halfCosTheta = ((start.x * end.x) + (start.y * end.y)) + ((start.z * end.z) + (start.scalar * end.scalar));

                if (halfCosTheta < 0.0)
                {
                    end.scalar = -end.scalar
                    end.x = -end.x
                    end.y = -end.y
                    end.z = -end.z
                    halfCosTheta = -halfCosTheta;
                }

                if (Math.abs(halfCosTheta) > 0.999999)
                {
                    return Qt.quaternion(start.scalar + (t * (end.scalar - start.scalar)),
                                         start.x      + (t * (end.x      - start.x     )),
                                         start.y      + (t * (end.y      - start.y     )),
                                         start.z      + (t * (end.z      - start.z     )));
                }

                var halfTheta = Math.acos(halfCosTheta);
                var s1 = Math.sin((1.0 - t) * halfTheta);
                var s2 = Math.sin(t * halfTheta);
                var s3 = 1.0 / Math.sin(halfTheta);
                return Qt.quaternion((s1 * start.scalar + s2 * end.scalar) * s3,
                                     (s1 * start.x      + s2 * end.x     ) * s3,
                                     (s1 * start.y      + s2 * end.y     ) * s3,
                                     (s1 * start.z      + s2 * end.z     ) * s3);
            }

            function getAxis(quat) {
                var tmp1 = 1.0 - quat.scalar * quat.scalar;
                if (tmp1 <= 0) return Qt.vector3d(0.0, 0.0, 1.0);
                var tmp2 = 1 / Math.sqrt(tmp1);
                return Qt.vector3d(quat.x * tmp2, quat.y * tmp2, quat.z * tmp2);
            }

            function getAngle(quat) {
                return Math.acos(quat.scalar) * 2.0 * 180.0 / Math.PI;
            }
        }

        function resetView() {
            // if (importNode.status === RuntimeLoader.Success) {
                helper.resetController()
            // }
        }

        Node {
            id: orbitCameraNode
            PerspectiveCamera {
                id: orbitCamera
                rotation: animator.result
                property real cameraAnimation: 1
                SequentialAnimation {
                    loops: Animation.Infinite
                    running: true
                    NumberAnimation {
                        target: orbitCamera
                        property: "cameraAnimation"
                        to: -1
                        duration: 5000
                        easing.type: Easing.InOutQuad
                    }
                    NumberAnimation {
                        target: orbitCamera
                        property: "cameraAnimation"
                        to: 1
                        duration: 5000
                        easing.type: Easing.InOutQuad
                    }
                }
                position: Qt.vector3d(50 * cameraAnimation, 0, 0)
                eulerRotation.x: -20
                eulerRotation.y: 20 * cameraAnimation
            }
        }

        PerspectiveCamera {
            id: camera
            position: Qt.vector3d(0, 50, 50)
            rotation: animator.result
            // eulerRotation.x: -30
        }

        // WasdController {
        //     controlledObject: camera
        //     rotation: animator.result
        // }

        DirectionalLight {
            eulerRotation.x: -30
        }

        RuntimeLoader {
            id: importNode
            source: windowRoot.importUrl

            // instancing: instancingButton.checked ? instancing : null
            onBoundsChanged: helper.updateBounds(bounds)

            Component.onCompleted: {
                    view3D.resetView();
                }
        }

        Node {
            // position: helper.boundsCenter
            position: Qt.vector3d(0, 800, 0)
            SequentialAnimation on eulerRotation.x {
                loops: Animation.Infinite
                NumberAnimation {
                    to: 90
                    duration: 3500
                    easing.type: Easing.InOutQuad
                }
                NumberAnimation {
                    to: -90
                    duration: 3500
                    easing.type: Easing.InOutQuad
                }
            }
            Model {
                parent: importNode
                id: cube
                source: "#Cube"
                materials: PrincipledMaterial {
                    baseColor: "red"
                }

                opacity: 0.2
                visible: false
                position: helper.boundsCenter

                scale: Qt.vector3d(helper.boundsSize.x / 100,
                                   helper.boundsSize.y / 100,
                                   helper.boundsSize.z / 100)
            }
        }

        NumberAnimation
        {
            property quaternion start: quatHelper.eulerToQuaternionXYZ(0, -70, 0)
            property quaternion end: quatHelper.eulerToQuaternionXYZ(0, 100, 0)
            property quaternion result: quatHelper.slerp(start, end, t)
            property real t: 0
            id: animator
            target: animator
            property: "t"
            from: 0.0
            to: 1.0
            duration: 6000
            running: true
            loops: Animation.Infinite
        }
    }

    Item {
        width: debugViewToggleText.implicitWidth
        height: debugViewToggleText.implicitHeight
        anchors.right: parent.right
        Label {
            id: debugViewToggleText
            text: "Click here " + (dbg.visible ? "to hide DebugView" : "for DebugView")
            anchors.right: parent.right
            anchors.top: parent.top
        }
        MouseArea {
            anchors.fill: parent
            onClicked: dbg.visible = !dbg.visible
            DebugView {
                y: debugViewToggleText.height * 2
                anchors.right: parent.right
                source: view3D
                id: dbg
                visible: false
            }
        }
    }
}
