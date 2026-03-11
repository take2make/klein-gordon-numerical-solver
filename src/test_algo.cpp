#include "algo.h"

std::vector<double> phi_analytic_gauss() {
    std::vector<double> phi(N_x * (N_steps + 1), 0.0);
    for(int n = 0; n <= N_steps; n++)
    {
        double t_n = n * dt;
        for(int i = 0; i < N_x; i++)
        {
            double x_i = i * dx;
            phi[idx(i, n)] = 0.5 * A * std::exp(-1 * std::pow((x_i - t_n - x_0), 2)/(2.0 * sigma * sigma)) + 0.5 * A * std::exp(-1 * std::pow((x_i + t_n - x_0), 2)/(2.0 * sigma * sigma));
        }
    }
    return phi;
}

void write_analytic_data(int step) {
    std::vector<double> phi = phi_analytic_gauss();
    std::ofstream file("dat/klein_gordon_output_" + std::to_string(step) + ".dat");
    for (int i = 0; i < N_x; i++) 
    {
        file << i * dx << " " << phi[idx(i, step + 1)] << "\n";
    }
    file.close();
}