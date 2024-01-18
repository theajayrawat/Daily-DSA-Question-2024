// https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1
// TC: O(M*N)
// SC: O(M*N)

class Solution{
public:
    int dp[101][101];
    int solve(int m, int n, int i, int cnt){
        if(n==cnt)
            return 1;
        if(dp[i][cnt]!=-1) 
            return dp[i][cnt];
        
        int ans=0;
        for(int j=2*i;j<=m;j++){
            ans+=solve(m,n,j,cnt+1);
        }
        
        return dp[i][cnt]=ans;
            
    }
    int numberSequence(int m, int n){
        // code here
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=1;i<=m;++i)
        {
            //solve(val,ind,m,n)
            ans+=solve(m,n,i,1);
        }
        return ans;
        
    }
};
