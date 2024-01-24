// https://www.geeksforgeeks.org/problems/is-it-a-tree/1
// TC: O(N)
// SC: O(N)

class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<int> ad[n];
        for(auto it:adj){
            int u=it[0];
            int v=it[1];
            ad[u].push_back(v);
            ad[v].push_back(u);
        }
        vector<int>vis(n,0);
        vis[0]=1;
        queue<pair<int,int>> q;
        q.push({0,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:ad[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    return 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                return 0;
            }
        }
        return 1;
    }
};