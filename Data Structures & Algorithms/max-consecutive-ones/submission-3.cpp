class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // maxNum, currNum
        unsigned int maxNum = 0;
        unsigned int i = 0, len = nums.size();
        while (i < len) {
            if (nums[i] == 1) {
                unsigned int currNum = 0;
                while (i < len && nums[i] == 1) {
                    ++currNum;
                    ++i;
                }
                if (currNum > maxNum) maxNum = currNum;
            } else {
                ++i;
            }
        }
        return maxNum;
    }
};