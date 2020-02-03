#include "Trainers.h"

bool Train_Perceptron(Perceptron &p, std::vector<std::vector<float>> cases, std::vector<float> expected_out)
{
    bool is_training_succes = false;

    unsigned int error_count = 0;
    unsigned int iterations = 0;
    float learn_factor = 0.45f;

    do
    {
        error_count = 0;
        for(size_t i = 0; i < cases.size(); ++i)
        {
            float computed_out = p.Feed(cases[i]);
            float error = expected_out[i] - computed_out;
            if(expected_out[i] != computed_out)
                ++error_count;

            float current_bias = p.Get_Bias();
            float new_bias = current_bias + learn_factor * error;
            p.Set_Bias(new_bias);

            for(size_t j = 0; j < p.Get_Num_Of_Inputs(); ++j)
            {
                float current_weight = p.Get_Weight_At(j);
                float new_weight = current_weight + learn_factor * error * cases[i][j];
                p.Set_Weight_At(j, new_weight);
            }
        }
        ++iterations;
    }while(error_count != 0 && iterations < 100);


    if(iterations < 100) is_training_succes = true;

    return is_training_succes;
}
