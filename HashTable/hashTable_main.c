//
// Created by 苏汉宇 on 17/6/27.
// 数据结构之 哈希表
//

#include <stdio.h>
#include <stdlib.h>
#include "hashTable.c"

int main(){
    char key[] = "k1";
    int num1 = 499;
    char s1[5] = "test";
    sprintf(s1, "k%d", num1);
    // 测试,打印出存储在字符指针中的字符串
//    char* str1 = "where is ";
//    printf("string is :%s\n", str1);


//    printf("key is : %s\n", s1);
    // 创建哈希表
    HashTable* ht = create_hash_table();

    for (int i = 500; i > 499; --i) {
        sprintf(s1, "k%d", i);
        hash_put(ht, s1, i+11);
    }

    // 测试hash_find
    HashNode* hn = hash_find(ht, "k500");
    printf("node value: %d\n",hn->value);


    // 测试 打印hash表中存储的值
//    int code = hashcode("k500");
//    printf("code is : %d\n", code);
//    printf("key code is :%d\n", ht->Node[code]->value);

    printf("hello world!-----\n");
    return 0;
}


/**
 * 遇到的一些问题
 * 1.memset原型：void *memset(void *buffer, int c, int count);
　 功能：把buffer所指内存区域的前count个字节设置成字符c。
　 说明：返回指向buffer的指针。
 * 2.查看实例 http://blog.csdn.net/feixiaoxing/article/details/6885657
 * 3.打印size_t的数据类型时的占位符是%zu
 * 4.标准库中的strlen函数的巧妙实现
 * 5.打印字符指针中存储的字符串 可以直接  char* str1 = "where is ";printf("string is :%s\n", str1);
 * 因为,printf是从首地址开始打印,直到'\0'结束
 *
 */

