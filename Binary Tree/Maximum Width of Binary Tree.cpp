/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans=1;
        unsigned long long temp=1;
        queue<pair<TreeNode*,unsigned long long>>q;//we cant do q.push_back() but can do q.back(),yesssss!!!!
        q.push({root,0});
        

        while(!q.empty()){
        temp=q.back().second-q.front().second+1;
        ans=max(ans,(int)temp);


        int n=q.size();
        for(int i=0;i<n;i++){

            pair<TreeNode*,unsigned long long>curr=q.front();
            q.pop();

            

            
        if(curr.first->left!=NULL)q.push({curr.first->left,2*curr.second+1});
        if(curr.first->right!=NULL)q.push({curr.first->right,2*curr.second+2});

        }

        

            }

            return ans;

    }
};