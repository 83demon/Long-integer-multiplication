#include <iostream>
#include "karatsuba.h"
#include "primality.h"
#include "fermat.h"
#include "miller_rabin.h"
#include "solovay_strassen.h"


int main() {
    LongIntMult::set_base(10); //no more, than 10 000
    LongIntMult::set_mult(new Karatsuba());
    LongIntMult::set_prime(new Miller_Rabin());

    LongIntMult a,b,c,d,e;
    a = "1684";
    b = "46";
    c = a*b;
    d=d.naive_multiplication(a.digits,b.digits);
    e=d-c;
    std::cout<<e;
    //bool res =c.prime(383500561,2);
    //std::cout<<res;
    //c.stress_test(300);


    return 0;
}
