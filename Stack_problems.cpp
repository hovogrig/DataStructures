#include <stack>
#include <iostream>
#include <string> 


void order(std::stack <int> s1){   // ordering s1 stack in s2
    std::stack <int> s2,s3;            
    int temp{};
    if(!s1.empty()){ 
        s2.push(s1.top());
        s2.pop();
    }
    while(!s1.empty()){ 
        temp = s1.top();
        s1.pop();
        while(!s2.empty() && temp>s2.top()){ 
            s3.push(s2.top());
            s2.pop();
        }
        s2.push(temp);
        while(!s3.empty()){ 
            s2.push(s3.top());
            s3.pop();
        }
    }
    int len=s2.size();
    for(int i=0; i<len; ++i){ 
        std::cout<<s2.top()<<' ';
        s2.pop();       
    }
    std::cout<<" "<<std::endl;
}

void copy(std::stack <int> s1){   // copying s1 stack in s2 without repetition 
    std::stack <int> s2, s3;
    if(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s1.empty()){ 
    bool flag = false;
    int temp = s1.top();
    s1.pop();
    while (!s2.empty()) {
        if(temp != s2.top()){ 
            s3.push(s2.top());
            s2.pop();
        }
        else { 
            flag=true;
            break;
        } 
    }
    while(!s3.empty()){ 
            s2.push(s3.top());
            s3.pop();
        }
        if(!flag){ 
            s2.push(temp);
        }
    }
    int len = s2.size();
    for(int i=0; i<len; ++i){ 
        std::cout<<s2.top()<<' ';
        s2.pop();
    }
    std::cout<<' '<<std::endl;
}

void fill_s3(std::stack <int> s1,std::stack <int> s2) {  // elements of s3 stack are
    std::stack <int> s3;                                 //one from s1 another s2
    while (!s1.empty() || !s2.empty()) { 
        if(!s1.empty()){
            s3.push(s1.top());
            s1.pop();
    }
        if(!s2.empty()){ 
            s3.push(s2.top());
            s2.pop();
    }
}
    int len = s3.size();
    for(int i=0; i<len; ++i){ 
        std::cout<<s3.top()<<' ';
        s3.pop();
    }
    std::cout<<' '<<std::endl;
}

void IsPalindrome(std::string str) {   // Checking if string palindrom or not using stack 
    std::stack <char> s1;
    for(int i=0; i<str.size()/2; ++i){ 
        s1.push(str[i]);
    }   
    bool flag = true;
    if(str.size()%2==0){
        for(int i =str.size()/2; i<str.size(); ++i){ 
            if(str[i] != s1.top()){ 
                flag =false;
                break;
            }
            s1.pop();
        }
    }
    else {
        for(int i=(str.size()/2)+1; i<str.size(); ++i){ 
            if(str[i] != s1.top()){ 
                flag =false;
                break;
            }
            s1.pop();
        } 
    }
    std::cout<<flag<<std::endl;
}