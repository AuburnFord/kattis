#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	string out = "";
	string in;
	cin >> in;
	out.push_back(in.at(0));
	for (int i = 1; i < in.length() - 1; i++) {
		if (in.at(i) == '-') {
			out.push_back(in.at(i+1));
		}
	}
	cout << out << endl;
	return 0;
}
