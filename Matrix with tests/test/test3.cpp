#include<iostream>
#include<matrix.hpp>
int main(){
    double n, m;
    std::cin >> n >> m;
    Matrix A(5, 1, n);
    Matrix B(1, 5, m);
    Matrix D(1, 1, 1);
    D = A * B;
    D.print();
}