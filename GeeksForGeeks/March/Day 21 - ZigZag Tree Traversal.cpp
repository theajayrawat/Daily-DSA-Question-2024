// https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
// TC: O(N)
// SC: O(N)

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	 vector<int>ans;
        if(root==NULL)return ans;
        bool leftToRight = true;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int qlen=q.size();
            vector<int> row(qlen);
            for(int i=0;i<qlen;i++){
                Node* curr=q.front();
                q.pop();
                int index = leftToRight ? i : qlen - i - 1;
    	        row[index] = curr -> data;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            leftToRight = !leftToRight;
            ans.insert(ans.end(), row.begin(), row.end());
        }
        return ans;
    }
};