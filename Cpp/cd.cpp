#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	while(a||b){
		unordered_set<int> seen;
		int t, count = 0;
		while(a--) {
			cin >> t;
			seen.insert(t);
		}	
		while(b--) {
			cin >> t;
			if(seen.find(t)!=seen.end()) count++;
		}
		cout << count << "\n";
		cin >> a >> b;
	}
	return 0;
}
