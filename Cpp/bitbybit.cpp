#include <iostream>
using namespace std;

void fill(int a[]) {
	for(int i = 0; i < 32; i++) {
		*(a+i)=-1;	
	}
}

int main() {
	int mem[32];
	int instr;
	cin >> instr;
	while(instr) {
		fill(mem);
		while(instr) {
			string cmd;
			int i,j;
			cin >> cmd;	
			if(cmd== "SET") {
					cin >> i;
					mem[i] = 1;
			} else if(cmd== "CLEAR") {
					cin >> i;
					mem[i] = 0;
			} else if(cmd== "OR") {
					cin >> i >> j;
					if(mem[i]==1||mem[j]==1) {
						mem[i]=1;
					} else if(mem[i]==-1||mem[j]==-1){
						mem[i]=-1;
					} else mem[i]=0;
			} else {
				cin >> i >> j;
				if(mem[i]==0||mem[j]==0) {
					mem[i]=0;
				} else if(mem[i]==-1||mem[j]==-1) {
					mem[i]=-1;
				} else mem[i] = 1;
			}
			instr--;
		}
		string out ="";
		for(int i = 31; i >= 0; i--) {
			if(mem[i]==-1) out+="?";
			else out+=mem[i]+0x30;
		}
		cout << out << "\n";
		cin >> instr;
	}
}
