// https://leetcode.com/problems/majority-element/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int cnt=0;

        for(int i=0;i<nums.size();i++){
            if(ele==nums[i]){
                cnt++;
            }else{
                cnt--;
            }

            if(cnt==0){
                ele=nums[i];
                cnt=1;
            }
        }

        return ele;
    }
};

