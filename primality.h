//
// Created by vo1ku on 19.10.2020.
//

#ifndef LAB_2_PRIMALITY_H
#define LAB_2_PRIMALITY_H
#include "long_int.h"
#include <climits>
#include <random>

unsigned long long binary_pow(unsigned long long a, unsigned long long n, unsigned long long m);
int kronecker_jacobi_symbol(long long a, long long n);
std::vector<long long> shifting_pow(unsigned long long a, int pow_base);


#endif //LAB_2_PRIMALITY_H
