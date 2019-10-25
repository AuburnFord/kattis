#include <bits/stdc++.h>
using namespace std;

void fastint(int& num) {
	num = 0;
	for (int c = getchar(); c > 47 && c < 58; c = getchar()) num = num * 10 + c - '0';
}

int main() {
	int capacity, stops;
	fastint(capacity);
	fastint(stops);	
	int off, on, wait, curr = 0;
	bool flag = true;
	while (flag && stops--) {
		fastint(off);
		fastint(on);
		fastint(wait);
		if (off > curr)
			flag = false;
		else {	
			curr -= off;
			if (curr + on > capacity)
				flag = false;
			else {
				curr += on;
				if (wait && capacity - curr)
					flag = false;
			}
		}
	}
	if (flag) {
		if (curr != 0 || wait != 0)
			flag = false;
	}
	if (flag)
		cout << "possible" << endl;
	else
		cout << "impossible" << endl;
	return 0;
}
