# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: 林沛陞
Email: easonlin0925250286@gmail.com
使用環境:windows

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  int myHashInt(int key, int m) {
    
	key *= 4000000007UL;
	if (key < 0) key = -key; 
    return key % m;
}

  ```
- Rationale: 用一個極大的質數來乘以key，這樣不管m是多少都能夠實現不規律的雜湊。 

### Non-integer Keys
- Formula / pseudocode:
  ```text
  unsigned long hash = 1;
    for (char c : str) {
        int val = (int)c;   
        hash *= val ;
    }
    hash *= 4000000007UL;
    return static_cast<int>(hash % m);  // basic division method
  ```
- Rationale: 同integer，但字串會先換成ASCII在乘以極大的質數。
- 參考資料: [https://medium.com/swlh/why-should-the-length-of-your-hash-table-be-a-prime-number-760ec65a75d1```](https://medium.com/swlh/why-should-the-length-of-your-hash-table-be-a-prime-number-760ec65a75d1)

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
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
  ```
  or
  ```bash
  #include "hash_fn.hpp"

int myHashInt(int key, int m) {
    
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
    return static_cast<int>(hash % m);  // basic division method
}
  ```

### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

 === Table Size m = 10 ===
Key     Index
-----------------
21      3
22      4
23      5
24      6
25      7
26      8
27      9
28      0
29      1
30      8
51      5
52      6
53      7
54      8
55      9
56      0
57      1
58      2
59      7
60      6

=== Table Size m = 11 ===
Key     Index
-----------------
21      6
22      8
23      7
24      6
25      5
26      4
27      3
28      2
29      1
30      0
51      9
52      8
53      7
54      6
55      5
56      4
57      3
58      2
59      10
60      0

=== Table Size m = 37 ===
Key     Index
-----------------
21      20
22      28
23      32
24      36
25      3
26      7
27      11
28      15
29      19
30      14
51      10
52      14
53      18
54      22
55      26
56      30
57      34
58      1
59      32
60      28

  === Hash Function Observation (C++ Version) ===

  === Table Size m = 10 ===
Key     Index
-----------------
21      3
22      4
23      5
24      6
25      7
26      8
27      9
28      0
29      1
30      8
51      5
52      6
53      7
54      8
55      9
56      0
57      1
58      2
59      7
60      6

=== Table Size m = 11 ===
Key     Index
-----------------
21      6
22      8
23      7
24      6
25      5
26      4
27      3
28      2
29      1
30      0
51      9
52      8
53      7
54      6
55      5
56      4
57      3
58      2
59      10
60      0

=== Table Size m = 37 ===
Key     Index
-----------------
21      20
22      28
23      32
24      36
25      3
26      7
27      11
28      15
29      19
30      14
51      10
52      14
53      18
54      22
55      26
56      30
57      34
58      1
59      32
60      28
  ```

- Example output for strings:
  ```
  === String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     4
bat     2
cow     5
ant     4
owl     6
bee     0
hen     8
pig     8
fox     8

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     7
dog     0
bat     5
cow     9
ant     6
owl     6
bee     6
hen     7
pig     9
fox     5

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     20
dog     35
bat     32
cow     33
ant     15
owl     23
bee     23
hen     6
pig     17
fox     32
  ```
<img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/99ee7c34-ab6e-4df1-8a31-81c638d0ffb2" /> <img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/08669909-7396-48f2-8247-2fed0ce5198a" /> <img width="800" height="900" alt="image" src="https://github.com/user-attachments/assets/9363fb85-c0fa-43ff-850f-52ba9729e125" />
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
### Prime vs non-prime `m`: 
- 質數會表現得比非質數好，會較為分散；以 key%m 為例 ，可以打散key，使索引均勻分布在整個表格中，collision 減少，但如果m是18(2*3*3)，被m抓到的機率更高，collision 提高。
### Patterns or collisions:
- Linear Probing:容易造成 index 重複，collision 上升。
- Separate Chaining: 接受collision，用link list 串起來，但搜尋特定元素的時間複雜度可隨著鏈條變長而降至 O（n）
- Open Addressing : 雖然能大程度減少collision， 但越滿效率會顯著下降。
### Improvements:
- 理想狀態會是key比空格還多，這樣就會減少collision 的可能。
- 加大碰撞處理
- https://ithelp.ithome.com.tw/articles/10367225

## Reflection
1. size 比 key 多
2. 不用index = key % m 容易造成重複。
3. Open Addressing 配上Separate Chaining ，如鍊不夠長或是碰撞太多再加長。
