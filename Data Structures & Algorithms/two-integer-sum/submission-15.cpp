class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int diff = target - nums[i];
            if (m.count(diff)) {
                vector<int> retv;
                retv.push_back(m[diff]);
                retv.push_back(i);
                return retv;
            } else {
                m[nums[i]] = i;
            }
        }
    }
};
