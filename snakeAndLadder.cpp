#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

// typedef vector<vector<vector<int>>> vvvi;
// typedef vector<vector<int>> vvi;
// typedef vector<int> vi;

// vvvi vectName( size, vvi ( size, vi( size, value)));

// #define ll long long int
#define Faster ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

template<typename T>
class Graph{
	map<T,list<T>> l;
public:
	void addEdge(T x, T y){
		l[x].push_back(y);
		// l[y].push_back(x);
	}
	int bfs(T src, T dest, int n){
		// map<T, bool> visited;
		// queue<T> q;
		// q.push(src);
		// visited[src]=true;
		// while(!q.empty()){
		// 	T node = q.front();
		// 	cout << node << "->";
		// 	q.pop();
		// 	for(int nbr: l[node]){
		// 		if(!visited[nbr]){
		// 			q.push(nbr);
		// 			visited[nbr]=true;
		// 		}
		// 	}
		// }
		map<T, int> dist;
		map<T, T> parent;
		queue<T> q;

		for(auto node_pair : l){
			T node = node_pair.first;
			dist[node]=INT32_MAX;
		}
		q.push(src);
		dist[src]=0;
		parent[src]=src;
		while(!q.empty()){
			T node = q.front();
			q.pop();
			for(int nbr: l[node]){
				if(dist[nbr]==INT32_MAX){
					q.push(nbr);
					dist[nbr]=dist[node]+1;
					parent[nbr]=node;
				}
			}
		}
		T temp=dest;
		while(temp!=src){
			cout << temp << "<--";
			temp=parent[temp];
		}
		cout<<src<<endl;
		return dist[dest];
	}
};

int main()
{
	Faster;
	int board[50]={0};
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=10;
	board[32]=-2;
	board[34]=-22;
	Graph<int> g;
	int n=6;
	for(int i=0;i<=n*n;i++){
		for(int dice=1;dice<=6;dice++){
			int j=i+dice;
			j+=board[j];
			if(j<=n*n){
				g.addEdge(i,j);
			}
		}
	}
	g.addEdge(n*n,n*n);
	cout<<g.bfs(0, n*n,n);
	return 0;
}
