#include <iostream>
using namespace std;

void fastint(int &num) {
	int c;
	num = 0;
	c = getchar();
	for(;c>47&&c<58;c=getchar()) num=num*10+c-48;
}

int main() {
	int a,b;
	fastint(a);
	fastint(b);
	int count,lcarry;
	while(a||b) {
		count = 0;
		lcarry = 0;
		while(a||b) {
			if (a%10 + b%10 + lcarry > 9) {
				count++;
				lcarry=1;		
			} else lcarry = 0;
			a/=10;
			b/=10;
		}	
		if(count == 1) {
			cout<<count<<" carry operation.\n";
		} else if(count == 0) {
			 cout<<"No carry operation.\n";
		} else cout<<count<<" carry operations.\n";
		fastint(a);
		fastint(b);
	}
	return 0;
}
