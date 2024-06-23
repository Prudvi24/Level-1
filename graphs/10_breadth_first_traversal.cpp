#include <bits/stdc++.h>

using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;

	Edge(int in_source, int in_dest, int in_weight){
		this->source = in_source;
		this->dest = in_dest;
		this->weight = in_weight;
	}
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
	cout<<"Graph display"<<endl;
	for(auto g : graph){
			for(auto e : g){
			cout<<e.source<<" - "<<e.dest<<" - "<<e.weight<<endl;
		}
	}
}

void breadth_first_traversal(vector<vector<Edge>>&graph, int &source){
	queue<pair<int, string>>q;
	q.push({source, to_string(source)});
	vector<bool>visited(graph.size(), 0);
	while(!q.empty()){
		pair<int, string>p = q.front();
		q.pop();
		string path = p.second;
		if(visited[p.first]==1){
			continue;
		}
		else{
			visited[p.first] = 1;
		    cout<<p.first<<" @ "<<p.second<<endl;
		    for(auto e : graph[p.first]){
		    	if(visited[e.dest]==0){
		    		q.push({e.dest, path+to_string(e.dest)});
		    	}
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
	int source;
	cin>>source;
	cout<<"breadth first traversal"<<endl;
	breadth_first_traversal(graph, source);
	return 0;
}

/*
input
------------
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
2
*/