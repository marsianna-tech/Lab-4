#include<iostream>
#include <random>
#include <chrono>
#include <time.h>
#include"subvector.hpp"
#pragma once
class Matrix{
    subvector<double> data;
    unsigned cols, rows;

    struct Row{
    double *begin;
    double *end;

    double& operator[](size_t index);
    const double operator[](size_t index) const;
    static void swap(Row A, Row B);
};

public:
    Matrix(unsigned rows, unsigned cols, double value = 0);
    static Matrix Identity(unsigned rows, unsigned cols);
    static Matrix getSpecificDeterminant(unsigned n, double determinant);
public:
    unsigned get_rows() const;
	unsigned get_cols() const;

public:
    Matrix& transpose();

    void change_rows(unsigned r1, unsigned r2);

    void rows_linear_combination(unsigned fix, unsigned change, double coef);

    double calculateDeterminant();
void print();

public:
    Row operator[](size_t index);
    const Row operator[](size_t index) const;
    Matrix operator+(Matrix B);
    Matrix operator*(Matrix B);
};
