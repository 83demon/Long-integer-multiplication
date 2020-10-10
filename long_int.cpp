//
// Created by vo1ku on 02.10.2020.
//

#include "long_int.h"
#include "vector_tools.h"
#include <vector>
#include <random>
#include <iostream>
#include <ostream>
#include <cstring>
#include <algorithm>
#include <chrono>

int LongIntMult::base;
Multiplication *LongIntMult::multiplication = nullptr; // definition of static method

LongIntMult Multiplication::multiply(std::vector<int> &a, std::vector<int> &b) {}


void LongIntMult::stress_test(int len_vector) {
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> naive_res;
    LongIntMult fast_res_obj;
    std::vector<int> fast_res;
    while(true) {
        for (int i = 0; i < len_vector; i++) {
            a.push_back(rand() % base);
            b.push_back(rand() % base);
        }


        auto start1 = std::chrono::high_resolution_clock::now();
        naive_res = naive_multiplication(a, b);
        auto end1 = std::chrono::high_resolution_clock::now();
        double difference1 = std::chrono::duration<double, std::milli>(end1-start1).count();

        auto start2 = std::chrono::high_resolution_clock::now();
        fast_res_obj = multiplication->multiply(a, b);
        auto end2 = std::chrono::high_resolution_clock::now();
        double difference2 = std::chrono::duration<double, std::milli>(end2-start2).count();
        fast_res = fast_res_obj.digits;


        if(naive_res==fast_res){
            std::cout<<"OK\t"<<difference1<<"\t"<<difference2<<std::endl;
            a.clear();
            b.clear();
        }
        else{
            for(auto i:a){
                std::cout<<i;
            }
            std::cout<<" a"<<"\n";

            for(auto i:b){
                std::cout<<i;
            }
            std::cout<<" b"<<"\n";

            for(auto i:naive_res){
                std::cout<<i;
            }
            std::cout<<" naive_res"<<"\n";

            for(auto i:fast_res){
                std::cout<<i;
            }
            std::cout<<" fast_res"<<"\n";

            break;
        }

    }
}


void LongIntMult::set_base(int num) {
    base = num;
}


void LongIntMult::set_mult(Multiplication *mult) {
    multiplication = mult;
}


std::ostream& operator<<(std::ostream& os, const LongIntMult &res){
    for(auto i: res.digits) {
        os << i;
    }
    return os;
}


LongIntMult LongIntMult::operator*(LongIntMult &other) {
    LongIntMult res = multiplication->multiply(this->digits,other.digits);
    return res;

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


std::vector<int> LongIntMult::naive_multiplication(std::vector<int> a, std::vector<int> b) {
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(),b.end());
    std::vector<int> res(1,0);
    std::vector<int> temp_vec(1,0);
    int temp, temp_int, temp_module;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            temp = a[i]*b[j];
            temp_int = temp/base;
            temp_module = temp%base;
            temp_vec[0]+=temp_module;
            if(temp_vec[0]/base>0){
                temp_vec[0]%=base;
                temp_int+=1;
            }
            temp_vec.insert(temp_vec.begin(),temp_int);
        }
        for(int k=0;k<i;k++){
            temp_vec.push_back(0);
        }
        res = add(res,temp_vec);
        temp_vec = {0};
    }

    bool equals = equal_elems(res);

    if(res[0]==0 && equals){res = {0};}
    else{while(res[0]==0){res.erase(res.begin());}}

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
