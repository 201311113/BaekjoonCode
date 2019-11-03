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
bool cmp(string s1, string s2) {
	if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == s2[i]) continue;
			return s1[i] > s2[i];
		}
	}
	return s1.size() > s2.size();
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	if (cmp(s1, s2)) cout << s1;
	else cout << s2;

}