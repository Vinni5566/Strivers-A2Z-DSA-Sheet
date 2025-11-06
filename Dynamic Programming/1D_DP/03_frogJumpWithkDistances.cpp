#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {

        int n = heights.size();

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i < heights.size(); i++) {
            for(int j = 1; j <= k; j++) {
                if(i-j >= 0) {
                    int jumpEnergy = dp[i-j] + abs(heights[i] - heights[j]);
                    dp[i] = min(dp[i], jumpEnergy);
                }
            }
        }

        return dp[n-1];
    }
};