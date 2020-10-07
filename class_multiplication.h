//
// Created by vo1ku on 02.10.2020.
//

#ifndef LAB_2_CLASS_MULTIPLICATION_H
#define LAB_2_CLASS_MULTIPLICATION_H
#include <vector>

class LongIntMult{
    int base = 10;
    std::vector<int> digits;
    std::vector<int> split(int a);
    std::vector<int> shift(std::vector<int> a, int pow, int len_of_base);
    int join(std::vector<int> res);
    std::vector<int> add(std::vector<int> a, std::vector<int> b);
    std::vector<int> subtract(std::vector<int> a, std::vector<int> b);
    int len_base(std::vector<int> a, std::vector<int> b);


public:
    LongIntMult (int number){split(number);};
    std::vector<int> karatsuba(std::vector<int> a, std::vector<int> b, int depth);
    //LongIntMult (std::string number){}
};

#endif //LAB_2_CLASS_MULTIPLICATION_H
