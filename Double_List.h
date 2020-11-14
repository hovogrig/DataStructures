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
    void append(T);     // append element from back of list
    void reverse();     // reversed original list
    void swap(int,int);   // swaped 2 nodes with indexes
    void sort();        // order original list (SelectionSort) 

private:
    void deallocate();
    Node<T>* get_index(int);  //return index-th node from list

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
void LinkedList<T>::swap(int ind1, int ind2){ 
    if ((ind1<0 || ind1>=m_size) && (ind2<0 || ind2>=m_size)) { 
        std::cout<<"index is out of bound"<<std::endl;
        return;
    }
    Node<T>*tmp = this->get_index(ind1);
    Node<T>*tmp1 = this->get_index(ind2);
    Node<T>*tmp2 = new Node<T>;
    tmp2->m_data = tmp->m_data;
    tmp->m_data = tmp1->m_data;
    tmp1->m_data = tmp2->m_data;
    delete tmp2;
}

template <typename T>
void LinkedList<T>::reverse(){ 
    for(int i=0; i<(this->get_size()/2); ++i){ 
        this->swap(i,m_size-1-i);
    }
}

template <typename T>
void LinkedList<T>::sort(){ 
    for (int i = 0; i < m_size; ++i) {
        int min = i;
        for(int j =i+1; j<m_size; ++j){ 
            if((this->get_index(min)->m_data) > (this->get_index(j)->m_data)) {    
                min = j;
            }
        }
        this->swap(i,min);
    } 
}

template <typename T>
void LinkedList<T>::insert(int index, T num){ 
    if(index < 0){ 
        std::cout<<"index out of bound"<<std::endl;
        return;
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
void LinkedList<T>::append(T element){ 
    Node<T>* n = new Node<T>(element);
    if(m_size==0){ 
        tail=n;
        head=n;
        ++m_size;
        return;
    }
    tail->next=n;
    n->previous=tail;
    tail=n;
    ++m_size;
    return;
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
Node<T>* LinkedList<T>::get_index(int index){ 
    if(is_empty()) {
        throw std::exception();
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
    return tmp;
}

template <typename T>
void LinkedList<T>::get_head() { std::cout<<head->m_data<<std::endl; }

template <typename T>
void LinkedList<T>::get_tail() { std::cout<<tail->m_data<<std::endl; }