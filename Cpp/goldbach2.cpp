#include <iostream>
#include <vector>
using namespace std;

int main() {
	bool prime[32001];
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i <= 32000; i++) {
		prime[i] = true;
	}
	for (int i = 2; i <= 32000; i++) {
		if (prime[i]) {
			for (int j = i*i; j<=32000; j+=i) {
				prime[j] = false;
			}
		}
	}
	int cases;
	int desired;
	vector<int> pairs;
	cin >> cases;
	while (cases > 0) {
		cin >> desired;
		for (int i = 2; i <= (desired+1)/2; i++) {
			if (prime[i] && prime[desired-i]) pairs.push_back(i);
		}	
		cout << desired << " has " << pairs.size() << " representation(s)" << endl;
		for (int i = 0; i < pairs.size(); i++) 
			cout << pairs[i] << "+" << desired-pairs[i] << endl;	
		cout << endl;
		pairs.clear();
		cases--;
	}
	return 0;
}
