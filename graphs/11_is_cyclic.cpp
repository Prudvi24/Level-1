#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;
	
	//default constructor
	Edge(){}

    //parameterized constructor
	Edge(int in_source, int in_dest, int in_weight):source(in_source),
				dest(in_dest), weight(in_weight){

	}
};

void build_graph(vector<vector<Edge>>&graph, const int &edges){
	int source, dest, weight;
	for(int i=0;i<edges;i++){
		cin>>source>>dest>>weight;
		graph[source].push_back(Edge(source, dest, weight));
		graph[dest].push_back(Edge(dest, source, weight));
	}
}

void display_graph(vector<vector<Edge>>&graph){
	for(auto g : graph){
		for(auto e : g){
			cout<<e.source<<" - "<<e.dest<<" - "<<e.weight<<endl;
		}
	}
}

bool is_cyclic(vector<vector<Edge>>&graph, const int &source, 
										vector<bool>&visited){
	queue<pair<int, string>>q;
	q.push({source, ""+to_string(source)});
	while(!q.empty()){
		//pick the top vertex from the queue.
		pair<int, string>tv = q.front();
		q.pop();
		if(visited[tv.first]==true){
			cout<<"Cycle found here when exploring "<<tv.first<<" @ "<<tv.second<<endl;
			return true;
		}
		cout<<tv.first<<" @ "<<tv.second<<endl;
		visited[tv.first] = true;
		for(auto e : graph[tv.first]){
			if(visited[e.dest]==false){
				q.push({e.dest, tv.second+to_string(e.dest)});
			}
		}
	}
	return false;
}

int main(){
	int vertices, edges, source;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	vector<bool>visited(vertices,0);
	bool ans = 0;
	for(int i=0;i<vertices; i++){
		if(visited[i]==false){
			ans = is_cyclic(graph, i, visited);
			if(ans){
				break;
			}
		}
	}
	if(ans){
		cout<<"Cyclic graph"<<endl;
	}
	else{
		cout<<"Acyclic graph"<<endl;
	}
	return 0;
}
/*
Input 1
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

Input 2
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

*/