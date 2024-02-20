// https://leetcode.com/problems/missing-number/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=nums.size();
        for(int i=0;i<nums.size();i++){
            s^=i;
            s^=nums[i];
        }
        return s;
    }
};

