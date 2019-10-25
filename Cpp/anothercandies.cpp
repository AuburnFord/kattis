#include <iostream>
#include <math.h>
using namespace std;

void fastll(long long& num) {
	int c = getchar();
	num = 0;
	for(;c>47 && c<58; c=getchar()) num = num*10 + c - '0';
}

int main() {
	int num;
	cin >> num;
	string out = "";
	while(num) {
		int total = 0;
		int kids;
		cin>>kids;
		getchar();
		long long candies;
		for(int i = 0; i < kids; i++) {
			fastll(candies);
			total += candies%kids;
			total %= kids;
		}
		if(!total)
			out+="YES\n";		
		else
			out+="NO\n";
		num--;
	}	
	cout << out;
	return 0;
}
