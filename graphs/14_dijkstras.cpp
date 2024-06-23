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
	string sp;
	int total_wt;

	Tuple(){

	}
	Tuple(int &in_v, string in_sp, int in_total_wt):
		v(in_v), sp(in_sp), total_wt(in_total_wt){
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
		return a.total_wt > b.total_wt;
	}
};

void shortest_path_to_all_from_source(vector<vector<Edge>>&graph, int &src, vector<bool>&visited){
	priority_queue<Tuple, vector<Tuple>, myComp>pq;
	pq.push(Tuple(src, ""+to_string(src), 0));

	while(!pq.empty()){
		Tuple top_node = pq.top();
		pq.pop();

		if(visited[top_node.v]){
			continue;
		}
		visited[top_node.v]=1;
		cout<<top_node.v<<" via "<<top_node.sp<<" @ "<<top_node.total_wt<<endl;
		for(auto node : graph[top_node.v]){
			if(visited[node.dest]==0){
				pq.push(Tuple(node.dest, top_node.sp+to_string(node.dest), top_node.total_wt+node.weight));
			}
		}
	}
}

void dijkstras_algo(vector<vector<Edge>>&graph, int &vertices, int &edge, int &src){
	vector<bool>visited(vertices, 0);
	shortest_path_to_all_from_source(graph, src, visited);
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	int src;
	cin>>src;
	dijkstras_algo(graph, vertices, edges, src);
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