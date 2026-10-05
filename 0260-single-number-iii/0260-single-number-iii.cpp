class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xorAll = 0;

        for (int num : nums) {
            xorAll ^= num;
        }

        long long diffBit = (long long)xorAll & -(long long)xorAll;

        int a = 0;
        int b = 0;

        for (int num : nums) {
            if ((long long)num & diffBit)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};