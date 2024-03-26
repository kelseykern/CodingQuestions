TreeNode *recurse(int prestart, int preend,
                  vector<int> &preorder,
                  int instart, int inend,
                  vector<int> &inorder)
{
    if (prestart > preend || instart > inend)
        return NULL;

    // beginning of preorder will be the new root
    TreeNode *root = new TreeNode(preorder[prestart]);

    // move down the inorder vector until we find our
    preorder new root value int root_index = 0;
    while (root_index < inorder.size() &&
           inorder[root_index] != root->val)
        root_index++;

    // find how many left elements we have from
    our inorder vector int size = root_index - instart;

    // check left with root as first element after prestart
    root->left = recurse(prestart + 1, prestart + size, preorder,
                         instart, root_index - 1, inorder);

    // check right with root as last element of prestart
    root->right = recurse(prestart + size + 1, preend, preorder,
                          root_index + 1, inend, inorder);
    return root;
}
TreeNode *buildTree(vector<int> &preorder,
                    vector<int> &inorder)
{
    // starting with root as preorder[0]
    TreeNode *root = recurse(0, preorder.size() - 1, preorder,
                             0, inorder.size() - 1, inorder);
    return root;
}
