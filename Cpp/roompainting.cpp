#include<iostream>
using namespace std;

int* mem;
int cans;

void fastint(int& num) {
	int c;
	num = 0;
	c = getchar();
	for(;c>47 && c<58; c=getchar()) num=num*10+c-'0';
}

int fastintNoStore() {
	int c;
	int num = 0;
	c = getchar();
	for(;c>47 && c<58; c=getchar()) num=num*10+c-'0';
	return num;
}

void merge(int l, int m, int r) {
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	
	for(i = 0; i < n1; i++) 
		L[i] = mem[l+i];
	for(j = 0; j < n2; j++)
		R[j] = mem[m+1+j];

	i = 0;
	j = 0;
	k = l;
	while(i<n1 && j<n2) {
		if(L[i]<= R[j]) {
			mem[k] = L[i];
			i++;
		} else {
			mem[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<n1) {
		mem[k] = L[i];
		i++;
		k++;
	}
	while(j<n2) {
		mem[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int l, int r) {
	if (l<r) {
		int m = l+(r-l)/2;
		mergeSort(l, m);
		mergeSort(m+1, r);
		merge(l, m, r);
	}
}

int minWaste(int req) {
	int l = 0;
	int r = cans-1;
	while (l<r){
		int m = l+(r-l)/2;
		if (mem[m] == req)
			return 0;	
		if (mem[m] > req)
			r = m;
		else
			l = m + 1;
	}
	while(mem[r]>req)
		r--;
	r++;
	return mem[r] - req;
}

int main() {
	int r;
	fastint(cans);	
	fastint(r);
	mem = new int[cans];
	for(int i = 0; i < cans; i++) {
		fastint(mem[i]);
	}
	mergeSort(0, cans-1);
	long waste = 0;
	for(int i =0; i < r; i++) {
		waste += minWaste(fastintNoStore());
	}
	cout << waste << endl;
	return 0;
}
