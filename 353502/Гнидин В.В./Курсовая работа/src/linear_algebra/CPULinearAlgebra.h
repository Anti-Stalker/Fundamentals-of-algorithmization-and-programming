//
// Created by volodya-petarda on 3/13/24.
//
#ifndef NEURALNETWORK_CPULINEARALGEBRA_H
#define NEURALNETWORK_CPULINEARALGEBRA_H

#include <iostream>
#include <random>
#include "../neural_network/ActivationTypes.h"

const float LRELU_COEF = 0.05;

void doZeros(float *a, int n);
void doZeros(float **a, int n, int m);
int doRandomInt(int l, int r);
float doNormalRandom(float u, float s);
void doNormalRandom(float *a, int n, float u, float s);
void doNormalRandom(float **a, int n, int m, float u, float s);
float doRandom(float l = -1.0, float r = 1.0);
void doRandom(float *a, int n, float l = -1.0, float r = 1.0);
void doRandom(float **a, int n, int m, float l = -1.0, float r = 1.0);
void vectMatrMult(float *v, float **matr, float *out, int n, int m);
void vectTMatrMult(float *v, float **matr, float *out, int n, int m);
void addVectVectMult(float *v1, float *v2, float **out, int n, int m);
void scalarMult(float *v, float a, int n);
void scalarMult(float **v, float a, int n, int m);
void vectSubVect(float *v1, float *v2, int n);
void vectAddVect(float *v1, float *v2, int n);
void matrSubMatr(float **m1, float **m2, int n, int m);
int getMaxIndex(float *v, int n);

void activate(float *a, ActivationType type, int n);
void activateError(float *x, float *y, int type, int n);
void multDerivative(float *a, float *out, ActivationType type, int n);
void derivativeError(float *x, float *y, float *out, ActivationType type, int n);

#endif //NEURALNETWORK_CPULINEARALGEBRA_H
