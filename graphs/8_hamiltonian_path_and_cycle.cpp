#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;
    //default constructor
	Edge(){

	}
	//paramterized constructor
	Edge(int in_source, int in_dest, int in_weight):
				source(in_source), dest(in_dest), weight(in_weight){

	}
};

void build_graph(vector<vector<Edge>>&graph, const int &edges){
	int source, dest, weight;
	for(int i=0;i<edges;i++){
		cin>>source>>dest>>weight;
		graph[source].emplace_back(Edge(source, dest, weight));
		graph[dest].emplace_back(Edge(dest, source, weight));
	}
}

void display_graph(vector<vector<Edge>>&graph){
	for(auto g : graph){
		for(auto e : g){
			cout<<e.source<<" - "<<e.dest<<" - "<<e.weight<<endl;
		}
	}
}


/*
Hamiltonian Path : It is the path where every vertex is visited atmost once.
Hamiltonian cycle : It is the path where every vertex is visited atmost once (hamiltonian path) and
					the source and destination vertex shares the same edge.
*/
void hamiltonian_path_and_cycles(vector<vector<Edge>>&graph, int source, 
						string psf,vector<bool>&visited, int &rem_src){

	if(visited[source]==1){
		return ;
	}

	if(psf.length()==graph.size()){
		cout<<"hamiltonian_path = "<<psf<<"."<<endl;
		for(auto e : graph[source]){
			if(e.dest == rem_src){
				cout<<"hamiltonian_cycles = "<<psf<<"*"<<endl;
				break;
			}
		}
		return ;
	}
	visited[source]=1;
	for(auto e : graph[source]){
		hamiltonian_path_and_cycles(graph, e.dest, psf+to_string(e.dest), visited, rem_src);
	}
	visited[source]=0;
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	vector<bool>visited(vertices, 0);
	int source;
	cin>>source;
	hamiltonian_path_and_cycles(graph, source, ""+to_string(source),visited, source);
	return 0;
}

/*
input
---------------
7
9 
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
2 5 10
5 6 10
4 6 10
0
*/