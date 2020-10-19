//
// Created by vo1ku on 19.10.2020.
//

#include "toom_cook.h"

LongIntMult Toom_Cook::multiply(std::vector<int> &a, std::vector<int> &b){
    LongIntMult C;
    vector_len_check(a,b,parts_to_split-1);
    std::vector<int> res;
    if(a.size()==3 && b.size()==3){
        long long A = C.join(a), B=C.join(b);
        res = LongIntMult(A*B).digits;
        return res;
    }

    std:: vector<int> m2,m1,m0,n2,n1,n0, p_1pos,p_1neg,p_2,p_inf, q_1pos,q_1neg,q_2,q_inf;
    std::vector<int> r_0,r_1pos,r_1neg,r_2,r_inf, r0,r1,r2,r3,r4;
    std::vector<int> m2_four_times = {0}, n2_four_times = {0}, r4_16_times ={0}, r3_8_times={0},r2_4_times={0};

    m2 = partial_split(a,1,parts_to_split);
    m1 = partial_split(a,2,parts_to_split);
    m0 = partial_split(a,3,parts_to_split);
    n2 = partial_split(b,1,parts_to_split);
    n1 = partial_split(b,2,parts_to_split);
    n0 = partial_split(b,3,parts_to_split);

    int len_of_base = n0.size()-1;//cause of sign bit;

    r_0 = multiply(n0,m0).digits;

    p_1pos = C.add(C.add(m2,m1),m0);
    q_1pos = C.add(C.add(n2,n1),n0);
    r_1pos = multiply(p_1pos,q_1pos).digits;

    p_1neg =C.subtract(C.add(m2,m0),m1);
    q_1neg =C.subtract(C.add(n2,n0),n1);
    r_1neg =multiply(p_1neg,q_1neg).digits;

    for(int i=0;i<3;i++){
        m2_four_times = C.add(m2_four_times,m2);
        n2_four_times = C.add(n2_four_times,n2);
    }
    p_2 = C.add(C.add(C.add(m1,m1),m0),m2_four_times);
    q_2 = C.add(C.add(C.add(n1,n1),n0),n2_four_times);
    r_2 = multiply(q_2,p_2).digits;

    p_inf = m2;
    q_inf = n2;
    r_inf = multiply(m2,n2).digits;


    for(int i=0;i<15;i++){
        r4_16_times = C.add(r4_16_times,r_inf);
    }
    for(int i=0;i<7;i++){
        r3_8_times = C.add(r3_8_times,r_2);
    }
    for(int i=0;i<3;i++){
        r2_4_times = C.add(r2_4_times,r_1neg);
    }

    r0 = r_0;
    r1 = C.add(C.add(C.add(C.add(r_inf,r_2),r_1neg),r_1pos),r_0);
    r2 = C.subtract(C.subtract(C.add(C.add(r_inf,r_1neg),r_0),r_2),r_1pos);
    r3 = C.add(C.add(C.add(C.add(C.add(r_1pos,r_1pos),r4_16_times),r3_8_times),r2_4_times),r_0);
    r4 = r_inf;

    r4 = C.shift(r4,4,len_of_base);
    r3 = C.shift(r3,3,len_of_base);
    r2 = C.shift(r2,2, len_of_base);
    r1 = C.shift(r1,1,len_of_base);

    res = C.add(C.add(C.add(C.add(r4,r3),r2),r1),r0);
    return LongIntMult(res);
}