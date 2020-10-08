//
// Created by vo1ku on 08.10.2020.
//

#include "multiply.h"

std::vector<int> Karatsuba::multiply(std::vector<int> &a, std::vector<int> &b) {
    /*vector_len_check(a,b);
    //std::cout<<depth<<std::endl;
    if(a.size()==1 && b.size()==1){
        int temp = a[0]*b[0];
        std::vector<int> res = normalize(temp);
        return res;
    }

    std::vector<int> x0 = slice_with_check(a,2);
    std::vector<int> y0 = slice_with_check(b,2);
    std::vector<int> x1 = slice_with_check(a,1);
    std::vector<int> y1 = slice_with_check(b,1);

    int len_of_base = std::min(len_base(x1,x0),len_base(y1,y0));

    vector_len_check(x1,x0);
    vector_len_check(y1,y0);


    std::vector<int> z2 = karatsuba(x1,y1,depth+1);
    std::vector<int> z0 = karatsuba(x0,y0,depth+1);
    std::vector<int> x1_x0 = add(x1,x0);
    std::vector<int> y1_y0 = add(y1,y0);
    std::vector<int> t1 = karatsuba(x1_x0,y1_y0,depth+1);
    std::vector<int> t2 = subtract(t1,z2);
    std::vector<int> z1 = subtract(t2,z0);
    std::vector<int>z2_b2m = shift(z2,2, len_of_base);
    std::vector<int> z1_bm = shift(z1,1, len_of_base);
    std::vector<int> z21 = add(z2_b2m,z1_bm);
    std::vector<int> res = add(z21, z0);
    return res;*/
    return std::vector<int> {-1};
}
