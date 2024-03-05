// https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
// TC: O(NlogN)
// SC: O(N)

class Solution{
public:
	static bool cmp(string X , string Y){
        string XY = X+Y;
        string YX = Y+X;
       return (XY > YX);
    }
    
    string printLargest(int n, vector<string> &arr) {
        // code here
        sort(arr.begin() , arr.end(),cmp);
        string res = "";
        for(int i = 0 ; i < n ; i++ ) res+=(arr[i]);
        return res;
    }

};