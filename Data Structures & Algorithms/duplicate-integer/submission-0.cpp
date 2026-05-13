#include <algorithm>
#include <vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       for (int i = 1, s = nums.size(); i < s; i++) {
            if (nums[i] == nums[i - 1])
                return true;
       }
       return false; 
    }
};