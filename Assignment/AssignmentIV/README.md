# Assignment IV: Hash Function Design & Observation

## 執行環境
- windows visual studio 2022

## 設計概念
- int myHashInt(int key, int m) {
    
	key *= 4000000007UL;
	if (key < 0) key = -key; 
    return key % m;
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 1;
    for (char c : str) {
        int val = (int)c;   
        hash *= val ;
    }
    hash *= 4000000007UL;
    return static_cast<int>(hash % m);  
}

 integer乘以一極大的質數。
 string 先換成ASCII，一樣乘以一個極大數質數。
 參考資料:https://medium.com/swlh/why-should-the-length-of-your-hash-table-be-a-prime-number-760ec65a75d1
## 結果
<img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/99ee7c34-ab6e-4df1-8a31-81c638d0ffb2" />
<img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/08669909-7396-48f2-8247-2fed0ce5198a" />
<img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/9363fb85-c0fa-43ff-850f-52ba9729e125" />


