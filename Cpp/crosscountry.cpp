#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> nodes;

void fastint(int &num) {
	bool negative = false;
	int c;
	num = 0;
	c = getchar();
	if(c=='-'){
		negative = true;
		c = getchar();
	}
	for(;c>47 && c<58; c=getchar()) num = num*10+c-48;
	if(negative) num*=-1;
}	

struct Pair {
	int weight, pos;	
	bool operator<(Pair other) const {
		return weight > other.weight;
	}
};

int dijkstra(int start, int end) {
	priority_queue<Pair> pairs;
	set<int> visited;
	Pair* temp = new Pair;
	temp->weight = 0;
	temp->pos = start;
	pairs.push(*temp);
	int count = 0;
	while(pairs.top().pos != end && count < 10) {
		Pair cur = pairs.top(); 	
//		cout << cur.pos << " " << cur.weight << "\n";
		if(visited.find(cur.pos)==visited.end()) {
			for(int i = 0; i < nodes[cur.pos].size(); i++) {
				// add all of the neighbors to the pq
				if(i != cur.pos) {
					temp = new Pair;
					temp->pos = i;
					temp->weight = cur.weight + nodes[cur.pos][i];
					
					pairs.push(*temp);
				}
			}
		}
		visited.insert(cur.pos);
		pairs.pop();
//		count++;
	}
	return pairs.top().weight;
}

int main() {
	int n, s, t;
	fastint(n);
	fastint(s);
	fastint(t);
	int temp;
	nodes = vector<vector<int>>(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			fastint(temp);
			nodes[i].push_back(temp);
		}
	}
	cout << dijkstra(s,t) << "\n";	
	return 0;
}
