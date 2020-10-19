//
// Created by vo1ku on 19.10.2020.
//

#include "primality.h"

unsigned long long binary_pow(unsigned long long a, unsigned long long n, unsigned  long long m){
    if (n == 0){
        return 1;}
    if (n % 2 == 1){
        return (a * binary_pow(a, n-1, m)) % m;}
    else{
        unsigned long long k = binary_pow(a, n/2, m);
        return (k*k)%m;}
}


bool Fermat::prime(unsigned long long n, unsigned long long accuracy) {
    if(n<3){
        return true;
    }
    for(unsigned long long i=0;i<accuracy;i++) {
        unsigned long long a = (rand() % (n - 2) + 2);
        if(binary_pow(a,n-1,n)!=1){
            return false;
        }
    }
    return true;
}