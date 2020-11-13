#pragma once
#include <iostream>
#include <string>

const int maxsize = 50;

template <typename T>
class Queue {
public:
    Queue();

    int length();
    bool empty();
    void insert(T);
    void remove();
    void clear();
    void print();
    int frontf();

private: 
    int count;
    int front;
    int rear;
    T arr[maxsize];
};

template <typename T>
Queue<T>::Queue(): front(-1), rear(-1), count(0) {}

template <typename T>
bool Queue<T>::empty(){
    return count==0;
}

template <typename T>
int Queue<T>::length(){ 
    return count;
}

template <typename T>
void Queue<T>::insert(T num){
    if(length()==0) { 
        front=0;
        rear=-1;
    }
    if(rear != maxsize-1){ 
        arr[++rear]=num; 
        ++count;
    }
    else { 
        std::cout<<"Queue is full!"<<std::endl;
    }
}

template <typename T>
void Queue<T>::remove() {
    if(!empty()){
        for(int i=0;i<length()-1;++i){
            arr[i]= arr[i+1];
        }
    --count;
    --rear;
    }
    else { 
        std::cout<<"Queue is empty!"<<std::endl;
    }
}

template <typename T>
void Queue<T>::clear(){ 
    count = 0;
}

template <typename T>
void Queue<T>::print(){ 
    for(int i=0;i<length();++i){
        std::cout<<arr[i]<<' ';
    }
    std::cout<<' '<<std::endl;
}

template <typename T>
int Queue<T>::frontf(){
    if(length()!=0){ 
        return arr[front];
    }
    else { 
        std::cout<<"Queue is empty!"<<std::endl;
        return -1;
    }
}