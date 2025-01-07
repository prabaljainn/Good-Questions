// 199. Binary Tree Right Side View 
// https://leetcode.com/problems/binary-tree-right-side-view/description/


/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            vector<int> ans;
            if (!root)
                return ans;
            queue<TreeNode*> q;
            q.push(root);


    while (!q.empty()) {
        int levelSize = q.size();
        TreeNode* node = nullptr;

        // Pop each node of this level and push its children
        for (int i = 0; i < levelSize; i++) {
            node = q.front();
            q.pop();
            
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        // After popping all nodes at this level,
        // the 'node' pointer now points to the rightmost node in that level
        ans.push_back(node->val);
    }

            return ans;
        }
};
