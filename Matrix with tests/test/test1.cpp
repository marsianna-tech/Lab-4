#include<iostream>
#include<matrix.hpp>
int main(){
    double first_det, sec_det, third_det;
    std::cin >> first_det >> sec_det >> third_det;

    Matrix A = Matrix::getSpecificDeterminant(5, first_det);
    Matrix B = Matrix::getSpecificDeterminant(10, sec_det);
    Matrix C = Matrix::getSpecificDeterminant(15, third_det);
    std::cout << "1: " << A.calculateDeterminant() << std::endl;
    std::cout << "2: " << B.calculateDeterminant() << std::endl;
    std::cout << "3: " << C.calculateDeterminant() << std::endl;
}