//
// Created by vo1ku on 08.10.2020.
//
#include "multiply.h"



LongIntMult Karatsuba::multiply(std::vector<int> &a, std::vector<int> &b) {
    LongIntMult C;

    if(a.size()==1 && b.size()==1){
        int temp = a[0]*b[0];
        std::vector<int> res = C.normalize(temp);
        return LongIntMult(res);
    }

    vector_len_check(a,b,len_to_split);

    std::vector<int> x0 = partial_split(a,2,len_to_split);
    std::vector<int> y0 = partial_split(b,2,len_to_split);
    std::vector<int> x1 = partial_split(a,1,len_to_split);
    std::vector<int> y1 = partial_split(b,1,len_to_split);

    int len_of_base = x0.size(); //also works for y0.size()


    LongIntMult z2_obj = multiply(x1,y1);
    std::vector<int> z2 = z2_obj.digits;

    LongIntMult z0_obj = multiply(x0,y0);
    std::vector<int> z0 = z0_obj.digits;

    std::vector<int> x1_x0 = C.add(x1,x0);
    std::vector<int> y1_y0 = C.add(y1,y0);

    LongIntMult t1_obj = multiply(x1_x0,y1_y0);
    std::vector<int> t1 = t1_obj.digits;

    std::vector<int> t2 = C.subtract(t1,z2);
    std::vector<int> z1 = C.subtract(t2,z0);
    std::vector<int>z2_b2m = C.shift(z2,2, len_of_base);
    std::vector<int> z1_bm = C.shift(z1,1, len_of_base);
    std::vector<int> z21 = C.add(z2_b2m,z1_bm);
    std::vector<int> res = C.add(z21, z0);
    return LongIntMult(res);
}
