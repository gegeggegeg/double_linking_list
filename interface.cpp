#include <iostream>
#include <unistd.h>
#include <string>
#include <map>
#include "linkinglist.hpp"

using namespace std;
void show(linknode*);

int main()
{
	linknode *node = mass_init();
	cout<< "Please choose your action: ";
	map<string, int> command;
	command["show"] = 1;
	command["printlist"] =2;
	command["forward"] = 3;
	command["backward"] = 4;
	command["delete"] = 5;
	command["insert"] = 6;
	command["help"] = 7;
	string input;
	int offset = 0;
	int val = 0;
	char answer;
	getline(cin, input);
	while( input != "quit"){
		switch(command[input]){
			case 1:
				show(node);
				break;
			case 2:
				printlist(node);
				break;
			case 3:
				cout << "Please enter offset: ";
				cin>>offset;
				node = node->move_forward(offset);
				show(node);
				break;
			case 4:
				cout << "Please enter offset: ";
				cin >> offset;
				node = node->move_backward(offset);
				show(node);
				break;
			case 5:
				cout << "Are you sure deleting current node ?(y/n)";
				cin >> answer;
				if (answer == 'y'){
					node = node->delete_node();
					show(node);
				}
				break;
			case 6:
				cout << "What number do you want to insert? ";
				cin >> val;	
				node = node->insert_node(val);
				break;
			case 7:
				cout <<"show\nprintlist\nforward\nbackward\ndelete\ninsert\n";
				break;
			default:
				getline(cin, input);
				continue;
		}
		cout << "Please enter your action: ";
		getline(cin, input);	
	}
	return 0;
}

void show(linknode *ref){
	cout << "Current position is: " << ref->pos << endl;
	cout << "Current value is: " << ref->value << endl;
}

