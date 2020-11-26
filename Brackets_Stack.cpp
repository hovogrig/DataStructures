#include <iostream>
#include <string>
#include <stack>

bool in(char chars[], char b){ 
    for(int i=0; i<3; ++i){ 
        if(chars[i]==b){ 
            return true;
        }
    }
    return false;
}

int get_index(char chars[], char b){ 
    if(in(chars, b)) { 
        for(int i=0; i<3;++i){ 
            if(chars[i]==b){ 
                return i;
            }
        }
    }
    return -1;
}

int main() { 
    std::string str;
    std::cin>>str;
    std::stack <char> s1;
    char opening[3]={'(', '[', '{'};
    char closing[3] = {')', ']', '}'};
    bool flag = true;
    if(in(closing, str[0])){
        flag = false;
    }
    else {
        for(int i=0; i<str.length(); ++i){ 
            if(in(opening,str[i])){ 
                s1.push(str[i]);
            }
            else {
                if(s1.empty()){ 
                    flag = false;
                    break;
                } 
                int ind = get_index(closing, str[i]);
                int ind1 = get_index(opening,s1.top());
                s1.pop();
                if (ind != ind1){ 
                    flag = false;
                    break;
                }
            }
        }
    }
    if(s1.empty() && flag) {
        std::cout<<"YES"<<std::endl;
    }
    else {
        std::cout<<"NO"<<std::endl;
    }
    return 0;
}