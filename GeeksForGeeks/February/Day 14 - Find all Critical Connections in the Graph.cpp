// https://www.geeksforgeeks.org/problems/critical-connections/1
// TC: O(V+E+ElogE)
// SC: O(V+E)

class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<vector<int>> &ans,vector<int> &lowtime,int &timer,int parent){
        lowtime[node]=timer;
        int parentTime=timer;
        timer++;
        for(auto x:adj[node]){
            if(x==parent)continue;
            else if(!lowtime[x]){
                dfs(x,adj,ans,lowtime,timer,node);
            }
            lowtime[node]=min(lowtime[node],lowtime[x]);
            if(parentTime<lowtime[x]){
                if(node<x)ans.push_back({node,x});
                else ans.push_back({x,node});
            }
        }
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<vector<int>> ans;
	    int timer=1;
	    vector<int> lowtime(v,0);
	    dfs(0,adj,ans,lowtime,timer,-1);
	    sort(ans.begin(),ans.end());
	    return ans;
	}

}