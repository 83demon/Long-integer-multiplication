//
// Created by vo1ku on 08.10.2020.
//

#ifndef LAB_2_KARATSUBA_H
#define LAB_2_KARATSUBA_H
#include "long_int.h"


class Karatsuba : public Multiplication{
    int len_to_split = 2;
public:
    LongIntMult multiply(std::vector<int> &a, std::vector<int> &b) override;
};

#endif //LAB_2_KARATSUBA_H
