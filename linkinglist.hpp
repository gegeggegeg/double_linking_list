#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct linknode
{
	public:
		linknode(int i):prevnode(NULL), nextnode(NULL), value(i), pos(0){}
		linknode *prevnode;
		linknode *nextnode;
		int pos;
		int value;
		int print_node() {return value;}
		linknode* move_forward(int);
		linknode* move_backward(int);
		linknode* insert_node(int);
		linknode* delete_node();	
};

void printlist(linknode*);
linknode* mass_init();

linknode* linknode::insert_node(int node){
	linknode *insert = new linknode(node);
	insert->nextnode = this->nextnode;
	(this->nextnode)->prevnode = insert;
	insert->prevnode = this;
	this->nextnode = insert;
	linknode *temp = insert;
	while(temp!= NULL){
		temp->pos = (temp->prevnode)->pos+1;
		temp = temp->nextnode;
	}
	return insert;
}

linknode* linknode::delete_node(){
	(this->prevnode)->nextnode = this->nextnode;
	linknode *current = this->nextnode;
	linknode *temp = this->nextnode;
	while(temp != NULL){
		temp->pos = temp->pos - 1;
		temp = temp->nextnode;
	}
	return current;
}

linknode* linknode::move_forward(int offset){
	linknode *ret = this;
	for(int i = 0; i <offset; i++){
		if(ret->nextnode != NULL)
			ret = ret->nextnode;
	}
	return ret;
}
linknode* linknode::move_backward(int offset){
	linknode *ret = this;
	for(int i=0; i<offset; i++){
		if(ret->prevnode != NULL)
			ret = ret->prevnode;
	}
	return ret;
}

void printlist(linknode *refnode){
	while(refnode->prevnode != NULL)
		refnode = refnode->prevnode;
	linknode *refnode2 = refnode;
	while(refnode2 != NULL){
		cout << refnode2->pos;
		if(refnode2->pos >= 10)
			cout << "  ";
		else
			cout << "   ";
		refnode2 = refnode2->nextnode;
	}
	cout << endl;
	while(refnode != NULL){
		cout << refnode->value;
		refnode = refnode->nextnode;
		if (refnode != NULL)
			cout << "<=>";
	}
	cout<< endl;
}

linknode* mass_init(){
	srand(time(NULL));
	int random_number = 0;
	random_number = rand()%10;
	linknode *startnode = new linknode(random_number);
	startnode->pos = 1;
	linknode *lastnode = startnode;
	for(int i =0; i < 20; i++){
		random_number = rand()%10;
		linknode *current = new linknode(random_number);
		current->prevnode = lastnode;
		current->pos = lastnode->pos+1;
		lastnode->nextnode = current;
		lastnode = current;
	}
	return startnode;
}
