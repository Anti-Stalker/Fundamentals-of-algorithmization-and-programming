#include "stl_reader.h"

std::vector<float> coords, normals;
std::vector<unsigned int> tris, solids;

struct Vector {
    float X;
    float Y;
    float Z;
};

float signedVolumeOfTriangle(Vector p1, Vector p2, Vector p3) {
    float v321 = p3.X*p2.Y*p1.Z;
    float v231 = p2.X*p3.Y*p1.Z;
    float v312 = p3.X*p1.Y*p2.Z;
    float v132 = p1.X*p3.Y*p2.Z;
    float v213 = p2.X*p1.Y*p3.Z;
    float v123 = p1.X*p2.Y*p3.Z;
    return (1.0f/6.0f)*(-v321 + v231 + v312 - v132 - v213 + v123);
}

float getVolumeStl(std::string f_path)
{
    stl_reader::ReadStlFile (f_path.c_str(), coords, normals, tris, solids);
    const size_t numTris = tris.size() / 3;
    float sumVolume = 0;
    for(size_t itri = 0; itri < numTris; ++itri) {
        float* c = &coords[3 * tris [3 * itri + 0]];
        Vector p1 = {c[0], c[1], c[2]};
        c = &coords[3 * tris [3 * itri + 1]];
        Vector p2 = {c[0], c[1], c[2]};
        c = &coords[3 * tris [3 * itri + 2]];
        Vector p3 = {c[0], c[1], c[2]};
        sumVolume += signedVolumeOfTriangle(p1, p2, p3);
    }

    return sumVolume;
}

