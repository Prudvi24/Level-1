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

void LevelOrderTraversalZigZag(Node *root){
	queue<Node*>mq;
	stack<Node*>st;
	mq.push(root);
	int level = 0;
	while(!mq.empty()){
		Node *front_node = mq.front();
		mq.pop();
		cout<<front_node->data<<" ";
		if(level%2==0){
			for(int i=0;i<front_node->children.size();i++){
				st.push(front_node->children[i]);
			}
		}
		else{
			for(int i=front_node->children.size()-1; i>=0; i--){
				st.push(front_node->children[i]);
			}
		}
		if(mq.empty()){
			cout<<".\n";
			while(!st.empty()){
				mq.push(st.top());
				st.pop();
			}
			level++;
		}
		//deallocate the generic tree nodes one by one
		delete front_node;
	}
}

int main(){
	vector<int>arr = {10,20,50,-1,60,-1,-1,30, 70, -1, 80, 110, 
					 -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, 
					 -1, -1};
	Node *root = BuildGenericTree(arr);
	LevelOrderTraversalZigZag(root);
	return 0;
}
