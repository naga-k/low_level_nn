#include "loss.h"

// Calculate the data and regularization losses
double Loss::calculate(Eigen::MatrixXd& output, Eigen::VectorXi& y) {
    // Number of samples
    int samples = output.rows();

    // Probabilities for target values - only if categorical labels
    Eigen::VectorXd p_y(samples);
    for (int i = 0; i < samples; i++) {
        p_y(i) = output(i, y(i));
    }

    // Losses
    Eigen::ArrayXd losses = -p_y.array().log();

    // Data loss
    double data_loss = losses.mean();

    return data_loss;
}
