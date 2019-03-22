#include <iostream>
#include <cstdlib>
using namespace std;

void fastIn(int &val) {
	int c = getchar();
	while(c=='\n') {
		c = getchar();
	}
	val = c-'0';
}

int find(int child, int* parent) {
	if(child == parent[child]) return child;
	if(parent[child] == -1) return -1;
	return parent[child] = find(parent[child], parent);
}

void unionF(int a, int b, int* parent) {
	if(parent[a] == -1) {
		parent[find(b,parent)] = -1;
		return;
	}
	if(parent[b] == -1) {
		parent[find(a,parent)] = -1;
		return;
	}
	if(find(a,parent) == find(b,parent)) return;	
	parent[find(a,parent)] = parent[find(b,parent)];
}

int main() {
	int h, w;
	cin >> h >> w;
	int* map = new int[h*w];
	int* parent = new int[h*w+1];
	parent[h*w] = -1;
	// Get all tiles and init parent to self
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			fastIn(map[i*w+j]);
			parent[i*w+j] = i*w+j;
		}
	}
	// Union all edge water with sea(h*w)
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(map[i*w+j] == 0 && (i==0||i==h-1||j==0||j==w-1)) {
				unionF(i*w+j, h*w, parent);			
			}
		}
	}
	// Print all tiles
//	for(int i = 0; i < h; i++) {
//		for(int j = 0; j < w; j++) {
//			cout << map[i*w+j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << endl;
	
	// Print parent of tiles
//	for(int i = 0; i < h; i++) {
//		for(int j = 0; j < w; j++) {
//			cout << parent[i*w+j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << parent[h*w] << endl;

	// Union all water tiles
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(map[i*w+j]==0) {
				if(i-1>=0 && map[(i-1)*w+j] == 0) unionF(i*w+j,(i-1)*w+j,parent);
				if(i+1<h && map[(i+1)*w+j] == 0) unionF(i*w+j,(i+1)*w+j,parent);
				if(j-1>=0 && map[i*w+j-1] == 0) unionF(i*w+j,i*w+j-1,parent);
				if(j+1<w && map[i*w+j+1] == 0) unionF(i*w+j,i*w+j+1,parent);
			}
		}
	}

	// Print parent of tiles
//	for(int i = 0; i < h; i++) {
//		for(int j = 0; j < w; j++) {
//			cout << parent[i*w+j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << parent[h*w] << endl;
	int count = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(map[i*w+j] == 1) {
				if(i-1>=0 && find((i-1)*w+j,parent) == find(h*w,parent)) count++;
				if(i+1<h && find((i+1)*w+j,parent) == find(h*w,parent)) count++;
				if(j-1>=0 && find(i*w+j-1,parent) == find(h*w,parent)) count++;
				if(j+1<w && find(i*w+j+1,parent) == find(h*w,parent)) count++;
				if(i==0) count++; 
				if(i==h-1) count++;
				if(j==0) count++;
				if(j==w-1) count++;
			}
		}
	}
	cout << count << "\n";
	return 0;
}
