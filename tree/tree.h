#ifndef __TREE_H__
#define __TREE_H__
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <malloc.h>
#include <cstdlib>
/******************************************
 * 
 *   名称：二叉查找树ADT
 *   作者：TDL 
 *   时间:2018.3.16
 *   参考：数据结构和算法分析（C语言描述）
 * 
 * **************************************/

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
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

/******************************************
 * 
 *   名称：平衡查找树ADT（AVL Tree）
 *   作者：TDL 
 *   时间:2018.3.17
 *   参考：数据结构和算法分析（C语言描述）
 * 
 * **************************************/
struct AvlNode;
typedef struct AvlNode* AvlPosition;
typedef struct AvlNode* AvlTree;

//初始化
AvlTree AvlMakeEmpty(AvlTree T = NULL);

//返回树的高度
int Height(AvlPosition P);
AvlPosition SingleRotateWithLeft(AvlPosition k1);
AvlPosition SingleRotateWithRight(AvlPosition k1);
AvlPosition DoubleRotateWithLeft(AvlPosition k1);
AvlPosition DoubleRotateWithRight(AvlPosition k1);

//插入元素(如果已经存在则什么也不做),返回该元素位置
AvlPosition Insert(AvlTree T, int value);
#endif