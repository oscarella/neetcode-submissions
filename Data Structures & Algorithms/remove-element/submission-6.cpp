class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lp = 0; // everything that has been searched that is not val is the left of lp
        for (int rp = 0, len = nums.size(); rp < len; ++rp) {
            if (nums[rp] != val) {
                std::swap(nums[lp], nums[rp]);
                ++lp;
            }
        }
        return lp;
    }
};