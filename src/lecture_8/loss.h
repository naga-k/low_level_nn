#ifndef LOSS_H
#define LOSS_H

#include <Eigen/Dense>

class Loss {
public:
    // Calculate the data and regularization losses
    double calculate(Eigen::MatrixXd& output, Eigen::VectorXi& y);
};

#endif // LOSS_H
