//
// Created by vo1ku on 19.10.2020.
//

#include "fermat.h"

bool Fermat::prime(unsigned long long n, unsigned long long accuracy) {
    if(n<4){
        return true;
    }
    for(unsigned long long i=0;i<accuracy;i++) {
        unsigned long long a = (rand() % (n - 4) + 2);
        if(binary_pow(a,n-1,n)!=1){
            return false;
        }
    }
    return true;
}