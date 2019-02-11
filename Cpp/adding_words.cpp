#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

void calc(string cmd);

unordered_map<string, int> varVal;
unordered_map<int, string> valVar;

int main() {
	string next;
	while (cin >> next) {
		if(next == "def") {
			string var;
			int val;
			cin >> var >> val;
			if(varVal.find(var)!=varVal.end()){
				valVar.erase(varVal[var]);
			}
			varVal[var] = val;
			valVar[val] = var;
		} else if(next == "clear") {
			varVal.clear();
			valVar.clear();
		} else if(next == "calc") {
			string cmd;
			getline(cin, cmd);
			calc(cmd);
		}
	}
	return 0;
}

void calc(string cmd) {
	istringstream input(cmd.substr(1));
	char s = '+';
	string var;
	int sum = 0;
	while(input >> var) {
		if(varVal.find(var) != varVal.end()) {
			if (s == '+') {
				sum += varVal[var];
			} else {
				sum -= varVal[var];
			}
			input >> s;
		} else {
			cout << cmd.substr(1) << " unknown" << endl;
			return;
		}
	}	
	if(valVar.find(sum) != valVar.end()) {
		cout << cmd.substr(1) << " " << valVar[sum] << endl;
	} else {
		cout << cmd.substr(1) << " unknown" << endl;
	}
	return;
}
