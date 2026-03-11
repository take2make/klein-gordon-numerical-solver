#include "algo.h"

void set_initial_conditions(std::vector<double>& phi)
{
    for(int i = 0; i < N_x; i++)
    {
        double x_i = i * dx;
        phi[idx(i, 0)] = A * std::exp(-1 * std::pow((x_i - x_0), 2)/(2.0 * sigma * sigma)) * std::cos(k * x_i);
    }
}

void set_gauss_conditions(std::vector<double>& phi)
{
    for(int i = 0; i < N_x; i++)
    {
        double x_i = i * dx;
        phi[idx(i, 0)] = A * std::exp(-1 * std::pow((x_i - x_0), 2)/(2.0 * sigma * sigma));
    }
}
