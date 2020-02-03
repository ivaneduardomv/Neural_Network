#include "Perceptron.h"

Perceptron::Perceptron(size_t number_of_inputs)
{
	std::random_device rd;
	std::default_random_engine  dre(rd());
	std::uniform_real_distribution<float> dist(0.1f, 1.0f);

	this->num_of_inputs = number_of_inputs;
	this->weights.resize(num_of_inputs);
	this->bias = dist(dre);

	std::vector<float>::iterator it_weights;
	for(it_weights = this->weights.begin(); it_weights != this->weights.end(); ++it_weights)
	{
		(*it_weights) = dist(dre);
	}
}

Perceptron::Perceptron(size_t number_of_inputs, float init_bias, std::vector<float> init_weights)
{
    this->num_of_inputs  = number_of_inputs;
	this->weights.resize(num_of_inputs);
    this->bias = init_bias;

	std::vector<float>::iterator it_init_weights = init_weights.begin();
	std::vector<float>::iterator it_weights;
	for(it_weights = this->weights.begin(); it_weights != this->weights.end(); ++it_weights)
    {
        (*it_weights) = (*it_init_weights);
		++it_init_weights;
    }
}

Perceptron::~Perceptron()
{
}

float Perceptron::Feed(std::vector<float> input)
{
    float weighted_sum = this->bias;

	std::vector<float>::iterator it_input = input.begin();
	std::vector<float>::iterator it_weights;
	for(it_weights = this->weights.begin(); it_weights != this->weights.end(); ++it_weights)
    {
        weighted_sum += (*it_weights) * (*it_input);
		++it_input;
    }
    return this->Act_Func(weighted_sum);
}

void Perceptron::Train(std::vector<std::vector<float>> train_cases, std::vector<float> expected_output)
{
	float learn_factor = 0.45f;
	std::vector<float>::iterator it_expected_output = expected_output.begin();
	std::vector<std::vector<float>>::iterator it_train_cases;
	for(it_train_cases = train_cases.begin(); it_train_cases != train_cases.end(); ++it_train_cases)
	{
		float error = (*it_expected_output) - this->Feed((*it_train_cases));

		this->bias += learn_factor * error;

		std::vector<float>::iterator it_train_input = (*it_train_cases).begin();
		std::vector<float>::iterator it_weights;
		for (it_weights = this->weights.begin(); it_weights != this->weights.end(); ++it_weights)
		{
			(*it_weights) += (*it_weights) + learn_factor * error * (*it_train_input);
			++it_train_input;
		}
		++it_expected_output;
	}
}

float Perceptron::Get_Bias(void)
{
    return this->bias;
}
float Perceptron::Get_Weight_At(size_t index)
{
    return this->weights.at(index);
}

size_t Perceptron::Get_Num_Of_Inputs(void)
{
    return this->num_of_inputs;
}

void Perceptron::Set_Bias(float new_bias)
{
    this->bias = new_bias;
}

void Perceptron::Set_Weight_At(size_t index, float new_weight)
{
    this->weights.at(index) = new_weight;
}

void Perceptron::To_JSON(void)
{
	std::cout << "Perceptron = {";
	std::cout << "\"num_of_inputs\":" << this->num_of_inputs << ",";
	std::cout << "\"bias\":" << this->bias << ",";
	std::cout << "\"weights\":[";
    for(size_t i = 0; i < this->num_of_inputs; ++i)
    {
		std::cout << this->weights[i];
        if(i < num_of_inputs - 1)
        {
			std::cout << ",";
        }
    }
	std::cout << "]}" << std::endl;
}

float Perceptron::Act_Func(float weighted_sum)
{
    float output = 0.0f;
	if (weighted_sum > 0.0f)
		output = 1.0f;
	//else
		//output = weighted_sum / 100.0f;

    return output;
}
