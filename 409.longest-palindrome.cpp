// @leet start
class Solution {
public:
    bool isUpper(char c) {
        return int('A') <= int(c) && int(c) <= int('Z');
    }

    int charToNum(char c) {
        return isUpper(c) ? int(c - 'A') : int(c - 'a')+26;
    }

    int longestPalindrome(string s) {
        vector<int> characters(52, 0);
        for(int i=0; i<s.size(); i++) {
            characters[charToNum(s[i])]++;
        }
        bool countOneOdd = false; // keeps track of only one odd
        unsigned int count = 0;
        for(int i=0; i<characters.size(); i++) {
            count += characters[i];
            if(characters[i] % 2 != 0) {
                countOneOdd = true;
                count--;
            }
        }
        return countOneOdd ? count + 1 : count;
    }
};
// @leet end
