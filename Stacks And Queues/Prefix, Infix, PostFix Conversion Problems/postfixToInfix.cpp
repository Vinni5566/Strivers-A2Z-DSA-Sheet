#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string postfixToInfix(string s) {
        stack<string> st;

        for (char ch : s) {
            // Operand
            if (isalpha(ch)) {
                st.push(string(1, ch));
            }
            // Operator
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                st.push("(" + op2 + ch + op1 + ")");
            }
        }
        return st.top();
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    cout << sol.postfixToInfix(s);

    return 0;
}