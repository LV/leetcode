// @leet start
class Solution {
public:
    stack<char> processStr(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '#') {
                if(!stk.empty()) stk.pop;
            }
            else stk.push(s[i]);
        }
        return stk;
    }

    string stackToStr(stack<char> s) {
        string final = "";
        while(!s.empty()) {
            final.push_back(s.top());
            s.pop();
        }
        return final;
    }

    bool backspaceCompare(string s, string t) {
        stack<char> stackS = processStr(s);
        stack<char> stackT = processStr(t);
        return stackToStr(stackS) == stackToStr(stackT);
    }
};
// @leet end
