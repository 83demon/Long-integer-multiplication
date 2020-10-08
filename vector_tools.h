//
// Created by vo1ku on 07.10.2020.
//

#ifndef LAB_2_VECTOR_TOOLS_H
#define LAB_2_VECTOR_TOOLS_H
#include <vector>


std::vector<int> slice_with_check(std::vector<int> const &v, int part);
std::vector<int> vector_slice(std::vector<int> const &v, int m, int n);
std::vector<int> copy_vector(std::vector<int> const &vec);
void vector_len_check(std::vector<int> &a, std::vector<int> &b);
bool equal_elems(std::vector<int> a);

#endif //LAB_2_VECTOR_TOOLS_H
