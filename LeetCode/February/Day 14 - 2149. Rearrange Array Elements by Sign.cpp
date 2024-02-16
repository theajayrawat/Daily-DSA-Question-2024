// https://leetcode.com/problems/rearrange-array-elements-by-sign/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>v;
        int odd=0;
        int even=0;
        int n=nums.size();

        while(odd<n && even<n){
            while(nums[even]<0 && even<n){
                even++;
            }
            v.push_back(nums[even]);
            even++;

            while(nums[odd]>0 && odd<n){
                odd++;
            }
            v.push_back(nums[odd]);
            odd++;
        }

        return v;
    }
};