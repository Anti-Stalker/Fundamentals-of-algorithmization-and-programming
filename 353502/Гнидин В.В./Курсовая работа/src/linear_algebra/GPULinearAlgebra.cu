//
// Created by volodya-petarda on 3/29/24.
//
#include "GPULinearAlgebra.h"

cublasHandle_t handle = nullptr;


__global__ void doZerosKernel(float *a, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        a[tid] = 0;
        tid += step;
    }
}

__global__ void addVectorKernel(float *a, float *out, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        out[tid] += a[tid];
        tid += step;
    }
}

__global__ void subVectorKernel(float *a, float *out, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        out[tid] -= a[tid];
        tid += step;
    }
}

__global__ void scalarVectorMultGPU(float *v, float a, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        v[tid] *= a;
        tid += step;
    }
}


__global__ void activateLReluKernel(float *a, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        if(a[tid] <= 0)
            a[tid] *= LRELU_COEF;
        tid += step;
    }
}

__global__ void activateSigmoidKernel(float *a, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        a[tid] = 1 / (1 + expf(-a[tid]));
        tid += step;
    }
}

__global__ void activateTanhKernel(float *a, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        a[tid] = (1 - expf(-2 * a[tid])) / (1 + expf(-2 * a[tid]));
        tid += step;
    }
}

__global__ void preactivateSoftmaxKernel(float *a, float mx, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        a[tid] = expf(a[tid] - mx);
        tid += step;
    }
}

__global__ void crossEntropyErrorKernel(float *y, float *out, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        if(y[tid] >= 0.999)
            out[tid] = -1;
        else
            out[tid] = 0;
        tid += step;
    }
}

__global__ void squaredErrorKernel(float *x, float *y, float *out, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        out[tid] = 2 * (x[tid] - y[tid]);
        tid += step;
    }
}

__global__ void multDerivativeLReluKernel(float *a, float *out, int n) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while (tid < n) {
        if (a[tid] < 0)
            out[tid] *= LRELU_COEF;
        tid += step;
    }
}

__global__ void multDerivativeSigmoidKernel(float *a, float *out, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        out[tid] *= a[tid] * (1 - a[tid]);
        tid += step;
    }
}

__global__ void multDerivativeSoftmaxKernel(float *a, float *out, int n, int ind){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        if(tid == ind)
            out[tid] = a[tid] - 1;
        else
            out[tid] = a[tid];
        tid += step;
    }
}

__global__ void multDerivativeTanhKernel(float *a, float *out, int n){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int step = gridDim.x * blockDim.x;
    while(tid < n){
        out[tid] *= (1 - a[tid] * a[tid]);
        tid += step;
    }
}

__global__ void vectorVectorMultKernel(const float *v1, const float *v2, float *matr, const int n, const int m){
    int i = blockIdx.x;
    while(i < n){
        if(v1[i] == 0){
            i += gridDim.x;
            continue;
        }
        int j = threadIdx.x;
        while(j < m){
            matr[i * m + j] += v1[i] * v2[j];
            j += blockDim.x;
        }
        i += gridDim.x;
    }
}

__global__ void slowMaxValueKernel(float *a, float *res, int n){
    *res = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > *res)
            *res = a[i];
    }
}


void doZerosGPU(float *a, int n){
    const int THREADS_CNT = 32, BLOCKS_CNT = 32;
    doZerosKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, n);
}

void matrixVectorMultGPU(float *a, float *x, float *y, int n, int m){
    if(handle == nullptr)
        cublasCreate_v2(&handle);
    float al = 1, bet = 1;
    cublasSgemv_v2(handle, CUBLAS_OP_N, m, n, &al, a, m, x, 1, &bet, y, 1);
}

void tMatrixVectorMultGPU(float *a, float *x, float *y, int n, int m){
    if(handle == nullptr)
        cublasCreate_v2(&handle);
    float al = 1, bet = 1;
    cublasSgemv_v2(handle, CUBLAS_OP_T, m, n, &al, a, m, x, 1, &bet, y, 1);
}

void vectorVectorMultGPU(float *v1, float *v2, float *matr, int n, int m){
    const int THREADS_CNT = 128, BLOCKS_CNT = 128;
    vectorVectorMultKernel<<<BLOCKS_CNT, THREADS_CNT>>>(v1, v2, matr, n, m);
}

void scalarVectMultGPU(float *v, float a, int n){
    const int THREADS_CNT = 128, BLOCKS_CNT = 128;
    scalarVectorMultGPU<<<BLOCKS_CNT, THREADS_CNT>>>(v, a, n);
}

void addVectorGPU(float *a, float *out, int n){
    const int THREADS_CNT = 128, BLOCKS_CNT = 128;
    addVectorKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, out, n);
}

void subVectorGPU(float *a, float *out, int n){
    const int THREADS_CNT = 128, BLOCKS_CNT = 128;
    subVectorKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, out, n);
}

void activateGPU(float *a, ActivationType type, int n){
    switch(type){
        case(Nothing):{
            break;
        }
        case(LRelu):{
            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            activateLReluKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, n);
            break;
        }
        case(SoftMax):{
            if(handle == nullptr)
                cublasCreate_v2(&handle);

            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            float mx = getMaxValueGPU(a, n);
            preactivateSoftmaxKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, mx, n);
            float sum = 0;
            cublasSasum_v2(handle, n, a,1, &sum);
            scalarVectorMultGPU<<<BLOCKS_CNT, THREADS_CNT>>>(a, 1.0f / sum, n);
            break;
        }
        case(Sigmoid):{
            if(handle == nullptr)
                cublasCreate_v2(&handle);

            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            activateSigmoidKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, n);
            break;
        }
        case(Tanh):{
            if(handle == nullptr)
                cublasCreate_v2(&handle);

            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            activateTanhKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, n);
            break;
        }
        default:{
            std::cout<<"unknown activation type"<<'\n';
        }
    }
}


void derivativeErrorGPU(float *x, float *y, float *out, ActivationType type, int n){
    switch(type){
        case(SquaredError):{
            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            squaredErrorKernel<<<BLOCKS_CNT, THREADS_CNT>>>(x, y, out, n);
            break;
        }
        case(CrossEntropyError):{
            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            crossEntropyErrorKernel<<<BLOCKS_CNT, THREADS_CNT>>>(y, out, n);
            break;
        }
        default:{
            std::cout<<"unknown derivative type\n";
        }
    }
}

void multDerivativeGPU(float *a, float *out, ActivationType type, int n){
    switch(type){
        case(Nothing):{
            break;
        }
        case(LRelu):{
            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            multDerivativeLReluKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, out, n);
            break;
        }
        case(SoftMax):{
            if(handle == nullptr)
                cublasCreate_v2(&handle);

            int mnInd = 0;
            cublasIsamax_v2(handle, n, out, 1, &mnInd);
            mnInd--;
            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            multDerivativeSoftmaxKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, out, n, mnInd);

            break;
        }
        case(Sigmoid):{
            if(handle == nullptr)
                cublasCreate_v2(&handle);
            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            multDerivativeSigmoidKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, out, n);
            break;
        }
        case(Tanh):{

            if(handle == nullptr)
                cublasCreate_v2(&handle);
            const int THREADS_CNT = 32, BLOCKS_CNT = 32;
            multDerivativeTanhKernel<<<BLOCKS_CNT, THREADS_CNT>>>(a, out, n);
            break;
        }
        default:{
            std::cout<<"unknown derivative type\n";
        }
    }
}

float getMaxValueGPU(float *a, int n){
    float *dev_res;
    cudaMalloc((void**)&dev_res, 1 * sizeof(float));
    slowMaxValueKernel<<<1, 1>>>(a, dev_res, n);
    float mx;
    cudaMemcpy(&mx, dev_res, 1 * sizeof(float), cudaMemcpyDeviceToHost);
    cudaFree(dev_res);
    return mx;
}

int getMaxIndexGPU(float *a, int n){
    int mxInd = 0;
    cublasIsamax_v2(handle, n, a, 1, &mxInd);
    mxInd--;
    return mxInd;
}