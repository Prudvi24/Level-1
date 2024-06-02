#include<bits/stdc++.h>

using namespace std;

class Edge{
public:
	int source;
	int dest;

	Edge(){

	}
	Edge(int in_source, int in_dest):
			source(in_source), dest(in_dest){
	}
};

void build_graph(vector<vector<Edge>>&graph, int &edges){
	int source, dest;
	for(int i=0;i<edges;i++){
	    cin>>source>>dest;
	    graph[source].push_back(Edge(source, dest));
	    graph[dest].push_back(Edge(dest, source));
    }
}

void display_graph(vector<vector<Edge>>&graph){
	for(auto g : graph){
		for(auto e : g){
			cout<<e.source<<" - "<<e.dest<<endl;
		}
	}
}

void get_components(vector<vector<Edge>>&graph, vector<bool>&visited,
						int &src, vector<int>&gc){
	if(visited[src]==1){
		return ;
	}
	visited[src]=1;
	gc.push_back(src);
	for(auto e : graph[src]){
		get_components(graph, visited, e.dest, gc);
	}
}

void display_components(vector<vector<int>>&components){
	cout<<"[";
	for(auto vec : components){
		cout<<"[";
		for(auto val : vec){
			cout<<val<<" ";
		}
		cout<<"]";
	}
	cout<<"]"<<endl;
}

int friends_combination(vector<vector<int>>&components){
	int ans = 0;
	for(int i=0;i<components.size();i++){
		int fiog = 0;
		for(int j=i+1; j<components.size();j++){
			fiog += components[j].size();
		}
		ans += (components[i].size()*fiog);
	}
	return ans;
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
		if(visited[i]==0){
			vector<int>gc;
	        get_components(graph, visited, i, gc);
	        components.push_back(gc);
	    }
    }
    int ans = friends_combination(components);
    cout<<"Possible combination of friends (not from the same club) = "<<ans<<endl;
	return 0;
}

/*
input
------------
7
5
0 1
2 3
4 5
5 6
4 6
*/