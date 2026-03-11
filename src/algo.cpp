#include "algo.h"

double laplace_phi(const std::vector<double>& phi, int i, int n) {
    int ip = (i + 1) % N_x;
    int im = (i - 1 + N_x) % N_x;
    return (phi[idx(ip, n)] - 2.0 * phi[idx(i, n)] + phi[idx(im, n)]) / (dx * dx);
}

void set_pi_half(std::vector<double>& phi, std::vector<double>& pi_half, const std::vector<double>& pi0, double dt)
{
    for (int i = 0; i < N_x; ++i) {
        double lap0 = laplace_phi(phi, i, 0);
        pi_half[idx(i, 0)] = pi0[i] + 0.5 * dt * (lap0 - m*m * phi[idx(i, 0)]);
    }
}

void solution_step(std::vector<double>& phi, std::vector<double>& pi_half, int n)
{
    for (int i = 0; i < N_x; ++i) {
        double lap = laplace_phi(phi, i, n);
        double pi_prev_half = (n == 0) ? pi_half[idx(i, 0)] : pi_half[idx(i, n - 1)];
        double pi_new_half  = pi_prev_half + dt * (lap - m*m * phi[idx(i, n)]);
        pi_half[idx(i, n)] = pi_new_half;
        phi[idx(i, n + 1)] = phi[idx(i, n)] + dt * pi_new_half;
    }
}

int main() {
    std::vector<double> phi(N_x * (N_steps + 1), 0.0);
    std::vector<double> pi_half(N_x * N_steps, 0.0);
    
    set_initial_conditions(phi);
    set_pi_half(phi, pi_half, std::vector<double>(N_x, 0.0), dt);

    for (int n = 0; n < N_steps; ++n) {
        solution_step(phi, pi_half, n);
        if(n % steps_per_data_write == 0 || n == N_steps - 1)
        {
            //check_energy_convervation(phi, pi_half, n);
            write_data(phi, n);
            //write_analytic_data(n);
            std::cout << "wrote data for step " << n << "\n";
        }
    }
    return 0;
}
