//
//  avl-tree.h
//  AVL-tree
//
//  Created by 苏汉宇 on 17/3/23.
//  Copyright © 2017年 苏汉宇. All rights reserved.
//

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include <stdio.h>

#define BASEPTR_TO_DERIVEDPTR(baseptr, derivedtype, basemember) ((derivedtype*)(((char*)baseptr)-(int)&((((derivedtype*)0)->basemember))))

#define INT_VAL(pvalue) *(int *)(pvalue)

//平衡树节点结构
typedef struct eg_avltree_node
{
    struct eg_avltree_node *parent;           // parent node pointer
    struct eg_avltree_node *left;            // left node pointer
    struct eg_avltree_node *right;            // right node pointer
    int balanceFactor;                       // balance factor (-1, 0, +1)
    void* myvalue;
} AvlTreeNode,*pAvlTreeNode;

// 比较函数-prototype for user defined comparison function
typedef int (*eg_avltree_compare_func)(AvlTreeNode* n1, AvlTreeNode* n2);

// 平衡树结构
typedef struct eg_avltree
{
    AvlTreeNode* root;         // root node pointer
    eg_avltree_compare_func cmpfunc;      // compare function pointer
} AvlTree;

// 平衡树相关函数的定义
//平衡树初始化函数
void eg_avltree_init(AvlTree* tree, eg_avltree_compare_func pf);


//平衡树第一个节点
AvlTreeNode* eg_avltree_first(AvlTree* tree);

//平衡树最后一个节点
AvlTreeNode* eg_avltree_last(AvlTree* tree);
//获取下一个节点
// returns next node (0 if no next node)
AvlTreeNode* eg_avltree_next(AvlTreeNode* node);
//获取上一个节点
// returns previous node (0 if no previous node)
AvlTreeNode* eg_avltree_prev(AvlTreeNode* node);
//节点插入
// insert node to tree
AvlTreeNode* eg_avltree_insert(AvlTree* tree, AvlTreeNode* node);

AvlTreeNode* rotate_left(AvlTreeNode* root);
AvlTreeNode* rotate_right(AvlTreeNode* root);

// 获取节点的平衡因子
int getBalanceFactory(AvlTreeNode* node);
// 获取某个节点 它的字树的高度
int height(AvlTreeNode* node);
// 通过旋转，将某个子节点的树进行平衡
AvlTreeNode* rebalance(AvlTreeNode* node);



#endif /* _AVL_TREE_H_ */
