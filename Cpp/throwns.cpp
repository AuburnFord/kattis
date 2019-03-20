#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int k, c;
	stack<int> a;
	a.push(0);
	cin >> k >> c;
	for(int i = 0; i < c; i++) {
		string next;
		int val;
		cin >> next;
		if(next == "undo") {
			cin >> val;
			while(val--) {
				a.pop();
			}
		} else {
			val = stoi(next);	
			int sum = a.top() + val;
			while(sum < 0) {
				sum += k;
			}
			a.push(sum%k);
		}	
	}	
	cout << a.top() << "\n";
	return 0;
}
