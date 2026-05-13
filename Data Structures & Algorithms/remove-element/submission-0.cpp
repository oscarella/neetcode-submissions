class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), l = 0, r = 0;
        while (r < len) {
            if (nums[r] == val) { // Equals val
                ++r;
            } else { // Does not equal val
                nums[l++] = nums[r++];
            }
        }
        return l;
    }
};