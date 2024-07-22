#include "activation_functions.h"
#include <cmath>

void ReLU::forward(const Eigen::MatrixXd& inputs) {
    output = inputs.unaryExpr([](double x) { return std::max(0.0, x); });
}

const Eigen::MatrixXd& ReLU::getOutput() {
    return output;
}

void Sigmoid::forward(const Eigen::MatrixXd& inputs) {
    output = inputs.unaryExpr([](double x) { return 1.0 / (1.0 + std::exp(-x)); });
}

const Eigen::MatrixXd& Sigmoid::getOutput() {
    return output;
}

void Softmax::forward(const Eigen::MatrixXd& inputs) {
    Eigen::MatrixXd exp_inputs = inputs.array().exp();
    output = exp_inputs.array().rowwise() / exp_inputs.colwise().sum().array();
}

const Eigen::MatrixXd& Softmax::getOutput() {
    return output;
}