#include <iostream>
#include <unordered_set>
using namespace std;

int** mem;
int trees, people;

bool fastint(int& num) {
	int c = getchar();
	if(c==EOF) return false;
	num = 0;
	for(;c>47 && c<58; c=getchar()) num = num * 10 + c -'0';
	return true;
}

int main() {
	fastint(people);
	fastint(trees);
	mem = new int*[people+1];
	for(int i = 0; i < people+1; i++) {
		mem[i] = new int[trees+1];
		for(int j = 0; j < trees + 1; j++) mem[i][j] = 0;
	}
	int tree, pers;
	unordered_set<string> seen;
	while(fastint(pers)) {
		fastint(tree);
		mem[pers][tree] = 1;	
	}	
	for(int i = 1; i < (people+1); i++) {
		string temp = "";
		for(int j = 1; j < trees+1; j++) {
			temp += (mem[i][j]+'0');
		}
//		cout << temp << endl;
		seen.insert(temp);
	}
	cout << seen.size() << endl;
	return 0;
}
