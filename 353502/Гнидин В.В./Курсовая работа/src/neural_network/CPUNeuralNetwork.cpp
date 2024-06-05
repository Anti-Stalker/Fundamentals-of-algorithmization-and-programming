//
// Created by volodya-petarda on 3/13/24.
//

#include "CPUNeuralNetwork.h"

CPUNeuralNetwork::CPUNeuralNetwork(std::vector<int> sizes) {
    this->layers = sizes.size();
    this->sizes = sizes;
    createArrays();
}

void CPUNeuralNetwork::setActivationType(const std::vector<ActivationType> &types) {
    for(int i = 0; i < layers; i++){
        activationType[i] = types[i];
    }
}

void CPUNeuralNetwork::printA() {
    std::cout<<"printed a:\n";
    for(int i = 0; i < layers; i++){
        for(int j = 0; j < sizes[i]; j++){
            std::cout<<a[i][j]<<' ';
        }
        std::cout<<'\n';
    }
}

void CPUNeuralNetwork::printB() {
    std::cout<<"printed b:\n";
    for(int i = 0; i < layers; i++){
        for(int j = 0; j < sizes[i]; j++){
            std::cout<<b[i][j]<<' ';
        }
        std::cout<<'\n';
    }
}

void CPUNeuralNetwork::printWeights() {
    std::cout<<"printed weights:\n";
    for(int i = 0; i < layers - 1; i++){
        for(int j = 0; j < sizes[i]; j++){
            for(int q = 0; q < sizes[i + 1]; q++){
                std::cout<<weights[i][j][q]<<' ';
            }
            std::cout<<'\n';
        }

        std::cout<<'\n';
    }
}

void CPUNeuralNetwork::forwardPropagation() {
    for(int i = 1; i < layers; i++){
        vectMatrMult(a[i - 1], weights[i - 1], a[i], sizes[i - 1], sizes[i]);
        vectAddVect(a[i], b[i], sizes[i]);
//        if(true){
//            std::cout<<i<<") ";
//            for(int j = 0; j < sizes[layers - 1]; j++){
//                std::cout<<a[i][j]<<' ';
//            }
//            std::cout<<'\n';
//        }
        activate(a[i], activationType[i], sizes[i]);
    }
}

void CPUNeuralNetwork::backwardPropagation(float *y) {
    derivativeError(a[layers - 1], y, delt[layers - 1], errorType,sizes[layers - 1]);
    multDerivative(a[layers - 1], delt[layers - 1], activationType[layers - 1], sizes[layers - 1]);
    for(int i = layers - 2; i >= 0; i--){
        vectTMatrMult(delt[i + 1], weights[i], delt[i], sizes[i + 1], sizes[i]);
        multDerivative(a[i], delt[i], activationType[i], sizes[i]);
    }
    for(int i = 0; i < layers - 1; i++){
        addVectVectMult(a[i], delt[i + 1], deltWeights[i], sizes[i], sizes[i + 1]);
    }
    for(int i = 1; i < layers; i++){
        vectAddVect(deltB[i], delt[i], sizes[i]);
    }
    for(int i = 0; i < layers; i++){
        doZeros(delt[i], sizes[i]);
    }
}

void CPUNeuralNetwork::doUpdate(float alpha) {
    for(int i = 0; i < layers - 1; i++){
        scalarMult(deltWeights[i], alpha, sizes[i], sizes[i + 1]);
        matrSubMatr(weights[i], deltWeights[i], sizes[i], sizes[i + 1]);
        doZeros(deltWeights[i], sizes[i], sizes[i + 1]);
    }
    for(int i = 1; i < layers; i++){
        scalarMult(deltB[i], alpha, sizes[i]);
        vectSubVect(b[i], deltB[i], sizes[i]);
        doZeros(deltB[i], sizes[i]);
    }
}

std::pair<float, bool> CPUNeuralNetwork::train(float *x, float *y, float alpha, int batchSize) {
    setInput(x);
    forwardPropagation();
    backwardPropagation(y);
    doUpdate(alpha);
    float error = 0.0;
    for(int i = 0; i < sizes[layers - 1]; i++){
        error += pow(a[layers - 1][i] - y[i], 2);
    }
    int mxInd = getMaxIndex(a[layers - 1], sizes[layers - 1]);
    bool isCorrect = false;
    if(y[mxInd] >= 0.99)
        isCorrect = true;
    return {error, isCorrect};
}

float *CPUNeuralNetwork::predict(float *x) {
    setInput(x);
    forwardPropagation();
    return a[layers - 1];
}

void CPUNeuralNetwork::setInput(float *x) {
    for(int i = 0; i < sizes[0]; i++){
        a[0][i] = x[i];
    }
    for(int i = 1; i < layers; i++){
        doZeros(a[i], sizes[i]);
    }
}

void CPUNeuralNetwork::setErrorActivationType(ActivationType activationType) {
    this->errorType = activationType;
}

void CPUNeuralNetwork::save(const std::string& path) {
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
        for(int j = 0; j < sizes[i]; j++){
            for(int k = 0; k < sizes[i + 1]; k++){
                out<<weights[i][j][k]<<' ';
            }
            out<<'\n';
        }
    }
    for(int i = 0; i < layers; i++){
        for(int j = 0; j < sizes[i]; j++){
            out<<b[i][j]<<' ';
        }
        out<<'\n';
    }
    out.close();
}

void CPUNeuralNetwork::load(const std::string &path) {
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
        for(int j = 0; j < sizes[i]; j++){
            for(int k = 0; k < sizes[i + 1]; k++){
                in>>weights[i][j][k];
            }
        }
    }

    for(int i = 0; i < layers; i++){
        for(int j = 0; j < sizes[i]; j++){
            in>>b[i][j];
        }
    }
    in.close();
}

void CPUNeuralNetwork::createArrays() {
    a = new float*[layers];
    b = new float*[layers];
    delt = new float*[layers];
    deltB = new float*[layers];
    for(int i = 0; i < layers; i++){
        a[i] = new float[sizes[i]];
        b[i] = new float[sizes[i]];
        delt[i] = new float[sizes[i]];
        deltB[i] = new float[sizes[i]];
        doZeros(a[i], sizes[i]);
        doZeros(b[i], sizes[i]);
        doZeros(delt[i], sizes[i]);
        doZeros(deltB[i], sizes[i]);
    }
    weights = new float**[layers - 1];
    deltWeights = new float**[layers - 1];
    for(int i = 0; i < layers - 1; i++){
        weights[i] = new float*[sizes[i]];
        deltWeights[i] = new float*[sizes[i]];
        for(int j = 0; j < sizes[i]; j++){
            weights[i][j] = new float[sizes[i + 1]];
            deltWeights[i][j] = new float[sizes[i + 1]];
        }

        float edge = 3.0f * sqrt(1.0 / (sizes[i] + sizes[i + 1]));
        doNormalRandom(weights[i], sizes[i], sizes[i + 1], 0, edge);
        doZeros(deltWeights[i], sizes[i], sizes[i + 1]);
    }

    activationType = std::vector<ActivationType>(layers);
    for(int i = 0; i < layers - 1; i++)
        activationType[i] = ActivationType::Nothing;
    activationType[layers - 1] = ActivationType::SquaredError;

}

CPUNeuralNetwork::CPUNeuralNetwork() {

}


