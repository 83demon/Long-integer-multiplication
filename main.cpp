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

    LongIntMult a,b,c;
    a = "3564646864685555547747474747555555555555";
    b = "46454645661111111111147474747474747411111";
    c = a*b;


    std::cout<<c<<"\n";
    bool res =c.prime(383500561,2);
    std::cout<<res;
    // prints 1 if number is prime 0 otherwise


    return 0;
}
