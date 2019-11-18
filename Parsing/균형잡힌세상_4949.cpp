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
bool chk(string s) {
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			stk.push(s[i]);
		}
		else if (s[i] == ')') {
			if (!stk.empty() && stk.top() == '(') stk.pop();
			else return false;								// if���� �ƴϸ� ������ ��� ��������
		}
		else if (s[i] == ']') {
			if (!stk.empty() && stk.top() == '[') stk.pop();
			else return false;								// if���� �ƴϸ� ������ ��� ��������
		}
	}
	if (stk.empty()) return true;
	else return false;
}
int main() {
	string s;
	while (1) {
		getline(cin, s);
		if (s[0] == '.' && s.size() == 1) break;
		if (chk(s)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}