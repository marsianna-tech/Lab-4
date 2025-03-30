#include <iostream>
#include <random>
#include <chrono>
#include <time.h>
#include <iomanip>
#include"matrix.hpp"


    double& Matrix::Row::operator[](size_t index){
        double *el_pointer;
        el_pointer = begin + index;
        return *(el_pointer);
    }
    const double Matrix::Row::operator[](size_t index) const {
        double *el_pointer;
        el_pointer = begin + index;
        return *(el_pointer);
    }
     void Matrix::Row::swap(Row A, Row B){
        Row tmp;
        tmp.begin = A.begin;
        A.begin = B.begin;
        B.begin = tmp.begin;
        tmp.end = A.end;
        A.end = B.end;
        B.end = tmp.end;
    }


    Matrix::Matrix(unsigned rows, unsigned cols, double value): rows(rows), cols(cols){
        for (int i = 0; i < rows*cols; ++i){
            data.push_back(value);
            //std::cout<< data[i-1] << std::endl;
        }
    }
    Matrix::Matrix(){
        for (int i = 0; i < 36; i = i + 2){
                if(i % 4 == 0){
                    data.push_back(i + 1);
                }
                else{
                    data.push_back(i * 7);
                }
        }
    }
    Matrix Matrix::Identity(unsigned rows, unsigned cols){

        Matrix E(rows, cols, 0);
        unsigned int k = 0;
        for (int i = 0; i < cols*rows; ++i){
            if(i == k){
                E.data[i] = 1;
                k = k + E.rows + 1;
            }
            else{
                E.data[i] = 0;
            }
        }
        return E;
    }

    Matrix Matrix::getSpecificDeterminant(unsigned n, double determinant){
        int i, j;
        int stime;
        long int ltime;
        ltime = std::time(NULL);
        stime = (unsigned) ltime*ltime;
        std::srand(stime);
        double rd;
        Matrix A(n, n, 0);
        for(i = 0; i < n; ++i){
            for(j = 0; j < n; ++j){
                if(i < j){
                    A[i][j] = ((double)std::rand()/(double)RAND_MAX) * 50;
                }
                else if(i == j){
                        if(i == 0){
                            A[i][j] = determinant;
                        }
                        else{
                            A[i][j] = 1.0;
                        }
                }
                else{
                    A[i][j] = 0.0;
                }
            }
        }
        for(i = 1; i < n; ++i){
           A.rows_linear_combination(i, 0, rand() % (101) - 50);
        }
        unsigned a, b;
        for(i = 0; i < n; ++i){
            for (j = 0; j < 2; ++j) {
                a = rand() % n;
                b = rand() % n;
                if (a == b) b = (a + 1) % n;
                A.change_rows(a, b);
            }
        }
        A.print();
        return A;
    }


    //static Matrix getSpecificDeterminant(unsigned n, double determinant){

    //}
//2) getters
    unsigned Matrix::get_rows() const {
        return rows;
    }
	unsigned Matrix::get_cols() const {
        return cols;
	}

    Matrix& Matrix::transpose(){
        Matrix A_t (rows, cols, 0);
        int i, j;
        for(i = 0; i < cols; ++i){
            for(j = 0; j < rows; ++j){
                A_t[j][i] = (*this)[i][j];
            }
        std::cout << std::endl;
        }
        std::swap(A_t.data.mas, this->data.mas);
        return *this;
    }

    void Matrix::change_rows(unsigned r1, unsigned r2) {
        for (unsigned col = 0; col < cols; ++col) {
            std::swap(data[r1 * cols + col], data[r2 * cols + col]);
        }
    }

    void Matrix::rows_linear_combination(unsigned fix, unsigned change, double coef) {
        for (unsigned col = 0; col < cols; ++col) {
            (*this)[fix][col] = (*this)[fix][col] + coef * (*this)[change][col];
        }
    }

    double Matrix::calculateDeterminant() {
        double det = (double)1;
        Matrix tmp(*this);
        int main_element;
        double coef;
        for (unsigned main_col = 0; main_col < cols; ++main_col) {
            /**Frodo beggins lives under a hill with his uncle bilbo beggins.
            ...
            At the end of his way, Frodo Baggins leaves on an Elven ship alongside Gandalf and Bilbo
            and sets off for the Undying Lands - also known as Valinor.*/
            bool found_nonzero = false;
            for (unsigned row = main_col; row < rows; ++row) {
                if (tmp[row][main_col] > 1e-10) {
                    found_nonzero = true;
                    main_element = tmp[row][main_col];
                    if (row != main_col) {
                        tmp.change_rows(row, main_col);
                        det = -det;
                    }
                    break;
                }
            }
            if (!found_nonzero) {
                    tmp.print();
                    std::cout << "!";
                    return 0;
            }
            for (unsigned row = main_col + 1; row < rows; ++row) {
                coef = -(double)tmp[row][main_col] / tmp[main_col][main_col];
                tmp.rows_linear_combination(row, main_col, coef);
            }
            det *= tmp[main_col][main_col];
            std::cout << "det: "<< det << std::endl;
        }
        std::cout << "det: "<< det << std::endl;
        return det;
    }
void Matrix::print() {
    for(int i = 0; i < this->get_rows(); ++i){
        for(int j = 0; j < this->get_cols(); ++j){
            std::cout << (*this)[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix::Row Matrix::operator[](size_t index) {
        Row A;
        int j = 0, i = 0;
        double * begin;
        double * end;

        begin = data.mas + index * rows;
        end = data.mas + (index + 1) * rows;
        A.begin = begin;
        A.end = end;
        return A;
    }
    const Matrix::Row Matrix::operator[](size_t index) const {
        Row A;
        int j = 0, i = 0;
        double * begin;
        double * end;
        begin = data.mas + index * rows;
        end = data.mas + (index + 1) * rows;
        A.begin = begin;
        A.end = end;
        return A;
    }
    Matrix Matrix::operator+(Matrix B){
        Matrix Sum(cols,rows);
        int i, j;
        if((this->cols == B.cols) && (this->rows == B.rows)){
            for(i = 0; i < this->cols; ++i){
                for(j = 0; j < this->rows; ++j){
                    Sum[i][j] = (*this)[i][j] + B[i][j];
                }
            }
        }
           return Sum;
    }
   Matrix Matrix::operator*(Matrix B){
    int p, i, j;
    Matrix Composition(this->rows, B.cols, 0);
    if(this->cols == B.rows){
        for(i = 0; i < this->cols; ++i){
            for(j = 0; j < B.rows; ++j){
                for(p = 0; p < B.cols; ++p){
                    Composition[i][j] += (*this)[i][p]*B[p][j];
                }

            }
        }
    }
    return Composition;
}