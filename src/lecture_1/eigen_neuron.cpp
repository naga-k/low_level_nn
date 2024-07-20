#include <iostream>
#include <Eigen/Dense>

int main(){
    Eigen::Vector4d inputs(0.2, 0.8, -0.5, 1.0);
    Eigen::Vector4d weights(0.4, 0.8, -0.5, 1.0);

    double bias = 2.0;

    double dot_product = inputs.dot(weights);

    double output = dot_product + bias;

    std::cout << "Output: " << output << std::endl;

    return 0;

}