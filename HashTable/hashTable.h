//
// Created by 苏汉宇 on 17/6/27.
//

#ifndef DATASTRUCTURE_HASHTABLE_H
#define DATASTRUCTURE_HASHTABLE_H


#include <jmorecfg.h>
#include <stdbool.h>

#define HASHTABLE_SIZE  10
#define SUCCESS 1
#define FAILED 0
#define IS_NULL(x) (bool)(x == NULL)

// hash节点的结构
typedef struct HashNode{
    struct HashNode* next;
    char* key;
    int value;
} HashNode;

// hash表
typedef struct HashTable {
    HashNode* Node[HASHTABLE_SIZE];
}HashTable;


//创建1个空的的hashTable
HashTable* create_hash_table();
// 根据key获取值 查找hash节点
HashNode* hash_find(HashTable* ht, char* key);
// 向hash表中存放数据
int hash_put(HashTable* ht, char* key, int data);
// 释放hash节点 【暂未实现】
void hash_free();
// 释放hash表  【暂未实现】
void hashTable_free();
// 打印HashTable  【暂未实现】
void print_hashTable(HashTable* ht);




#endif //DATASTRUCTURE_HASHTABLE_H
