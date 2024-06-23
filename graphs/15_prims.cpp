#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;

	Edge(){

	}
	Edge(int &in_source, int &in_dest, int &in_weight):
		source(in_source), dest(in_dest), weight(in_weight){
	}
};

class Tuple{
public:
	int v;
	int av;
	int wt;

	Tuple(){

	}
	Tuple(int &in_v, int in_av, int in_wt):
		v(in_v), av(in_av), wt(in_wt){
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
	for(auto vec : graph){
		for(auto edge : vec){
			cout<<edge.source<<" - "<<edge.dest<<" - "<<edge.weight<<endl;
		}
	}
	cout<<endl;
}

struct myComp{
	bool operator()(Tuple &a, Tuple &b){
		return a.wt > b.wt;
	}
};

void prims_algorithm(vector<vector<Edge>>&graph, int &src, vector<bool>&visited){
	priority_queue<Tuple, vector<Tuple>, myComp>pq;
	pq.push(Tuple(src, -1, 0));

	while(!pq.empty()){
		Tuple top_node = pq.top();
		pq.pop();

		if(visited[top_node.v]){
			continue;
		}
		visited[top_node.v]=1;
		if(top_node.av != -1){
		    cout<<top_node.v<<" - "<<top_node.av<<" @ "<<top_node.wt<<endl;
	    }
		for(auto node : graph[top_node.v]){
			if(visited[node.dest]==0){
				pq.push(Tuple(node.dest, top_node.v, node.weight));
			}
		}
	}
}

void minimum_spanning_tree(vector<vector<Edge>>&graph, int &vertices, int &edge, int &src){
	vector<bool>visited(vertices, 0);
	prims_algorithm(graph, src, visited);
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	int src;
	cin>>src;
	minimum_spanning_tree(graph, vertices, edges, src);
	return 0;
}

/*

Test case 1:
7
8
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
0

Test case 2
9  
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7 
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0
*/