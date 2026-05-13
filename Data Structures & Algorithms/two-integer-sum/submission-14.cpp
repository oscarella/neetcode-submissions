class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int diff = target - nums[i];
            if (m.count(diff)) {
                vector<int> retv;
                retv.push_back(min(m[diff], i));
                retv.push_back(max(m[diff], i));
                return retv;
            } else {
                m[nums[i]] = i;
            }
        }
    }
};
