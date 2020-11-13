#pragma once

// SINGLE LINKED LIST

struct Node {  
    Node(): m_data(0), next(nullptr) {};
    Node(int data): m_data(data), next(nullptr) {};

    Node* next;
    int m_data;
};

class LinkedList {
public: 
    LinkedList();  // Default constructor
    ~LinkedList(); // Destructor

    void print();   //print elements
    int get_head();  // return m_data of head
    int get_tail();  // return m_data of tail
    bool is_empty();  // checking is lis empty
	int size();       // return size of list
	void insert(int, int);  // insert element on specified index in list 
	void remove(int);      // remove with index
    void append(int);  //append element from back
    void pop_back();   // pop element from back   (STACK)
    void pop_front();   // pop element from front  (QUEUE)

private:
    void deallocate();  // delete all nodes

private: 
    Node* head;
    Node* tail;
    int m_size;
};