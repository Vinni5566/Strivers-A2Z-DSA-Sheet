#include <iostream>
#include <vector>
using namespace std;

//optimized

class Solution {
public:
    int findKRotation(vector<int> &nums)  {

        int n = nums.size();
        
        //if array is sorted, no rotation
        if(nums[0] <= nums[n-1])  return 0; 

        int l = 0;
        int r = n-1;

        while(l <= r) {
            
            int mid = l + (r-l)/2;

            if(nums[mid] <= nums[r]) { //pivot is in left half
                r = mid - 1;
            } else { //pivot is in right half
                l = mid + 1;
            }
        }

        //l will point ot index of minimum element
        return l+1; //no. of right rotations
    }
};


//brute force

class Solution {
public:
    int findKRotation(vector<int> &nums)  {

        int n = nums.size();
        
        //if array is sorted, no rotation
        if(nums[0] <= nums[n-1])  return 0; 

        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
                return i + 1; //no. of right rotations
            }
        }

        return 0; //fallback
    }
};