//
// Created by vo1ku on 19.10.2020.
//

#ifndef LAB_2_SOLOVAY_STRASSEN_H
#define LAB_2_SOLOVAY_STRASSEN_H
#include "long_int.h"
#include "primality.h"
#include <random>

class Solovay_Strassen : public Prime{
public:
    bool prime(unsigned long long a, unsigned long long accuracy) override;
};


#endif //LAB_2_SOLOVAY_STRASSEN_H
