#ifndef DRAWERML_H
#define DRAWERML_H
#include "Consts.h"
#include "object.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "QtMath"

class DrawerGL : public QOpenGLWidget, protected QOpenGLFunctions {
public:
    DrawerGL(QWidget *parent = nullptr);

    ~DrawerGL() {};

    void SetGrid(Object ***grid);

    void draw(Object ***grid);

    void activate();

protected:
    void initializeGL() override;

    void paintGL() override;

    void resizeGL(int w, int h) override;

private:

    bool _is_active = true;
    Object*** _grid;
};


#endif // DRAWERML_H
