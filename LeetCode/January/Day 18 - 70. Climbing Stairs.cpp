// https://leetcode.com/problems/climbing-stairs/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n<2)
            return n;
        int step1=1;
        int step2=2;
        for(int i=3;i<=n;i++){
            int ans=step1+step2;
            step1=step2;
            step2=ans;
            
        }
        return step2;
        
    }
};

