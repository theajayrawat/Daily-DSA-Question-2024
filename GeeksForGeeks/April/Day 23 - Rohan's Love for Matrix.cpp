// https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1
// TC: O(N)
// SC: O(1)

class Solution {
  public:
    int firstElement(int n) {
        // code here
        int mod = 1000000007;
        int a = 1, b=1;
        int c = a+b;
        int i=1;
        while(i<n){
            a = b;
            b = c;
            c = (a%mod+b%mod)%mod;
            i++;
        }
        return a;
    }
};