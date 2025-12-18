#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class solution {

public:
      string prefixToInfix(string s) {

        stack<string> st;

        for(int i = s.length()-1; i >= 0; i--) {
            string str = string(1, s[i]);

            if(isalpha(s[i])) {
                st.push(str);
            } else {
                string top1 = st.top(); st.pop();
                string top2 = st.top(); st.pop();
                st.push("(" + top1 + str + top2 + ")");
            }
        }

        return st.top();
      }
};

int main() {

    string s;
    cin >> s;

    solution sol;
    cout << sol.prefixToInfix(s);

    return 0;
}