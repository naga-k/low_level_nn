#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <Eigen/Dense>

// Function to generate spiral data
void generate_spiral_data(int samples, int classes, Eigen::MatrixXd& X, Eigen::VectorXi& y) {
    X.resize(samples * classes, 2);
    y.resize(samples * classes);
    
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    
    int ix = 0;
    for (int class_number = 0; class_number < classes; ++class_number) {
        for (int sample_number = 0; sample_number < samples; ++sample_number) {
            double r = static_cast<double>(sample_number) / samples;
            double t = class_number * 4 + r * 4 + ((rand() % 100) / 100.0) * 0.2;
            X(ix, 0) = r * sin(t * 2.5);
            X(ix, 1) = r * cos(t * 2.5);
            y(ix) = class_number;
            ix++;
        }
    }
}

// Function to write data to a file and plot with gnuplot
void plot_with_gnuplot(const Eigen::MatrixXd& X, const Eigen::VectorXi& y) {
    std::ofstream data_file("data.txt");
    for (int i = 0; i < X.rows(); ++i) {
        data_file << X(i, 0) << " " << X(i, 1) << " " << y(i) << "\n";
    }
    data_file.close();

    // Plotting using gnuplot
    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Spiral Data'\n");
        fprintf(gnuplotPipe, "set xlabel 'X-axis'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y-axis'\n");
        fprintf(gnuplotPipe, "plot 'data.txt' using 1:2:3 with points palette pt 7\n");
        pclose(gnuplotPipe);
    } else {
        std::cerr << "Error: Could not open gnuplot pipe." << std::endl;
    }
}

int main() {
    const int samples = 100;
    const int classes = 3;
    Eigen::MatrixXd X;
    Eigen::VectorXi y;

    generate_spiral_data(samples, classes, X, y);

    plot_with_gnuplot(X, y);

    return 0;
}
