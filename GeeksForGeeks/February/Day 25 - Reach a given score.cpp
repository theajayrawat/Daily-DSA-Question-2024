// https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1
// TC: O(N)
// SC: O(N)

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
      vector<long long>dp(n+1,0);
      dp[0] = 1;
      for(int i=3;i<n+1;i++) {
          dp[i] += dp[i-3];
      }
      for(int i=5;i<n+1;i++) {
          dp[i] += dp[i-5];
      }
      for(int i=10;i<n+1;i++) {
          dp[i] += dp[i-10];
      }
      return dp[n];
    }
};