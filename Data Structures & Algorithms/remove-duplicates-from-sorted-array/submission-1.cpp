class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lp = 0;
        for (int rp = 0; rp < nums.size(); ++rp) {
            if (!rp || nums[rp] != nums[rp - 1]) { // element is unique
                nums[lp] = nums[rp]; // assign [lp] w/ [rp]
                ++lp;
            }
        }
        return lp;
    }
};