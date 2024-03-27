// https://leetcode.com/problems/first-missing-positive/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long n=nums.size();
        for(long long i=0;i<n;i++){   
            long long index=(long long)nums[i]-1;
            while((long long)nums[i]-1!=i && index>=0 && index<n && (long long)nums[i]!=(long long)nums[index]){
                swap(nums[i],nums[index]);
                index=nums[i]-1;
            }
        }

        for(long long i=0;i<n;i++){
            if((long long)nums[i]-1!=i)
                return i+1;
        }

        return n+1;
    }
};