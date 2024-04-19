// https://www.geeksforgeeks.org/problems/in-first-but-second5423/1
// TC: O(N)
// SC: O(N)

class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	    unordered_set<int> st;
	    for(int i=0;i<m;i++)
	    st.insert(b[i]);
	    
	    vector<int> ans;
	    for(int i=0;i<n;i++)
	    {
	        if(st.count(a[i])==0)
	        ans.push_back(a[i]);
	    }
	    
	    return ans;
	} 
};