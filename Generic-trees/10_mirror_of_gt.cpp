#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	vector<Node*>children;
};

Node* BuildGenericTree(vector<int>&arr){
	Node *root = nullptr;
	stack<Node*>st;
	for(int i=0;i<arr.size();i++){
		if(arr[i]==-1){
			st.pop();
		}
		else{
			Node *newNode = new Node();
			newNode->data = arr[i];
			//if the stack has node
			if(st.size()>0){
				Node *curr = st.top();
				curr->children.emplace_back(newNode);
			}
			else{
				root = newNode;
			}
			st.push(newNode);
		}
	}
    return root;
}

void reverse_children(Node *node){
	for(size_t i=0; i<node->children.size()/2; i++){
		Node *tmp = node->children[i];
		node->children[i] = node->children[node->children.size()-1-i];
		node->children[node->children.size()-1-i] = tmp;
	}
}

void mirror_of_gt(Node *root){
	if(root==nullptr){
		return ;
	}
	reverse_children(root);
	for(auto node : root->children){
		mirror_of_gt(node);
	}
}

void display_generic_tree(Node *root){
	if(root==nullptr){
		return ;
	}
	cout<<root->data<<" --> ";
	for(auto node : root->children){
		cout<<node->data<<", ";
	}
	cout<<"."<<endl;
	for(auto node : root->children){
		display_generic_tree(node);
	}
}

int main(){
	vector<int>arr = {10,20,50,-1,60,-1,-1,30, 70, -1, 80, 110, 
					 -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, 
					 -1, -1};
	Node *root = BuildGenericTree(arr);
	cout<<"Display before mirror"<<endl;
	display_generic_tree(root);
	mirror_of_gt(root);
	cout<<"\nDisplay after mirror"<<endl;
	display_generic_tree(root);
	return 0;
}
