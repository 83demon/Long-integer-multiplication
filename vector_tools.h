//
// Created by vo1ku on 07.10.2020.
//

#ifndef LAB_2_VECTOR_TOOLS_H
#define LAB_2_VECTOR_TOOLS_H
#include <vector>
#include <cmath>
#include <string>


std::vector<int> partial_split(std::vector<int> const &v, int part, int len_to_split);
std::vector<int> vector_slice(std::vector<int> const &v, int m, int n);
std::vector<int> copy_vector(std::vector<int> const &vec);
void vector_len_check(std::vector<int> &a, std::vector<int> &b, int len_to_split);
bool equal_elems(std::vector<int> a);
bool equal_elems(std::string a);

#endif //LAB_2_VECTOR_TOOLS_H
