#include <iostream>
#include "multiply.h"




int main() {
    LongIntMult::set_base(10); //no more, than 10 000
    LongIntMult::set_mult(new Karatsuba);


    LongIntMult a,b,c;
    a = "864684";
    b = 448949815;


    c.stress_test(20);


    //c = a*b;
    //std::cout<<c;


    return 0;
}
