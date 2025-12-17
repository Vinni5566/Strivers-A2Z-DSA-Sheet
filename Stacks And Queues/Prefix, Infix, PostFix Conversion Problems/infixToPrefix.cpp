#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string prefixToInfix(string s) {
        reverse(s.begin(), s.end());

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                s[i] = ')';
            }

            if(s[i] == ')') {
                s[i] = '(';
            }
        }

        string res;

        stack<char> st;

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
            }

            else {
                if(ch == '^') {
                    while(!st.empty() && precedence(ch) <= precedence(st.top())) {
                        res.push_back(st.top());
                        st.pop();
                    }
                } else {
                    while(!st.empty() && precedence(ch) < precedence(st.top())) {
                        res.push_back(st.top());
                        st.pop();
                    }
                }
            }

            st.push(ch);
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
        
    }

    int precedence(char c) {
        if(c == '+' || c == '-') return 1;
        if(c == '/' || c == '*') return 2;
        if(c == '^') return 3;
        return 0;
    }
};