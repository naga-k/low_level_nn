#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

// Function to generate spiral data
void generate_spiral_data(int samples, int classes, std::vector<double>& x_values, std::vector<double>& y_values) {
    int ix = 0;
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    for (int class_number = 0; class_number < classes; ++class_number) {
        for (int sample_number = 0; sample_number < samples; ++sample_number) {
            double r = static_cast<double>(sample_number) / samples;
            double t = class_number * 4 + r * 4 + ((rand() % 100) / 100.0) * 0.2;
            x_values.push_back(r * sin(t * 2.5));
            y_values.push_back(r * cos(t * 2.5));
        }
    }
}

// Function to write data to a file and plot with gnuplot
void plot_with_gnuplot(const std::vector<double>& x_values, const std::vector<double>& y_values) {
    std::ofstream data_file("data.txt");
    for (size_t i = 0; i < x_values.size(); ++i) {
        data_file << x_values[i] << " " << y_values[i] << "\n";
    }
    data_file.close();

    // Plotting using gnuplot
    FILE* gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Spiral Data'\n");
        fprintf(gnuplotPipe, "set xlabel 'X-axis'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y-axis'\n");
        fprintf(gnuplotPipe, "plot 'data.txt' with points pt 7\n");
        pclose(gnuplotPipe);
    } else {
        std::cerr << "Error: Could not open gnuplot pipe." << std::endl;
    }
}

int main() {
    const int samples = 100;
    const int classes = 3;
    std::vector<double> x_values, y_values;

    generate_spiral_data(samples, classes, x_values, y_values);

    plot_with_gnuplot(x_values, y_values);

    return 0;
}
