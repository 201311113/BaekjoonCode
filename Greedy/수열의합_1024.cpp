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
int main() {
	ll n, m;
	cin >> n >>  m;
	bool flag = 0;
	for (int i = m; i < 101; i++) {
		if (i % 2 == 0) {
			if (n % i == i / 2) {
				ll pivot = n / i;
				ll els = (n % i) - 1;
				pivot -= els;
				if (pivot < 0) continue;
				for (int j = 0; j < i; j++) {
					cout << pivot++<<" ";
				}
				flag = 1;
				break;
			}
		}
		else {
			if (n % i == 0) {
				ll pivot = n / i;
				ll els = i / 2;
				pivot -= els;
				if (pivot < 0) continue;
				for (int j = 0; j < i; j++) {
					cout << pivot++<<" ";
				}
				flag = 1;
				break;
			}
		}
	}
	if (!flag) cout << -1;
}