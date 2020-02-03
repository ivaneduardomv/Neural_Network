#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED

#include <iostream>
#include <vector>
#include <random>

class Perceptron
{
public:
	Perceptron(size_t);
    Perceptron(size_t, float, std::vector<float>);
    ~Perceptron();

    float Feed(std::vector<float>);
	void Train(std::vector<std::vector<float>>, std::vector<float>);

    float Get_Bias(void);
    float Get_Weight_At(size_t);
    size_t Get_Num_Of_Inputs(void);

    void Set_Bias(float);
    void Set_Weight_At(size_t, float);

    void To_JSON(void);

private:
    size_t num_of_inputs;
    float bias;
    std::vector<float> weights;

	float Act_Func(float);
};

#endif // PERCEPTRON_H_INCLUDED
