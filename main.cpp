#include <iostream>
#include "multiply.h"
#include "primality.h"


int main() {
    LongIntMult::set_base(10000); //no more, than 10 000
    LongIntMult::set_mult(new Karatsuba());
    LongIntMult::set_prime(new Fermat());

    LongIntMult a,b,c;
    a = "149";
    b = 704;
    bool res =c.prime(101003767,2);
    std::cout<<res;
    //c = a*b;
    //std::cout<<c;
    //c.stress_test(300);





    return 0;
}
