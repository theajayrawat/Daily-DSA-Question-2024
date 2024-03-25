// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            int index=nums[i]-1;
            if(nums[i]!=i+1 && nums[i]!=nums[index]){
                swap(nums[i],nums[index]);
            }
            else{
                i++;
            }
        }

        vector<int>ans;
        for(i=0;i<n;i++){
            if(nums[i]!=i+1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};