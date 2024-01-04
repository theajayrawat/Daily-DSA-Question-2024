// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        int cnt=0;
        for(auto &i: mp){
            int freq=i.second;
            if(freq==1)
                return -1;
            if(freq%3==0){
                cnt+=(freq)/3;
            }else if(freq==2){
                cnt++;
            }else{
                cnt+=(freq)/3;
                cnt++;
            }
        }

        return cnt;

    }
};