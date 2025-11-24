/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
key *= 4000000007UL; 
if (key < 0) key = -key;
return key % m;
}

int myHashString(const char* str, int m) {
unsigned long hash = 1;
for (int i = 0; str[i] != '\0'; i++) {
unsigned int val = (unsigned char)str[i]; 
hash *= val; 
}
hash *= 4000000007UL; 
if (hash < 0) hash = -hash;
return (int)(hash % m);
}
