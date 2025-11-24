/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    
	key *= 2654435761; // Knuth's multiplicative method
	if (key < 0) key = -key; // ensure non-negative
    return key % m;
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    for (char c : str) {
        int val = (int)c;   // 將字元轉成對應的 ASCII 數字
        hash += val * 2654435761;
    }
    return static_cast<int>(hash % m);  // basic division method
}
