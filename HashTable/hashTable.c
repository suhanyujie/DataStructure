//
// Created by 苏汉宇 on 17/6/27.
//

#include "hashTable.h"
#include <stdlib.h>
#include <string.h>

static int hashcode(const char *s)
{
    int len = strlen(s);
    const unsigned char *name = (const unsigned char *)s;
    unsigned long h = 0, g;
    int i;

    for(i=0;i<len;i++)
    {
        h = (h << 4) + (unsigned long)(name[i]); //hash左移4位，当前字符ASCII存入hash
        if ((g = (h & 0xF0000000UL))!=0)
            h ^= (g >> 24);
        h &= ~g;  //清空28-31位。
    }
    h = (int)h % HASHTABLE_SIZE;

    return h;
}
// 创建hashTable
HashTable* create_hash_table()
{
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    // 初始化新申请的内存空间
    memset(hashTable, 0, sizeof(HashTable));
    if(IS_NULL(hashTable))return NULL;

    return hashTable;
}

// 根据键 获取值
HashNode* hash_find(HashTable* ht, char* key)
{
    if(IS_NULL(ht))return NULL;
    HashNode* pNode;
    // 根据键 用函数运算出索引值
    int code = hashcode(key);
//    printf("%s-->%d\n", key, code);
    pNode = ht->Node[code % HASHTABLE_SIZE];
    if(IS_NULL(pNode))return NULL;
    while (pNode)
    {
        if (*(pNode->key) == *key)
        {
            return pNode;
        }
        pNode = pNode->next;
    }
    return NULL;
}

// 向hashTable中加数据
int hash_put(HashTable* ht, char* key, int data)
{
    HashNode* pNode;
    size_t code = hashcode(key);
//    printf("the code is %d\n", code);
    if(IS_NULL(ht))return FAILED;
    if(IS_NULL(ht->Node[ code ])){
        pNode = (HashNode*)malloc(sizeof(HashNode));
        pNode->value = data;
        pNode->key = key;
        ht->Node[ code ] = pNode;
        return SUCCESS;
    }
    // 是否已经存在这个值了
    if(!IS_NULL(hash_find(ht, key))){
        return FAILED;
    }
    // 这里说明已经碰撞了,往对应的链表中放了
    pNode = ht->Node[ code ];
    while(!IS_NULL(pNode->next)){
        pNode = pNode->next;
    }
    pNode->next = (HashNode*)malloc(sizeof(HashNode));
    pNode->next->value = data;

    return SUCCESS;
}
// 打印HashTable
void print_hashTable(HashTable* ht)
{
    if( !IS_NULL(ht) ){
        for (int i = 0; i < HASHTABLE_SIZE; ++i) {
            printf("%d\n", ht->Node[i]->value);
        }
    }
}















