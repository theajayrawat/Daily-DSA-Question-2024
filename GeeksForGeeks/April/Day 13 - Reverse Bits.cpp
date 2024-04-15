// https://www.geeksforgeeks.org/problems/reverse-bits3556/1
// TC: O(1)
// SC: O(1)

class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
          long long reversed = 0;
        for (int i = 0; i < 32; i++) {
            reversed = (reversed << 1) | (x & 1);
            x >>= 1;
        }
        return reversed;
    }
};