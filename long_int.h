//
// Created by vo1ku on 02.10.2020.
//

#ifndef LAB_2_LONG_INT_H
#define LAB_2_LONG_INT_H
#include "vector_tools.h"
#include <vector>
#include <random>
#include <iostream>
#include <ostream>
#include <cstring>
#include <algorithm>
#include <chrono>


class LongIntMult;


class Multiplication{
public:
    virtual LongIntMult multiply(std::vector<int> &a, std::vector<int> &b);
};


class Prime{
public:
    virtual bool prime(unsigned long long a, unsigned long long accuracy);
};


class LongIntMult{
    static int base;
    static Multiplication *multiplication;
    static Prime *primality;
    std::vector<int> digits;
    std::vector<int> naive_multiplication(std::vector<int> a, std::vector<int> b);
    long long join(std::vector<int> a);
    std::vector<int> normalize(int a) const;
    static std::vector<int> shift(std::vector<int> a, int pow, int len_of_base);
    std::vector<int> add(std::vector<int> a, std::vector<int> b) const;
    std::vector<int> subtract(std::vector<int> a, std::vector<int> b) const;
public:

    static void set_base(int base);
    static void set_prime(Prime *prime_);
    static void set_mult(Multiplication *multiplication);
    friend std::ostream& operator<<(std::ostream& os, const LongIntMult &res);
    void operator= (const char *num);
    void operator= (int num);
    LongIntMult operator+ (LongIntMult &other);
    LongIntMult operator- (LongIntMult &other);
    friend bool operator==(const LongIntMult &a, const LongIntMult& b);
    friend bool operator!=(const LongIntMult &a, const LongIntMult& b);
    friend bool operator<(const LongIntMult &a, const LongIntMult& b);
    friend bool operator>(const LongIntMult &a, const LongIntMult& b);
    friend bool operator<=(const LongIntMult &a, const LongIntMult& b);
    friend bool operator>=(const LongIntMult &a, const LongIntMult& b);
    bool prime(unsigned long long a, unsigned long long accuracy);
    LongIntMult operator* (LongIntMult &other);
    LongIntMult (std::vector<int> &res){digits=res;};
    LongIntMult(auto num){operator=(num);};
    LongIntMult(){};
    void stress_test(int len_vector);
    friend class Karatsuba;
    friend class Toom_Cook;
};


#endif //LAB_2_LONG_INT_H
