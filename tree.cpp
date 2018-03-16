#include "tree.h"

struct TreeNode
{
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
}