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

struct myComp{
	bool operator()(pair<int, string>&a, pair<int, string>&b){
		return a.first > b.first;
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

string spsf;
int spw = INT_MAX;
string lpsf;
int lpw = INT_MIN;
string cpsf;
int cpw = INT_MAX;
string fpsf;
int fpw = INT_MIN;

priority_queue<pair<int, string>, vector<pair<int, string>>, myComp>pq;

void mutli_solver(vector<vector<Edge>>&graph, vector<bool>&visited,
							int &v1, int &v2, int &criteria, int &k,
							string psf, int wsf){
	if(v1==v2){
		//check for the shortest path so far
		if(wsf < spw){
			spw = wsf;
			spsf = psf;
		}
		//check the longest path so far
		if(wsf > lpw){
			lpw = wsf;
			lpsf = psf;
		}
		//check for the ceil path for the given criteria
		if(wsf > criteria && wsf < cpw){
			cpw = wsf;
			cpsf = psf;
		}
		//check for the floor path for the given criteria
		if(wsf <criteria && wsf > fpw){
			fpw = wsf;
			fpsf = psf;
		}
		//push elements in the max heap based on the wsf seen, till k elements
		if(pq.size()<k){
			pq.push({wsf, psf});
		}
		// if pq is full, if new path has more than the top element remove the top element and add it to the heap
		else{
			pair<int, string>p = pq.top();
			if(p.first < wsf){
				pq.pop();
				pq.push({wsf, psf});
			}
		}
		return ;
	}
	if(visited[v1]){
		return ;
	}
	visited[v1]=1;
	for(auto e : graph[v1]){
		mutli_solver(graph, visited, e.dest, v2, criteria, k, 
			psf+to_string(e.dest), wsf+e.weight);
	}
	visited[v1]=0;
}

void display_graph(vector<vector<Edge>>&graph){
	cout<<"Graph display"<<endl;
    for(auto g : graph){
	    for(auto e : g){
	        cout<<e.source<<" - "<<e.dest<<" - "<<e.weight<<endl;
		}
	}
}

int main(){
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<Edge>>graph(vertices);
	build_graph(graph, edges);
	display_graph(graph);
	vector<bool>visited(vertices, 0);
	int v1, v2, criteria, k;
	cin>>v1>>v2>>criteria>>k;
	mutli_solver(graph, visited, v1, v2, criteria, k, to_string(v1)+"", 0);
	cout<<"Smallest path= "<<spsf<<" @ "<<spw<<endl;
	cout<<"Longest path= "<<lpsf<<" @ "<<lpw<<endl;
	cout<<"Just larger path than "<<criteria<<" = "<<cpsf<<" @ "<<cpw<<endl;
	cout<<"Just Smallest path than "<<criteria<<" = "<<fpsf<<" @ "<<fpw<<endl;
	cout<<k<<"th larget path= "<<pq.top().second<<" @ "<<pq.top().first<<endl;
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
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
0
6
40
3
*/