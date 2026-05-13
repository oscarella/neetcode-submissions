class NumMatrix {
    vector<vector<int>> prefix_grid;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix_grid = matrix;

        for (int i = 0, n = matrix.size(); i < n; ++i) { // traverse row
            for (int j = 0, m = matrix[i].size(); j < m; ++j) { // traverse col
                int left_sum = 0, top_sum = 0, diag_sum = 0;
                // left sum
                if (j > 0) left_sum = prefix_grid[i][j-1];
                // top sum
                if (i > 0) top_sum = prefix_grid[i-1][j];
                // diag sum
                if (j > 0 && i > 0) diag_sum = prefix_grid[i-1][j-1];
                prefix_grid[i][j] = left_sum + top_sum - diag_sum + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int prefix_sum = prefix_grid[row2][col2];
        if (row1 > 0 && col1 > 0) prefix_sum += prefix_grid[row1-1][col1-1];
        if (col1 > 0) prefix_sum -= prefix_grid[row2][col1-1];
        if (row1 > 0) prefix_sum -= prefix_grid[row1-1][col2];
        return prefix_sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */