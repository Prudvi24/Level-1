#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;

	Edge(){

	}
	Edge(int in_source, int in_dest, int in_weight):
	source(in_source), dest(in_dest), weight(in_weight){

	}
};

void build_graph(vector<vector<Edge>>&graph, int &edges){
	int src, dest, wt;
	for(int i=0;i<edges;i++){
		cin>>src>>dest>>wt;
		graph[src].push_back(Edge(src, dest, wt));
	}
}

void display_graph(vector<vector<Edge>>&graph){
	for(auto adj_list : graph){
		for(auto node : adj_list){
			cout<<node.source<<" - "<<node.dest<<" - "<<node.weight<<endl;
		}
	}
}

void topological_sort(vector<vector<Edge>>&graph, int &src, 
	stack<int>&st, vector<bool>&visited){
	visited[src]=true;
	for(auto node : graph[src]){
		if(visited[node.dest]==false){
			topological_sort(graph, node.dest, st, visited);
		}
	}
	st.push(src);
}

void display_result(stack<int>&st){
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	vector<bool>visited(vertices, false);
	stack<int>st;
	for(int i=0;i<vertices;i++){
		if(visited[i]==false){
	        topological_sort(graph, i, st, visited);
	    }
	}
	display_result(st);
	return 0;
}

/*
Test case 1
6
6
5 0 10
4 0 10
5 2 10
4 1 10
2 3 10
3 1 10


Test case 2
7
8
0 1 10
1 2 10
2 3 10
0 3 10
4 3 10
4 5 10
4 6 10
5 6 10
*/