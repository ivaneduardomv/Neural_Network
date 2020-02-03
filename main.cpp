#include <iostream>
#include <vector>

#include "MyDefines.h"

#include "Perceptron.h"
#include "Trainers.h"

void Test_Perceptron_Trainer(void);

int main(int argc, char *argv[])
{
	Perceptron p(2);
	std::vector<std::vector<float>> in_data_and(4, std::vector<float>(2));
	std::vector<float> out_data_and(4);
	in_data_and[0][0] = 0; in_data_and[0][1] = 0; out_data_and[0] = 0;
	in_data_and[1][0] = 0; in_data_and[1][1] = 1; out_data_and[1] = 0;
	in_data_and[2][0] = 1; in_data_and[2][1] = 0; out_data_and[2] = 0;
	in_data_and[3][0] = 1; in_data_and[3][1] = 1; out_data_and[3] = 1;

	size_t iter = 1;
	do
	{
		p.Train(in_data_and, out_data_and);

		std::cout << "iteracion: " << iter << std::endl;
		std::vector<std::vector<float>>::iterator it_in_data_and;
		for (it_in_data_and = in_data_and.begin(); it_in_data_and != in_data_and.end(); ++it_in_data_and)
		{
			std::cout << p.Feed((*it_in_data_and)) << std::endl;
		}
		++iter;

	}while(iter < 100);

	system("pause");

    return 0;
}

void Test_Perceptron_Trainer(void)
{
	Perceptron p_and(2);
	std::vector<std::vector<float>> in_data_and(4, std::vector<float>(2));
	std::vector<float> out_data_and(4);
	in_data_and[0][0] = 0; in_data_and[0][1] = 0; out_data_and[0] = 0;
	in_data_and[1][0] = 0; in_data_and[1][1] = 1; out_data_and[1] = 0;
	in_data_and[2][0] = 1; in_data_and[2][1] = 0; out_data_and[2] = 0;
	in_data_and[3][0] = 1; in_data_and[3][1] = 1; out_data_and[3] = 1;

	std::cout << "--------------------------------------------------Initial states" << std::endl;
	p_and.To_JSON();
	std::cout << "------------------------------------------------------------" << std::endl;

	if (Train_Perceptron(p_and, in_data_and, out_data_and))
	{
		std::cout << "Training success!" << std::endl;
	}
	else
	{
		std::cout << "Training failure!" << std::endl;
	}

	std::cout << "--------------------------------------------------Final states" << std::endl;
	p_and.To_JSON();
	std::cout << "------------------------------------------------------------" << std::endl;

	Perceptron p_or(2);
	std::vector<std::vector<float>> in_data_or(4, std::vector<float>(2));
	std::vector<float> out_data_or(4);
	in_data_or[0][0] = 0; in_data_or[0][1] = 0; out_data_or[0] = 0;
	in_data_or[1][0] = 0; in_data_or[1][1] = 1; out_data_or[1] = 1;
	in_data_or[2][0] = 1; in_data_or[2][1] = 0; out_data_or[2] = 1;
	in_data_or[3][0] = 1; in_data_or[3][1] = 1; out_data_or[3] = 1;

	std::cout << "--------------------------------------------------Initial states" << std::endl;
	p_or.To_JSON();
	std::cout << "------------------------------------------------------------" << std::endl;

	if (Train_Perceptron(p_or, in_data_or, out_data_or))
	{
		std::cout << "Training success!" << std::endl;
	}
	else
	{
		std::cout << "Training failure!" << std::endl;
	}

	std::cout << "--------------------------------------------------Final states" << std::endl;
	p_or.To_JSON();
	std::cout << "------------------------------------------------------------" << std::endl;
}