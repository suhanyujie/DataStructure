//
//  avl-tree.c
//  AVL-tree
//
//  Created by 苏汉宇 on 17/3/23.
//  Copyright © 2017年 苏汉宇. All rights reserved.
//

#include "avl-tree.h"


//声明辅助函数
// forward declaration of helper functions
static void AdjustAfterIns(struct eg_avltree *tree, struct eg_avltree_node *son, struct eg_avltree_node *curr, int hc);
// static void AdjustAfterDel(struct eg_avltree *tree, struct eg_avltree_node *curr, int hc);
// static void Swap(struct eg_avltree_node *n1, struct eg_avltree_node *n2, struct eg_avltree *tree);

//初始化
void eg_avltree_init(AvlTree* T, eg_avltree_compare_func pf)
{
    T->root = NULL;
    T->cmpfunc = pf;
}

//平衡树第一个节点
AvlTreeNode* eg_avltree_first(AvlTree* T)
{
    AvlTreeNode* root = T->root;
    if(root){
        return root->left;
    }
    return root;
}

//最后一个节点
AvlTreeNode* eg_avltree_last(AvlTree* T)
{
    AvlTreeNode* root = T->root;
    if (root->right) {
        root = root->right;
    }
    
    return root;
}

//下一个节点
AvlTreeNode* eg_avltree_next(AvlTreeNode* node)
{
    if (node->right) {
        for (node = node->right; node->left; node = node->left);
    }
    return node;
}

//上一个节点
AvlTreeNode* eg_avltree_prev(AvlTreeNode* node){
    
    return node;
}

//插入节点实现
AvlTreeNode* eg_avltree_insert(AvlTree* T, AvlTreeNode* node)
{
    
    printf("1.value是：%d\n",INT_VAL(node->myvalue));
    if(!T->root){
        T->root = node;
        return T->root;
    }
    AvlTreeNode* root = T->root;
    AvlTreeNode* parent;
    AvlTreeNode* curNode;
    int res = 0,hc;
    
    //        创建新节点
    if (!root) {
        root = node;
        root->parent = NULL;
        return root;
    }
    curNode = root;
    parent = curNode;
    //    不允许相同的节点出现
    while (1) {
        // 插入的节点大于当前节点-1，否则+1
        res = T->cmpfunc(node, curNode);
        printf("节点cmp后的差是：%d\n",res);
        if(res > 0){
            if(curNode->right){
                curNode = curNode->right;
            }else{
                curNode->right = node;
                hc = (curNode->balanceFactor)--;
                break;
            }
        }else if (res < 0){
            if(curNode->left){
                curNode = curNode->left;
            }else{
                curNode->left = node;
                hc = (curNode->balanceFactor)++;
                break;
            }
        }else{
            printf("已经存在这个节点了！！");
            return curNode;
        }
    }
    node->parent = curNode;
    
    printf("curNode bf is:%d\n",curNode->balanceFactor);
    
    // 插入之后，旋转进行调整
    AdjustAfterIns(T, node, curNode, hc);
    
    return node;
}


// 旋转调整二叉树的平衡度
static void AdjustAfterIns(AvlTree* T,AvlTreeNode* node,AvlTreeNode* curNode,int hc)
{
    while (hc) {
        node = curNode;
        curNode = curNode->parent;
        if (!curNode) {
            break;
        }
        // L型
        if (node==curNode->left) {
            if(curNode->balanceFactor >= 0){
                
            }
            
        }else{
            // node==curNode->right
            if (curNode->balanceFactor <= 0) {
                hc = (curNode->balanceFactor)++;
            }else{
                AvlTreeNode* p1 = curNode->parent;
                if (hc > 0) {
                    if (!p1) {
                        T->root = node;
                    }else if(p1->left == curNode){
                        p1->left = node;
                    }else{
                        p1->right = node;
                    }
                    node->parent = p1;
                }
            }
            
        }
    }

}

int getBalanceFactory(AvlTreeNode* node)
{
    int leftHeight,rightHeight;
    leftHeight = height(node->left);
    rightHeight = height(node->right);
    
    return (leftHeight-rightHeight);
}

int height(AvlTreeNode* node)
{
    if (!node) {
        return 0;
    }
    int leftHeight,rightHeight;
    leftHeight = height(node->left);
    rightHeight = height(node->right);
    
    return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
}

AvlTreeNode* rebalance(AvlTreeNode* node)
{
    
    return node;
}

/**
 i. 将2作为根结点
 
 ii. 将1作为2的左孩子
 
 iii. 将2的左孩子作为1的右孩子（维护树的有序性，只是此处为NULL而已） !important
 */
AvlTreeNode* rotate_left(AvlTreeNode* root)
{
    AvlTreeNode* tmpNode;
    AvlTreeNode* curNode;
    curNode = root->right;
    tmpNode = root->parent;
    if (tmpNode) {
        if (tmpNode->left == root) {
            tmpNode->left = curNode;
        }else{
            tmpNode->right = curNode;
        }
    }
    // 关键的几步！！！  看了好久啊
    curNode->parent = tmpNode;
    root->right = curNode->left;
    curNode->left = root;
    
    return curNode;
}

AvlTreeNode* rotate_right(AvlTreeNode* root)
{
    AvlTreeNode* curNode = root->left;
    AvlTreeNode* tmpNode = root->parent;
    
    if (tmpNode) {
        if (tmpNode->left == root) {
            tmpNode->left = curNode;
        }else{
            tmpNode->right = curNode;
        }
    }
    curNode->right = root;
    root->left = curNode->right;
    root->parent = curNode;
    
    return curNode;
}


















//struct mydata
//{
//    int myvalue1;
//    struct eg_avltree_node avlnode;
//};








