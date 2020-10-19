//
// Created by vo1ku on 19.10.2020.
//

#include "primality.h"
#include <cmath>

unsigned long long binary_pow(unsigned long long a, unsigned long long n, unsigned  long long m){
    if(m==1){return 0;}
    if((m-1)>ULLONG_MAX/(m-1)){std::cout<<"overflow"<<std::endl;}
    unsigned long long res=1;
    a=a%m;
    while(n>0){
        if(n%2==1){
            res=(res*a)%m;
        }
        n=n>>1;
        a=(a*a)%m;
    }
    return res;
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


std::vector<long long> shifting_pow(unsigned long long a,int base){
    std::vector<long long> res;
    long long r=0,d;
    while(a/(int(pow(base,r)))%2==0){
        r+=1;
    }
    d = a/(int(pow(base,r)));
    res.push_back(r);
    res.push_back(d);
    return res;
}