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
    return NULL;
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

Position Insert(SearchTree T, int value)
{
    if(T == NULL)
    {
        T = (Position)malloc(sizeof(struct TreeNode));
        T->value = value;
        T->left = NULL;
        T->right = NULL;
    }

    if(T->value > value)
        T->left = Insert(T->left, value);
    if(T->value < value)
        T->right = Insert(T->right, value);

    return T;
}

SearchTree Delete(SearchTree T, int value_to_delete)
{
    if(T == NULL)
        return NULL;
    if(T->value > value_to_delete)
        T->left = Delete(T->left, value_to_delete);
    else if(T->value < value_to_delete)
        T->right = Delete(T->right, value_to_delete);
    else if(T->right && T->left)
    {
        Position tmp = FindMin(T->right);
        T->value = tmp->value;
        T->right  = Delete(T->right, value_to_delete);

    }
    else
    {
        Position tmp = T;
        if(T->left == NULL)
        { 
            T = T->right;
        }
        else
        {
            T = T->left;
        }
        free(tmp);
    }
    return T;
}

void MidOrderPrintTree(SearchTree T)
{
    if(T)
    {
        MidOrderPrintTree(T->left);
        printf("%d  ", T->value);
        MidOrderPrintTree(T->right);
    }
}