#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;

struct tup {
	int val;
	int pos;
};

bool operator < (const tup &t1, const tup &t2) {
	/* NOTE: C++ priority queue pushes highest val to top! Java pq relies on NATURAL ORDERING */
	// Java PQ: 1 2 3 4 5
	// C++ PQ: 5 4 3 2 1
	return (t1.val > t2.val);
}

void fastint(int& num) {
	int c = getchar();
	num = 0;
	for(; c>47 && c<58; c=getchar()) num = num * 10 + c - '0';
}

void dijkstra(map<int, map<int,int>>& neighbors, map<int,int>& dist, int start) {
	priority_queue<tup> pq;	
	tup temp1;
	temp1.pos = start;
	temp1.val = 0;
	pq.push(temp1);
	while(pq.size() != 0) {
		tup curr = pq.top();
		pq.pop();
		if(dist[curr.pos] == -1) {
			for(auto it = neighbors[curr.pos].begin(); it!=neighbors[curr.pos].end(); it++) {
				tup temp;	
				temp.pos = it->first;
				temp.val = curr.val + it->second;
				pq.push(temp);
			}
			dist[curr.pos] = curr.val;
		}
	}
}

int main() {
	int n, m, q, s;
	string out = "";
	fastint(n);
	fastint(m);
	fastint(q);
	fastint(s);
	while(n || m || q || s) {
		map<int, map<int,int>> neighbors;
		for(int i = 0; i < m; i++) {
			int u, v, d;
			fastint(u);		
			fastint(v);		
			fastint(d);		
			if(neighbors.count(u)) {
				if(neighbors[u].count(v)) {
					if(neighbors[u][v] > d) {
						neighbors[u][v] = d;
					}
				} else {
					neighbors[u][v] = d;
				}
			} else {
				neighbors[u][v] = d;
			}
		}
//		for(auto it = neighbors.begin(); it!=neighbors.end(); it++) {
//			for(auto it2 = it->second.begin(); it2!=it->second.end(); it2++) {
//				cout << it->first << " " << it2->first << " " << it2->second << endl;
//			}
//		}
		map<int, int> dist;
		for(int i = 0; i < n; i++) {
			dist[i] = -1;
		}
		dijkstra(neighbors, dist, s);
		for(int i = 0; i < q; i++) {
			int req;
			fastint(req);
			if(dist[req] == -1)
				out += "Impossible\n";
			else
				out += to_string(dist[req]) + "\n";	
		}
//		for(auto it = dist.begin(); it!=dist.end(); it++) {
//			cout << it->first << " " << it->second << endl;
//		}
		out += "\n";
		fastint(n);
		fastint(m);
		fastint(q);
		fastint(s);
	}
	out.pop_back();
	cout << out;
				
	return 0;
}
