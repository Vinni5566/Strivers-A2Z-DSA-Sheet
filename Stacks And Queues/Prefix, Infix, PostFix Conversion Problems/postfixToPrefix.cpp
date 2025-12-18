#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class solution {

public: 
      string postfixToPrefix(string s) {

        stack<string> st;

        for(int i = 0; i < s.length(); i++) {
            string str = string(1, s[i]);

            if(isalpha(s[i])) {
                st.push(str);
            } else {
                string top1 = st.top(); st.pop();
                string top2 = st.top(); st.pop();
                st.push("(" + str + top2 + top1 + ")");
            }
        }

        return st.top();
      }
};

int main() {
    
    string s;
    cin>>s;

    solution sol;
    cout << sol.postfixToPrefix(s);

    return 0;

}