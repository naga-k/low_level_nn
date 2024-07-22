#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

#include <Eigen/Dense>

class ReLU {
public:
    void forward(const Eigen::MatrixXd& inputs);
    const Eigen::MatrixXd& getOutput();

private:
    Eigen::MatrixXd output;
};

class Sigmoid {
public:
    void forward(const Eigen::MatrixXd& inputs);
    const Eigen::MatrixXd& getOutput();

private:
    Eigen::MatrixXd output;
};

#endif // ACTIVATION_FUNCTIONS_H