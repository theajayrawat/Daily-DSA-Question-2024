// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1
// TC: O(N^2)
// SC: O(N)

class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here
	    int cnt=0;
        unordered_map<int,int>mp;
        for(auto i:mat1) 
            for(auto j:i) 
                mp[j]++;
        for(auto i:mat2) 
            for(auto j:i) 
                if(mp.find(x-j)!=mp.end()) 
                    cnt+=mp[x-j];
        return cnt;
	}
};