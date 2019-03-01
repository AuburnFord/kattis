#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int trips, queries;
	cin >> trips;
	unordered_map<string, vector<int>> trip;
	for (int i = 0; i < trips; i++) {
		string loc;
		int yr;
		cin >> loc >> yr;
		trip[loc].push_back(yr);
	}	
	for(unordered_map<string, vector<int>> :: iterator it = trip.begin(); it != trip.end(); it++) {
		sort(it->second.begin(),it->second.end());
	}
	cin >> queries;
	for (int i = 0; i < queries; i++) {
		string loc;
		int num;
		cin >> loc >> num;
		cout << trip[loc][num-1] << endl;
	}
	return 0;
}
