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
SearchTree MakeEmpty(SearchTree T = NULL);

//查找值为Value的节点，并返回位置指针
Position Find(SearchTree T, int value);

//寻找最大最小值，返回位置指针
Position FindMax(SearchTree T);
Position FindMin(SearchTree T);

//插入元素(如果已经存在则什么也不做),返回该元素位置
Position Insert(SearchTree T, int value);

//删除元素，返回删除元素后树的根
SearchTree Delete(SearchTree T, int value_to_delete);

//中序遍历
void MidOrderPrintTree(SearchTree T);
#endif