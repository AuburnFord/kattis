#include <cstdlib>
#include <iostream>
using namespace std;


int board[4][4];

int main() {
	int dir;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> board[i][j];
		}
	}
	cin >> dir;
	switch(dir) {
		case 0: 
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 3; j++) {
					if (board[i][j] != 0) {
						int a = j+1;
						while (a < 4) {
							if (board[i][a] != 0) {
								if(board[i][j] == board[i][a]) {
									board[i][j] *= 2;
									board[i][a] = 0;
								}
								break;
							}
							a++;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					if(board[i][j]==0) {
						for(int c = j+1; c < 4; c++) {
							if (board[i][c] != 0) {
								board[i][j] = board[i][c];
								board[i][c] = 0;
								break;
							}
						}
					}
				}
			}
			break;
		case 2: 
			for (int i = 0; i < 4; i++) {
				for (int j = 3; j >= 0; j--) {
					if (board[i][j] != 0) {
						int a = j-1;
						while (a >= 0) {
							if (board[i][a] != 0) {
								if(board[i][j] == board[i][a]) {
									board[i][j] *= 2;
									board[i][a] = 0;
								}
								break;
							}
							a--;
						}
					}
				}
				for (int j = 3; j >= 0; j--) {
					if(board[i][j]==0) {
						for(int c = j-1; c >= 0; c--) {
							if (board[i][c] != 0) {
								board[i][j] = board[i][c];
								board[i][c] = 0;
								break;
							}
						}
					}
				}
			}
			break;
		case 1: 
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 3; j++) {
					if (board[j][i] != 0) {
						int a = j+1;
						while (a < 4) {
							if (board[a][i] != 0) {
								if(board[j][i] == board[a][i]) {
									board[j][i] *= 2;
									board[a][i] = 0;
								}
								break;
							}
							a++;
						}
					}
				}
				for (int j = 0; j < 4; j++) {
					if(board[j][i]==0) {
						for(int c = j+1; c < 4; c++) {
							if (board[c][i] != 0) {
								board[j][i] = board[c][i];
								board[c][i] = 0;
								break;
							}
						}
					}
				}
			}
			break;
		case 3: 
			for (int i = 0; i < 4; i++) {
				for (int j = 3; j >= 0; j--) {
					if (board[j][i] != 0) {
						int a = j-1;
						while (a >= 0) {
							if (board[a][i] != 0) {
								if(board[j][i] == board[a][i]) {
									board[j][i] *= 2;
									board[a][i] = 0;
								}
								break;
							}
							a--;
						}
					}
				}
				for (int j = 3; j >= 0; j--) {
					if(board[j][i]==0) {
						for(int c = j-1; c >= 0; c--) {
							if (board[c][i] != 0) {
								board[j][i] = board[c][i];
								board[c][i] = 0;
								break;
							}
						}
					}
				}
			}
			break;
	}	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
