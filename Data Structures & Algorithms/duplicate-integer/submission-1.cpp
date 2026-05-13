class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (s.count(nums[i])) return true;
            else  s.insert(nums[i]);
        }
        return false; 
    }
};