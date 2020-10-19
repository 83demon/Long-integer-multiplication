//
// Created by vo1ku on 19.10.2020.
//

#ifndef LAB_2_PRIMALITY_H
#define LAB_2_PRIMALITY_H
#include "long_int.h"
#include <random>

unsigned long long binary_pow(unsigned long long a, unsigned long long n, unsigned long long m);

class Fermat : public Prime{
public:
    bool prime(unsigned long long a, unsigned long long accuracy) override;
};

#endif //LAB_2_PRIMALITY_H
