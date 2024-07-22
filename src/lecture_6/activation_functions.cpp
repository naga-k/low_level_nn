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