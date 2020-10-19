//
// Created by vo1ku on 19.10.2020.
//

#ifndef LAB_2_TOOM_COOK_H
#define LAB_2_TOOM_COOK_H
#include "long_int.h"
#include "vector_tools.h"

class Toom_Cook : public Multiplication{
    int parts_to_split = 3;
public:
    LongIntMult multiply(std::vector<int> &a, std::vector<int> &b) override;
};
#endif //LAB_2_TOOM_COOK_H
