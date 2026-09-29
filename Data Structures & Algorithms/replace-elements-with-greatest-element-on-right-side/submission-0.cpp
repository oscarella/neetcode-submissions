class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = -1;
        for (int i = arr.size() - 1; i >= 0; --i) {
            int tmp = arr[i];
            arr[i] = -1;
            max = std::max(max, tmp);
        }
        return arr;
    }
};