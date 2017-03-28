//
//  main.c
//  AVL-tree
//
//  Created by 苏汉宇 on 17/3/23.
//  Copyright © 2017年 苏汉宇. All rights reserved.
//

/*
-----------------------------平衡二叉树-------------------------------------------------------------------------
* 一些概念  空节点 叶子节点 非叶子节点 树的高度
* 参考资料 http://www.cnblogs.com/huangxincheng/archive/2012/07/22/2603956.html
* 定义 父节点的左子树和右子树的高度之差不能大于1
* 平衡因子BF（Balanced Factor）定义为该结点的左子树与右子树的高度之差
* 根据AVL树的定义，AVL树中的任意结点的平衡因子只可能是-1
 
* 找下一个节点，是找左节点
* 找上一个节点，是找右节点

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset 为了解决使用memset时有warning提示的问题 */
#include "avl-tree.h"



int myCmpFunc(AvlTreeNode* n1, AvlTreeNode* n2)
{
    
    return INT_VAL(n1->myvalue) - INT_VAL(n2->myvalue);
}

static void InitMydataArray(AvlTreeNode* pArr, int nSize);

int main(int argc, const char * argv[]) {
    
    int tmpBf;
    AvlTreeNode* tmpRes;
    AvlTree* T = (AvlTree *)malloc(sizeof(AvlTree *));
    AvlTreeNode* dataArr = (AvlTreeNode *)malloc(10*sizeof(AvlTreeNode));
    // zero memory
    memset(dataArr, 0, 10 * sizeof(AvlTreeNode));
    
//    printf("T的地址是%p--\n",T->root);
    eg_avltree_init(T, myCmpFunc);
    InitMydataArray(dataArr, 10);
    printf("avlNode size is %lu\n",sizeof(AvlTreeNode));
    
    eg_avltree_insert(T, &dataArr[0]);
    tmpBf = getBalanceFactory(T->root);
    printf("root bf is %d\n",tmpBf);
    if (tmpBf >= 2 || tmpBf <= -2) {
        tmpRes = rotate_left(T->root);
        printf("new root val is %d\n",INT_VAL(tmpRes->myvalue));
    }
    
    
    eg_avltree_insert(T, &dataArr[1]);
    //eg_avltree_insert(T, &dataArr[2]);
    tmpBf = getBalanceFactory(T->root);
    printf("root bf is %d\n",tmpBf);
    if (tmpBf >= 2 || tmpBf <= -2) {
        tmpRes = rotate_left(T->root);
        printf("new root val is %d\n",INT_VAL(tmpRes->myvalue));
    }
    
    
    /*
    for (int i=0; i<2; i++) {
        eg_avltree_insert(T, dataArr[i]);
        printf("the avlNode is:%d \n", INT_VAL(dataArr[i]));
        
    }*/
    
    
    printf("Hello, World!\n");
    return 0;
}

// 初始化
static void InitMydataArray(AvlTreeNode* pArr, int nSize)
{
    int i, j;
    void* tmp;
    
    // 按顺序填充值
    for (i=0; i<nSize; i++){
        pArr[i] = *(AvlTreeNode *)malloc(sizeof(AvlTreeNode *)); 
        int* pval = malloc(sizeof(int *));
        *pval = i;
        pArr[i].myvalue = pval;
        pArr[i].left = NULL;
        pArr[i].right = NULL;
        pArr[i].parent = NULL;
        pArr[i].balanceFactor = 0;
    }
    
    // random suffle
    for (i=0; i<nSize; i++)
    {
        j = rand() * (double)(nSize-1) / RAND_MAX;
        tmp = pArr[i].myvalue;
        pArr[i].myvalue = pArr[j].myvalue;
        pArr[j].myvalue = tmp;
    }
}
