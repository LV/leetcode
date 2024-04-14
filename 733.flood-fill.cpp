// @leet start
class Solution {
public:
    void changePixel(vector<vector<int>>& image, vector<vector<bool>>& visited, const int sr, const int sc, const int oldColor, const int newColor) {
        if(0 > sr || sr >= image.size()) return;
        if(0 > sc || sc >= image[0].size()) return;
        if(image[sr][sc] != oldColor) return;
        if(visited[sr][sc]) return;

        image[sr][sc] = newColor;
        visited[sr][sc] = true;

        changePixel(image, visited, sr+1, sc, oldColor, newColor);
        changePixel(image, visited, sr-1, sc, oldColor, newColor);
        changePixel(image, visited, sr, sc+1, oldColor, newColor);
        changePixel(image, visited, sr, sc-1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        changePixel(image, visited, sr, sc, image[sr][sc], color);
        return image;
    }
};
// @leet end
