// Calculate the preorder traversal result using the traversal idea

// store the result of the preorder traversal
int* res;
int resSize;

int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
    res = (int*)malloc(100 * sizeof(int));
    resSize = 0;
    traverse(root);
    *returnSize = resSize;
    return res;
}

// binary tree traversal function
void traverse(struct TreeNode* root) 
{
    if (root == NULL) 
	{
        return;
    }
    // preorder position
    res[resSize++] = root->val;
    traverse(root->left);
    traverse(root->right);
}