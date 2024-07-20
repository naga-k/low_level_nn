#include <iostream>

int main(){
    std::cout << "Second Neuron!" << std::endl;

    float inputs[] = {1.0, 2.0, 3.0, 2.5};
    float weights[] = {0.2, 0.8, -0.5,1.0};
    float bias = 2.0;

    float outputs = (inputs[0] * weights[0] + inputs[1] * weights[1] + inputs[2] * weights[2]) + bias;

    std::cout << "Output: ";
    std::cout << outputs << std::endl;
}