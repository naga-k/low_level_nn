#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <fstream>
#include <sstream>
#include <random> // Include this for random number generation

// Dense Layer Class
class DenseLayer {
public:
    DenseLayer(int n_inputs, int n_neurons) {
        weights = Eigen::MatrixXd::Random(n_inputs, n_neurons) * 0.01;
        biases = Eigen::MatrixXd::Zero(1, n_neurons);
    }

    void forward(const Eigen::MatrixXd& inputs) {
        output = (inputs * weights).rowwise() + biases.row(0);
    }

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

    // std::random_device rd;
    std::mt19937 generator(123); // Initialize random number generator
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

// Save data to a file for gnuplot
void save_data_for_plotting(const Eigen::MatrixXd& X, const Eigen::VectorXi& y) {
    std::ofstream file("data.txt");
    for (int i = 0; i < X.rows(); ++i) {
        file << X(i, 0) << " " << X(i, 1) << " " << y(i) << "\n";
    }
    file.close();
}

// Plot data using gnuplot
void plot_data_with_gnuplot() {
    std::ofstream gnuplot_pipe("gnuplot_commands.txt");
    gnuplot_pipe << "set terminal png size 800,600\n";
    gnuplot_pipe << "set output 'plot.png'\n";
    gnuplot_pipe << "set title 'Spiral Data'\n";
    gnuplot_pipe << "set xlabel 'X'\n";
    gnuplot_pipe << "set ylabel 'Y'\n";
    gnuplot_pipe << "set key off\n";
    gnuplot_pipe << "set style data points\n";
    gnuplot_pipe << "plot 'data.txt' using 1:2:3 with points palette\n";
    gnuplot_pipe.close();

    system("gnuplot gnuplot_commands.txt");
    std::cout << "Plot saved as plot.png" << std::endl;
}

int main() {
    const int samples = 100;
    const int classes = 3;
    Eigen::MatrixXd X;
    Eigen::VectorXi y;

    generate_spiral_data(samples, classes, X, y);

    DenseLayer dense1(2, 3);
    dense1.forward(X);

    std::cout << "Output of the first few samples:" << std::endl;
    std::cout << dense1.getOutput().topRows(5) << std::endl;

    // Save data and plot
    save_data_for_plotting(X, y);
    plot_data_with_gnuplot();

    return 0;
}
