#include <iostream>
#include <unordered_set>
using namespace std;

void rotate(char** grill, int len) {
	for(int i = 0; i<len/2; i++) {
		for(int j = i; j < len-i-1; j++) {
			char temp = grill[i][j];
			grill[i][j] = grill[len-1-j][i];
			grill[len-1-j][i] = grill[len-1-i][len-1-j];
			grill[len-1-i][len-1-j] = grill[j][len-1-i];
			grill[j][len-1-i] = temp;	
		}
	}
}

int main() {
	int n;
	cin >> n;
	int window = 0;
	getchar();
	char** grill = new char*[n];
	for(int i = 0; i < n; i++) {
		grill[i] = new char[n];
		for(int j = 0; j < n; j++) {
			grill[i][j] = getchar();
			if(grill[i][j] == '.') window++;
		}
		getchar();
	}
	string scram, decrypt = "";
	for(int i = 0; i < n*n; i++) decrypt+="?";
	cin >> scram;
	int loc = 0;
	unordered_set<int> seen;
	for(int i = 0; i < 4; i++) {
		for(int y = 0; y < n; y++) for(int x = 0; x < n; x++) if(grill[y][x]=='.') {
			seen.insert(y*n+x);
			if(loc>=n*n) {
				cout << "invalid grille\n";
				return 0;
			}
			if(decrypt[y*n+x]=='?') decrypt[y*n+x] = scram[loc++];		
		}
		rotate(grill,n);
	}	
	string out = "";
	for(int i = 0; i < n*n; i++) {
		if(decrypt[i]=='?') {
			out = "invalid grille";
			break;
		} else out+=decrypt[i];
	}
	cout << out << endl;
	return 0;
}
