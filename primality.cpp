//
// Created by vo1ku on 19.10.2020.
//

#include "primality.h"
#include <cmath>

unsigned long long binary_pow(unsigned long long a, unsigned long long n, unsigned  long long m){
    if (n == 0){
        return 1;}
    if (n % 2 == 1){
        return (a * binary_pow(a, n-1, m)) % m;}
    else{
        unsigned long long k = binary_pow(a, n/2, m);
        return (k*k)%m;}
}


int kronecker_jacobi_symbol(long long n, long long k){
    //n should be greater than 0
    n = n%k;
    long long t = 1;
    while(n!=0){
        while(n%2==0){
            n/=2;
            long long r = k%8;
            if(r==3 || r==5){
                t = -t;
            }
        }
        long long temp = n;
        n = k;
        k = temp;
        if(n%4==3 && k%4==3){
            t=-t;
        }
        n=n%k;
    }
    if(k==1){
        return t;
    }
    else{
        return 0;
    }
}


