#include <iostream>
#include <Eigen/Dense>
#include "Loss_CategoricalCrossentropy.h"

// Function to convert one-hot encoded class targets to class labels
Eigen::VectorXi oneHotToClassLabels(const Eigen::MatrixXd& oneHot) {
    Eigen::VectorXi classLabels(oneHot.rows());
    for (int i = 0; i < oneHot.rows(); ++i) {
        Eigen::MatrixXd::Index maxIndex;
        oneHot.row(i).maxCoeff(&maxIndex);
        classLabels(i) = maxIndex;
    }
    return classLabels;
}

int main() {
    // Initialize softmax outputs
    Eigen::MatrixXd softmax_outputs(3, 3);
    softmax_outputs << 0.7, 0.1, 0.2,
                       0.1, 0.5, 0.4,
                       0.02, 0.9, 0.08;
    
    // Initialize class targets in one-hot encoding
    Eigen::MatrixXd class_targets(3, 3);
    class_targets << 1, 0, 0,
                     0, 1, 0,
                     0, 1, 0;
    
    // Convert one-hot encoded class targets to class labels
    Eigen::VectorXi class_labels = oneHotToClassLabels(class_targets);

    // Calculate loss
    Loss_CategoricalCrossentropy loss_function;
    double loss = loss_function.calculate(softmax_outputs, class_labels); // Assuming calculate is correctly implemented to handle this
    
    // Print loss
    std::cout << "Loss: " << loss << std::endl;

    return 0;
}