#include <iostream>
#include "long_int.h"
#include <vector>
#include <algorithm>
#include "vector_tools.h"


int main() {
    LongIntMult a,b,c;
    a = "23456";
    b = 5556841;

    LongIntMult::set_mult("Karatsuba");
    c = a*b;
    std::cout<<c;

    return 0;
}
