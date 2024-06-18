// @leet start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> binary(n);
        string binStr = binary.to_string();
        reverse(binStr.begin(), binStr.end());
        bitset<32> reversedNum(binStr);
        return static_cast<uint32_t>(reversedNum.to_ulong());
    }
};
// @leet end
