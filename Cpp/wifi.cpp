#include <bits/stdc++.h>

using namespace std;

void countingsort(int tosort[], int length) {
	static int sort[1000001];
	for(int i = 0; i < length; i++) {
		sort[tosort[i]]++; 
	}
	int i = 0;
	for(int x = 0; x < 1000001; x++) {
		while(sort[x]) {
			tosort[i++] = x;
			sort[x]--;
		}
	}
}

int ap_needed(int houses[], int interval_width, int house_length) {
	int count = 0;
	int end_interval = -1;
	for(int house = 0; house < house_length; house++) {
		if(houses[house] > end_interval) {
			end_interval = houses[house] + interval_width;
			count++;
		}
	}
	return count;
}

void compute() {
	int aps, num_houses;
	cin >> aps >> num_houses;
	int* houses;
	houses = new int[num_houses];
	for(int i = 0; i < num_houses; i++)
		cin >> houses[i];
	countingsort(houses, num_houses);
	int lo = 0;
	// largest interval is at most largest house # - (smallest house + num houses - 1) 
	int hi = houses[num_houses-1];
	while(hi > lo) {
		int m = (hi+lo)/2;
		// the number of aps to cover given the current interval	
		int needed = ap_needed(houses, m, num_houses);
		if(needed > aps)
			lo = m + 1;
		else
			hi = m;
	}
	delete [] houses;	
	cout << lo/2.0 << endl;
}

int main() {
	int cases;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
	cin >> cases; 
	cout << fixed;
	cout.precision(1);
	while(cases--)
		compute();
	return 0;
}
