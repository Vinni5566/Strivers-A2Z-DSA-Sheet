#include <iostream>
#include <vector>
using namespace std;

class stack {

    int top;
    int size;
    vector<int> st;

public:
     stack(int s) {
        size = s;
        int top = -1;
        st.resize(size);
     }

     void push(int x) {

        if(top >= size) {
            cout<<"Stack overflow"<<endl;
        }

        top = top + 1;
        st[top] = x;


     }

     void pop() {

        if(top < 0) {
            cout<<"Stack underflow"<<endl;
        }

        top--;
     }

     int top() {
        if(top >= size) {
            cout<<"Stack overflow"<<endl;
        }

        if(top < 0) {
            cout<<"Stack underflow"<<endl;
        }

        return st[top];
     }

     bool empty() {
        if(top < 0) return true;
        return false;
     }

     bool full() {
        if(top >= size) return true;
        return false;
     }
};