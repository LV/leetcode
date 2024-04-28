// @leet start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int indexLimit = numeric_limits<int>::max();
        for(int i=0; i<strs.size(); i++) if(strs[i].size() < indexLimit) indexLimit = strs[i].size();
        string commonPrefix = "";

        for(int i=0; i<indexLimit; i++) {
            char commonChar = strs[0][i];
            bool allEqual = true;
            for(int j=1; j<strs.size(); j++) {
                if(strs[j][i] != commonChar) {
                    allEqual = false;
                    break;
                }
            }
            if(!allEqual) break;
        }

    }
};
// @leet end
