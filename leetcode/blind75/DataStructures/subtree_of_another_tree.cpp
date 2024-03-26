bool is_match(TreeNode *root, TreeNode *sub)
{
    if (root == NULL && sub == NULL)
        return true;
    if (root == NULL || sub == NULL)
        return false;
    if (root->val != sub->val)
        return false;

    if (is_match(root->left, sub->left))
        return is_match(root->right, sub->right);

    return false;
}

bool isSubtree(TreeNode *root, TreeNode *subroot)
{
    if (!root)
        return false;

    if (is_match(root, subroot))
        return true;
    else
    {
        return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
    }
}
