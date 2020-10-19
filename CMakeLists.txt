cmake_minimum_required(VERSION 3.17)
project(lab_2)

set(CMAKE_CXX_STANDARD 20)


add_executable(lab_2 main.cpp long_int.cpp long_int.h vector_tools.cpp vector_tools.h karatsuba.cpp karatsuba.h primality.cpp primality.h solovay_strassen.cpp solovay_strassen.h fermat.cpp fermat.h miller_rabin.cpp miller_rabin.h toom_cook.cpp toom_cook.h)