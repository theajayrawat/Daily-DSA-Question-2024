// https://www.geeksforgeeks.org/problems/search-pattern0205/1
// SC: O(N+M)
// TC: O(M)

class Solution
{
    public:
        void compute( vector<int>&lps, string pat, int m){
            int len=0;
            lps[0]=0;
            int i=1;
            while(i<m){
               if(pat[i]==pat[len]){
                   len++;
                   lps[i]=len;
                   i++;
               }else{
                   if(len!=0){
                       len=lps[len-1];
                   }else{
                       lps[i]=0;
                       i++;
                   }
               }
            }
            
        }
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int m=pat.size();
            int n=txt.size();
            vector<int>lps(m,0);
            compute(lps,pat,m);
            
             vector<int> result;
             
            int i = 0; // Index for text
            int j = 0; // Index for pattern
            
            while(i<n){
                if(pat[j]==txt[i]){
                    i++;
                    j++;
                }
                if(j==m){
                    result.push_back(i-j+1);
                    j = lps[j - 1];
                }else if(i<n && pat[j] != txt[i]){
                    if(j!=0){
                        j=lps[j-1];
                    }else{
                        i++;
                    }
                }
            }
            
            return result;
        }
     
};