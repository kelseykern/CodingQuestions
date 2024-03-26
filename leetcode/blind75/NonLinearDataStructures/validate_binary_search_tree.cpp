bool isValid(TreeNode *root, long int min, long int max)
{
    bool is_valid = false;
    if (root == NULL)
        return true;
    if (root->val > min && root->val < max)
    {
        bool left = isValid(root->left, min, root->val);
        bool right = isValid(root->right, root->val, max);
        is_valid = left && right;
    }
    return is_valid;
}
bool isValidBST(TreeNode *root)
{
    return isValid(root, LONG_MIN, LONG_MAX);
}
