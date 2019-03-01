#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

long favourable(int page, unordered_map<int, vector<int>>* paths, unordered_map<int,long>* seen) {
	if(seen->find(page)!=seen->end()) {
		return (*seen)[page];	
	}
	long count = 0;
	for(vector<int>::iterator it = (*paths)[page].begin(); it!=(*paths)[page].end(); it++) {
		count += favourable(*it, paths, seen);
	}
	(*seen)[page]+=count;
	return count;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cases;
	cin >> cases;
	while(cases) {
		unordered_map<int,vector<int>> choice;
		unordered_map<int,long> seen;
		int choices;
		cin >> choices;
		while(choices) {
			int pageN;
			string end;
			int temp;
			cin >> pageN >> end;
			if(end=="favourably") seen[pageN] = 1;
			else if(end=="catastrophically") seen[pageN] = 0;
			else {
				choice[pageN].push_back(stoi(end));	
				cin >> temp;
				choice[pageN].push_back(temp);
				cin >> temp;
				choice[pageN].push_back(temp);
			}	
			choices--;
		}
		cout << favourable(1, &choice, &seen) << "\n";	
		cases--;
	}
	return 0;
}
