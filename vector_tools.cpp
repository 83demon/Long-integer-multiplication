//
// Created by vo1ku on 07.10.2020.
//

#include "vector_tools.h"
#include <vector>
#include <cmath>

bool equal_elems(std::vector<int> a){
    bool res = true;
    int fist_occur = a[0];
    for(int i=0;i<a.size();i++){
        if(fist_occur!=a[i]){
            res = false;
        }
    }
    return res;
}

void vector_len_check(std::vector<int> &a, std::vector<int> &b){
    int len_diff = abs(a.size()-b.size());
    if(a.size()>b.size()){
        for(int i=0;i<len_diff;i++){
            b.insert(b.begin(),0);
        }
    }
    else if(a.size()<b.size()){
        for(int i=0;i<len_diff;i++){
            a.insert(a.begin(),0);
        }
    }
}

std::vector<int> slice_with_check(std::vector<int> const &v, int part){
    std::vector<int> res;

    if(v.size()%2==0){
        if(part==1){
            res = vector_slice(v,0,v.size()/2);
        }
        else if(part==2){
            res =  vector_slice(v,v.size()/2, v.size());
        }
    }
    else{
        if(part==1){
            res =  vector_slice(v,0,v.size()/2+1);
        }
        else if(part==2){
            res = vector_slice(v,v.size()/2+1, v.size());
        }
    }
    return res;
}

std::vector<int> vector_slice(std::vector<int> const &v, int m, int n){
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    std::vector<int> vec(first, last);
    return vec;
}


std::vector<int> copy_vector(std::vector<int> const &vec){
    std::vector<int> v(vec.size());
    std::copy(vec.begin(), vec.end(), v.begin());
    return v;
}