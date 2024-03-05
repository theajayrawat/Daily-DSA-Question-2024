// https://www.geeksforgeeks.org/problems/power-set4302/1
// TC: O(NlogN)
// SC: O(N)

class Solution{
	public:
	void solve(int index,string s,vector<string>&ans,string res)
    {
        if(index>=s.size())
        {
            if(!res.empty())
            ans.push_back(res);
            return ;
        }
        else
        {
            solve(index+1,s,ans,res+s[index]);
            solve(index+1,s,ans,res);
        }
    }
    vector<string> AllPossibleStrings(string s){
            // Code here
        vector<string>ans;
        solve(0,s,ans,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};