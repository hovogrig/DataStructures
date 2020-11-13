#pragma once
#include <iostream> 
#include <exception>

// DOUBLE LINKED LIST

template <typename T>
struct Node { 
    Node(): m_data(0),next(nullptr),previous(nullptr) {};
    Node(T data) : m_data(data), next(nullptr), previous(nullptr) {}; 

    T m_data;
    Node<T>* next;
    Node<T>* previous;
};

template <typename T>
class LinkedList { 
public: 
    LinkedList();
    ~LinkedList();

    bool is_empty() const { return m_size ==0; }
    int get_size() const { return m_size; }
    void insert(int, T);
    void remove(T);    // remove with element
    void print();
    void get_tail();
    void get_head();
    int get_index(int);  //return data of index-rd node from list

private:
    void deallocate();

private:
    int m_size;
    Node<T>*head;
    Node<T>* tail;
};

template <typename T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), m_size(0) {};

template <typename T>
void LinkedList<T>::print(){ 
    Node<T>*tmp=head;
    while(tmp != nullptr){ 
        std::cout<<tmp->m_data<<' ';
        tmp = tmp->next;
    }
    std::cout<<' '<<std::endl;
}

template <typename T>
void LinkedList<T>::insert(int index, T num){ 
    if(index < 0){ 
        std::cout<<"Wrong index"<<std::endl;
    }
    if(index > m_size) {index = m_size;}    
    Node<T>*tmp=head;
    Node<T>*n = new Node<T>(num);
    if(index == 0){ 
        if(m_size != 0){ 
            head->previous= n;
            n->next= head;
            head=n;
            ++m_size;
            return;
        }
        head=n;
        tail=n;
        ++m_size;
        return;
    }
    for(int i=0; i<index-1;++i){ 
        tmp = tmp->next;
    }
    if(index==m_size){
        tmp->next = n;
        n->previous=tmp;
        tail = n;
        ++m_size;
        return;
    }
    tmp->next->previous = n;
    n->next=tmp->next;
    n->previous=tmp;
    tmp->next = n;
    ++m_size;
    return;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    deallocate();
}

template <typename T>
void LinkedList<T>::deallocate(){ 
    if(m_size==0) {return;}
    Node<T>*tmp = head;
    while(tmp->next!=nullptr){ 
        tmp=tmp->next;
        delete tmp->previous;      
    }
    delete tmp;
    m_size=0;
}

template <typename T>
void LinkedList<T>::remove(T data){ 
    if(m_size==0){ return;}
    Node<T>*tmp = head;
    while(tmp!=nullptr){ 
        if(head->m_data == data){ 
            tmp=tmp->next;
            delete head;
            head=tmp;
            --m_size;
            continue;
        }
        if(tmp->m_data==data) {
            if(tmp->next == nullptr) { 
             tail=tmp->previous;
             tmp->previous->next=nullptr;
             delete tmp;
             --m_size;
             return;   
            } 
            tmp->previous->next=tmp->next;
            tmp->next->previous=tmp->previous;
            Node<T>*n=tmp;
            tmp=tmp->next;
            delete n;
            --m_size;
            continue;
        }
        tmp = tmp->next;
    }
}

template <typename T>
int LinkedList<T>::get_index(int index){ 
    if(is_empty()) {
        std::cout<<"Empty list"<<std::endl;
        return -1;
    }
    if(index<0 || index>=m_size){ 
        throw std::out_of_range ("Index is out of range");
    }
    int ind{};
    Node<T>*tmp =head;
    while(ind!=index) {
        tmp = tmp->next; 
        ++ind;
    }
    return tmp->m_data;
}

template <typename T>
void LinkedList<T>::get_head() { std::cout<<head->m_data<<std::endl; }

template <typename T>
void LinkedList<T>::get_tail() { std::cout<<tail->m_data<<std::endl; }