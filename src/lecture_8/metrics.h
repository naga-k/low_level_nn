#ifndef METRICS_H
#define METRICS_H

#include <Eigen/Dense>

class Metrics {
public:
    template <typename T>
    double accuracy(const Eigen::MatrixXd& predictions, const Eigen::MatrixBase<T>& class_targets) const;
};

template <typename T>
double Metrics::accuracy(const Eigen::MatrixXd& predictions, const Eigen::MatrixBase<T>& class_targets) const {
    // Check if predictions and class_targets have compatible dimensions
    assert(predictions.rows() == class_targets.rows() && "Dimensions of predictions and class_targets must match");
    
    Eigen::VectorXi class_indices(class_targets.rows());

    if (class_targets.cols() == 1) {
        // If class_targets is already class indices
        class_indices = class_targets.template cast<int>();
    } else {
        // If class_targets is one-hot encoded
        for (int i = 0; i < class_targets.rows(); ++i) {
            Eigen::MatrixXd::Index maxIndex;
            class_targets.row(i).maxCoeff(&maxIndex);
            class_indices(i) = maxIndex;
        }
    }

    // Count correct predictions
    int correct_predictions = 0;
    for (int i = 0; i < predictions.rows(); ++i) {
        Eigen::MatrixXd::Index predicted_index;
        predictions.row(i).maxCoeff(&predicted_index);
        if (predicted_index == class_indices(i)) {
            ++correct_predictions;
        }
    }

    // Calculate accuracy
    double accuracy = static_cast<double>(correct_predictions) / predictions.rows();
    return accuracy;
}

#endif // METRICS_H
