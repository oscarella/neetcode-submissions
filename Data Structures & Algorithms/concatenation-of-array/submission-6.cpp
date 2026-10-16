class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int> retVec(size * 2);
        for (int i = 0; i < size; ++i) {
            retVec[i] = retVec[i + size] = nums[i];
        }
        return retVec;
    }
};