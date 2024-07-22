#include "Loss_CategoricalCrossentropy.h"
#include <algorithm>

double Loss_CategoricalCrossentropy::forward(const Eigen::MatrixXd& y_pred, const Eigen::VectorXi& y_true) {
    // Number of samples
    int samples = y_pred.rows();

    // Clipping y_pred to avoid log(0)
    auto clip = [](double value) { return std::max(1e-7, std::min(1 - 1e-7, value)); };
    Eigen::MatrixXd y_pred_clipped = y_pred.unaryExpr(clip);

    Eigen::VectorXd correct_confidences(samples);
    for (int i = 0; i < samples; ++i) {
        correct_confidences(i) = y_pred_clipped(i, y_true(i));
    }

    // Calculate negative log likelihoods
    Eigen::VectorXd negative_log_likelihoods = -correct_confidences.array().log();
    // Return the mean of negative log likelihoods as the loss
    return negative_log_likelihoods.mean();
}
