#include <iostream>
#define m 3
#define n 4

int main(){
    std::cout << "First Layer!" << std::endl;

    float inputs[] = {0.2, 0.8, -0.5, 1.0};

    float weights[m][n] = {{0.2, 0.8, -0.5, 1.0},
                          {0.5, -0.91, 0.26, -0.5},
                          {-0.26, -0.27, 0.17, 0.87}};

    float biases[] = {2.0, 3.0, 0.5};

    float layer_outputs[n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            layer_outputs[j] += inputs[i] * weights[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        layer_outputs[i] += biases[i];
    }

    std::cout << "Outputs: " << layer_outputs[0] << ", " << layer_outputs[1] << ", " << layer_outputs[2] << std::endl           ;



    
}