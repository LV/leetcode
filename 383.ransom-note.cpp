// @leet start
// MEMORY EFFICIENT SOLUTION
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         sort(ransomNote.begin(), ransomNote.end());
//         sort(magazine.begin(), magazine.end());
//
//         int ransomPointer = 0;
//         int magazinePointer = 0;
//
//         while(ransomPointer < ransomNote.size()) {
//             if(magazinePointer == magazine.size()) return false;
//             if(ransomNote[ransomPointer] < magazine[magazinePointer]) return false;
//             if(ransomNote[ransomPointer] == magazine[magazinePointer]) ransomPointer++;
//             magazinePointer++;
//         }
//         return true;
//     }
// };

class Solution {
public:
    int charToNum(const char c) {
        return int(c - 'a');
    }

    bool canConstruct(string ransomNote, string magazine) {
        int ransomCount[26];
        fill(ransomCount, ransomCount+26, 0);

        int magazineCount[26];
        fill(magazineCount, magazineCount+26, 0);

        for(int i=0; i<ransomNote.size(); i++) ransomCount[charToNum(ransomNote[i])]++;
        for(int i=0; i<magazine.size(); i++) magazineCount[charToNum(magazine[i])]++;

        for(int i=0; i<26; i++) if(ransomCount[i] > magazineCount[i]) return false;
        return true;
    }
};
// @leet end
