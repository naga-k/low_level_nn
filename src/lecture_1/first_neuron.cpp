#include <iostream>

int main() {
    std::cout << "First Neuron!" << std::endl;
    
    int inputs[] = {1, 2, 3};
    int weights[] = {3, 2, 1};
    int bias = 1;

    int outputs = (inputs[0] * weights[0] + inputs[1] * weights[1] + inputs[2] * weights[2]) + bias;

    std::cout << "Output: ";
    std::cout << outputs << std::endl;
}