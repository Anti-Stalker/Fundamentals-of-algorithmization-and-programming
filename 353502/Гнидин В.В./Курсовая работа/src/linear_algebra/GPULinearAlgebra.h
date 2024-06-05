//
// Created by volodya-petarda on 3/29/24.
//

#ifndef NEURALNETWORK_GPULINEARALGEBRA_H
#define NEURALNETWORK_GPULINEARALGEBRA_H
#include "cuda.h"
#include "cublas_v2.h"
#include "cusparse_v2.h"
#include "../neural_network/ActivationTypes.h"
#include "CPULinearAlgebra.h"
#include <iostream>

void doZerosGPU(float *a, int n);
void matrixVectorMultGPU(float *a, float *x, float *y, int n, int m);
void tMatrixVectorMultGPU(float *a, float *x, float *y, int n, int m);
void vectorVectorMultGPU(float *v1, float *v2, float *matr, int n, int m);
void scalarVectMultGPU(float *v, float a, int n);
void derivativeErrorGPU(float *x, float *y, float *out, ActivationType type, int n);
void multDerivativeGPU(float *a, float *out, ActivationType type, int n);
void addVectorGPU(float *a, float *out, int n);
void subVectorGPU(float *a, float *out, int n);
void activateGPU(float *a, ActivationType type, int n);
float getMaxValueGPU(float *a, int n);
int getMaxIndexGPU(float *a, int n);

#endif //NEURALNETWORK_GPULINEARALGEBRA_H
