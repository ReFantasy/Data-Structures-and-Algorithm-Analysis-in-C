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

Position Find(SearchTree T, int value)
{
    if(T == NULL)
        return T;
    if(T->value > value)
        Find(T->left, value);
    else if(T->value < value)
        Find(T->right, value);
    else
        return T;
}

Position FindMax(SearchTree T)
{
    if(T != NULL)
    {
        while(T->right != NULL)
            T = T->right;
    }

    return T;
}
Position FindMin(SearchTree T)
{
    if(T != NULL)
    {
        while(T->left != NULL)
            T = T->left;
    }

    return T;
}