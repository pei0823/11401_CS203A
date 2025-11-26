# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++.
Students are expected to implement and analyze the behavior of hash functions, evaluate their efficiency, and understand their applications in computer science.

**Developer:** 林沛陞
**Email:** [easonlin0925250286@gmail.com](mailto:easonlin0925250286@gmail.com)
**使用環境:** Windows

---

## My Hash Function

### Integer Keys

* **Formula / Pseudocode:**

```cpp
int myHashInt(int key, int m) {
    key *= 4000000007UL;
    if (key < 0) key = -key;
    return key % m;
}
```

* **Rationale:**
  用一個極大的質數來乘以 key，這樣不管 m 是多少都能夠實現不規律的雜湊。

### Non-integer Keys

* **Formula / Pseudocode:**

```cpp
unsigned long hash = 1;
for (char c : str) {
    int val = (int)c;   
    hash *= val;
}
hash *= 4000000007UL;
return static_cast<int>(hash % m);  // basic division method
```

* **Rationale:**
  同 integer，但字串會先換成 ASCII，再乘以極大的質數。
* **參考資料:** [Why should the length of your hash table be a prime number](https://medium.com/swlh/why-should-the-length-of-your-hash-table-be-a-prime-number-760ec65a75d1)

---

## Experimental Setup

* **Table sizes tested (m):** 10, 11, 37
* **Test dataset:**

  * Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  * Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
* **Compiler:** GCC and G++
* **Standard:** C23 and C++23

---

## Results

| Table Size (m) | Index Sequence      | Observation              |
| -------------- | ------------------- | ------------------------ |
| 10             | 1, 2, 3, 4, ...     | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...    | More uniform             |
| 37             | 20, 21, 22, 23, ... | Near-uniform             |

---

## Compilation, Build, Execution, and Output

### Compilation

* 使用 Makefile:

```bash
# Build both C and C++ versions
make all

# Build only C version
make c

# Build only C++ version
make cxx
```

### Manual Compilation (if needed)

* **C:**

```bash
gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
```

* **C++:**

```bash
g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
```

### Clean Build Files

```bash
make clean
```

### Execution

```cpp
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

或 C++ 版本：

```cpp
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
    return static_cast<int>(hash % m);
}
```

---

## Result Snapshot

### Example output for integers

```
=== Hash Function Observation (C Version) ===

=== Table Size m = 10 ===
Key     Index
-----------------
21      3
22      4
23      5
24      6
...
```

### Example output for strings

```
=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     4
bat     2
cow     5
...
```

### Images

<img src="https://github.com/user-attachments/assets/99ee7c34-ab6e-4df1-8a31-81c638d0ffb2" width="800" height="900" />
<img src="https://github.com/user-attachments/assets/08669909-7396-48f2-8247-2fed0ce5198a" width="800" height="900" />
<img src="https://github.com/user-attachments/assets/9363fb85-c0fa-43ff-850f-52ba9729e125" width="800" height="900" />

* **Observations:** Outputs align with the analysis, showing better distribution with prime table sizes.

---

## Analysis

### Prime vs Non-prime `m`

* 質數會表現得比非質數好，索引較均勻分布，collision 減少。
* 例如，若 m = 18(2*3*3)，key 被 m 抓到的機率較高，collision 增加。

### Patterns or Collisions

* **Linear Probing:** 容易造成 index 重複，collision 上升。
* **Separate Chaining:** 接受 collision，用 linked list 串起，但搜尋元素時間複雜度隨鏈長可降至 O(n)。
* **Open Addressing:** 可減少 collision，但越滿效率顯著下降。

### Improvements

* key 比表格 size 多，可減少 collision。
* 增加碰撞處理長度。
* 參考: [iThome article](https://ithelp.ithome.com.tw/articles/10367225)

---

## Reflection

1. Table size 應比 key 多。
2. 不直接使用 `index = key % m`，避免重複。
3. 建議 Open Addressing 配合 Separate Chaining，如鏈不夠長或碰撞太多可加長。
