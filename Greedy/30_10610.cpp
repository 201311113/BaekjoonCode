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
string n;
int main() {
	cin >> n;
	bool flag = 0;
	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '0') flag = 1;
		int num = n[i]-'0';
		sum += num;
	}
	if (sum % 3 != 0)flag = 0;
	if (!flag) { 
		cout << -1;
		return 0;
	}
	sort(n.begin(), n.end());
	reverse(n.begin(), n.end());
	cout << n;
}