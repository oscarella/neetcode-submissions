class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; // value, index
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int search = target - nums[i];
            if (m.count(search)) return {m[search], i};
            else m[nums[i]] = i;
        }
        return {};
    }
};
