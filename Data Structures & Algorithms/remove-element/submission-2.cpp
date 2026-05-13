class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lp = 0;
        for (int rp = 0; rp < nums.size(); ++rp) {
            if (nums[rp] != val) nums[lp++] = nums[rp];
        }
        return lp;
    }
};