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

void TraversalInGT(Node *root){
	if(root==nullptr){
		return ;
	}
	cout<<"Node Pre "<<root->data<<endl;
	for(auto node : root->children){
		cout<<"Edge Pre "<<root->data<<"-"<<node->data<<endl;
		TraversalInGT(node);
		cout<<"Edge Post "<<root->data<<"-"<<node->data<<endl;
	}
	cout<<"Node Post "<<root->data<<endl;
}

int main(){
	vector<int>arr = {10,20,50,-1,60,-1,-1,30, 70, -1, 80, 110, 
					 -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, 
					 -1, -1};
	Node *root = BuildGenericTree(arr);
	TraversalInGT(root);
	return 0;
}
