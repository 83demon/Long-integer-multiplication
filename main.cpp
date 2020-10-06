#include <iostream>
#include "class_multiplication.h"
#include <vector>
#include <algorithm>


int main() {
    std::vector<int> a12{2,1,1,2};
    std::vector<int> b1{1,0,7};

    LongIntMult a =23;
    std::vector<int> c = a.karatsuba(a12,b1,0);
    for(int i=0;i<c.size();i++){
        std::cout<<c[i];
    }
    return 0;
}
