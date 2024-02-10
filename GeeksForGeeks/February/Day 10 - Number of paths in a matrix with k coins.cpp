// https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1
// TC: O(N*M*K)
// SC: O(N*M*K)

#define ll long long
class Solution {
    public:
    ll help(vector<vector<int>>& v,int i,int j,int k,vector<vector<vector<int>>>& memo)
    {
        //base case
        if(i==0 and j==0)
        {
            if((k-v[0][0])==0)
            return 1;
            else
            return 0;
        }
        
        if(k<=0 || i<0 || i>=v.size() || j<0 || j>=v[0].size())
            return 0;
        
        //memo check
        if(memo[i][j][k]!=-1)
        return memo[i][j][k];
        
        //recursive calls
        //and small calculation
        ll a=help(v,i-1,j,k-v[i][j],memo);
        ll b=help(v,i,j-1,k-v[i][j],memo);
        return memo[i][j][k]=a+b;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> memo(arr.size(),vector<vector<int>>(arr[0].size(),vector<int>(k+1,-1)));
        ll ans=help(arr,n-1,n-1,k,memo);
        return ans;
    }
};

