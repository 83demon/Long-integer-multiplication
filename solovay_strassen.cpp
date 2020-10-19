//
// Created by vo1ku on 19.10.2020.
//

#include "solovay_strassen.h"


bool Solovay_Strassen::prime(unsigned long long n, unsigned long long accuracy){
    if(n<4){
        return true;
    }
    for(unsigned long long i=0;i<accuracy;i++) {
        unsigned long long a = (rand() % (n - 3) + 2);
        if(std::__gcd(a,n)>1){
            return false;
        }
        unsigned long long b = binary_pow(a,(n-1)/2,n);
        if(b>1){b-=n;}
        if(b!=kronecker_jacobi_symbol(a,n)){
            return false;
        }
    }
    return true;
}