#pragma once
#include <iostream>

const int maxsize = 50;

template <typename T>
class Stack {
public: 

    Stack();

    bool empty();
    void get_top();
    void push(T);
    void pop();
    void clear();
    void print();

private:
    T arr[maxsize];
    int top;
};

template <typename T>
Stack<T>::Stack(): top(-1) {};

template <typename T>
bool Stack<T>::empty(){
    return top==-1;
}

template <typename T>
void Stack<T>::get_top(){
    if(top!=-1){
        std::cout<<arr[top]<<std::endl;
    }
    else{
        std::cout<<"Stack is empty"<<std::endl;
    }
}

template <typename T>
void Stack<T>::push(T a){ 
    if(top != maxsize-1){
            arr[++top]=a;
    }
    else { 
        std::cout<<"Stack is full!"<<std::endl;
    }
}

template <typename T>
void Stack<T>::pop(){ 
    if(empty()){
        std::cout<<"Stack is empty"<<std::endl;
    }
    else{ 
        --top;
    }
}

template <typename T>
void Stack<T>::clear(){
    top=-1;
}

template <typename T>
void Stack<T>::print(){
    if(!empty()){
        for(int i=0; i<=top;++i){
            std::cout<<arr[i]<<' ';
        }
        std::cout<<' '<<std::endl;
    }
    else {
        std::cout<<"Stack is empty!"<<std::endl;
    }
}