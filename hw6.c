#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

int main(){
	char s[MAX_NAME_LEN + MAX_PHONE_LEN];
	char srh_name[MAX_NAME_LEN];
	char cmd;
	//init string
	for(int i = 0; i < MAX_NAME_LEN + MAX_PHONE_LEN; i++){
		s[i] = '\0';
		srh_name[i] = '\0';
	}
	//root of tree
	Node_pointer root;
	//output name of every node in string 
	char output_name[1000];
	for(int i = 0; i< 1000; i++)
		output_name[i] = '\0';
	//read input D
	while(gets(s))
	{
		if(strlen(s) == 1){//input string is command
			cmd = s[0];//get command, what to do now	
			if(cmd == 'D'){//start set tree
				root = genNode(gets(s));
			}
			else if(cmd == 'S'){//D finished
				Print_tree_VLR(root, output_name);
				output_name[strlen(output_name) - 1] = '\0';//delete the final blankspace
				printf("%s\n",	output_name);
				break;
			}
		}
		else if(strlen(s) > 1){//input string is record
			root = InsertNode_AVL(root, genNode(s));
		}
	}
	//read input S
	gets(srh_name);//first search name
	do{
		SearchNode(root, srh_name);
		gets(srh_name);
		if(strlen(srh_name) != 1)//next line char is not E
			printf("\n");
	}while(strlen(srh_name) != 1);
	
	return 0;
}

Node_pointer genNode(char record[])
{
	Node_pointer temp = (Node_pointer)malloc(sizeof(Node)); 
	char input_name[MAX_NAME_LEN];
	char input_phone_number[MAX_PHONE_LEN];
	sscanf(record, "%s %s", input_name, input_phone_number);
	strcpy(temp->record.name, input_name);
	strcpy(temp->record.phone_number, input_phone_number);
	temp->left_child = NULL;
	temp->right_child = NULL;
	return temp; 
};

Node_pointer InsertNode_AVL(Node_pointer parent, Node_pointer insert_node)
{
	int cmp = 0;
	/*-----insert new node-----*/
	if(parent)
	{
		cmp = strcmp(parent->record.name, insert_node->record.name);
		if(cmp > 0)
		{
			if(!parent->left_child)
			{
				parent->left_child = insert_node;
			}
			else
			{
				parent->left_child = InsertNode_AVL(parent->left_child, insert_node);
			}
		}
		else if(cmp < 0)
		{
			if(!parent->right_child)
			{
				parent->right_child = insert_node;
			}
			else
			{
				parent->right_child = InsertNode_AVL(parent->right_child, insert_node);
			}
		}
	}
	/*-----calculate balance factor-----*/
	int BF = getBF(parent);
	if(BF < -1){
		cmp = strcmp(parent->right_child->record.name, insert_node->record.name);
		/*---RR case---*/
		if(cmp < 0){
			return RR(parent);
		}
		/*---RL case---*/
		if(cmp > 0){
			return RL(parent);
		}
	}
	if(BF > 1){
		cmp = strcmp(parent->left_child->record.name, insert_node->record.name);
		/*---LL case---*/
		if(cmp > 0){
			return LL(parent);
		}
		/*---LR case---*/
		if(cmp < 0){
			return LR(parent);
		}
	}
	return parent;
};
int Max(int a, int b)
{
	return (a > b)? a:b;
};
int getH(Node_pointer ptr)
{//height
	if(ptr == NULL){
		return 0;
	}
	else{
		return 1 + Max(getH(ptr->left_child), getH(ptr->right_child));
	}
};
int getBF(Node_pointer ptr)
{//Balance Factor
	return getH(ptr->left_child) - getH(ptr->right_child);
};

Node_pointer RR(Node_pointer ptr)
{
	Node_pointer new_parent = ptr->right_child;
	ptr->right_child = new_parent->left_child;
	new_parent->left_child = ptr;
	return new_parent;
};
Node_pointer LL(Node_pointer ptr)
{
	Node_pointer new_parent = ptr->left_child;
	ptr->left_child = new_parent->right_child;
	new_parent->right_child = ptr;
	return new_parent;
};
Node_pointer RL(Node_pointer ptr)
{
	Node_pointer new_parent = ptr->right_child->left_child;
	ptr->right_child->left_child = new_parent->right_child;
	new_parent->right_child = ptr->right_child;
	ptr->right_child = new_parent->left_child;
	new_parent->left_child = ptr;
	return new_parent;

};
Node_pointer LR(Node_pointer ptr)
{
	Node_pointer new_parent = ptr->left_child->right_child;
	ptr->left_child->right_child = new_parent->left_child;
	new_parent->left_child = ptr->left_child;
	ptr->left_child = new_parent->right_child;
	new_parent->right_child = ptr;
	return new_parent;
};

void SearchNode(Node_pointer ptr, char srh_name[])
{
	if(ptr)
	{
		int cmp = strcmp(ptr->record.name, srh_name);
		if(cmp == 0)
		{/*---find node---*/
			printf("%s %s", ptr->record.name, ptr->record.phone_number);
		}
		else if(cmp < 0)
		{//srh_name < record name
			SearchNode(ptr->right_child, srh_name);
		}
		else if(cmp > 0)
		{//srh_name > record name
			SearchNode(ptr->left_child, srh_name);
		}
	}
	else
	{
		printf("%s null", srh_name);
	}
};

void Print_tree_VLR(Node_pointer ptr, char *output_str)
{
	if(ptr)
	{
		strcat(output_str, ptr->record.name);
		strcat(output_str, " ");
		Print_tree_VLR(ptr->left_child, output_str);
		Print_tree_VLR(ptr->right_child, output_str);
	}
};
