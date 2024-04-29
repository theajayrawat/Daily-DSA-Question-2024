// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;
        for (int n : nums) {
            finalXor = finalXor ^ n;
        }
        
        return __builtin_popcount(finalXor ^ k);
    }
};