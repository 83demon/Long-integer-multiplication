//
// Created by vo1ku on 02.10.2020.
//

#include "class_multiplication.h"
#include <vector>
#include <iostream>
#include <algorithm>


template<typename T>
std::vector<T> vector_slice(std::vector<T> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n+1;

    std::vector<T> vec(first, last);
    return vec;
}


template<typename T>
std::vector<T> copy_vector(std::vector<T> const &vec)
{
    std::vector<T> v(vec.size());
    std::copy(vec.begin(), vec.end(), v.begin());
    return v;
}

std::vector<int> LongIntMult::add(std::vector<int> a, std::vector<int> b){
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


std::vector<int> LongIntMult::subtract(std::vector<int> a, std::vector<int> b) {
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
    while(difference[0]==0 || difference[0]==-1){difference.erase(difference.begin());}

    return difference;
}



std::vector<int> LongIntMult::split(int a) {
    //needs to be reimplemented
    std::vector<int> res;
    if(a/base!=0){
        res.push_back(a/base);
    }
    res.push_back(a%base);
    return res;
}


int LongIntMult::join(std::vector<int> num) {
    //needs to be implemented;
    return 0;
}


std::vector<int> LongIntMult::shift(std::vector<int> a, int m){
    for(int i=0;i<m;i++){
        a.push_back(0);
    }
    return a;
}


std::vector<int> LongIntMult::karatsuba(std::vector<int> a, std::vector<int> b,int depth) {
    std::cout<<depth<<std::endl;
    if(a.size()==1 && b.size()==1){
        int temp = a[0]*b[0];
        std::vector<int> res = split(temp);
        return res;
    }
    std::vector<int> x0{a.back()};
    std::vector<int> y0{b.back()};
    std::vector<int> x1 = vector_slice(a,0,a.size()-2);
    std::vector<int> y1 = vector_slice(b,0,b.size()-2);

    std::vector<int> z2 = karatsuba(x1,y1,depth+1);
    std::vector<int> z0 = karatsuba(x0,y0,depth+1);
    std::vector<int> x1_x0 = add(x1,x0);
    std::vector<int> y1_y0 = add(y1,y0);
    std::vector<int> t1 = karatsuba(x1_x0,y1_y0,depth+1);
    std::vector<int> t2 = subtract(t1,z2);
    std::vector<int> z1 = subtract(t2,z0);
    std::vector<int>z2_b2m = shift(z2,2);
    std::vector<int> z1_bm = shift(z1,1);
    std::vector<int> z21 = add(z2_b2m,z1_bm);
    std::vector<int> res = add(z21, z0);
    return res;
}