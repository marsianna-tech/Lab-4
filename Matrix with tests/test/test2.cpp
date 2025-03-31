#include<iostream>
#include<matrix.hpp>
int main(){
    double det;
    int n;
    std::cin >> n >> det;
    Matrix A = Matrix::getSpecificDeterminant(n, det);
    A.print();
    A.transpose();
    A.print();
}