#include <iostream>
#include <Eigen/Dense>

int main() {
    // Define two arrays
    Eigen::ArrayXXf array1(2, 3);
    Eigen::ArrayXXf array2(2, 1);

    // Initialize arrays with values
    array1 << 1, 2, 3,
              4, 5, 6;
    array2 << 10,
              20;

    // Broadcasting and summation
    Eigen::ArrayXXf result = array1 + array2.replicate(1, 3);

    // Print the arrays and the result
    std::cout << "Array 1:\n" << array1 << "\n\n";
    std::cout << "Array 2 (broadcasted):\n" << array2.replicate(1, 3) << "\n\n";
    std::cout << "Result (Array 1 + Array 2):\n" << result << "\n";

    return 0;
}
