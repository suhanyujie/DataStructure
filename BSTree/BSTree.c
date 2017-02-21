//
//  BSTree.c
//  BSTree
//
//  Created by 苏汉宇 on 17/2/14.
//  Copyright © 2017年 苏汉宇. All rights reserved.
//

/*
 1.将BSTree.h文件中定义的函数进行实现
 2.关于二叉树
    * 节点比较 right > parent > left
 
    * 分为：
    前序遍历  先访问根节点------左子树------右子树
    中序遍历  左子树---根节点---右子树
    后序遍历   左子树---右子树---根节点
 
 
 
 
 
 
 */


#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

// 实现 创建二叉树
BSTREE_API BSTree* create_bstree()
{
    BSTree* T = (BSTree *)malloc(sizeof(BSTree));
    if(T == NULL){
        return NULL;
    }
    T->root = NULL;
    T->size = INIT_SIZE;
    
    return T;
}


// 执行插入
void do_insert(BSTree* T, BSTreeNode* newNode)
{
    BSTreeNode* current = T->root;
    BSTreeNode* insertParent = NULL;
    // 遍历节点
    while (current != NULL) {
        printf("do_insert...\n");
        insertParent = current;
        if( INT_VAL(newNode->value) > INT_VAL(insertParent->value) ){
            current = current->right;
        }else{
            current = current->left;
        }
    }
    newNode->parent = insertParent;
    if(insertParent == NULL){
        T->root = newNode;
    } else if (INT_VAL(newNode->value) < INT_VAL(insertParent->value)){
        insertParent->left = newNode;
    } else {
        insertParent->right = newNode;
    }
}

// 节点插入的相关操作
BSTREE_API int tree_insert(BSTree* T,void* value)
{
    BSTreeNode* newNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
    if(newNode == NULL){
        return FAILED;
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    do_insert(T, newNode);
    T->curr_size++;
    
    return SUCCESS;
}
// 实现打印树节点
void print_node(const void* value)
{
    printf("%d\n", *((int*)value));
}

// 前序遍历
void before_traverse(const BSTreeNode* root)
{
    if(IS_NULL(root)){
        return;
    }
    print_node(root->value);
    // test
    //root = root->right;
    //printf("1.0是不是空：%d\n", (int)(root == NULL));
    //printf("1.1是不是空：%d\n", *(int *)root->value);
    //return;
    before_traverse(root->left);
    before_traverse(root->right);

}
// 中序遍历
void middle_traverse(const BSTreeNode* root)
{
    if(root == NULL){
        return;
    }
    middle_traverse(root->left);
    print_node(root->value);
    middle_traverse(root->right);
    
}
// 后序遍历
void after_traverse(const BSTreeNode* root)
{
    if(root == NULL){
        return;
    }
    after_traverse(root->left);
    after_traverse(root->right);
    print_node(root->value);
    
}

// 二叉树 是否已满
BSTREE_API bool is_full(const BSTree* T)
{
    return T->size == T->curr_size;
}

//判断树是否空
BSTREE_API bool is_empty(const BSTree* T)
{
    return T->curr_size == 0;
}






