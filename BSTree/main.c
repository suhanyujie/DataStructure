//
//  main.c
//  BSTree
//
//  Created by 苏汉宇 on 17/2/14.
//  Copyright © 2017年 苏汉宇. All rights reserved.
//

/*
 1.二叉树的节点删除：
 节点删除是相对比较复杂的一种操作。
 
 
 
 
 */




#include "BSTree.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    BSTree *T = create_bstree();
    T->curr_size = 0;
    int* data = NULL;
    int arr[INIT_SIZE] = {120,134,24,  16,31,18,  39,65,75,  21,42,13,  12};
    printf("是不是空呢:%d\n",arr[14]);
    // 插入3个节点
    for(int i=0;i<INIT_SIZE;i++){
        if(arr[i] == 0)continue;
        data = (int *)malloc(sizeof(int));
        *data = arr[i];
        tree_insert(T, data);
        
    }
    
    // before_traverse(T->root);
    printf("------\n");
    int height = tree_height(T->root);
    printf("高度是：%d\n",height);
    BSTreeNode* max = tree_max_node(T->root);
    printf("节点最大的值是：");
    print_node(max->value);
    BSTreeNode* min = tree_min_node(T->root);
    printf("节点最小的值是：");
    print_node(min->value);
    
    printf("------\n");
    // 测试寻找节点
    int* var1 = NULL;
    var1 = (int *)malloc(sizeof(int));
    *var1 = 12;
    BSTreeNode* res = tree_search(T, var1);
    printf("寻找节点值为%d的父节点的值是：",INT_VAL(var1));
    print_node(res->parent->value);
    // 测试删除节点
    *var1 = 16;
    tree_delete(T, var1);
    before_traverse(T->root);
    
    
    
    
    
    printf("Hello, World!2017\n");
    return 0;
}
