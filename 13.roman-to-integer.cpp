// @leet start
class Solution {
public:
    int charToNum(char c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                throw invalid_argument("Roman character is not valid!");
        }
    }

    int romanToInt(string s) {
        int number = 0;

        for(int i=0; i<s.size()-1; i++) {
            if(charToNum(s[i]) < charToNum(s[i+1])) {
                number += charToNum(s[i+1]) - charToNum(s[i]);
                i++; // we evaluated the character after, therefore we need to increment again
            } else number += charToNum(s[i]);
        }
        // evaluate last character
        if(charToNum(s[s.size()-2]) >= charToNum(s[s.size()-1])) number += charToNum(s[s.size()-1]);

        return number;
    }
};
// @leet end
