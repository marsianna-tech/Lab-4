#include <iostream>
#include <random>
#include <chrono>
#include <time.h>
#include <iomanip>
#pragma once
template<typename T>

struct subvector {
        T *mas;
        unsigned int top;
        unsigned int capacity;
public:
    subvector(): mas(NULL), capacity(0), top(0) {}
    subvector(const subvector& sv): mas(NULL), capacity(sv.capacity), top(sv.top) {
        mas = new T[capacity];
        for (unsigned i = 0; i < top; ++i) {
            mas[i] = sv.mas[i];
        }
    }
    subvector(subvector&& sv): mas(sv.mas), capacity(sv.capacity), top(sv.top) {
        sv.mas = NULL;
        sv.top = 0;
        sv.capacity = 0;
    }
    const subvector& operator=(const subvector& sv) {
        delete[] mas;
        capacity = sv.capacity;
        top = sv.top;
        mas = new T[capacity];
        for (unsigned i = 0; i < top; ++i) {
            mas[i] = sv.mas[i];
        }
        return *this;
    }
    const subvector& operator=(subvector&& sv) {
        delete[] mas;
        capacity = sv.capacity;
        top = sv.top;
        mas = sv.mas;
        sv.mas = NULL;
        return *this;
    }
    ~subvector(){
        delete[] mas;
    }
public:
    T& operator[](size_t index) {
        //std::cout << index;
         //std::cout <<  typeid(mas[index]).name();
         //std::cout << mas[index];
        return mas[index];
    }
    const T& operator[] (size_t index) const {
        return mas[index];
    }
    bool resize(unsigned int new_capacity){
        T *p;
        int i;
        p = mas;
        if (new_capacity == 0){
            mas = NULL;
            capacity = 0;
            top = 0;
            delete [] p;
            return 0;
        }
        else{
            mas = new T[new_capacity];
            if(mas == NULL){
                return 0;
            }
            else{
                if (new_capacity < top){
                    for (i = 0; i < new_capacity; ++i){
                        *((mas) + i) = *(p + i);
                    }
                    top = new_capacity;
                }
                else{
                    for (i = 0; i < top; ++i){
                        *((mas) + i) = *(p + i);
                    }
                }
            capacity = new_capacity;
            delete [] p;
            return 1;
            }
        }
    }

    T pop_back(){
        T *p;
        int i;
        p = mas;
        if (top == 0){
            return 0;
        }
        else{
            p += top;
            --(top);
            return *(p - 1);
        }
    }

    void shrink_to_fit(){
        this->resize(top);
    }

    bool push_back(T d){
        T *p;
        int i;
        if (capacity == 0){
            mas = new T[1];
            *(mas) = d;
            capacity = 1;
            top = 1;
            return 0;
        }
        else if (capacity == top){
            this->resize(2 * capacity);
            p = mas;
            p += top;
            *p = d;
            ++top;
            return 1;
        }
        else{
            p = mas;
            p += top;
            *p = d;
            ++top;
            return 1;
        }
    }

    void clear() {
        top = 0;
    }
};
