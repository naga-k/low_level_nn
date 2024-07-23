#include <iostream>
#include <Eigen/Dense>

int main(){

    Eigen::MatrixXd softmax_outputs(3,3);
    softmax_outputs << 0.7, 0.2, 0.1,
                        0.5, 0.1, 0.4,
                        0.02, 0.9, 0.08;

    Eigen::VectorXi class_targets(3);
    class_targets << 0, 1, 1;

    Eigen::VectorXi predictions(3);

    for (int i = 0; i < softmax_outputs.rows(); i++) {
        Eigen::MatrixXd::Index maxIndex;
        softmax_outputs.row(i).maxCoeff(&maxIndex);
        predictions(i) = maxIndex;
    }

    if (class_targets.cols() > 2)
    {
        for (int i = 0; i < class_targets.rows(); i++){
            Eigen::MatrixXd::Index maxIndex;
            softmax_outputs.row(i).maxCoeff(&maxIndex);
            predictions(i) = maxIndex;
        }
    }

    int correct_predictions = 0;
    for (int i = 0; i < predictions.size(); i++){
        if( predictions(i) == class_targets(i)){
            correct_predictions++;
        }
    }

    double accuracy = static_cast<double>(correct_predictions)/predictions.size();

    std::cout << "Accuracy" << ": " << accuracy << std::endl;


    
}