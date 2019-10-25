#include <iostream>
using namespace std;

void fastint(int& num) {
	int c;
	num = 0;
	c = getchar();
	for(; c>47  && c < 58; c = getchar()) num = num*10+c-'0';
}

const int nxt[8][3] = {
	{4,2,1},
	{5,3,0},
	{6,0,3},
	{7,1,2},
	{0,6,5},
	{1,7,4},
	{2,4,7},
	{3,5,6}
};

string print(int n) {
	if(n==0) return "NNN";
	if(n==1) return "NNY";
	if(n==2) return "NYN";
	if(n==3) return "NYY";
	if(n==4) return "YNN";
	if(n==5) return "YNY";
	if(n==6) return "YYN";
	if(n==7) return "YYY";
}

int main() {
	int cases, priests, c0, c1, c2;
	fastint(cases);
	string out = "";
	while(cases--) {
		fastint(priests);	
		int des[priests][8], fav[priests][8];
		for(int i = 0; i < priests; i++) for(int j = 0; j < 8; j++) fastint(des[i][j]);
		// figure out best flip based on cur state
		for(int i = 0; i < 8; i++) {
			c0 = des[priests-1][nxt[i][0]];
			c1 = des[priests-1][nxt[i][1]];
			c2 = des[priests-1][nxt[i][2]];
			if(c0 < c1 && c0 < c2) fav[priests-1][i] = nxt[i][0];
			else if(c1 < c2) fav[priests-1][i] = nxt[i][1];
			else fav[priests-1][i] = nxt[i][2];
		}
		for(int i = priests-2; i>=0; i--) {
			for(int j = 0; j < 8; j++) {
				c0 = des[i][fav[i+1][nxt[j][0]]];
				c1 = des[i][fav[i+1][nxt[j][1]]];
				c2 = des[i][fav[i+1][nxt[j][2]]];
				if(c0 < c1 && c0 < c2) fav[i][j] = fav[i+1][nxt[j][0]];
				else if(c1 < c2) fav[i][j] = fav[i+1][nxt[j][1]];
				else fav[i][j] = fav[i+1][nxt[j][2]];
			}
		}
		out+=print(fav[0][0]);
		out+='\n';
	}
	cout << out;
	return 0;
}
