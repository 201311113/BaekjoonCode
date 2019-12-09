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
int main() {
	int h, m;
	cin >> h >> m;
	m -= 45;
	if (m < 0) {
		h -= 1;
		if (h < 0) {
			h += 24;
		}
		m += 60;
	}
	cout << h << " " << m;
}