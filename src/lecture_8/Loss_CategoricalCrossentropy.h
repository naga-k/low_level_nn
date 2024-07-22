#ifndef LOSS_CATEGORICALCROSSENTROPY_H
#define LOSS_CATEGORICALCROSSENTROPY_H

#include "loss.h"

class Loss_CategoricalCrossentropy : public Loss {
public:
    double forward(const Eigen::MatrixXd& y_pred, const Eigen::VectorXi& y_true);
};

#endif // LOSS_CATEGORICALCROSSENTROPY_H
