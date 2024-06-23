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

void build_graph(vector<vector<Edge>>&graph, const int &edges){
	int source;
	int dest;
	int weight;
	for(int i=0;i<edges;i++){
		cin>>source>>dest>>weight;
		if(source >= graph.size() || dest >= graph.size()){
			return ;
		}
		graph[source].push_back(Edge(source, dest, weight));
		graph[dest].push_back(Edge(dest, source, weight));
	}
}

bool is_connected(vector<vector<Edge>>&graph, vector<bool>visited, int &v1,
					int &v2){
	// If the source and dest vertices are same then there exist a path
	if(v1==v2){
		return true;
	}

    // If the vertices are not in the graph return false, here itself
	if(v1>=graph.size() || v2>=graph.size()){
		return false;
	}

    // If the vertex is already visited then don't need to visit again
	if(visited[v1]==1){
		return false;
	}

	visited[v1]=1; //marks the vertex as visited
	for(auto e : graph[v1]){
		bool ans = is_connected(graph, visited, e.dest, v2);
		if(ans){
			return true;
		}
	}

	// If no path exist return false
	return false;
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	int v1, v2;
	cin>>v1>>v2;
	vector<bool>visited(vertices, 0);
	bool res = is_connected(graph, visited, v1, v2);
	if(res){
		cout<<"Connected"<<endl;
	}
	else{
		cout<<"Not connected"<<endl;
	}
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