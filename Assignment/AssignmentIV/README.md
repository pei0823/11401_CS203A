# Assignment IV: Hash Function Design & Observation

## 執行環境
- windows visual studio 2022

## 設計概念
```cpp
// Hash function for integer keys
int myHashInt(int key, int m) {
    key *= 4000000007UL;  // 乘以極大質數
    if (key < 0) key = -key; 
    return key % m;
}

// Hash function for string keys
int myHashString(const std::string& str, int m) {
    unsigned long hash = 1;
    for (char c : str) {
        int val = (int)c;   
        hash *= val;  // 累乘 ASCII 值
    }
    hash *= 4000000007UL;  // 再乘以極大質數
    return static_cast<int>(hash % m);  
}
```
integer乘以一極大的質數。
string 先換成ASCII，一樣乘以一個極大數質數。
參考資料: [https://medium.com/swlh/why-should-the-length-of-your-hash-table-be-a-prime-number-760ec65a75d1```](https://medium.com/swlh/why-should-the-length-of-your-hash-table-be-a-prime-number-760ec65a75d1)

## 結果
<img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/99ee7c34-ab6e-4df1-8a31-81c638d0ffb2" /> <img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/08669909-7396-48f2-8247-2fed0ce5198a" /> <img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/9363fb85-c0fa-43ff-850f-52ba9729e125" />
Size 越大、index 重複率越低：key 和 index 之間有一定關係，在 size 越小的情況下越明顯。

最好的情況是 random。如果當前 index 已經有東西了，那就再次取一次隨機值。
如 case 數超出 size，則可接受每個 index 收 case/size 個東西。
這種方法能確保所有 index 不重複且完全隨機，但每次執行結果都不同。

如果用我的方法，key 做越多處理越好，數字越大、越奇怪，效果越好。
