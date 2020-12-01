#ifndef RECORD_H
#define RECORD_H
#define MAX_NAME_LEN 21
#define MAX_PHONE_LEN 11
//record: name, phone number
typedef struct Record Record;
struct Record{
	char name[MAX_NAME_LEN];
	char phone_number[MAX_PHONE_LEN];
};
//node
typedef struct Node *Node_pointer;
typedef struct Node Node;
struct Node{
	Node_pointer left_child;
	Record record;
	Node_pointer right_child;
};

Node_pointer genNode(char record[]);
Node_pointer InsertNode_AVL(Node_pointer parent, Node_pointer insert_node);

int Max(int a, int b);
int getH(Node_pointer ptr);
int getBF(Node_pointer ptr);
Node_pointer RR(Node_pointer ptr);
Node_pointer LL(Node_pointer ptr);
Node_pointer RL(Node_pointer ptr);
Node_pointer LR(Node_pointer ptr);

void SearchNode(Node_pointer ptr, char srh_name[]);

void Print_tree_VLR(Node_pointer ptr, char *output_str);
#endif
