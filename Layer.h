#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include "Perceptron.h"

#define DEFAULT_NUM_OF_PERCEPTRONS 2

class Layer
{
public:
	Layer(size_t, size_t);
    ~Layer();

	std::vector<float> Feed(std::vector<float>);

	size_t Get_Num_Of_Perceptrons(void);
    
    void To_JSON(void);

private:
	size_t num_of_perceptrons;
	std::vector<Perceptron> *perceptrons;
};

#endif // LAYER_H_INCLUDED
