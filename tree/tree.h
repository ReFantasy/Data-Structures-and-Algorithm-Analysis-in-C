#ifndef __TREE_H__
#define __TREE_H__
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <cstdlib>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

//二叉查找树ADT

//初始化
SearchTree MakeEmpty(SearchTree T);

//查找值为Value的节点，并返回位置指针
Position Find(SearchTree T, int value);

//寻找最大最小值，返回位置指针
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);
#endif