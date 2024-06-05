//
// Created by volodya-petarda on 3/28/24.
//
#include "GPUNeuralNetwork.h"

GPUNeuralNetwork::GPUNeuralNetwork() {

}

GPUNeuralNetwork::GPUNeuralNetwork(std::vector<int> sizes) {
    this->layers = sizes.size();
    this->sizes = sizes;
    createArrays();
}

void GPUNeuralNetwork::printA() {
    std::cout<<"a:\n";
    for(int i = 0; i < layers; i++){
        float *temp = new float[sizes[i]];
        cudaMemcpy(temp, a[i], sizes[i] * sizeof(float), cudaMemcpyDeviceToHost);
        for(int j = 0; j < sizes[i]; j++){
            std::cout<<temp[j]<<' ';
        }
        std::cout<<'\n';
        delete[] temp;
    }
}

void GPUNeuralNetwork::printB() {
    std::cout<<"b:\n";
    for(int i = 0; i < layers; i++){
        float *temp = new float[sizes[i]];
        cudaMemcpy(temp, b[i], sizes[i] * sizeof(float), cudaMemcpyDeviceToHost);
        for(int j = 0; j < sizes[i]; j++){
            std::cout<<temp[j]<<' ';
        }
        std::cout<<'\n';
        delete[] temp;
    }
}

void GPUNeuralNetwork::printWeights() {
    std::cout<<"weights:\n";
    for(int i = 0; i < layers - 1; i++){
        float *temp = new float[sizes[i] * sizes[i + 1]];
        cudaMemcpy(temp, weights[i], sizes[i] * sizes[i + 1] * sizeof(float), cudaMemcpyDeviceToHost);

        for(int j = 0; j < sizes[i]; j++){
            for(int k = 0; k < sizes[i + 1]; k++){
                std::cout<<temp[j * sizes[i + 1] + k]<<' ';
            }
            std::cout<<'\n';
        }
        std::cout<<'\n';
        delete[] temp;
    }
}

void GPUNeuralNetwork::createArrays() {
    a = new float*[layers];
    b = new float*[layers];
    delt = new float*[layers];
    deltB = new float*[layers];

    for(int i = 0; i < layers; i++){
        cudaMalloc((void**)&a[i], sizes[i] * sizeof(float));
        cudaMalloc((void**)&b[i], sizes[i] * sizeof(float));
        cudaMalloc((void**)&delt[i], sizes[i] * sizeof(float));
        cudaMalloc((void**)&deltB[i], sizes[i] * sizeof(float));
        doZerosGPU(a[i], sizes[i]);
        doZerosGPU(b[i], sizes[i]);
        doZerosGPU(delt[i], sizes[i]);
        doZerosGPU(deltB[i], sizes[i]);
    }
    weights = new float*[layers - 1];
    deltWeights = new float*[layers - 1];
    for(int i = 0; i < layers - 1; i++){
        cudaMalloc((void**)&weights[i], sizes[i] * sizes[i + 1] * sizeof(float));
        cudaMalloc((void**)&deltWeights[i], sizes[i] * sizes[i + 1] * sizeof(float));
        doZerosGPU(deltWeights[i], sizes[i] * sizes[i + 1]);
        float edge = 1.85f * sqrt(1.0 / (sizes[i] + sizes[i + 1]));
        float *temp = new float[sizes[i] * sizes[i + 1]];
        doNormalRandom(temp, sizes[i] * sizes[i + 1], 0, edge);
        cudaMemcpy(weights[i], temp, sizes[i] * sizes[i + 1] * sizeof(float), cudaMemcpyHostToDevice);
        delete[] temp;
    }
    cudaMalloc((void**)&y, sizes[layers - 1] * sizeof(float));

    activationType = std::vector<ActivationType>(layers);
    for(int i = 0; i < layers - 1; i++)
        activationType[i] = ActivationType::Nothing;
    activationType[layers - 1] = ActivationType::SquaredError;
}

void GPUNeuralNetwork::setInput(float *x) {

    cudaMemcpy(a[0], x, sizes[0] * sizeof(float), cudaMemcpyHostToDevice);

    for(int i = 1; i < layers; i++){
        doZerosGPU(a[i], sizes[i]);
    }
}

void GPUNeuralNetwork::setActivationType(const std::vector<ActivationType> &types) {
    for(int i = 0; i < layers; i++){
        activationType[i] = types[i];
    }
}

void GPUNeuralNetwork::setErrorActivationType(ActivationType activationType) {
    this->errorType = activationType;
}

void GPUNeuralNetwork::forwardPropagation() {
    for(int i = 1; i < layers; i++){
        matrixVectorMultGPU(weights[i - 1], a[i - 1], a[i], sizes[i - 1], sizes[i]);
        addVectorGPU(b[i], a[i], sizes[i]);
        activateGPU(a[i], activationType[i], sizes[i]);
    }
}

void GPUNeuralNetwork::backwardPropagation(float *y) {
    if(errorType != CustomError)
        derivativeErrorGPU(a[layers - 1], y, delt[layers - 1], errorType, sizes[layers - 1]);

    multDerivativeGPU(a[layers - 1], delt[layers - 1], activationType[layers - 1], sizes[layers - 1]);
    for(int i = layers - 2; i >= 0; i--){
        tMatrixVectorMultGPU(weights[i], delt[i + 1], delt[i], sizes[i], sizes[i + 1]);
        multDerivativeGPU(a[i], delt[i], activationType[i], sizes[i]);
    }
    for(int i = 0; i < layers - 1; i++){
        vectorVectorMultGPU(a[i], delt[i + 1], deltWeights[i], sizes[i], sizes[i + 1]);
    }
    for(int i = 1; i < layers; i++){
        addVectorGPU(delt[i], deltB[i], sizes[i]);
    }
    for(int i = 0; i < layers; i++){
        doZerosGPU(delt[i], sizes[i]);
    }
}

void GPUNeuralNetwork::doUpdate(float alpha) {
    for(int i = 0; i < layers - 1; i++){
        scalarVectMultGPU(deltWeights[i], alpha, sizes[i] * sizes[i + 1]);
        subVectorGPU(deltWeights[i], weights[i], sizes[i] * sizes[i + 1]);
        doZerosGPU(deltWeights[i], sizes[i] * sizes[i + 1]);
    }
    for(int i = 1; i < layers; i++){
        scalarVectMultGPU(deltB[i], alpha, sizes[i]);
        subVectorGPU(deltB[i], b[i], sizes[i]);
        doZerosGPU(deltB[i], sizes[i]);
    }
}

std::pair<float, bool> GPUNeuralNetwork::train(float *x, float *ty, float alpha, int batchSize) {
    batchStep++;
    cudaMemcpy(y, ty, sizes[layers - 1] * sizeof(float), cudaMemcpyHostToDevice);
    setInput(x);
    forwardPropagation();
    if(errorType == CustomError){
        cudaMemcpy(delt[layers - 1], ty, sizes[layers - 1] * sizeof(float), cudaMemcpyHostToDevice);
    }
    backwardPropagation(y);
    if(batchStep >= batchSize) {
        batchStep = 0;
        doUpdate(alpha);
    }
    float error = 0.0;
    float *m_a = new float[sizes[layers - 1]];
    cudaMemcpy(m_a, a[layers - 1], sizes[layers - 1] * sizeof(float), cudaMemcpyDeviceToHost);
    for(int i = 0; i < sizes[layers - 1]; i++){
        error += pow(m_a[i] - ty[i], 2);
    }
    bool isCorrect = false;
    if(activationType[layers - 1] == ActivationType::SoftMax) {
        int mxInd = getMaxIndex(m_a, sizes[layers - 1]);
        if (ty[mxInd] >= 0.99)
            isCorrect = true;
    }
    if(activationType[layers - 1] == ActivationType::Sigmoid){
        float delt = fabs(ty[0] - m_a[0]);
        if(m_a[0] >= 0.5 && ty[0] >= 0.99)
            isCorrect = true;
        else if(m_a[0] < 0.5 && ty[0] <= 0.01)
            isCorrect = true;
        else
            isCorrect = false;
    }
    if(activationType[layers - 1] == ActivationType::Tanh){
        float delt = fabs(ty[0] - m_a[0]);
        if(delt < 1)
            isCorrect = true;
    }
    delete[] m_a;
    return {error, isCorrect};
}

float *GPUNeuralNetwork::predict(float *x) {
    setInput(x);
    forwardPropagation();
    auto *result = new float[sizes[layers - 1]];
    cudaMemcpy(result, a[layers - 1], sizes[layers - 1] * sizeof(float), cudaMemcpyDeviceToHost);
    return result;
}

void GPUNeuralNetwork::save(const std::string &path) {
    std::ofstream out("../" + path);
    out<<std::fixed<<std::setprecision(40);
    out<<layers<<'\n';
    for(int i = 0; i < layers; i++){
        out<<sizes[i]<<' ';
    }
    out<<'\n';
    for(int i = 0; i < layers; i++){
        out<<activationType[i]<<' ';
    }
    out<<errorType<<'\n';

    for(int i = 0; i < layers - 1; i++){
        float *tempWeights = new float[sizes[i] * sizes[i + 1]];
        cudaMemcpy(tempWeights, weights[i], sizes[i] * sizes[i + 1] * sizeof(float), cudaMemcpyDeviceToHost);
        for(int j = 0; j < sizes[i]; j++){
            for(int k = 0; k < sizes[i + 1]; k++){
                out<<tempWeights[j * sizes[i + 1] + k]<<' ';
            }
            out<<'\n';
        }
        delete[] tempWeights;
    }
    for(int i = 0; i < layers; i++){
        float *tempB = new float[sizes[i]];
        cudaMemcpy(tempB, b[i], sizes[i] * sizeof(float), cudaMemcpyDeviceToHost);
        for(int j = 0; j < sizes[i]; j++){
            out<<tempB[j]<<' ';
        }
        out<<'\n';
        delete[] tempB;
    }
    out.close();

}

void GPUNeuralNetwork::load(const std::string &path) {

    std::ifstream in("../" + path);
    in>>layers;
    sizes = std::vector<int>(layers);
    for(int i = 0; i < layers; i++){
        in>>sizes[i];
    }
    createArrays();
    for(int i = 0; i < layers; i++){
        int t; in>>t;
        activationType[i] = (ActivationType)t;
    }
    int t; in>>t;
    errorType = (ActivationType)t;
    for(int i = 0; i < layers - 1; i++){
        float *tempWeights = new float[sizes[i] * sizes[i + 1]];
        for(int j = 0; j < sizes[i]; j++){
            for(int k = 0; k < sizes[i + 1]; k++){
                in>>tempWeights[j * sizes[i + 1] + k];
            }
        }
        cudaMemcpy(weights[i], tempWeights, sizes[i] * sizes[i + 1] * sizeof(float), cudaMemcpyHostToDevice);
        delete[] tempWeights;
    }

    for(int i = 0; i < layers; i++){
        float *tempB = new float[sizes[i]];
        for(int j = 0; j < sizes[i]; j++){
            in>>tempB[j];
        }
        cudaMemcpy(b[i], tempB, sizes[i] * sizeof(float), cudaMemcpyHostToDevice);
        delete[] tempB;
    }
    in.close();
}

