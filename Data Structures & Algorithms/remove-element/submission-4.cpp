class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lp = 0, rp = nums.size(); // return lp
        while (lp < rp) {
            if (nums[lp] == val) {
                // assign last element within valid range
                nums[lp] = nums[rp - 1];
                --rp;
            } else {
                ++lp;
            }
        }
        return rp;
    }
};