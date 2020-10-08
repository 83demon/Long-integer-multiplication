//
// Created by vo1ku on 02.10.2020.
//

#include "long_int.h"
#include "vector_tools.h"
#include <vector>
#include <iostream>
#include <ostream>
#include <cstring>
#include <algorithm>

std::string LongIntMult::mult_method; // definition of static method


void LongIntMult::set_mult(const char *method) {
    mult_method = method;
}


std::ostream& operator<<(std::ostream& os, const LongIntMult &res){
    for(auto i: res.digits) {
        os << i;
    }
    return os;
}


LongIntMult LongIntMult::operator*(LongIntMult &other) {
    //std::vector<int> res = multiplication->multiply(this->digits,other.digits);
    //return LongIntMult(res);
    if(mult_method=="Karatsuba"){
        std::vector<int> res = karatsuba(this->digits,other.digits);
        return LongIntMult(res);
    }
}


void LongIntMult::operator=(int num){
    std::string str_repr = std::to_string(num);
    std::string str_base = std::to_string(base);
    int base_len = str_base.size()-1; // only works for 10**x base
    auto input_len = str_repr.size();
    std::string temp;
    for(auto i=0;i<input_len;i+=base_len){
        temp = std::string(str_repr,i,base_len);
        digits.push_back(std::stoi(temp));
    }
}



void LongIntMult::operator=(const char *num){
    std::string str_base = std::to_string(base);
    int base_len = str_base.size()-1; // only works for 10**x base
    auto input_len = strlen(num);
    std::string temp;
    for(auto i=0;i<input_len;i+=base_len){
        temp = std::string(num,i,base_len);
        digits.push_back(std::stoi(temp));
    }
}

int LongIntMult::len_base(std::vector<int> a, std::vector<int> b){
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


std::vector<int> LongIntMult::add(std::vector<int> a, std::vector<int> b) const{
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(),b.end());
    std::vector<int> c = (a.size()>=b.size()) ? copy_vector(a) : copy_vector(b);
    std::vector<int> sum(1, 0);
    int index = 0;
    int stop1 = std::min(a.size(), b.size());
    int stop2 = std::max(a.size(),b.size());
    int temp_module,temp_int, temp;
    while(index!=stop1){
        temp = a[index]+b[index];
        temp_module = temp%base;
        temp_int = temp/base;
        sum[0]+=temp_module;
        if(sum[0]==base){
            temp_int = 1;
            sum[0]=0;
        }
        sum.insert(sum.begin(), temp_int);
        index+=1;
    }

    while (index!=stop2){
        temp = sum[0]+c[index];
        temp_module = temp%base;
        temp_int = temp/base;
        sum[0]=temp_module;
        sum.insert(sum.begin(), temp_int);
        index+=1;
    }
    if(sum[0]==0){sum.erase(sum.begin());}

    return sum;
}


std::vector<int> LongIntMult::subtract(std::vector<int> a, std::vector<int> b) const {
    // works only for a >= b
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(),b.end());
    int temp_a,temp_b;
    std::vector<int> difference(1, 0);
    int index = 0;
    int stop1 = std::min(a.size(), b.size());
    int stop2 = std::max(a.size(),b.size());
    int temp;
    while(index!=stop1){
        temp_a=a[index];
        if(temp_a<0){
            a[index]=0;
            a[index+1]-=1;
            temp_a = base-1;
        }
        temp_b=b[index];
        temp = temp_a - temp_b;
        if(temp<0){
            temp += base;
            a[index+1]-=1;
        }
        difference[0]=temp;
        difference.insert(difference.begin(), 0);
        index+=1;
    }
    while(index!=stop2){
        if(a[index]==-1){
            a[index]=base-1;
            a[index+1]-=1;
        }
        difference[0]=a[index];
        difference.insert(difference.begin(),0);
        index+=1;
    }

    bool equals = equal_elems(difference);

    if(difference[0]==0 && equals){
        difference = {0};
    }
    else {
        while (difference[0] == 0 || difference[0] == -1) { difference.erase(difference.begin()); }
    }


    return difference;
}



std::vector<int> LongIntMult::normalize(int a) const {
    std::vector<int> res;
    if(a/base!=0){
        res.push_back(a/base);
    }
    res.push_back(a%base);
    return res;
}


std::vector<int> LongIntMult::shift(std::vector<int> a, int pow, int len_of_base){
    if(a[0]!=0) {
        for (int i = 0; i < pow*len_of_base; i++) {
            a.push_back(0);
        }
    }
    return a;
}


std::vector<int> LongIntMult::karatsuba(std::vector<int> a, std::vector<int> b) {
    vector_len_check(a,b);
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


    std::vector<int> z2 = karatsuba(x1,y1);
    std::vector<int> z0 = karatsuba(x0,y0);
    std::vector<int> x1_x0 = add(x1,x0);
    std::vector<int> y1_y0 = add(y1,y0);
    std::vector<int> t1 = karatsuba(x1_x0,y1_y0);
    std::vector<int> t2 = subtract(t1,z2);
    std::vector<int> z1 = subtract(t2,z0);
    std::vector<int>z2_b2m = shift(z2,2, len_of_base);
    std::vector<int> z1_bm = shift(z1,1, len_of_base);
    std::vector<int> z21 = add(z2_b2m,z1_bm);
    std::vector<int> res = add(z21, z0);
    return res;
}