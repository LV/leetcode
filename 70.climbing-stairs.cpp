// @leet start
class Solution {
public:
    unordered_map<int, int> visited = {{1, 1}, {2, 2}};
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(auto iter = visited.find(n); iter != visited.end()) return iter->second;
        int compute = climbStairs(n-2) + climbStairs(n-1);
        visited.insert({n, compute});
        return compute;
    }
};
// @leet end

// TODO: Do some dynamic programming
