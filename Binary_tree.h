#include <iostream>
#include <queue>

template <typename T>
struct Node { 
    Node(): m_data(0), left(nullptr), right(nullptr) {};
    Node(T data): m_data(data), left(nullptr), right(nullptr) {};
    
    bool is_leaf() const {return (left==nullptr && right==nullptr);}
    bool has_left() const {return (left != nullptr && right == nullptr);} // has only left
    bool has_right() const {return (right != nullptr && left == nullptr);} // has only right
    bool has_both() const {return (right != nullptr && left != nullptr);}

    T m_data;
    Node* left;
    Node* right;
};

template <typename T>
class BinaryTree {
public:
    BinaryTree(): root(nullptr) {};
    ~BinaryTree();

    bool empty();
    int length();

    void insert_root(Node<T>*);
    void insert_left(T, Node<T>*);
    void insert_right(T, Node<T>*);
    
    void preorder(Node<T>*);   //travers (visit each node only after visit its children)
    void postorder(Node<T>*);  // visit children only after it's parent node
    void inorder(Node<T>*);   // first visit left children and it's node then right (symetric)
    
    int height(Node<T>*);   
    int sum(Node<T>*);     // return sum of all nodes
    int depth(Node<T>*);   // return distance from root to node 
    void delete_node(Node<T>*);  // deleting subtree (root equal to parameter)    
    void iterate();  // iterate by levels(using queue)
    int leaves_count(Node<T>*);
    int nodes_count(Node<T>*); // same length function
    int count(Node<T>*,T);  // count of nodes with x data 
    int two_children(Node<T>*);  // node's count that has two children
    int one_child(Node<T>*);  // node's count with 1 child
    void reverse(Node<T>*);   // reverse all nodes

private: 
    void free(Node<T>*); 
    void deallocate();

private:
    int m_size{};
    Node<T>* root;
};


template <typename T>
bool BinaryTree<T>::empty(){ 
    return root==nullptr;
}

template <typename T>
int BinaryTree<T>::length(){ 
    return m_size;
}

template <typename T>
void BinaryTree<T>::insert_root(Node<T>*node) {
    if(empty()) { 
        root=node;
        ++m_size;
        return;
    } 
        std::cout<<"Tree already has a root !"<<std::endl;
}

template <typename T>
void BinaryTree<T>::deallocate() {
    if(root == nullptr) { return; } 
    Node<T>*cur = root;
    std::queue <Node<T>*> q1;            
    q1.push(cur);                     
    while (!q1.empty()) {      
        if(cur->left != nullptr) { q1.push(cur->left); }
        if(cur->right != nullptr) {q1.push(cur->right); }
        cur = q1.front();
        delete cur;
        cur = nullptr;
        q1.pop();
        cur = q1.front();
    }
    m_size = 0;
}

template <typename T>
void BinaryTree<T>::insert_left(T data, Node<T>*node){ 
    if(m_size != 0) { 
        if(node->left == nullptr) { 
            Node<T>*n = new Node<T>(data);
            node->left = n;
            ++m_size;
        }
        else {
            std::cout<<"Node has a left child"<<std::endl;
        }
    }
    else { 
        std::cout<<"First you need to insert a root !"<<std::endl;
    }
}

template <typename T>
void BinaryTree<T>::insert_right(T data, Node<T>*node){ 
    if(m_size != 0) { 
        if(node->right == nullptr) { 
            Node<T>*n = new Node<T>(data);
            node->right = n;
            ++m_size;
        }
        else {
            std::cout<<"Node has a right child"<<std::endl;
        }
    }
    else { 
        std::cout<<"First you need to insert a root !"<<std::endl;
    }
}

template <typename T>
void BinaryTree<T>::preorder(Node<T>*root) {    
    if(root == nullptr) { return; }
    std::cout<<root->m_data <<" ";   // Visit()
    preorder(root->left);
    preorder(root->right);
}

template <typename T>
void BinaryTree<T>::postorder(Node<T>*root){ 
if(root == nullptr) { return; }
    postorder(root->left);
    postorder(root->right);
    std::cout<<root->m_data <<" ";   // Visit()
}

template <typename T>
void BinaryTree<T>::inorder(Node<T>*root) {
    if(root == nullptr) { return; }
    inorder(root->left);
    std::cout<<root->m_data <<" ";   // Visit()
    inorder(root->right);
}

template <typename T>
int BinaryTree<T>::height(Node<T>*root){ 
    if(root==nullptr) {return -1;}     
    int left = height(root->left);
    int right = height(root->right);  
    return left>right?left+1:right+1;  // tree's height equal to maximum of it's 
}                                      // left and right subtree's height +1

template <typename T>
int BinaryTree<T>::count(Node<T>*root, T data) { 
    if(root == nullptr) {return 0;}
    if(root->m_data == data) {return 1+count(root->left, data) + count(root->right, data);}
    return count(root->left, data) + count(root->right, data);
}

template <typename T>
int BinaryTree<T>::two_children(Node<T>*root) {  
    if(root == nullptr) { return 0;}
    if(root->has_both()){ return 1+two_children(root->left) + two_children(root->right); }  
    return two_children(root->left) + two_children(root->right);
}

template <typename T>
int BinaryTree<T>::one_child(Node<T>*root) {  
    if(root == nullptr) { return 0;}
    if(root->has_left() || root->has_right()){ 
        return 1+one_child(root->left) + one_child(root->right);
    }  
    return one_child(root->left) + one_child(root->right);
}

template <typename T>
int BinaryTree<T>::sum(Node<T>*root){ 
    if(root == nullptr) { return 0; }          // sum of tree's nodes is equal to left and  
    return root->m_data + sum(root->left) + sum(root->right);  // right subtree's nodes sum 
}

template <typename T>
int BinaryTree<T>::depth(Node<T>*node){ 
    return height(root) - height(node);
}

template <typename T>
void BinaryTree<T>::iterate(){ 
    if(empty()) { return; }  // if tree is empty
    Node<T>*cur = root;
    std::queue <Node<T>*> q1;          // at first current is root and it's children(from left to right)
    q1.push(cur);                     // are pushed to queue. Then current is equal to front of queue
    while (!q1.empty()) {            // doing this loop untill queue is not empty
        if(cur->left != nullptr) { q1.push(cur->left); }
        if(cur->right != nullptr) {q1.push(cur->right); }
        std::cout<<cur->m_data<<' ';
        q1.pop();
        cur = q1.front();
    }
    std::cout<<std::endl;
}

template <typename T>
void BinaryTree<T>::free(Node<T>*node){ 
    Node<T>*cur = root;
    std::queue <Node<T>*> q1;
    q1.push(cur);
    while (!q1.empty()) {
        if((cur->left) && (cur->left->m_data == node->m_data)){  
            delete cur->left;           
            cur->left = nullptr;        
            --m_size;
            return;
        }
        if((cur->right) && (cur->right->m_data == node->m_data)){ 
            delete cur->right;
            cur->right = nullptr;
            --m_size;
            return;
        }
        if(cur->left != nullptr) { q1.push(cur->left); }
        if(cur->right != nullptr) {q1.push(cur->right); }
        q1.pop();
        cur = q1.front();
    }
    delete root;   // if tree has only root then loop isn't work properly
    root = nullptr; // because root doesn't have left and right children
    --m_size;
}

template <typename T>
int BinaryTree<T>::nodes_count(Node<T>*root) { 
    if(root == nullptr) { return 0;} 
    return  1 + nodes_count(root->left) + nodes_count(root->right);
}

template <typename T>
void BinaryTree<T>::delete_node(Node<T>*root){ 
    if(root == nullptr) { return; }
    delete_node(root->left);
    delete_node(root->right);  //postorder traverse
    return free(root);
}

template <typename T> 
void BinaryTree<T>::reverse(Node<T>*root) { 
    if(root == nullptr) { return;} 
    Node<T>*tmp = root->right;
    root->right = root->left;
    root->left = tmp;
    reverse(root->left);
    reverse(root->right);
}

template <typename T>
int BinaryTree<T>::leaves_count(Node<T>*root){ 
    if(root == nullptr ) {return 0;}
    if(root->is_leaf()) { return 1;}
    return leaves_count(root->left) + leaves_count(root->right);
}

template <typename T>
BinaryTree<T>::~BinaryTree(){ 
    deallocate();
}