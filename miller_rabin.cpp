//
// Created by vo1ku on 19.10.2020.
//

#include "miller_rabin.h"


bool Miller_Rabin::prime(unsigned long long n, unsigned long long accuracy){
    if(n<4){
        return true;
    }
    std::vector<long long> nums = shifting_pow(n-1,2);
    long long r = nums[0], d = nums[1];
    WitnessLoop: for(unsigned long long i=0;i<accuracy;i++) {
        unsigned long long a = (rand() % (n - 4) + 2);
        long long x = binary_pow(a,d,n);
        if(x==1 || x==n-1){continue;}
        for(long long k=0;k<r-1;k++){
            x=(x*x)%n;
            if(x==n-1){
                goto WitnessLoop;
            }
        }
        return false;
    }
    return true;
}