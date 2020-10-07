#include <iostream>
#include "class_multiplication.h"
#include <vector>
#include <algorithm>
#include "vector_tools.h"

int len_base(std::vector<int> a, std::vector<int> b){
    int res;
    bool equals_a = equal_elems(a), equals_b = equal_elems(b);
    if(equals_a && equals_b && a[0]==b[0] &&a[0]==0){
        res = std::min(a.size(),b.size());
    }
    else if(equals_a && a[0]==0){
        while(b[0]==0){
            b.erase(b.begin());
        }
        res = b.size();
    }
    else if(equals_b && b[0]==0){
        while(a[0]==0){
            a.erase(a.begin());
        }
        res = a.size();
    }

    else{
        res = std::min(a.size(),b.size());
    }
    return res;
}



int main() {
    std::vector<int> a12{6,7,4,5,5,5,1,3,9,9,9,9,9};
    std::vector<int> b1{1,2,3,4,5,7,9,3,8,2,1,2};
    std::vector<int> d{0};
    std::vector<int> c{0};

    /*std::vector<int> res = add(d,c);
    for(int i =0;i<res.size();i++){
        std::cout<<res[i]<<" ";
    }*/

    LongIntMult a =23;
    std::vector<int> c1 = a.karatsuba(a12,b1,0);
    for(int i=0;i<c1.size();i++){
        std::cout<<c1[i];
    }


    return 0;
}
