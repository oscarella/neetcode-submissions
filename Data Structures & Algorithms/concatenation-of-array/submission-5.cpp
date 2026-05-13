class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> twiceNums(nums.size() * 2);
        for (int i = 0, n = nums.size(); i < n; ++i) {
            twiceNums[i] = twiceNums[n + i] = nums[i]; 
        }
        return twiceNums;
    }
};