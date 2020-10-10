#include <iostream>
#include "long_int.h"
#include <vector>
#include <algorithm>
#include "vector_tools.h"

int len_base(std::vector<int> a, std::vector<int> b){
    //seeks for the min len of base
    int res;
    bool equals_a = equal_elems(a), equals_b = equal_elems(b);
    if(equals_a && equals_b && a[0]==b[0] &&a[0]==0){
        res = std::min(a.size(),b.size());
    }
    else if(equals_a && a[0]==0){
        res = b.size();
    }
    else if(equals_b && b[0]==0){
        res = a.size();
    }
    else{
        res = std::min(a.size(),b.size());
    }
    return res;
}

int main() {
    LongIntMult::set_base(10000); //no more, than 10 000
    LongIntMult::set_mult("Karatsuba");


    LongIntMult a,b,c;
    a = "510";
    b = 420;


    c.stress_test(3000);


    //c = a*b;
    //std::cout<<c;


    return 0;
}
