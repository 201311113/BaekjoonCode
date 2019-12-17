#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<ctime>
#include<set>
#include<sstream>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>> map;
int ans = 0;
void moving(vector<int> dir) {
	vector<vector<int>> tmp;
	tmp = map;
	for (int k = 0; k < dir.size(); k++) {
		if (dir[k] == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - 1; j++) {
					bool flag = 0;
					if (tmp[i][j] == 0) {
						int o = j + 1;
						while (o <= n - 1) {
							if (tmp[i][o]) {
								flag = 1;
								break;
							}
							o++;
						}
						if (flag) {
							tmp[i][j] = tmp[i][o];
							tmp[i][o] = 0;
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {//0아닌 연속된 수 합치기
				for (int j = 0; j < n - 1; j++) {
					if (tmp[i][j] == 0) continue;
					if (tmp[i][j] == tmp[i][j + 1]) {
						tmp[i][j] *= 2;
						tmp[i][j + 1] = 0;
						j++;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - 1; j++) {
					bool flag = 0;
					if (tmp[i][j] == 0) {
						int o = j + 1;
						while (o <= n - 1) {
							if (tmp[i][o]) {
								flag = 1;
								break;
							}
							o++;
						}
						if (flag) {
							tmp[i][j] = tmp[i][o];
							tmp[i][o] = 0;
						}
					}
				}
			}
		}
		else if (dir[k] == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j > 0; j--) {
					bool flag = 0;
					if (tmp[i][j] == 0) {
						int o = j - 1;
						while (o >= 0) {
							if (tmp[i][o]) {
								flag = 1;
								break;
							}
							o--;
						}
						if (flag) {
							tmp[i][j] = tmp[i][o];
							tmp[i][o] = 0;
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {//0아닌 연속된 수 합치기
				for (int j = n - 1; j > 0; j--) {
					if (tmp[i][j] == 0) continue;
					if (tmp[i][j] == tmp[i][j - 1]) {
						tmp[i][j] *= 2;
						tmp[i][j - 1] = 0;
						j--;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j > 0; j--) {
					bool flag = 0;
					if (tmp[i][j] == 0) {
						int o = j - 1;
						while (o >= 0) {
							if (tmp[i][o]) {
								flag = 1;
								break;
							}
							o--;
						}
						if (flag) {
							tmp[i][j] = tmp[i][o];
							tmp[i][o] = 0;
						}
					}
				}
			}
		}
		else if (dir[k] == 2) {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j > 0; j--) {
					bool flag = 0;
					if (tmp[j][i] == 0) {
						int o = j - 1;
						while (o >= 0) {
							if (tmp[o][i]) {
								flag = 1;
								break;
							}
							o--;
						}
						if (flag) {
							tmp[j][i] = tmp[o][i];
							tmp[o][i] = 0;
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {//0아닌 연속된 수 합치기
				for (int j = n - 1; j > 0; j--) {
					if (tmp[j][i] == 0) continue;
					if (tmp[j][i] == tmp[j - 1][i]) {
						tmp[j][i] *= 2;
						tmp[j - 1][i] = 0;
						j--;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j > 0; j--) {
					bool flag = 0;
					if (tmp[j][i] == 0) {
						int o = j - 1;
						while (o >= 0) {
							if (tmp[o][i]) {
								flag = 1;
								break;
							}
							o--;
						}
						if (flag) {
							tmp[j][i] = tmp[o][i];
							tmp[o][i] = 0;
						}
					}
				}
			}
		}
		else if (dir[k] == 3) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n-1; j++) {
					bool flag = 0;
					if (tmp[j][i] == 0) {
						int o = j + 1;
						while (o <= n - 1) {
							if (tmp[o][i]) {
								flag = 1;
								break;
							}
							o++;
						}
						if (flag) {
							tmp[j][i] = tmp[o][i];
							tmp[o][i] = 0;
						}
					}
				}
			}
			for (int i = 0; i < n; i++) {//0아닌 연속된 수 합치기
				for (int j = 0; j < n - 1; j++) {
					if (tmp[j][i] == 0) continue;
					if (tmp[j][i] == tmp[j + 1][i]) {
						tmp[j][i] *= 2;
						tmp[j + 1][i] = 0;
						j += 1;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n-1; j++) {
					bool flag = 0;
					if (tmp[j][i] == 0) {
						int o = j + 1;
						while (o <= n - 1) {
							if (tmp[o][i]) {
								flag = 1;
								break;
							}
							o++;
						}
						if (flag) {
							tmp[j][i] = tmp[o][i];
							tmp[o][i] = 0;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < tmp[i][j]) ans = tmp[i][j];
		}
	}
}
void move(vector<int> dir,int cnt) {//0이 왼쪽 1이 오른쪽 2가 위 3이 아래
	if (cnt == 5) {
		moving(dir);
		return;
	}
	if (cnt > 5) return;
	for (int i = 0; i < 4; i++) {
		vector<int> tmp;
		tmp = dir;
		tmp.push_back(i);
		move(tmp, cnt + 1);
	}

	
}
int main() {
	cin >> n;
	
	for (int j = 0; j < n; j++) {
		vector<int> liner;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			liner.push_back(num);
		}
		map.push_back(liner);
	}
	
	for (int i = 0; i < 4; i++) {
		vector<int> tmp;
		tmp.push_back(i);
		move(tmp,1);
	}
	cout << ans;
}