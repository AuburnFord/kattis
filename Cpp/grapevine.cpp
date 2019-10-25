#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void fastint(int& num) {
	int c = getchar();
	num = 0;
	for(; c>47 && c<58; c=getchar()) num = num * 10 + c -'0';
}

void faststring(string& name) {
	char c = getchar();
	name = "";
	for(; (c>64 && c<91) || (c>96 && c<123) || (c>47 && c<58); c = getchar()) name.push_back(c);	
}

int main() {
	int num_people, connections, days;
//	cin >> num_people >> connections >> days;
	fastint(num_people);	
	fastint(connections);	
	fastint(days);	
	unordered_map<string, int> status;	
	for(int i = 0; i < num_people; i++) {
		string name;
		int resist;
//		cin >> name >> resist;
		faststring(name);
		fastint(resist);
		status[name] = resist;
	}
	// friendships
	unordered_map<string, unordered_set<string>> friends;
	for(int i = 0; i < connections; i++) {
		string name1, name2;
//		cin >> name1 >> name2;
		faststring(name1);
		faststring(name2);	
		friends[name1].insert(name2);
		friends[name2].insert(name1);
	}
	string start;
//	cin >> start;
	faststring(start);
	unordered_set<string> heard;
	heard.insert(start);
	queue<string> q;
	q.push(start);
	int count = 0;
	for(int i = 0; i < days; i++) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			string current = q.front();
			for(auto it = friends[current].begin(); it!=friends[current].end(); it++) {
				friends[*it].erase(current);
				if(heard.find(*it)==heard.end()) {
					count++;
					heard.insert(*it);
				}
				status[*it]--;
				if(status[*it]==0) {
					q.push(*it);
				}
			}
			q.pop();
		}
	}	
	cout << count << endl;
	return 0;
}
