#include "Layer.h"

Layer::Layer(size_t number_of_perceptrons, size_t number_of_inputs_per_perceptron)
{
	this->num_of_perceptrons = number_of_perceptrons;
	this->perceptrons = new std::vector<Perceptron>(this->num_of_perceptrons, Perceptron(number_of_inputs_per_perceptron));
}

Layer::~Layer()
{
	delete[] this->perceptrons;
}

std::vector<float> Layer::Feed(std::vector<float> input)
{
	std::vector<float> output(this->num_of_perceptrons);
    for(size_t i = 0; i < this->num_of_perceptrons; ++i)
    {
		output[i] = this->perceptrons->at(i).Feed(input);
    }
	return output;
}

size_t Layer::Get_Num_Of_Perceptrons(void)
{
	return this->num_of_perceptrons;
}

void Layer::To_JSON(void)
{
    std::cout << "Layer = {" << std::endl;
	std::cout << "\t\"num_of_perceptrons\":" << this->num_of_perceptrons << "," << std::endl;
	std::cout << "\t\"perceptrons\":[" << std::endl;
    for(size_t i = 0; i < this->num_of_perceptrons; ++i)
    {
		std::cout << "\t\t";
        this->perceptrons->at(i).To_JSON();
        if(i < this->num_of_perceptrons - 1)
        {
			std::cout << ",";
        }
		std::cout << std::endl;
    }
	std::cout << "\t\t]" << std::endl;
	std::cout << "\t}" << std::endl;
}
