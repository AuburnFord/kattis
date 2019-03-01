#include <iostream>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

int bfs(string start, string target, bool* primes, char* nums) {
	bool visited[10000] = {};
	int steps = 0;
	queue<string>* q = new queue<string>;
	queue<string>* nq = new queue<string>;
	while(start != target) {
		for(int i = 0; i < start.length(); i++) {
			for(int j = (i==0 ? 1:0); j < 10; j++) {
				string a = start.substr(0,i) + nums[j] + start.substr(i+1);
				if(primes[stoi(a)] && !visited[stoi(a)]) {
					nq->push(a);
					visited[stoi(a)] = true;
				}
			}
		}		
		if (q->empty()) {
			steps++;
			if(nq->empty()) return 0;
			else {
				delete q;
				q = nq;
				nq = new queue<string>;
			}
		}
		start=q->front();	
		q->pop();
	}
	return steps;
}

int main() {
	int cases;
	cin >> cases;
	bool prime[10000];
	for (int i = 0; i < 10000; i++) prime[i] = true;
	for (int i = 2; i <= sqrt(10000); i++) {
		if(prime[i]) {
			for (int j = i*i; j < 10000; j+=i) {
				prime[j] = false;
			}
		}
	}
	char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
	while (cases) {
		string start, target;
		cin >> start >> target;
		int res = bfs(start, target, prime, nums);
		if (res == -1) cout << "Impossible\n";
		else cout << res << "\n";
		cases--;
	}
	return 0;
}
