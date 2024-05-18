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

int height_in_gt(Node *root){
	int ht = -1;
	for(auto node : root->children){
		int mhc = height_in_gt(node);
		ht = max(mhc, ht);
	}
	ht += 1;
	return ht;
}

int main(){
	vector<int>arr = {10,20,50,-1,60,-1,-1,30, 70, -1, 80, 110, 
					 -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, 
					 -1, -1};
	Node *root = BuildGenericTree(arr);
	int ans = height_in_gt(root);
	cout<<ans<<endl;
	return 0;
}