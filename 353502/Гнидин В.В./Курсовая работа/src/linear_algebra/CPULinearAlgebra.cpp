//
// Created by volodya-petarda on 3/13/24.
//

#include "CPULinearAlgebra.h"


void doZeros(float *a, int n){
    for(int i = 0; i < n; i++)
        a[i] = 0;
}

void doZeros(float **a, int n, int m){
    for(int i = 0; i < n; i++){
        doZeros(a[i], m);
    }
}

int doRandomInt(int l, int r){
    static std::default_random_engine e(time(nullptr));
    std::uniform_int_distribution<> dis(l, r);
    return dis(e);
}

float doNormalRandom(float u, float s){
    static std::default_random_engine generator;
    static std::normal_distribution<float> distribution(u,s);
    return distribution(generator);
}

void doNormalRandom(float *a, int n, float u, float s){
    for(int i = 0; i < n; i++){
        a[i] = doNormalRandom(u, s);
    }
}

void doNormalRandom(float **a, int n, int m, float u, float s){
    for(int i = 0; i < n; i++){
        doNormalRandom(a[i], m, u, s);
    }
}


float doRandom(float l, float r){
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(l, r);
    return dis(e);
}

void doRandom(float *a, int n, float l, float r){
    for(int i = 0; i < n; i++){
        a[i] = doRandom(l, r);
    }
}

void doRandom(float **a, int n, int m, float l, float r){
    for(int i = 0; i < n; i++){
        doRandom(a[i], m, l, r);
    }
}

int getMaxIndex(float *v, int n){
    float mx = v[0];
    int mxInd = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > mx) {
            mx = v[i];
            mxInd = i;
        }
    }
    return mxInd;
}

void vectMatrMult(float *v, float **matr, float *out, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            out[j] += v[i] * matr[i][j];
        }
    }
}

void vectTMatrMult(float *v, float **matr, float *out, int n, int m){
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            out[j] += v[i] * matr[j][i];
        }
    }
}

void addVectVectMult(float *v1, float *v2, float **out, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            out[i][j] += v1[i] * v2[j];
        }
    }
}

void vectSubVect(float *v1, float *v2, int n){
    for(int i = 0; i < n; i++){
        v1[i] -= v2[i];
    }
}

void vectAddVect(float *v1, float *v2, int n){
    for(int i = 0; i < n; i++){
        v1[i] += v2[i];
    }
}

void matrSubMatr(float **m1, float **m2, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            m1[i][j] -= m2[i][j];
        }
    }
}

void scalarMult(float *v, float a, int n){
    for(int i = 0; i < n; i++)
        v[i] *= a;
}

void scalarMult(float **v, float a, int n, int m){
    for(int i = 0; i < n; i++){
        scalarMult(v[i], a, m);
    }
}

void activate(float *a, ActivationType type, int n){
    switch(type){
        case(Nothing):{
            break;
        }
        case(LRelu):{
            for(int i = 0; i < n; i++){
                if(a[i] < 0){
                    a[i] *= LRELU_COEF;
                }
            }
            break;
        }
        case(SoftMax):{
            int mxInd = getMaxIndex(a, n);
            float mx = a[mxInd];

            float sum = 0;
            for(int i = 0; i < n; i++){
                sum += expf(a[i] - mx);
            }
            for(int i = 0; i < n; i++){
                a[i] = expf(a[i] - mx) / sum;
            }
            break;
        }
        default:{
            std::cout<<"unknown activation type"<<'\n';
        }
    }
}

void activateError(float *x, float *y, ActivationType type, int n){
    switch(type){
        case(SquaredError):{
            break;
        }
        default:{
            std::cout<<"unknown error activation type\n";
        }
    }
}

void multDerivative(float *a, float *out, ActivationType type, int n){
    switch(type){
        case(Nothing):{
            break;
        }
        case(LRelu):{
            for(int i = 0; i < n; i++){
                if(a[i] < 0)
                    out[i] *= LRELU_COEF;
            }
            break;
        }
        case(SoftMax):{
            int mxInd = 0;
            float mxVal = 0;
            for(int i = 0; i < n; i++){
                if(fabs(out[i]) > fabs(mxVal)){
                    mxVal = out[i];
                    mxInd = i;
                }
            }

            for (int j = 0; j < n; j++) {
                if (mxInd == j)
                    out[j] = a[j] - 1;
                else
                    out[j] = a[j];
            }

            break;
        }
        default:{
            std::cout<<"unknown derivative type\n";
        }
    }
}

void derivativeError(float *x, float *y, float *out, ActivationType type, int n){
    switch(type){
        case(SquaredError):{
            for(int i = 0; i < n; i++){
                out[i] = 2 * (x[i] - y[i]);
            }
            break;
        }
        case(CrossEntropyError):{
            for(int i = 0; i < n; i++){
                if(y[i] >= 0.999){
                    out[i] = -1.0;
                }
            }
            break;
        }
        default:{
            std::cout<<"unknown derivative type\n";
        }
    }
}