/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    TreeNode *cur = A;
    vector<int> v;
    while(1){
        while(cur != NULL){
            v.push_back(cur->val);
            s.push(cur);
            cur = cur->left;
        }
        if( s.empty() )break;
        cur = s.top();
        s.pop();
        cur = cur->right;
    }
    return v;
}
