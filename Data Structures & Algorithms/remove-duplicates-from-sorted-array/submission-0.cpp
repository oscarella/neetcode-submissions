class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int k = 0;
        int val = -101;
        for (int i = 0; i < len; ++i) {
            if (nums[i] != val) { // different val is seen
                val = nums[i];
                // swap nums[k] & nums[i]
                int tmp = nums[i];
                nums[i] = nums[k];
                nums[k] = tmp;
                ++k;
                // i is incremented
            }
            // else - i is incremented
        }
        return k;
    }
};