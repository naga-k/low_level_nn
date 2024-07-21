#include <iostream>
#include <Eigen/Dense>

int main() {
    // Initialize inputs as a 3x4 matrix
    Eigen::MatrixXd inputs(3, 4);
    inputs << 1.0, 2.0, 3.0, 2.5,
              2.0, 5.0, -1.0, 2.0,
              -1.5, 2.7, 3.3, -0.8;

    // Initialize weights as a 3x4 matrix
    Eigen::MatrixXd weights(3, 4);
    weights << 0.2, 0.8, -0.5, 1.0,
               0.5, -0.91, 0.26, -0.5,
               -0.26, -0.27, 0.17, 0.87;

    // Initialize biases as a vector of size 3
    Eigen::Vector3d biases(2.0, 3.0, 0.5);

    // Transpose the weights matrix
    Eigen::MatrixXd weights_transposed = weights.transpose();

    // Perform matrix multiplication
    Eigen::MatrixXd outputs = inputs * weights_transposed;

    // Add biases to each row of the result
    Eigen::MatrixXd final_outputs = outputs.rowwise() + biases.transpose();

    // Print the result
    std::cout << "Final outputs:\n" << final_outputs << std::endl;

    return 0;
}
