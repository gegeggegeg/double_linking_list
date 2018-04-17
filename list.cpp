#include <iostream>
#include <string>
#include "linkinglist.hpp"

using namespace std;
void show(linknode*);

int main()
{
	linknode *node = mass_init();
	printlist(node);
	show(node);
	node = node->move_forward(7);
	show(node);
	node = node->insert_node(5);
	printlist(node);
	show(node);
	node = node->move_backward(3);
	show(node);
	node = node->delete_node();
	printlist(node);
	return 0;
}

void show(linknode *ref){
	cout << "Current position is: " << ref->pos << endl;
	cout << "Current value is: " << ref->value << endl;
}


