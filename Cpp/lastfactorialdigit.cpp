#include <bits/stdc++.h>
using namespace std;

int eval(int f) {
	int last = 1;
	while (f) {
		last = (f-- * last) % 10;
	}
	return last;
}

int main() {
	int cases;
	cin >> cases;
	int num;
	while (cases--) {
		cin >> num;
		cout << eval(num) << endl;	
	}
	return 0;
}
