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

// 寻找节点
BSTREE_API BSTreeNode* tree_search(const BSTree* T,void* value)
{
    BSTreeNode* root = T->root;
    while(!IS_NULL(root)){
        if(INT_VAL(root->value) == INT_VAL(value)){
            return root;
        }else if (INT_VAL(root->value) < INT_VAL(value)){
            root = root->right;
        }else{
            root = root->left;
        }
    }
    
    return root;
}

// 删除节点
int tree_delete(BSTree* T,void* value)
{
    if(IS_NULL(value))return SUCCESS;
    // 寻找这个值的节点
    BSTreeNode* pGoal = tree_search(T, value);
    if (IS_NULL(pGoal)) {
        return SUCCESS;
    }    // 删除操作
    /*
     1.没有子节点的情况
     2.有子节点的情况：先free子节点（防止内存泄漏），再free本身节点
     */
    if ( IS_NULL(pGoal->right) && IS_NULL(pGoal->left) ) {
        BSTreeNode* parent = pGoal->parent;
        if ( INT_VAL(pGoal->value) > INT_VAL(parent->value) ) {
            parent->right = NULL;
        } else {
            parent->left = NULL;
        }
        free(pGoal);
        printf("the parent val is:%d\n",INT_VAL(parent->value));
        return SUCCESS;
    } else {
        if(!IS_NULL(pGoal->left))
            tree_delete(T, pGoal->left->value);
        if(!IS_NULL(pGoal->right))
            tree_delete(T, pGoal->right->value);
        // 删完子节点时，再将自己删除
        BSTreeNode* parent = pGoal->parent;
        if ( INT_VAL(pGoal->value) > INT_VAL(parent->value) ) {
            parent->right = NULL;
        } else {
            parent->left = NULL;
        }
        free(pGoal);
        return SUCCESS;
    }
    
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
    if(IS_NULL(root)){
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

/**
 * 二叉树的高度
 * 高度是从叶节点数到它的根节点
 * 采用递归的方式 计算出树的高度
 */
int tree_height(const BSTreeNode* root)
{
    int hl = 0,hr = 0;
    if(IS_NULL(root))return 0;
    
    hl = tree_height(root->left);
    hr = tree_height(root->right);
    return hl>hr ? hl+1 : hr+1;
    
}

/**
 * 二叉树的最大节点
 */
BSTreeNode* tree_max_node(BSTreeNode* root)
{
    BSTreeNode* max = root;
    if(IS_NULL(max)){
        return max;
    }
    /*
    print_node(max->value);
    max = max->right;
    print_node(max->value);
    max = max->right;
    
    printf("是空吗：%d\n",(int)IS_NULL(max));
    return root;*/
    
    while (max->right != NULL) {
        max = max->right;
    }
    return max;
}
/**
 * 二叉树的最小节点
 */
BSTreeNode* tree_min_node(BSTreeNode* root)
{
    BSTreeNode* min = root;
    if(IS_NULL(min)){
        return min;
    }
    // !IS_NULL(min) 是错的
    while ( min->left != NULL ) {
        min = min->left;
    }
    return min;
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






