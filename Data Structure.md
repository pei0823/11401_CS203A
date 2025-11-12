# Data Structure（資料結構）

---

## 定義（Definition）

> **資料結構（Data Structure）**：  
> 將資料以最有利的型態存放在記憶體中，提供策略讓電腦能**高效率地存取與處理資料**。  
> 這些資料之間的**關係與存取策略**，就稱為「資料結構」。
> A data structure is a systematic way of organizing and storing data so that it can be used efficiently.《Data Structures and Algorithm Analysis in C》

📎 參考來源：  
[HackMD - 資料結構簡介](https://hackmd.io/@howkii-studio/apcs_overview/https%3A%2F%2Fhackmd.io%2F%40howkii-studio%2Fdata_structure)

---

## 與程式設計課程的差異

| 面向 | 程式設計（Programming） | 資料結構（Data Structure） |
|------|--------------------------|-----------------------------|
| 核心重點 | 撰寫正確的程式 | 選擇最合適的資料組織方式 |
| 著重內容 | 語法、邏輯、控制流程 | 各種資料結構的設計與比較 |
| 評估重點 | 程式可讀性、正確性 | 時間與空間複雜度（效率） |
| 目的 | 讓程式「能運作」 | 讓程式「運作得更快、更省資源」 |

 例：  
若有兩個資料結構 **A** 與 **B** 都能解決同一問題，  
但若 **B 的時間複雜度或特性** 比 **A** 更好，  
→ 我們會優先選擇 **B**。

---

## 資料結構的分類

###  邏輯結構（Logical Structure）

> 描述資料之間的**邏輯關聯**與**組織方式**。

#### 線性結構（Linear Structure）
資料之間呈「一對一」的線性關係。

- **Array（陣列）**  
- **Linked List（鏈結串列）**  
- **Stack（堆疊）**  
- **Queue（佇列）**

#### 非線性結構（Non-linear Structure）
資料之間呈「一對多」或「多對多」的關係。

- **Tree（樹）**  
- **Graph（圖）**

#### 靜態結構（Static Data Structure）
具有固定記憶體大小，但容易存取，只需一個index就可以拿資料

- **Array（陣列）**
- **Stack（堆疊）**  
- **Queue（佇列）**
  
#### 動態結構（Dynamic Data Structure）
具有**不**固定記憶體大小，雖然難存取，但不須限制大小。

- **Linked List（鏈結串列）**

  
---

### 實體結構（Physical Structure）

> 資料實際在記憶體中的**儲存方式**。

#### 連續配置（Sequential Storage）
- 資料依序連續儲存在記憶體中  
- 範例：**Array（陣列）**  
- 優點：存取速度快（可隨機存取）  
- 缺點：插入與刪除成本高

#### 鏈結配置（Linked Storage）
- 使用指標（Pointer）連結資料節點  
- 範例：**Linked List（鏈結串列）**  
- 優點：插入刪除靈活  
- 缺點：存取速度較慢（需遍歷節點）

---
## 資料結構操作
- insert 加入
- read 讀取
- update 更新
- delete 刪除

- isEmpty 判斷為空
- isFull 判斷為滿 (只給靜態結構)
- count 回傳元素數量
- capacity 回傳陣列大小 (只給靜態結構)
- clear 刪除所有元素

- search 搜尋元素
- sort 排序元素

- join 合併兩個集
- union 回傳兩個集所有不同的元素
- intersect 回傳兩個集所有相同的元素
- diffrence **保留** 僅存一集之元素
- symmetric diffrent **保留** 僅存兩集但非共同之元素

- push/pop 推入/推出
- enqueue/dequeue 排出/排入
- peek/top/front/rear 查看元素
- traverse 遍歷
- reverse 反轉元素
- rotate 旋轉元素


---
## 時間複雜度(Time Complexity)

O(1)<O(logn)<O(n)<O(nlogn)<O(n2)<O(n3)<O(2n)<O(n!)
tip:將n帶10 即可比大小

---

## 重點整理

| 分類面向 | 子類型 | 範例 | 特性 |
|-----------|--------|------|------|
| 邏輯結構 | 線性 | Array, Stack, Queue | 一對一關係 |
| 邏輯結構 | 非線性 | Tree, Graph | 一對多 / 多對多關係 |
| 實體結構 | 連續配置 | Array | 快速隨機存取 |
| 實體結構 | 鏈結配置 | Linked List | 靈活插入刪除 |



---

## 總結
在程式運行解果正確的情況下，依照各個資料結構之間不同的特性，選擇最合適的那一個。
     
