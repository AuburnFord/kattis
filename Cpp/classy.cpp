#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct person{
	string name;
	long class_id;
};

bool compPers(person a, person b) {
	if(a.class_id == b.class_id)
		return a.name.compare(b.name) > 0 ? false : true;
	else
		return a.class_id > b.class_id;
}

int idv(string a) {
	if(a == "upper")
		return 3;
	else if(a == "middle") 
		return 2;
	else 
		return 1;
}

void getname(string& name) {
	char c = getchar();
	name = "";
	for(; c!=':'; c = getchar()) name+=c;
	getchar(); // clear space
}

void getid(long& id) {
	stack<int> a;
	string cl = "";
	char c = getchar();
	while(c!='-'&&c!=' ') {
		cl += c;
		c = getchar();
	}	
	a.push(idv(cl));
	while(c == '-') {
		cl = "";
		c = getchar();
		while(c!='-' && c!=' ') {
			cl += c;
			c = getchar();
		}
		a.push(idv(cl));
	}
	for(int i = 0; i < 6; i++) getchar();
	int extra = 10 - a.size();
	id = 0;
	while(a.size()) {
		id = id*10 + a.top();
		a.pop();
	}
	while(extra--) {
		id = id*10 + 2;
	}
}

int main() {
	int cases;
	cin >> cases;
	string out = "";
	while(cases--) {
		int people;
		cin >> people;
		getchar();
		vector<person> p;
		while(people--) {
			person temp;
			getname(temp.name);
			getid(temp.class_id);	
			p.push_back(temp);
		}	
		sort(p.begin(), p.end(), compPers);
		for(auto it = p.begin(); it!= p.end(); it++) {
//			cout << it->name << " " << it->class_id << endl;
			out += it->name + "\n";
		}
		out +="==============================\n";
	}
	cout << out;
	return 0;
}
