// https://leetcode.com/problems/find-the-pivot-integer/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int pivotInteger(int n) {
        int val=sqrt((n*n + n)/2);
        return val*val==(n*n + n)/2? val : -1;
    }
};