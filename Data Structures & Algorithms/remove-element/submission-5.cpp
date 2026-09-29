class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lp = 0; // everything to the left is val
        for (int rp = 0, len = nums.size(); rp < len; ++rp) {
            if (nums[rp] == val) {
                std::swap(nums[lp], nums[rp]);
                ++lp;
            }
        }
        return lp;
    }
};