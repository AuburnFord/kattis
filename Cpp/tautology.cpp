#include <iostream>
#include <stack>

using namespace std;

char get_val(char c, int cases) {
	bool r;	
	switch (c) {
		case 'p': r = (cases & 16) == 16;
			break;
		case 'q': r = (cases & 8) == 8;
			break;
		case 'r': r = (cases & 4) == 4;
			break;
		case 's': r = (cases & 2) == 2;
			break;
		case 't': r = (cases & 1) == 1;
			break;
	}
	return (r ? '1' : '0');
}

string build_str(string& s, int cases) {
	string r;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a') {
			r.push_back(get_val(s[i], cases));
		} else r.push_back(s[i]);
	}
	return r;
}

int logic(int a, int b, char o) {
	int r;
	switch (o) {
		case 'K': r = (a && b ? 1 : 0);
			break;
		case 'A': r = (a || b ? 1 : 0);
			break;
		case 'C': r = ((!a || (a && b)) ? 1 : 0);
			break;
		case 'E': r = (a == b ? 1 : 0);
			break;
	}
	return r;
}

bool eval(string s) {
	int cases = 0;
	bool state = true;
	while (cases < 32) {
		string temp = build_str(s, cases);		
//		while (!ops.empty()) {
//			cout << ops.top() << " ";
//			ops.pop();
//		}
//		cout << endl;
//		while (!vals.empty()) {
//			cout << vals.top() << " ";
//			vals.pop();
//		}
//		cout << endl;
//		cout << (!ops.empty() && !vals.empty()) << endl;
		while (temp.length() > 1) {
			stack<char> vals;
			while (temp.back() < 'A' || temp.back() >= 'a') {
				vals.push(temp.back());
				temp.pop_back();	
			}
			if (temp.back() == 'N') {
				temp.pop_back();
				int t = vals.top() - '0';
				vals.pop();	
				temp.push_back(t == 1 ? '0' : '1');
			} else {
				int a = vals.top() - '0';
				vals.pop();
				int b = vals.top() - '0';
				vals.pop();
				char op = temp.back();
				temp.pop_back();	
				int r = logic(a,b,op);
//				cout << "c: " << cases << " a: " << a << " b: " << b << " op: " << op << " res: " << r << endl;
				temp.push_back(r + '0');
			}
			while (!vals.empty()) {
				temp.push_back(vals.top());
				vals.pop();
			}	
		}
		state &= (temp.back() == '1');
		cases++;
	}	
	return state;
}

int main() {
	string s;
	cin >> s;
	while (s != "0") {
		cout << (eval(s) ? "tautology" : "not") << endl;
		cin >> s;	
	}
//	for (int i = 0; i < 32; i++) {
//		cout << get_val('p',i) << get_val('q',i) << get_val('r',i) << get_val('s',i) << get_val('t',i) << endl;
//	}
//	for (int i = 0; i < 4; i++) {
//		int b = get_val('t', i);
//		int a = get_val('s', i);
//		cout << a << " " << b << " " <<  logic(a,b,'K') << " " << logic(a,b,'A') << " " << logic(a,b,'C') << " " << logic(a,b,'E') << endl;
//	}	
	return 0;
}
