// https://leetcode.com/problems/find-the-duplicate-number/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            while(nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
            }
            i++;
        }

        return nums[0];
    }
};