#include <iostream>
using namespace std;

int fastint(int& num) {
	int c = getchar();
	num = 0;
	for(;c>47 && c<58; c = getchar()) num = num *10 + c - '0';
	return c;
}

void swap(char& c) {
	if(c=='#') c = '.';
	else c = '#';
}

int main() {
	int lines;
	cin >> lines;
	getchar();
	bool first = true;
	bool img = false;
	while(lines) {
		img = true;
		string out = "";
		int sum = 0;
		char c = getchar();	
		getchar();
		int val;
		while(fastint(val) != '\n') {
			sum += val;
			for(int i = 0; i < val; i++) {
				out+=c;
			}
			swap(c);
		}
		sum += val;
		for(int i = 0; i < val; i++) {
			out+=c;
		}
		out+='\n';
		int total = 0;
		lines--;
		while(lines) {
			c = getchar();	
			getchar();
			while(fastint(val) != '\n') {
				total += val;
				for(int i = 0; i < val; i++) {
					out+=c;
				}
				swap(c);
			}
			total += val;
			for(int i = 0; i < val; i++) {
				out+=c;
			}
			out+='\n';
			if(total!=sum) img = false;
			total = 0;
			lines--;
		}
		if(!img) out += "Error decoding image\n";
		cin >> lines;
		getchar();
		if(first) {
			first = false;
		} else cout << "\n";
		cout << out;
	}
	return 0;
}
