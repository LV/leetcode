// @leet start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int row = matrix.size();
        const int col = matrix[0].size();
        vector<vector<int>> ans(col, vector<int>(row, 0));

        for(int i=0; i<col; i++) for(int j=0; j<row; j++) ans[j][i] = matrix[i][j];
        return ans;
    }
};
// @leet end
