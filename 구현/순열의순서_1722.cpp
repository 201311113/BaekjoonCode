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
bool chk[22];
int arr2[22];
int main() {
	ll n,num;
	cin >> n >> num;
	if (num == 1) {
		cin >> num;
		num--;
		for (int i = n - 1; i >= 0; i--) {
			ll tmp = 1;
			for (int j = i; j >= 1; j--) {
				tmp *= j;
			}
			ll ttmp = num / tmp;
			for (int j = 1; j <= n; j++) {
				if (!chk[j]) {
					if (ttmp == 0) {
						cout << j << " ";
						chk[j] = 1;
						break;
					}
					ttmp--;
				}
			}
			num %= tmp;
		}
	}
	else {
		ll ans = 1;
		for (int i = 1; i <= n; i++) {
			cin >> arr2[i];
		}
		for (int i = 1; i <= n; i++) {
			ll tmp = 1;
			ll pivot = 1;
			for (int j = n - i; j > 0; j--) {
				pivot *= j;
			}
			ll ord = 0;
			for (int j = 1; j <= n; j++) {
				if (!chk[j]) {
					if (arr2[i] == j) {
						chk[j] = 1;
						break;
					}
					else ord++;
				}
			}
			tmp *= ord * pivot;
			ans += tmp;
		}
		cout << ans;
	}
}