// @leet start
class Solution {
public:
    enum binState {
        carry00, carry01, carry10, carry11,
        hold00, hold01, hold10, hold11
    };

    void prependZeros(string& s, int amount) {
        s.insert(0, amount, '0');
    }

    binState getState(bool hasCarry, char a, char b) {
        if(hasCarry) {
            if(a=='0' && b=='0') return carry00;
            if(a=='0' && b=='1') return carry01;
            if(a=='1' && b=='0') return carry10;
            if(a=='1' && b=='1') return carry11;
        } else {
            if(a=='0' && b=='0') return hold00;
            if(a=='0' && b=='1') return hold01;
            if(a=='1' && b=='0') return hold10;
            if(a=='1' && b=='1') return hold11;
        }
        throw invalid_argument("Invalid character inputs!"); // should never reach this
    }

    string addBinary(string a, string b) {
        if(a.size() < b.size()) prependZeros(a, b.size()-a.size());
        if(a.size() > b.size()) prependZeros(b, a.size()-b.size());

        string finalStr = "";
        bool hasCarry = false;
        
        for(int i=a.size()-1; i>=0; i--) {
            binState state = getState(hasCarry, a[i], b[i]);
            switch(state) {
                case carry00:
                    finalStr.push_back('1');
                    hasCarry = false;
                    break;
                case carry01:
                    finalStr.push_back('0');
                    hasCarry = true;
                    break;
                case carry10:
                    finalStr.push_back('0');
                    hasCarry = true;
                    break;
                case carry11:
                    finalStr.push_back('1');
                    hasCarry = true;
                    break;
                case hold00:
                    finalStr.push_back('0');
                    hasCarry = false;
                    break;
                case hold01:
                    finalStr.push_back('1');
                    hasCarry = false;
                    break;
                case hold10:
                    finalStr.push_back('1');
                    hasCarry = false;
                    break;
                case hold11:
                    finalStr.push_back('0');
                    hasCarry = true;
                    break;
            }
        }
        if(hasCarry) finalStr.push_back('1');

        reverse(finalStr.begin(), finalStr.end());
        return finalStr; // string should be reversed
    }
};
// @leet end
