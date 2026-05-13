class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Idea: Swap any vals with end of arr
        int l = 0, r = nums.size(); // l - curr index, r - # of valid elements
        while (l < r) {
            if (nums[l] == val) {
                // swap nums[l] & nums[r-1]
                int tmp = nums[l];
                nums[l] = nums[r-1];
                nums[r-1] = tmp;
                --r;
            } else {
                ++l;
            }
        }
        return r;
    }
};