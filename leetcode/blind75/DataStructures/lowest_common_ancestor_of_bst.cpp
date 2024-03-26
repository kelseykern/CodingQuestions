TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    int curr_val = root->val;

    // if the current node is greater than p and q
    if (curr_val > p->val && curr_val > q->val)
    {
        // check the left subtree
        return lowestCommonAncestor(root->left, p, q);
    }
    // if the current node is less than p and q
    if (curr_val < p->val && curr_val < q->val)
    {
        // check the right subtree
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}
