//
// Created by vo1ku on 08.10.2020.
//

#ifndef LAB_2_MULTIPLY_H
#define LAB_2_MULTIPLY_H
#include <vector>
#include "long_int.h"


class Karatsuba : public Multiplication{
public:
    LongIntMult multiply(std::vector<int> &a, std::vector<int> &b) override;
};

#endif //LAB_2_MULTIPLY_H
