#include <iostream>
#include <random>
#include <chrono>
#include <time.h>
#include <iomanip>
#include "matrix.hpp"


int main(){
    double first_det, sec_det, third_det;
    std::cin >> first_det;

    Matrix A = Matrix::getSpecificDeterminant(5, first_det);
    std::cout<< first_det <<std::fixed<< std::setprecision(17)<< A.calculateDeterminant();
    //Matrix<double> B = Matrix<double>::getSpecificDeterminant(50, first_det);
    //std::cout<< first_det <<std::fixed<< std::setprecision(17)<< A.calculateDeterminant();

}