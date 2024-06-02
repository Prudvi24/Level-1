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
		source(in_source), dest(in_dest), weight(in_weight){
	}
};

void build_graph(vector<vector<Edge>>&graph, int &edges){
	int source, dest, weight;
	for(int i=0;i<edges;i++){
		cin>>source>>dest>>weight;
		graph[source].push_back(Edge(source, dest, weight));
		graph[dest].push_back(Edge(dest, source, weight));
	}
}

void display_graph(vector<vector<Edge>>&graph){
	cout<<"Graph"<<endl;
	for(auto g : graph){
		for(auto e : g){
			cout<<e.source<<" - "<<e.dest<<" - "<<e.weight<<endl;
		}
	}
}

void connected_components(vector<vector<Edge>>&graph, vector<bool>&visited, 
								int &src, vector<int>&gc){
	if(visited[src]==1){
		return ;
	}

	gc.push_back(src);
	visited[src]=1;
	for(auto e : graph[src]){
		connected_components(graph, visited, e.dest, gc);
	}
}

void display_components(vector<vector<int>>&components){
	cout<<components.size()<<" Components = [";
	for(auto vec : components){
		cout<<"[";
		for(auto vertex : vec){
			cout<<vertex<<", ";
		}
		cout<<"], ";
	}
	cout<<"]"<<endl;
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	vector<bool>visited(vertices, 0);
	vector<vector<int>>components;
	for(int i=0;i<vertices;i++){
		if(visited[i]==false){
			vector<int>gc;
	        connected_components(graph, visited, i, gc);
	        components.push_back(gc);
	    }
    }
	display_components(components);
	if(components.size()==1){
		cout<<"Since graph has one component, it is connected"<<endl;
	}
	else{
		cout<<"More than one component hence not connected"<<endl;
	}
	return 0;
}

/*
input 1
-------------
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

input 2
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
*/