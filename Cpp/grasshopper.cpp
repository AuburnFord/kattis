#include <iostream>
#include <queue>
#include <vector>

#define loc pair<int,int>
using namespace std;

bool bounded(loc pos, int num_r, int num_c) {
	if (pos.first >= 0 && pos.first < num_r && pos.second >= 0 && pos.second < num_c)
		return true;
	return false;
}

void bfs(loc start, loc dest, vector<vector<int>>& dist) {
	int r = dist.size();
	int c = dist[0].size();
	queue<loc> q;
	q.push(start);
	dist[start.first][start.second] = 0;
	
	loc moves[] = {
					loc(-2,1),
					loc(-1,2),
					loc(1,2),
					loc(2,1),
					loc(2,-1),
					loc(1,-2),
					loc(-1,-2),
					loc(-2,-1)
				};
	while (q.size()) {
		loc cur = q.front();
		q.pop();
		for(loc move: moves) {
			loc landing(cur.first+move.first,cur.second+move.second);
			if (bounded(landing, r, c) && dist[landing.first][landing.second] == -1) {
				q.push(landing);
				dist[landing.first][landing.second] = dist[cur.first][cur.second] + 1;
				if (landing.first == cur.first && landing.second == landing.second) {
					return;
				}
			}
		}
	}
}

int compute(loc start, loc end, int r, int c) {
	vector<vector<int>> dists (r);
	for (int i = 0; i < r; i++) {
		dists[i] = vector<int> (c,-1);
	}
	bfs(start, end, dists);
	return dists[end.first][end.second];
}

int main() {
	string results = "";
	int rows, columns, gr, gc, lr, lc, result;
	while (cin >> rows >> columns >> gr >> gc >> lr >> lc) {
		gr--;
		gc--;
		lr--;
		lc--;
		result = compute(loc (gr,gc), loc (lr,lc),rows,columns);
		if (result == -1)
			results+="Impossible\n";
		else
			results+=to_string(result)+'\n';
	}
	cout << results;
	return 0;
}
