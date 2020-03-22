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
#include<map>
#include<sstream>
using namespace std;
int cal(string s) {
	int num = 0;
	int tmp = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		num += (s[i] - '0') * tmp;
		tmp *= 10;
	}
	return num;
}
int main() {
	string s;
	cin >> s;
	vector<int> numarr;
	vector<char> sig;
	string arr="";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			int num = cal(arr);
			numarr.push_back(num);
			arr = "";
			sig.push_back(s[i]);
		}
		else {
			arr += s[i];
		}
	}
	int num = cal(arr);
	numarr.push_back(num);
	int ans = numarr[0];
	for (int i = 0; i < sig.size(); i++) {
		if (sig[i] == '-') {
			int tmp = 0;
			for (int j = i + 1;j<numarr.size();j++) {
				tmp += numarr[j];
			}
			ans -= tmp;
			break;
		}
		else ans += numarr[i + 1];
	}
	cout << ans;
}