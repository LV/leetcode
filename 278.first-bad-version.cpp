// @leet start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1) return 1;
        if(n == 2) return isBadVersion(1) ? 1 : 2;

        unsigned int maxPossibleVersion = n;
        unsigned int minPossibleVersion = 1;
        long unsigned int toSearch = (maxPossibleVersion + minPossibleVersion) / 2;
        while(maxPossibleVersion - minPossibleVersion > 1) {
            if(toSearch - minPossibleVersion == 1) {
                if(isBadVersion(minPossibleVersion)) return minPossibleVersion;
                if(isBadVersion(toSearch)) return toSearch;
            }
            if(maxPossibleVersion - toSearch == 1) return isBadVersion(toSearch) ? toSearch : maxPossibleVersion;

            if(!isBadVersion(toSearch)) minPossibleVersion = toSearch;
            else maxPossibleVersion = toSearch;
            toSearch = (maxPossibleVersion + minPossibleVersion) / 2;
        }
        return firstBadVersion(minPossibleVersion) ? minPossibleVersion : maxPossibleVersion;
    }
};
// @leet end
