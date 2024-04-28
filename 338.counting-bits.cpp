// @leet start
class Solution {
public:
    void addOneToBinaryString(string& s) {
        bool madeChange = false;
        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == '0') {
                s[i] = '1';
                madeChange = true;
                for(int j=i+1; j<s.size(); j++) s[j] = '0';
                break;
            }
        }
        if(!madeChange) {
            for(int i=0; i<s.size(); i++) s[i] = '0';
            s.insert(0, 1, '1');
        }
    }

    int countBitsInString(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++) if(s[i] == '1') count++;
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> result;
        string binaryStr = {'0'};
        for(int i=0; i<=n; i++) {
            result.push_back(countBitsInString(binaryStr));
            addOneToBinaryString(binaryStr);
        }
        return result;
    }
};
// @leet end
