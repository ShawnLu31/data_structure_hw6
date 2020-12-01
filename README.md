#### F740860872 呂文翔
# data_structure_hw6
## Result screenshot
* compile:
* execution:
* comparison:
## Program sturcture
* 流程圖:
## Program functions
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
### Main function

### Construct AVL tree
##### 1. Node_pointer genNode(char record[]);
##### 2. Node_pointer InsertNode_AVL(Node_pointer parent, Node_pointer insert_node);
##### 3. Node_pointer RR(Node_pointer ptr);
##### 4. Node_pointer LL(Node_pointer ptr);
##### 5. Node_pointer RL(Node_pointer ptr);
##### 6. Node_pointer LR(Node_pointer ptr);
##### 7. int Max(int a, int b);
##### 8. int getH(Node_pointer ptr);
##### 9. int getBF(Node_pointer ptr);

### Prinf out the name of the visited node in **Pre-Order** traversal
##### 1. void Print_tree_VLR(Node_pointer ptr, char *output_str);
### Search nodes
##### 1. void SearchNode(Node_pointer ptr, char srh_name[]);
