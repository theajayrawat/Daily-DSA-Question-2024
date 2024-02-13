// https://www.geeksforgeeks.org/problems/recursive-sequence1611/1
// TC: O(N)
// SC: O(N)

class Solution{
public:
    long long sequence(int n){
        // code here
        vector<int>dp(n+1,0);
        long long m=1e9+7;
        dp[0]=0;
        int cnt=1;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            int sum=1;
            for(int j=1;j<=i;j++){
                sum=((sum%m)*(cnt%m))%m;
                cnt++;
            }
            dp[i]=(dp[i-1]%m+ sum%m)%m;
        }
        
        return dp[n];
    }
};