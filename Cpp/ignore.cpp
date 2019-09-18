#include <iostream>
using namespace std;

bool fastint(int& num) {
	int c;
	c = getchar();
	if(c==EOF) {
		return false;
	}
	num = 0;
	for(; c>47 && c<58; c = getchar()) {
		num = num*10 + c - 48;
	}
	return true;
}


// valid chars 0 1 2 5 6 8 9
int main() {
	int val;
	string out = "";
	while(fastint(val)) {
		while(val>0) {
			int rem = val%7;
			val /=7;
			if(rem==3) out+='5';
			else if(rem==4) out+=('9');	
			else if(rem==5) out+=('8');	
			else out+=('0' + rem);
		}	
		out += '\n';
	}
	cout << out;
	return 0;
}
