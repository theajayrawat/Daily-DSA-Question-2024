// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
// TC: O(NlogN)
// SC: O(N)

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i += 3){
            if(nums[i+2] - nums[i] <= k){
                ans.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            else return {};
        }
        return ans;
    }
};