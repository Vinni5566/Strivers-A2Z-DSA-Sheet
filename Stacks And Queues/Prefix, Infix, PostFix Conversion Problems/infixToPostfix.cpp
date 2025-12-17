#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string infixToPostfix(string s) {
        
        stack<char> st;

        string res;

        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if(isalpha(ch)) {
                res.push_back(ch);
            } 
            
            else if(ch == '(') {
                st.push(ch);
            }

            else if(ch == ')') {
                while(!st.empty() && st.top() != '(') {
                    res.push_back(st.top());
                    st.pop();
                }
                
                if(!st.empty()) st.pop();
            }

            else {
                while(!st.empty() && st.top() != '(' && precedence(st.top()) >= precedence(ch)) {
                    res.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
                

        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }

    int precedence(char c) {
        if(c == '+' || c == '-') return 1;
        if(c == '*' || c == '/') return 2;
        if(c == '^') return 3;
        
        return 0;
    }
};