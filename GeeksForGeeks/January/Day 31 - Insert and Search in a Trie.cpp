// https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1
// T.C : O(N)
// S.C : O(N)

class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            // code here
            TrieNode* currentNode = root;
            for (int i=0;i<key.size();i++) {
                int ind=key[i]-'a';
                if (currentNode->children[ind] == NULL) {
                    TrieNode* newNode = new TrieNode();
                    currentNode->children[ind] = newNode;
                }
                currentNode = currentNode->children[ind];
                if(i==key.size()-1){
                    currentNode->isLeaf=true;
                }
            }
 
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            // code here
                TrieNode* currentNode = root;
                for (auto c : key) {
                    int ind=c-'a';
                    if (!currentNode->children[ind])
                        return false;
                    currentNode = currentNode->children[ind];
                }
                
            return currentNode->isLeaf;
        }
};

