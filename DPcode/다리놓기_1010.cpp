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
ll d[32][32];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= b; i++) {
			d[1][i] = i;
		}
		for (int i = 2; i <= b; i++) {
			for (int j = i; j <= b; j++) {
				for (int k = j; k >= i; k--) {
					d[i][j] += d[i - 1][k - 1];
				}
			}
		}
		cout << d[a][b]<< endl;
	}
}