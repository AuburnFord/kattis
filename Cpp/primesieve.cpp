#include <iostream>
#include <bitset>
using namespace std;

int main() {
	int top, q;
	cin >> top >> q;
	static bitset<100000001> prime (0x0);
	prime.set(1);
	int count = 0;
	int i;
	for (i = 2; i*i <= top; i++) {
		if(!prime[i]) {
			count++;
			for(int j = i*i; j <= top; j+=i) {
				prime.set(j);
			}
		}
	}
	while(i<=top) {
		if(!prime[i]) count++;
		i++;
	}
	cout << count << "\n";
	int query;
	while(q) {
		q--;
		cin >> query;
		cout << (prime[query] ? 0 : 1) << "\n";
	}
	return 0;
}
