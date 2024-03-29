#### F740860872 呂文翔
# data_structure_hw6
## Result screenshot
* compile:
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/compile.JPG)
* execution:
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/execution.JPG)
* comparison:
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/diff.JPG)
## Program sturcture
* 流程圖:  
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/structure.png)
## Program functions
### Main
* Parameter
	* char s[]  						儲存除入的字串
	* char cmd  						儲存現階段執行的任務('D' or 'S')
	* Node_pointer root 		AVL tree 的 root
### Construct AVL tree
##### 1. Node_pointer genNode(char record[]);
`generate node`  
* Parameter
	* record[]	node需儲存的資訊, inlcuding name and phone number.
* Return Value
	* return the pointer of node we generate.
##### 2. Node_pointer InsertNode_AVL(Node_pointer parent, Node_pointer insert_node);
`建立AVL tree`
* Parameter
	* parent       欲插入的insert_node的parent node.
	* insert_node  欲插入AVL tree的node.
* Return Value
	* return the pointer of new root after rebalancing.
##### 3. Node_pointer RR(Node_pointer ptr);
`RR rotation for rebalancing AVL tree `  
`balance factor < -1`
* Parameter
	* ptr   左右子樹不平衡的node的pointer.
* Return Value
	* 回傳該子樹經平衡調整後的新root的pointer.
##### 4. Node_pointer LL(Node_pointer ptr);
`LL rotation for rebalancing AVL tree `  
`balance factor > 1`
* Parameter
	* ptr   左右子樹不平衡的node的pointer.
* Return Value
	* 回傳該子樹經平衡調整後的新root的pointer.
##### 5. Node_pointer RL(Node_pointer ptr);
`RL rotation for rebalancing AVL tree `  
`balance factor < -1`
* Parameter
	* ptr   左右子樹不平衡的node的pointer.
* Return Value
	* 回傳該子樹經平衡調整後的新root的pointer.
##### 6. Node_pointer LR(Node_pointer ptr);
`LR rotation for rebalancing AVL tree `  
`balance factor > 1`
* Parameter
	* ptr   左右子樹不平衡的node的pointer.
* Return Value
	* 回傳該子樹經平衡調整後的新root的pointer.
##### 7. int Max(int a, int b);
* Return Value
	* return a when a > b.
	* return b when a < b.
##### 8. int getH(Node_pointer ptr);
`計算該node為root的子樹的高度.`
* Parameter
	* ptr   the pointer of root of subtree.
* Return value
	* return the height of the subtree.
##### 9. int getBF(Node_pointer ptr);
`得到該node的子樹的balance factor`
* Parameter
	* ptr   the pointer of root of subtree.
* Return value
	* return the balance factor of the subtree.
### Prinf out the name of the visited node in **Pre-Order** traversal
##### 1. void Print_tree_VLR(Node_pointer ptr, char *output_str);
`pre order traversal, 將tree各node所儲存的name放入output_str, name之間以空格分開`
* Parameter
	* ptr          欲輸出的子樹的root.
	* *output_str  最後輸出的字串.
### Search nodes
##### 1. void SearchNode(Node_pointer ptr, char srh_name[]);
`在tree搜尋name, 並印出record儲存的資訊`
* Parameter
	* ptr         此刻到達的node.
	* srh_name[]  欲搜尋的name.
## Program Design
### Define
```c
#define MAX_NAME_LEN 21
#define MAX_PHONE_LEN 11
```
### node struct
* node:
```c
typedef struct Node *Node_pointer;
typedef struct Node Node;
struct Node{
	Node_pointer left_child;
	Record record;
	Node_pointer right_child;
};
```
* record:
```c
typedef struct Record Record;
struct Record{
	char name[MAX_NAME_LEN];
	char phone_number[MAX_PHONE_LEN];
};
```
### Construct AVL tree
#### step1: insert
* 依序比較字母大小，較大放在右子樹，較小放在左子樹。
* 定義: A < B, a < b
* e.g.
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/insert.png)
#### step2: get balance factor
1. getBF(Node_pointer ptr);
```c
	return getH(ptr->left_child) - getH(ptr->right_child);
```
* e.g.  
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/bf1.png)
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/bf2.png)
2. getH(Node_pointer ptr);
```c
if(ptr == NULL){
		return 0;
	}
	else{
		return 1 + Max(getH(ptr->left_child), getH(ptr->right_child)); //回傳左右子樹較大的高度
	}
```
* e.g.  
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/h1.png)
`因Paul左子樹高度 > 右子樹高度, 將左子樹高度回傳`
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/h2.png)
`子樹回傳的高度 + 1 (node Paul) = ptr 右子樹的高度`
#### step3: rotation
1. RR rotation:
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/rotation/rr.PNG)
2. LL rotation:
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/rotation/ll.PNG)
3. RL rotation:
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/rotation/rl.PNG)
4. LR rotation:
![image](https://github.com/ShawnLu31/data_structure_hw6/blob/main/pic/rotation/lr.PNG)
