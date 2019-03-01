#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while(cases) {
		int a;
		cin >> a;
		unordered_map<string,unordered_set<string>> attr;	
		for(int i = 0; i<a; i++) {
			string at, cat;
			cin >> at >> cat;
			attr[cat].insert(at);
		}
		int count = 1;
		for(unordered_map<string,unordered_set<string>>::iterator it = attr.begin(); it!=attr.end(); it++) {
			count*=it->second.size()+1;	
		}
		cout << --count << "\n";
		cases--;
	}
}
