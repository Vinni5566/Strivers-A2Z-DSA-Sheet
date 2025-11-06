#include <iostream>
#include <vector>
#include <cmath>     // for abs()
#include <climits>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights) {

        int n = heights.size();

        vector<int> dp(n, 0);
        dp[0] = 0;

        for(int i = 1; i < heights.size(); i++) {
            int step1_Energy = dp[i-1] + abs(heights[i] - heights[i-1]);
            int step2_Energy = INT_MAX;
            if(i > 1) {
                int step2_Energy = dp[i-2] + abs(heights[i] - heights[i-2]);
            }

            dp[i] = min(step1_Energy, step2_Energy);
            
        }

        return dp[n-1];
    }
};
