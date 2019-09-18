#include <iostream>
#include <queue>
#include <set>
using namespace std;

int** mem;
int** steps;
int n, m;

int bfs() {
	queue<int> q;
	q.push(0);
	int val;
	set<int> seen;
	steps[0][0] = 0;
	while(q.size() != 0 && q.front() != n*m-1) {
		val = q.front();
		q.pop();
		if(seen.find(val) != seen.end()) continue;	
		int x = val%m;
		int y = val/m;
		int z = mem[y][x];
		seen.insert(val);
		if(x+z < m && seen.find(y*m + x + z) == seen.end()) {
			if(steps[y][x+z] == -1) {
				q.push(y*m+x+z);
				steps[y][x+z] = steps[y][x]+1;
			}
		}	
		if(x-z >= 0 && seen.find(y*m + x -z) == seen.end()) {
			if(steps[y][x-z] == -1) {
				q.push(y*m+x-z);
				steps[y][x-z] = steps[y][x]+1;
			}
		}	
		if(y+z < n && seen.find((y+z)*m + x) == seen.end()) {
			if(steps[y+z][x] == -1) {
				q.push((y+z)*m + x);
				steps[y+z][x] = steps[y][x]+1;
			}
		}	
		if(y-z >= 0 && seen.find((y-z)*m+x) == seen.end()) {
			if(steps[y-z][x] == -1) {
				q.push((y-z)*m+x);
				steps[y-z][x] = steps[y][x]+1;
			}
		}	
	}
	return steps[n-1][m-1];
}

int main() {
	cin >> n >> m;	
	mem = new int*[n];
	steps = new int*[n];
	getchar();
	for(int i = 0; i < n; i++) {
		mem[i] = new int[m];
		steps[i] = new int[m];
		for(int j = 0; j < m; j++) {
			mem[i][j] = (getchar()-'0');
			steps[i][j] = -1;
		}
		getchar();
	}	
	cout << bfs() << endl;	
	return 0;
}
