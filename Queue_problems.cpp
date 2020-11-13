#include <queue> 
#include <iostream>
#include <stack>

int main() { 
    // First part of q3 is q1 elements and second part is q2 elemets in reversed order
    std::queue <int> q1,q2,q3;
    std::stack <int> s1;
    q1.push(5);
    q1.push(6);
    q1.push(7);
    q1.push(8);

    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    while(!q1.empty()){ 
        q3.push(q1.front());
        q1.pop();
    }
    while(!q2.empty()){ 
        s1.push(q2.front());
        q2.pop();
    }
    while(!s1.empty()){ 
        q3.push(s1.top());
        s1.pop();
    }
    int len=q3.size();
    for(int i = 0; i<len; ++i){ 
        std::cout<<q3.front()<<' ';
        q3.pop();
    }
    std::cout<<' '<<std::endl;
    return 0;
}