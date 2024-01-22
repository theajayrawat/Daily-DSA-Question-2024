// https://leetcode.com/problems/set-mismatch/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int n = nums.size();
       int i=0;
        while(i<n){
            int index=nums[i]-1;
            if(nums[i]!=i+1 && nums[i]!=nums[index]){
                swap(nums[i],nums[index]);
            }
            else{
                i++;
            }
        }

       vector<int> ans;
       for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
               return {nums[i], i + 1};
           }
       } 

       return {-1, -1};
    }
};

