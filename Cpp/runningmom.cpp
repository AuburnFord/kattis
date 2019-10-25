#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool cycle_util(vector<string>& stack, unordered_set<string>& seen, unordered_set<string>& set_stack, unordered_map<string,unordered_set<string>>& edges) {
	string cur = stack.back();
	if (edges.find(cur) != edges.end()) {
		for (auto it = edges[cur].begin(); it != edges[cur].end(); it++) {
			if (seen.find(*it) != seen.end() && set_stack.find(*it) != set_stack.end()) {	
					return true;
			} else {
				stack.push_back(*it);
				set_stack.insert(*it);
				seen.insert(*it);
				bool result = cycle_util(stack, seen, set_stack, edges);
				if (!result) {
					set_stack.erase(stack.back());
					stack.pop_back();
				} else {
					return result;
				}
			}
		}
	}
	return false;	
}

bool find_cycle(string start, unordered_map<string,unordered_set<string>>& edges) {
	vector<string> stack;
	stack.push_back(start);

	unordered_set<string> set_stack;
	set_stack.insert(start);

	unordered_set<string> seen;
	seen.insert(start);	
	
	return cycle_util(stack, seen, set_stack, edges);
}

int main() {
	int edges;
	cin >> edges;
	string loc1, loc2;
	unordered_map<string,unordered_set<string>> flights;
	while(edges--) {
		cin >> loc1 >> loc2;	
		flights[loc1].insert(loc2);
	}	
//	for(auto it = flights.begin(); it!=flights.end(); it++) for(auto it2 = (*it).second.begin(); it2 != (*it).second.end(); it2++) cout << (*it).first << ": " << *it2 << endl; 
	string query;
	while (cin >> query) {
		cout << query << " " << (find_cycle(query, flights) ? "safe" : "trapped") << endl;
	}
	return 0;	
}
