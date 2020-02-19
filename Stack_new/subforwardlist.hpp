//
//  subforwardlist.hpp
//  Stack_new
//
//  Created by Данила Дудин on 19.02.2020.
//  Copyright © 2020 Данила Дудин. All rights reserved.
//

#ifndef subforwardlist_hpp
#define subforwardlist_hpp
#include "Header.h"


template <typename T>
class Node{
    public:
    Node *next;
    T data;
        Node (T data = T(), Node *next=nullptr){
            this->data = data;
            this->next = next;
        }
};



template <typename T>
class subforwardlist: public Stack {
public:
    subforwardlist();
    ~subforwardlist();
    bool push_back(T data);
    int get_size() {return Size;};
    T&operator[](const int index);
    void pop_front();
    void clear();
    void push_front(T data);
    int pop_back();
    void insert(T value, int index);
    void removeAt(int index);
private:
int Size;
Node<T> *head;
};

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
void subforwardlist<T>::clear(){
    while (Size){
        pop_front();
    }
}


template <typename T>
    subforwardlist<T>::subforwardlist(){
        Size = 0;
        head = nullptr;
}


template <typename T>
    subforwardlist<T>::~subforwardlist(){
        cout<< "Destructor was initiated"<<endl;
        clear();
}


template <typename T>
bool subforwardlist<T>::push_back(T data){
    if (head == nullptr){
        head = new Node<T>(data);
    }
    else{
        Node<T> *current = this->head;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = new Node<T>(data);
    }
    Size++;
    return true;
}


template <typename T>
T & subforwardlist<T>::operator[](const int index){
    int counter = 0;
    Node<T> *current = this->head;
    while(current != nullptr){
        if (counter == index){
            return current->data;
        }
        current = current->next;
        counter++;
    }
    return current->data;;
}


template <typename T>
void subforwardlist<T>::pop_front(){
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    Size--;
}


template <typename T>
void subforwardlist<T>::push_front(T data){
    head = new Node<T>(data, head);
    Size++;
}


template <typename T>
void subforwardlist<T>::insert(T value, int index){
    if(index==0){
        push_front(value);
    }
    else{
        Node<T> *previous = this->head;
        for(int i = 0; i < index - 1; i++){
            previous = previous->next;
        }
        previous->next=new Node<T>(value, previous->next);
        Size++;
    }
}


template <typename T>
void subforwardlist<T>::removeAt(int index){
    if (index == 0){
        pop_front();
    }
    else{
        Node<T> *previous = this->head;
        for(int i = 0; i < index - 1; i++){
            previous = previous->next;
        }
        Node<T> *ToDelete = previous->next;
        previous->next = ToDelete->next;
        delete ToDelete;
        Size--;
    }
}


template <typename T>
int subforwardlist<T>::pop_back(){
    removeAt(Size-1);
    return 0;
}
#endif /* subforwardlist_hpp */
