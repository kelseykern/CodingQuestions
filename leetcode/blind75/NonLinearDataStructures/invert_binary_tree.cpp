void recurseInvert(TreeNode *root)
{

    if (root == NULL)
        return;

    // these will return when we hit the last children
    recurseInvert(root->left);
    recurseInvert(root->right);

    // swap children
    TreeNode *tempLeft = root->left;
    root->left = root->right;
    root->right = tempLeft;

    return;
}

TreeNode *invertTree(TreeNode *root)
{
    recurseInvert(root);
    return root;
}
