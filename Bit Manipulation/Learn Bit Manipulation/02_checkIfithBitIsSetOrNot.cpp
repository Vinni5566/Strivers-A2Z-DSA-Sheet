#include <iostream>
using namespace std;

class Solution {
public:
    bool checkIthBit(int n, int i) {
        return (n & (1 << i)) != 0;
    }
};