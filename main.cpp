#include <iostream>
#include "multiply.h"
#include "primality.h"
#include "fermat.h"
#include "solovay_strassen.h"


int main() {
    LongIntMult::set_base(10000); //no more, than 10 000
    LongIntMult::set_mult(new Karatsuba());
    LongIntMult::set_prime(new Solovay_Strassen());

    LongIntMult a,b,c;
    a = "149";
    b = 704;
    bool res =c.prime(11112823,2);
    int k = kronecker_jacobi_symbol(43,683);
    unsigned long long n = binary_pow(43,341,683);
    std::cout<<res;
    //c = a*b;
    //std::cout<<c;
    //c.stress_test(300);





    return 0;
}
