//
//  main.c
//  BSTree
//
//  Created by 苏汉宇 on 17/2/14.
//  Copyright © 2017年 苏汉宇. All rights reserved.
//

/*
 
 
 */




#include "BSTree.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    BSTree *T = create_bstree();
    T->curr_size = 0;
    int* data = NULL;
    int arr[10] = {12,34,1,65,75,21,42};
    // 插入3个节点
    for(int i=0;i<2;i++){
        data = (int *)malloc(sizeof(int));
        *data = arr[i];
        tree_insert(T, data);
        
    }
    
    before_traverse(T->root);
    
    
    
    
    printf("Hello, World!1111\n");
    return 0;
}
