#include "Linked_List.h"
#include <iostream>

// SINGLE LINKED LIST

LinkedList::LinkedList():head(nullptr),tail(nullptr),m_size(0) {};

bool LinkedList::is_empty(){ 
    return m_size==0;
}

int LinkedList::size(){ 
    Node*n=head;
    int count=0;
    while(n!=nullptr){     // Actually m_size shows our list size
        n=n->next;        //  And this algorithm is equal to -> return m_size;
        ++count;
    }
    delete n;
    return count;
}

void LinkedList::append(int data){ 
    if(head != nullptr && tail != nullptr){
        Node* tmp = new Node(data);
        tail->next=tmp;
        tail = tail->next;
    }
    else { 
        Node*first=new Node(data);    // if element is first then head must be it
        head = first;
        tail=first;
    }
    ++m_size;
}

void LinkedList::print() {
    if(m_size ==0) { 
        return;
    }
    Node*n = head;              // n is first element and print that until it's nullptr
    while(n!=nullptr){ 
        std::cout<<n->m_data<<' ';
        n=n->next;
    }
    std::cout<<' '<<std::endl;
}

void LinkedList::insert(int data, int index) { 
    if(index <0){ 
        std::cout<<"Wrong index"<<std::endl;
        return;
    }
    if(index >=m_size){ 
        index = m_size;
    }
    Node* tmp = new Node(data);
    if (index == 0){
        if(m_size != 0) {                // if inserted first element
            tmp->next = head;            // then head must be new node        
        }                               // and new node->next will show old head
        head=tmp;
        ++m_size;
        return;
    } 
    Node*n = head;
    for(int i=0; i<m_size; ++i){ 
        if(i == index-1){             // loop until (index-1)rd node. Then next of
            tmp->next=n->next;        // (index-1)rd node show to tmp and tmp's next in n's next 
            n->next=tmp;
            break;
        }
        else { 
            n = n->next;
        }
    }
    if(tmp->next==nullptr){ 
        tail=tmp;
    }
    ++m_size;
}

void LinkedList::remove(int index){ 
    if(index<0){ 
        std::cout<<"Wrong Index"<<std::endl;
    }
    Node*tmp=head;
    if(index == 0 ) {
        if(m_size != 1){ 
            head=head->next;           // if list size greater than 1 and removed head 
        }                              // then new head must be head->next(previous head)
        --m_size;
        delete tmp;
        return;
    }
    if(index>=m_size) { index = m_size-1;}
    for (int i = 0; i < index-1; ++i) {
        tmp=tmp->next;
    }
    if(index==m_size-1){ 
        tail=tmp;
        delete tmp->next;              // if removed last element then next of (n-1)rd
        tmp->next=nullptr;             // must be nullptr and last element must be delete
        --m_size;
        return;
    }
    tmp->next=tmp->next->next;     // There is a memory lack deleted node                      
    --m_size;                      // actually doesn't deleted
}                               

int LinkedList::get_head() { 
    return head->m_data;
}

int LinkedList::get_tail(){ 
    return tail->m_data;
}

LinkedList::~LinkedList() {
    deallocate();
}

void LinkedList::deallocate(){ 
    if(m_size==0){ return; }
    Node*ptr=head;
    Node*ptr1=head->next;
    while(m_size != 0){ 
        delete ptr;
        ptr=ptr1;
        ptr1 = (m_size==1)?nullptr:ptr1->next;  // if ptr1 is the last element
        --m_size;                               // then it equal to nullptr else it's next
    }
}

void LinkedList::pop_back() {
    if(m_size==0){ return;}
    Node*tmp = head;
    for (int i=0; i < m_size-2; ++i) {
        tmp=tmp->next;
    }
    tail = tmp;
    tmp = tmp->next;         // tail is (n-1)rd node and deleted last node
    tail->next = nullptr;
    delete tmp;
    --m_size;
}

void LinkedList::pop_front(){ 
    if(m_size==0){ return;}
    Node*tmp = head;
    head = head->next;       // now head is second node and first node must be delete
    delete tmp;
    --m_size;
}