#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {

        int n = nums.size();

        if(k == 0) return true;
         
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));

        for(int i = 0; i < n+1; i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < k+1; j++) {

                if(nums[i-1] <= j) dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][k];
    }
};