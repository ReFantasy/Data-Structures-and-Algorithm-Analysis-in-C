#ifndef __TREE_H__
#define __TREE_H__
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <cstdlib>

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

//initialize
SearchTree MakeEmpty(SearchTree T);
#endif