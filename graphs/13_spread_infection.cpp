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

int spread_infection(vector<vector<Edge>>&graph, vector<bool>&visited, 
	const int &source, const int &level){
	queue<pair<int, int>>q;
	q.push({source, 1});
	int count = 0;
	while(!q.empty()){
		pair<int, int>front_vertex = q.front();
		q.pop();

		if(front_vertex.second > level){
			break;
		}

		if(visited[front_vertex.first]==1){
			continue;
		}
		count++;
		visited[front_vertex.first] = 1;
		for(auto e : graph[front_vertex.first]){
            if(visited[e.dest]==0){
			    q.push({e.dest, front_vertex.second+1});
			}
		}
	}
	while(!q.empty()){
		q.pop();
	}
	return count;
}

int main(){
	int vertices, edges, source, level;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	vector<bool>visited(vertices, 0);
	cin>>source>>level;
	int count = spread_infection(graph, visited, source, level);
	cout<<"Total infected: "<<count<<endl;
}