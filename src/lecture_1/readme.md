# Neural Network Layer Computation

## Overview

This document describes the mathematical operations used to compute the output of a single layer of a neural network.

## Components

1. **Inputs**: A vector of input values \( X = [X_1, X_2, X_3, X_4] \).
2. **Weights**: A matrix of weights for each neuron, where each row corresponds to the weights associated with a specific neuron.
3. **Biases**: A vector of bias values, where each element corresponds to the bias of a specific neuron.

## Mathematical Operations

### Inputs

- \( X = [X_1, X_2, X_3, X_4] \)

### Weights

- For Neuron 1: \( W^{(1)} = [W_{11}, W_{12}, W_{13}, W_{14}] \)
- For Neuron 2: \( W^{(2)} = [W_{21}, W_{22}, W_{23}, W_{24}] \)
- For Neuron 3: \( W^{(3)} = [W_{31}, W_{32}, W_{33}, W_{34}] \)

### Biases

- For Neuron 1: \( b^{(1)} \)
- For Neuron 2: \( b^{(2)} \)
- For Neuron 3: \( b^{(3)} \)

### Output Calculation

For each neuron \( j \) in the layer:

1. **Compute the Weighted Sum**: The weighted sum \( Z_j \) is calculated as follows:

   \[
   Z_j = \sum_{i=1}^{4} (W_{ji} \cdot X_i)
   \]

   Where \( W_{ji} \) represents the weight from the \( i \)-th input to the \( j \)-th neuron, and \( X_i \) represents the \( i \)-th input value.

2. **Add Bias**: The final output \( O_j \) for the neuron is computed by adding the bias \( b_j \) to the weighted sum \( Z_j \):

   \[
   O_j = Z_j + b_j
   \]

3. **Store the Output**: The computed output \( O_j \) is stored as the result for the \( j \)-th neuron.

### Example Calculation

Given:
- Inputs: \( X = [1, 2, 3, 2.5] \)
- Weights for Neuron 1: \( W^{(1)} = [0.2, 0.8, -0.5, 1] \)
- Bias for Neuron 1: \( b^{(1)} = 2 \)

For Neuron 1:

1. Compute the weighted sum:

   \[
   Z_1 = (0.2 \cdot 1) + (0.8 \cdot 2) + (-0.5 \cdot 3) + (1 \cdot 2.5) = 0.2 + 1.6 - 1.5 + 2.5 = 2.8
   \]

2. Add the bias:

   \[
   O_1 = Z_1 + b^{(1)} = 2.8 + 2 = 4.8
   \]

The output for Neuron 1 is 4.8.

### General Formula

For any neuron \( j \):

\[
O_j = \left( \sum_{i=1}^{4} (W_{ji} \cdot X_i) \right) + b_j
\]

## Summary

- **Inputs** are multiplied by corresponding weights.
- **Weighted sums** are computed for each neuron.
- **Biases** are added to the weighted sums.
- **Outputs** are stored and can be used for further computations or layer processing.
