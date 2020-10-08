//
// Created by vo1ku on 08.10.2020.
//

#ifndef LAB_2_MULTIPLY_H
#define LAB_2_MULTIPLY_H
#include <vector>

class Multiply{
public:
    virtual std::vector<int> multiply(std::vector<int> &a, std::vector<int> &b);
};

class Karatsuba : public Multiply{
public:
    std::vector<int> multiply(std::vector<int> &a, std::vector<int> &b);
};

#endif //LAB_2_MULTIPLY_H
