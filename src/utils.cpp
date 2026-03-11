#include "algo.h"

void write_data(const std::vector<double>& phi, int step) 
{
    std::ofstream file("dat/klein_gordon_output_" + std::to_string(step) + ".dat");
    for (int i = 0; i < N_x; i++) 
    {
        file << i * dx << " " << phi[idx(i, step)] << "\n";
    }
    file.close();
}

void check_energy_convervation(const std::vector<double>& phi, const std::vector<double>& pi_half, int n) {
    double energy = 0.0;
    for (int i = 1; i < N_x - 1; ++i) {
        double kinetic = 0.5 * pi_half[idx(i, n)] * pi_half[idx(i, n)];
        double potential = 0.5 * m * m * phi[idx(i, n)] * phi[idx(i, n)];
        double phi_dot_dx = (phi[idx((i + 1), n)] - phi[idx((i - 1), n)]) / (2.0 * dx);
        potential += 0.5 * phi_dot_dx * phi_dot_dx;
        energy += kinetic + potential;
    }
    std::cout << "Energy at step " << n << ": " << energy << "\n";
}
