#include <iostream>
#include <map>
using namespace std;

void fastint(int& num) {
	int c = getchar();
	num = 0;
	for(; c>47 && c<58; c = getchar()) num = num*10+c-'0';
}

int main() {
	int s, c, k;
	map<int,int> socks;
	fastint(s);
	fastint(c);
	fastint(k);
	int temp;
	for(int i = 0; i < s; i++) {
		fastint(temp);
		if(socks.find(temp)==socks.end()) socks[temp] = 0;
		socks[temp]++;
	}	
//	for(map<int,int>::iterator it = socks.begin(); it!=socks.end(); it++) cout << it->first << " " << it->second << "\n";
	map<int,int>::iterator it = socks.begin();
	int washers = 0;
	int rem = c;
	int left = it->first;
	while(it!=socks.end()) {
		//check if within range
		if(it->first-left>k) {
			rem = c;
			washers++;
			left = it->first;
		}

		//update rem
		if(it->second>rem) {
			it->second-=rem;
			washers++;
			rem = c;
			left = it->first;	
		} else if(it->second<rem) {
			rem-=it->second;
			it->second = 0;
		} else {
			washers++;
			it->second = 0;
			rem = 0;
		}

		//check if out
		if(it->second==0) {
			it++;
			if(rem==0) {
				rem = c;
				left=it->first;
			}
		}
	}
	if(rem<c) washers++; // add final socks washer
	cout << washers << "\n";
		
	return 0;
}
