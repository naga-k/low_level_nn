#include <iostream>
#include <Eigen/Dense>

int main() {
    // Initialize Eigen vectors and matrices
    Eigen::Vector4d inputs(1.0, 2.0, 3.0, 2.5);
    
    // Initialize weights as a 3x4 matrix
    Eigen::MatrixXd weights(3, 4);
    weights << 0.2, 0.8, -0.5, 1.0,
               0.5, -0.91, 0.26, -0.5,
               -0.26, -0.27, 0.17, 0.87;
    
    // Initialize biases as a vector of size 3
    Eigen::Vector3d biases(2.0, 3.0, 0.5);

    // Compute the dot product of weights and inputs
    Eigen::VectorXd layer_outputs = weights * inputs + biases;

    // Print the result
    std::cout << "Layer outputs: " << layer_outputs.transpose() << std::endl;

    return 0;
}
