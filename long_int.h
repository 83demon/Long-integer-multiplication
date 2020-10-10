//
// Created by vo1ku on 02.10.2020.
//

#ifndef LAB_2_LONG_INT_H
#define LAB_2_LONG_INT_H
//#include "multiply.h"
#include <vector>
#include <string>

class LongIntMult{

    int base = 10;
    std::vector<int> digits;
    static std::string mult_method;
    std::vector<int> normalize(int a) const;
    static std::vector<int> shift(std::vector<int> a, int pow, int len_of_base);
    std::vector<int> multiplication(std::vector<int> a, std::vector<int> b);
    std::vector<int> add(std::vector<int> a, std::vector<int> b) const;
    std::vector<int> subtract(std::vector<int> a, std::vector<int> b) const;
    static int len_base(std::vector<int> a, std::vector<int> b);
public:
    static void set_mult(const char *method);
    friend std::ostream& operator<<(std::ostream& os, const LongIntMult &res);
    void operator= (const char *num);
    void operator= (int num);
    LongIntMult operator* (LongIntMult &other);
    LongIntMult (std::vector<int> &res){digits=res;};
    LongIntMult(auto num){operator=(num);};
    LongIntMult(){};
    void stress_test(int len_vector);
    std::vector<int> karatsuba(std::vector<int> a, std::vector<int> b);
};

bool equal_elems(std::vector<int> a);


#endif //LAB_2_LONG_INT_H
