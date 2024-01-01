// https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
// TC: O(N)
// SC: O(N)

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        if(n%2)
            return false;
    
        
        vector<int>freq(k,0);
        
        for(int i=0;i<n;i++){
            freq[nums[i]%k]++;
        }
        
        if(freq[0]%2)
            return false;
        
        for(int i=1;i<k;i++){
            if(freq[i]!=freq[k-i])
                return false;
        }
        
        return true;
    }
};