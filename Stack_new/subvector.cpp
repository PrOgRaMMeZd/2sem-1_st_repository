//
//  subvector.cpp
//  Stack_new
//
//  Created by Данила Дудин on 19.02.2020.
//  Copyright © 2020 Данила Дудин. All rights reserved.
//

#include "subvector.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

subvector::subvector(){
        this->capacity = 0;
        this->top = 0;
        this->mas = new int [1];
}

subvector::~subvector(){
        delete [] this->mas;
        this->top = 0;
        this->capacity = 0;
        int *newmas = new int [this->capacity];
        this->mas = newmas;
}

bool subvector::push_back(int d){
    int *newmas = new int [this->top + 1];
    for (int i = 0; i < this->top; i++){
        newmas[i] = this->mas[i];
    }
    newmas[this->top] = d;
    this->capacity++;
    this->top++;
    delete [] this->mas;
    this->mas=newmas;
    return true;
}

int subvector::pop_back(){
    if (this->capacity>1)
    {
        this->capacity --;
        int *newmas = new int [this->capacity];
        for (int i = 0; i < this->capacity; i++){
            newmas[i] = this->mas[i];
        }
        this->top--;
        delete [] this->mas;
        this->mas=newmas;
        return true;
    }
    else if (this->capacity==1){
        this->clear();
        return true;
    }
    else if (this->capacity<1){
        return false;
    }
    return false;
}

bool subvector::resize(unsigned int new_capacity){
    if (new_capacity >= this->capacity){
        int *newmas = new int [new_capacity];
        for (int i = 0; i < new_capacity; i++){
            newmas[i] = this->mas[i];
        }
        this->capacity=new_capacity;
        delete [] this->mas;
        this->mas=newmas;
        return true;
    }
    else return false;
}

void subvector::shrink_to_fit(){
    if (this->top < this->capacity){
        int *newmas = new int [this->top];
        for (int i = 0; i < this->top; i++){
            newmas[i] = this->mas[i];
        }
        this->capacity=this->top;
        delete [] this->mas;
        this->mas=newmas;
    }
    else cout<<"shrink_to_fit unneeded because capacity is equal to or less than top"<<endl;
}

void subvector::clear(){
        delete [] this->mas;
        int *newmas = new int [this->capacity];
        this->top = 0;
        this->capacity = 0;
        this->mas=newmas;
}

void subvector::Printer(){
    for (int i = 0; i<this->top;i++){
        cout << this->mas[i] << "\t";
    }
    cout<<endl;
}

int subvector::get_top(){
    return this->top;
}

int subvector::get_capacity(){
    return this->capacity;
}
