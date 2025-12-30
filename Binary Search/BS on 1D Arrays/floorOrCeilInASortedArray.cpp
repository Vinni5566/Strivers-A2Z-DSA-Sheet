#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {

        vector<int> result(2, -1);

        int n = nums.size();

        int l = 0;
        int r = n-1;

        while(l <= r) {

            int mid = l + (r-l)/2;

            //exact match, floor and ceil are same
            if(nums[mid] == x) {
                result[0] = x;
                result[1] = x;
                return result;
            } 
            
            //can be a floor, move right
            if(nums[mid] < x) {
                
                result[0] = nums[mid];
                l = mid + 1;

            } 
            
            //can be a ceil, move left
            else {

                result[1] = nums[mid];
                r = mid - 1;
                      
            }

        }

        return result;
   
    }
};