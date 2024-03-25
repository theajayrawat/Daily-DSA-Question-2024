// https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
// TC: O(2^N)
// SC: O(2^N)

class Solution{
public:	
	void helper(int one, int zero, int n, string ds, vector<string>& res)
    {
        if(one + zero == n)
        {
            res.push_back(ds);
            return;
        }
        
        if(one < n)
            helper(one + 1, zero, n, ds + '1', res);
        if(zero < one)
            helper(one, zero+1, n, ds + '0', res);
    }

	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    
	    vector<string> res;
	    
	    string ds;
	    
	    helper(0, 0, n, ds, res);
	    
	    return res;
	}
};