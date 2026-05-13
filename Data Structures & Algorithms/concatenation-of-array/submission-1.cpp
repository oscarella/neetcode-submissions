class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // One Pass solution
        vector<int> ans(nums.size() * 2);
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            ans[i] = ans[len + i] = nums[i];
        }
        return ans;
    }
};