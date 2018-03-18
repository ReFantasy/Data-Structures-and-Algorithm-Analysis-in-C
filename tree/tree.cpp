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

struct AvlNode
{
    int value;
    struct AvlNode* left;
    struct AvlNode* right;
    int height;
};

AvlTree AvlMakeEmpty(AvlTree T)
{
    if(T != NULL)
    {
        AvlMakeEmpty(T->left);
        AvlMakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

int Height(AvlPosition P)
{
    if(P != NULL)
        return P->height;
    return -1;
}

AvlPosition SingleRotateWithLeft(AvlPosition k2)
{
    AvlPosition k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = std::max(Height(k2->left), Height(k2->right))+1;
    k1->height = std::max(Height(k1->left), k2->height)+1;
    return k2;
}

AvlPosition SingleRotateWithRight(AvlPosition k1)
{
    AvlPosition k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = std::max(Height(k1->left), Height(k1->right))+1;
    k2->height = std::max(k1->height, Height(k2->right))+1;
    return k2;
}

AvlPosition DoubleRotateWithLeft(AvlPosition k1)
{
    k1->left = SingleRotateWithRight(k1->left);
    return SingleRotateWithLeft(k1);
}

AvlPosition DoubleRotateWithRight(AvlPosition k1)
{
    k1->right = SingleRotateWithLeft(k1->right);
    return SingleRotateWithRight(k1);
}

AvlPosition Insert(AvlTree T, int value)
{
    if(T == NULL)
    {
        T = (AvlPosition)malloc(sizeof(struct AvlNode));
        T->value = value;
        T->height = 0;
        T->left = NULL;
        T->right = NULL;
    }
    else if(value < T->value)
    {
        T->left = Insert(T->left, value);
        if(Height(T->left) - Height(T->right) == 2)
        {
            if(value < T->left->value)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else
    {
        T->right = Insert(T->right, value);
        if(Height(T->right) - Height(T->left) == 2)
        {
            if(value > T->right->value)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    T->height = std::max(Height(T->left), Height(T->right))+1;
    return T;
}

void MidOrderPrintAvlTree(AvlTree T)
{
    if(T)
    {
        MidOrderPrintAvlTree(T->left);
        printf("value:%d  height:%d\n", T->value, T->height);
        MidOrderPrintAvlTree(T->right);
    }
}