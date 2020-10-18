#include <iostream>
#include "multiply.h"



int main() {
    LongIntMult::set_base(10000); //no more, than 10 000
    LongIntMult::set_mult(new Karatsuba());


    LongIntMult a,b,c;
    a = "149";
    b = 704;
    //c = a*b;
    //std::cout<<c;
    c.stress_test(300);





    return 0;
}
