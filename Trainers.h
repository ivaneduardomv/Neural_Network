#ifndef TRAINERS_H_INCLUDED
#define TRAINERS_H_INCLUDED

#include "Perceptron.h"
#include "Layer.h"

bool Train_Perceptron(Perceptron&, std::vector<std::vector<float>>, std::vector<float>);

#endif // TRAINERS_H_INCLUDED
