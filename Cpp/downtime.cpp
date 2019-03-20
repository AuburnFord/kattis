#include <iostream>
#include <queue>
using namespace std;

int main() {
	int reqs, per, temp, max = 1;
	cin >> reqs >> per;
	queue<int> queue;	
	reqs--;
	cin >> temp;
	queue.push(temp);
	while(reqs--) {
		cin >> temp;
		while(!queue.empty() && temp-queue.front()>=1000) {
			queue.pop();
		}
		queue.push(temp);
		if(max<queue.size())max = queue.size();
	}
	cout << (max+per-1)/per << "\n";
	return 0;
}
