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
## Program functions
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
`RR rotation for rebalancing of AVL tree `  
`balance factor < -1`
* Parameter
	* ptr   左右子樹不平衡的node的pointer.
* Return Value
	* 回傳該子樹經平衡調整後的新root的pointer.
##### 4. Node_pointer LL(Node_pointer ptr);
`LL rotation for rebalancing of AVL tree `  
`balance factor > 1`
* Parameter
	* ptr   左右子樹不平衡的node的pointer.
* Return Value
	* 回傳該子樹經平衡調整後的新root的pointer.
##### 5. Node_pointer RL(Node_pointer ptr);
`RL rotation for rebalancing of AVL tree `  
`balance factor < -1`
* Parameter
	* ptr   左右子樹不平衡的node的pointer.
* Return Value
	* 回傳該子樹經平衡調整後的新root的pointer.
##### 6. Node_pointer LR(Node_pointer ptr);
`LR rotation for rebalancing of AVL tree `  
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
