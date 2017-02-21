//
//  main.c
//  LinkedList
//
//  Created by 苏汉宇 on 17/1/25.
//  Copyright © 2017年 苏汉宇. All rights reserved.
//
/*
 
 1.单项链表
 * 一个单向链表的节点被分成两个部分。第一个部分保存或者显示关于节点的信息，第二个部分存储下一个节点的地址。单向链表只可向一个方向遍历。
 * 链表最基本的结构是在每个节点保存数据和到下一个节点的地址
 
 * 功能：创建链表，插入新节点，删除节点，修改节点
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* memset 为了解决使用memset时有warning提示的问题 */
#include <unistd.h> /* close */

#include <assert.h>

#define LinkedListAPI
#define IS_NULL(x) ((x) == NULL)

// 节点
typedef struct LinkNode {
    void *value;
    struct LinkNode *next;
} LinkNode;

// 管理节点
typedef struct List {
    int (*compare)(void *const, void *const);
    
    struct LinkNode *head;
    struct LinkNode *tail;
    size_t length;
} List;

// 函数Api定义
//返回链表的长度
LinkedListAPI size_t list_length(const List* const L)
{
    return L->length;
}
// 创建链表
LinkedListAPI List* list_create(int (*compare)(void *const, void *const))
{
    List* L = malloc(sizeof(List));
    if(IS_NULL(L)){
        perror("malloc list failed\n");
    }else{
        printf("malloc list success\n");
        memset(L, 0, sizeof(List));
        L->length = 0;
        L->compare = compare;
        L->head = L->tail = NULL;
    }
    
    return L;
}
//链表的初始化
LinkedListAPI void list_init(List* L, int num)
{
    if(num < 1)perror("param num have to bigger than 1!\n ");
    LinkNode* p = NULL;
    LinkNode* r = NULL;
    int* tmpValue = NULL;
    // 如果一开始是空链表，则将第一个元素设为头节点
    for(int i = 0;i<num;i++){
        LinkNode* pNewNode = malloc(sizeof(LinkNode));
        if(L->length == 0){
            tmpValue = malloc(sizeof(int));
            *tmpValue = i;
            pNewNode->value = tmpValue;
            pNewNode->next = NULL;
            L->head = pNewNode;
            L->tail = NULL;
        }else{
            // 断言测试-----
            assert(L->head != NULL);
            // 循环到链表的tail，在最后 添加节点
            p = L->head;
            while( !IS_NULL(p) ){
                //printf("%d\n",*(int *)p->value);
                r = p;
                p = p->next;
            }
            
            tmpValue = malloc(sizeof(int));
            *tmpValue = i;
            pNewNode->value = tmpValue;
            pNewNode->next = NULL;
            
            r->next = pNewNode;
        }
        
        L->length++;
        r = pNewNode;
        
        //printf("%zu\n",L->length);
        //printf("%d\n",*(int *)L->head->value);
        //printf("%d\n",*(int *)L->head->next->value);
    }

}
// 插入节点
LinkedListAPI void list_insert(List* L, void *const value)
{
    if(IS_NULL(value)){
        perror("List is null\n");
    }
    LinkNode* node = malloc(sizeof(LinkNode));
    if(IS_NULL(node)){
        perror("malloc is err\n");
    }
    node->value = value;
    node->next = NULL;
    if(L->length==0){
        L->head = node;
        L->tail = node;
        L->length++;
        return;
    }
    L->length++;
    LinkNode* p = L->head;
    while (p) {
        if (L->compare(p->value,value) == -1) {
            p = p->next;
        } else {
            break;
        }
    }
    if (IS_NULL(p)) {
        L->tail->next = node;
        L->tail = node;
    } else {
        node->next = p->next;
        p->next = node;
    }
    
    return ;
}

//比较
int cmp(void *const a, void *const b)
{
    int *val1 = (int *)a;
    int *val2 = (int *)b;
    
    return (*val1 > *val2) - (*val1 < *val2);
}

//回调-打印
void visit(void* value)
{
    printf("[%d]->",*(int *)value);
}
//删除节点 n表示位置
LinkedListAPI void delete_node(List* L, void* const value)
{
    LinkNode* p = L->head;
    LinkNode* q = NULL;
//    visit(value);
    int i = 0;
    while(!IS_NULL(p)){
        if(cmp(p->value, value) == 0){
            q->next = p->next;
            L->length--;
            free(p);
            break;
        } else {
            q = p;
            p = p->next;
        }
        i++;
    }
    return;
}
//更新节点，修改节点
LinkedListAPI void list_update(List* L, int* pOldValue, int* newValue)
{
    LinkNode* p = L->head;
    int i = 0;
    
    while (p) {
        if(cmp(p->value, pOldValue) == 0){
            p->value = newValue;
        }else{
            p = p->next;
        }
        if(i>20)break;
        i++;
    }
}
//打印
LinkedListAPI void list_traversal(List *const L, void (*visit_func)(void* const))
{
    if(IS_NULL(L->head)){
        printf("list is null~\n");
    }
    LinkNode* p = L->head;
    while(!IS_NULL(p)){
        visit_func(p->value);
        p = p->next;
    }
}
//入口函数
int main(int argc, const char * argv[]) {
    List* L = list_create( &cmp );
    // eg 2
    list_init(L, 6);
    
    
    
    // eg 1
//    int* key = NULL;
//    for (int i=0; i<10; i++) {
//        key = malloc(sizeof(int));
//        *key = i;
//        list_insert(L, key);
//    }
//    int *num1 = NULL;
//    num1 = malloc(sizeof(int));
//    *num1 = 13;
//    int* pPosition = NULL;
//    pPosition = malloc(sizeof(int));
//    *pPosition = 3;
//    list_update(L, pPosition, num1);
//    //delete_node(L, num);
    
    list_traversal(L,visit);
    
    
//    printf("Hello, World!%zu\n",L->length);
    return 0;
}
