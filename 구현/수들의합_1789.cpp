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
	ll S;
	ll sum = 0 , ans;
	cin >> S;
	for (ll i = 1; i < 4300000000; i++) {
		sum += i;
		if (sum >= S) {
			ans = i-1;
			break;
		}
	}
	cout << ans;
}