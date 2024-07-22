#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <random>

// Dense Layer Class
class DenseLayer {
public:
    // Constructor for DenseLayer
    DenseLayer(int n_inputs, int n_neurons) {
        // Initialize weights and biases
        weights = Eigen::MatrixXd::Random(n_inputs, n_neurons) * 0.01;
        biases = Eigen::MatrixXd::Zero(1, n_neurons);
    }

    // Forward pass
    void forward(const Eigen::MatrixXd& inputs) {
        output = (inputs * weights).rowwise() + biases.row(0);
    }

    // Getter for output
    const Eigen::MatrixXd& getOutput() const {
        return output;
    }

private:
    Eigen::MatrixXd weights;
    Eigen::MatrixXd biases;
    Eigen::MatrixXd output;
};

// Generate spiral data
void generate_spiral_data(int samples, int classes, Eigen::MatrixXd& X, Eigen::VectorXi& y) {
    X.resize(samples * classes, 2);
    y.resize(samples * classes);
    int ix = 0;
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    for (int class_number = 0; class_number < classes; ++class_number) {
        for (int sample_number = 0; sample_number < samples; ++sample_number) {
            double r = static_cast<double>(sample_number) / samples;
            double t = class_number * 4 + r * 4 + distribution(generator) * 0.2;
            X(ix, 0) = r * sin(t * 2.5);
            X(ix, 1) = r * cos(t * 2.5);
            y(ix) = class_number;
            ix++;
        }
    }
}

int main() {
    const int samples = 100;
    const int classes = 3;
    Eigen::MatrixXd X;
    Eigen::VectorXi y;

    // Generate spiral data
    generate_spiral_data(samples, classes, X, y);

    // Create Dense layer with 2 input features and 3 output values
    DenseLayer dense1(2, 3);

    // Perform forward pass
    dense1.forward(X);

    // Output the first few samples
    std::cout << "Output of the first few samples:" << std::endl;
    std::cout << dense1.getOutput().topRows(5) << std::endl;

    return 0;
}
