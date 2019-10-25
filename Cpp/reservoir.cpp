#include <iostream>
using namespace std;

struct wall {
	int height; // height of current wall
	int loc; // x coord
	long cap; // capacity
	long htSum; // sum of all walls shorter until last taller
	int last; // idx of last wall taller, store self if tallest
	
};

void fastint(int& num) {
	int c = getchar();
	num = 0;
	for(; c>47 && c<58; c=getchar()) num = num*10 + c -'0';
}

void fastlong(long& num) {
	int c = getchar();
	num = 0;
	for(; c>47 && c<58; c=getchar()) num = num*10 + c -'0';
}

int bSearch(wall walls[], int num, long req) {
	int l = 0;
	int r = num-1;
	while (l<r){
		int m = l+(r-l)/2;
		if (walls[m].cap == req)
			return m;	
		if (walls[m].cap > req)
			r = m;
		else
			l = m + 1;
	}
	if(walls[r].cap < req) return num;
	return r;
}

int main() {
	int cases;
	fastint(cases);
	while(cases--) {
		int walls;
		fastint(walls);
		wall* revs = new wall[walls];
		for(int i = 0; i < walls; i++) {
			fastint(revs[i].loc);	
		}
		int idx=0;
		fastint(revs[idx].height);
		revs[idx].last = -1;
		revs[idx].htSum = revs[idx].height;
		revs[idx].cap = revs[idx].loc * revs[idx].height;
		idx++;
		while(idx < walls) {
			// calc contains
			// this is tough: Need to account for varying heights ie: real tall then short, then tallest
			// maybe not? instead of subtractive, how bout additive?
			// combination of both?
			fastint(revs[idx].height);
			// check if last wall was shorter
			int i = idx - 1;
			long htTrack = 0;
			while(i >= 0 && revs[i].height < revs[idx].height) {
				htTrack += revs[i].htSum;	
				i = revs[i].last;
			}	
			revs[idx].last = i;
			revs[idx].htSum = htTrack + revs[idx].height;
			if(i != -1) {
				revs[idx].cap = ((long)revs[idx].loc - 1 - revs[i].loc) * revs[idx].height - htTrack + revs[i].cap;
			} else {
				// current wall is tallest yet
				revs[idx].cap = (long)revs[idx].loc * revs[idx].height - htTrack;
			}
			idx++;	
		}
//		for(int i = 0; i < walls; i++) {
//			cout << revs[i].cap << " ";
//		}
//		cout << endl;
		int reqs;
		fastint(reqs);
		string out = "";
		long req;
		while(reqs--) {
			fastlong(req);
			out += to_string(bSearch(revs, walls, req)) + "\n";
		}
		cout << out;	
	}	
	return 0;
}
