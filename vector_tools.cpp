//
// Created by vo1ku on 07.10.2020.
//

#include "vector_tools.h"


bool equal_elems(std::vector<int> a){
    bool res = true;
    int fist_occur = a[0];
    for(int i : a){
        if(fist_occur!=i){
            res = false;
        }
    }
    return res;
}


bool equal_elems(std::string a){
    bool res = true;
    int fist_occur = a[0];
    for(int i : a){
        if(fist_occur!=i){
            res = false;
        }
    }
    return res;
}


void vector_len_check(std::vector<int> &a, std::vector<int> &b, int len_to_split){
    if(a.size()==b.size() && a.size()%len_to_split==0 && b.size()%len_to_split==0){return;}
    int max_len = std::max(a.size(),b.size());
    int j=-0;
    do{
        j+=1;
    }while (max_len>j*len_to_split);
    int new_len = j*len_to_split;

    for(int i=0;a.size()<new_len;i++){
        a.insert(a.begin(),0);
    }
    for(int i=0;b.size()<new_len;i++){
        b.insert(b.begin(),0);
    }
}


std::vector<int> partial_split(std::vector<int> const &v, int part, int m){
    // m==len to splits
    std::vector<int> res, temp_index;
    int i=0;
    while(temp_index.size()!=m){
        temp_index.push_back(i);
        i+=(v.size())/m;
    }
    int res_start = temp_index[part-1], res_stop = res_start+(v.size())/m;
    res = vector_slice(v,res_start,res_stop);
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