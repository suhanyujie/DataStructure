//
//  BSTree.h
//  BSTree
//
//  Created by 苏汉宇 on 17/2/14.
//  Copyright © 2017年 苏汉宇. All rights reserved.
//
/*
 1.这个文件中会引入stdbool.h文件
 * 介绍 https://zh.wikipedia.org/wiki/Stdbool.h
 * 它的作用大概是 将布尔值扩展，比如 true扩展为1；false扩展为0等等
 
 
 */



#ifndef BSTree_h
#define BSTree_h

#include <stdbool.h>

#define SUCCESS 1
#define FAILED 0
#define INIT_SIZE 20

// 定义接口名
#define BSTREE_API
// 定义判断函数
#define INT_VAL(v) *((int *)(v))
// 宏定义 is_null
#define IS_NULL(v) (bool)(v == NULL)

// 定义树节点的数据结构
typedef struct BSTreeNode
{
    void * value;
    struct BSTreeNode* left;
    struct BSTreeNode* right;
    struct BSTreeNode* parent;
} BSTreeNode;

// 定义树的数据结构
typedef struct BSTree
{
    BSTreeNode* root;
    int size;
    int curr_size;
} BSTree;


BSTREE_API BSTree* create_bstree();
BSTREE_API int tree_insert(BSTree* T,void* value);
BSTREE_API int tree_delete(BSTree* T,void* value);
BSTREE_API BSTreeNode* tree_search(const BSTree* T,void* value);

BSTREE_API int tree_height(const BSTreeNode* root);
BSTREE_API BSTreeNode* tree_max_node(BSTreeNode* root);
BSTREE_API BSTreeNode* tree_min_node(BSTreeNode* root);

// 其他函数
void before_traverse(const BSTreeNode* root);
void print_node(const void* value);





#endif /* BSTree_h */
