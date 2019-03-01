#include <iostream>
using namespace std;

int main() {
	int correct;
	cin >> correct;
	string his, yours;
	cin >> yours >> his;
	int len = yours.length();
	int diff = 0;
	for (int i = 0; i < len; i++) if(yours[i] != his[i]) diff++;
	/*
		min correct and same - accounts for correct answers we agreed on
		add anything he got wrong and we didnt agree on
			min len - correct and diff
	*/ 
	cout << (correct > len-diff ? len-diff : correct) + (len-correct > diff ? diff : len-correct) << endl;
	return 0;
}
