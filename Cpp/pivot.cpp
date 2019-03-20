#include <iostream>
using namespace std;
void fastint(int &num) {
	bool negative = false;
	int c;
	num = 0;
	c = getchar();
	if(c=='-'){
		negative = true;
		c = getchar();
	}
	for(;c>47 && c<58; c=getchar()) num = num*10+c-48;
	if(negative) num*=-1;
}	

int main() {
	int N;
	fastint(N);
	int* in = new int[N];
	int* maxL = new int[N];
	int max=-1,count=0,i;
	for(i = 0; i < N; i++) {
		fastint(in[i]);
		if(in[i]>max)max=in[i];
		maxL[i]=max;//set maxofuptoinclusive
	}	
	for(i = N-1; i>-1;i--) {
		if(in[i]<max)max=in[i];//keep track of smallest number
		if(max==maxL[i]) count++; //update when smallest number seen so far is larger than all left (ie valid pivot)	
	}
	cout << count << "\n";
	return 0;
}
