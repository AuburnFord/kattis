#include <bits/stdc++.h>
#include <iostream>
#include <bitset>
using namespace std;

void fastscan(int &number) {
	number = 0;
    for(int c = getchar(); c>47 && c <58; c=getchar()) number = number * 10 + c - 48;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int a,b;
    fastscan(a);
    fastscan(b);
    static bitset<10000001> seen;
    while(a||b){
        int t, count = 0;
        while(a--) {
            fastscan(t);
            seen.set(t);
        }   
        while(b--) {
            fastscan(t);
            if(seen.test(t)) count++;
        }
        cout << count << "\n";
        fastscan(a);
        fastscan(b);
        seen.reset();
    }
    return 0;
}
