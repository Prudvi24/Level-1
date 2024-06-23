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
	Tuple(int in_v, string in_sp, int in_total_wt):
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

void iterative_dfs(vector<vector<Edge>>&graph, int &vertices, int &src, 
	int &dest, vector<bool>&visited){
	stack<Tuple>st;
	st.push(Tuple(0, ""+to_string(0), 0));

	while(!st.empty()){
		Tuple topnode = st.top();
		st.pop();

		if(visited[topnode.v]==true){
			continue;
		}
		visited[topnode.v]=true;
		if(dest==topnode.v){
			cout<<topnode.v<<" - "<<topnode.sp<<" @ "<<topnode.total_wt<<endl;
		}

		for(auto node : graph[topnode.v]){
			if(visited[node.dest]==false){
				st.push(Tuple(node.dest, topnode.sp+to_string(node.dest), topnode.total_wt+node.weight));
			}
		}
	}
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	int src, dest;
	cin>>src>>dest;
	vector<bool>visited(vertices, false);
	iterative_dfs(graph, vertices, src, dest, visited);
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
6

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
5
*/