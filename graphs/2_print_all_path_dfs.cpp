#include <bits/stdc++.h>

using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;

	Edge(){

	}
	Edge(int in_source, int in_dest, int in_weight):
		source(in_source), dest(in_dest), weight(in_weight)
	{}
};

void build_graph(vector<vector<Edge>>&graph, int edges){
	int source, dest, weight;
	for(int i=0;i<edges;i++){
		cin>>source>>dest>>weight;
		graph[source].push_back(Edge(source, dest, weight));
		graph[dest].push_back(Edge(dest, source, weight));
	}
}

void display_graph(vector<vector<Edge>>&graph){
	for(auto g : graph){
		for(auto e: g){
			cout<<e.source<<" - "<<e.dest<<" - "<<e.weight<<endl;
		}
	}
}

void print_all_paths(vector<vector<Edge>>&graph, vector<bool>&visited,
						int &v1, int &v2, string psf){
	if(v1==v2){
		if(psf.empty()){
			cout<<"source and destination nodes are same"<<endl;
		}
		else{
			cout<<psf+to_string(v2)<<endl;
		}
		return ;
	}

	if(visited[v1]==1){
		return;
	}
	visited[v1]=1;
	for(auto e : graph[v1]){
		print_all_paths(graph, visited, e.dest, 
						v2, psf+to_string(e.source)+", ");
	}
	visited[v1]=0;
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	cout<<"Displaying the graph"<<endl;
	display_graph(graph);
	string psf = "";
	vector<bool>visited(vertices, 0);
	int v1, v2;
	cin>>v1>>v2;
	cout<<"Print all paths using DFS"<<endl;
	print_all_paths(graph, visited, v1, v2, psf);
	return 0;
}

/*
Input
----------------
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
0
6
*/