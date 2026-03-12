#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

const int N_x = 500;                    //how many points there are on the 1D grid
const int N_steps = 500;                //amount of time steps in the simulation
const int steps_per_data_write = 50;    //amount of steps transpiring per each time the data is saved

const double domain_size = 10.0;        //size of the physical domain
const double dx = domain_size/N_x;      //distance between grid points on the physical domain (spatial step size)
const double dt = 0.9 * dx;               //time step 

const double m = 7.0;                   //masse de la particule

const double A = 1.0;                   //amplitude of wave packet
const double x_0 = domain_size/2.0;     //initial position of the wave packet, initialized to center of domain
const double sigma = 0.5;               //Gaussian width 
const double k = 3.0;                   //wave number

inline int idx(int i, int n) { return i * N_x + n; }

void set_initial_conditions(std::vector<double>& phi);
double laplace_phi(const std::vector<double>& phi, int i, int n);
void set_pi_half(std::vector<double>& phi, std::vector<double>& pi_half, const std::vector<double>& pi0, double dt);
void solution_time_step(std::vector<double>& phi, std::vector<double>& pi_half, int n);
void check_energy_convervation(const std::vector<double>& phi, const std::vector<double>& pi_half, int n);

void write_analytic_data(int step);
void set_gauss_conditions(std::vector<double>& phi);
void set_initial_conditions(std::vector<double>& phi);

void write_data(const std::vector<double>& phi, int step);
void check_energy_convervation(const std::vector<double>& phi, const std::vector<double>& pi_half, int n);

#endif