// https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1
// TC: O(1)
// SC: O(1)

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        vector<int> arr;
        while(n>0)
        {
            arr.push_back(n&1);
            n=n>>1;
        }
        
        reverse(arr.begin(), arr.end());
        for(int i=1; i<arr.size(); i++)
        {
            arr[i]^=arr[i-1];
        }
        
        int ans=0;
        int pp=0;
        for(int i=arr.size()-1; i>=0; i--)
        {
            ans+=arr[i]*pow(2, pp);
            pp++;
        }
        return ans;
        
    }
};
