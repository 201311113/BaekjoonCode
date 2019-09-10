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
using namespace std;
int n;
bool str_cmp(string a, string b) {
	if (a.length() != b.length()) {//길이비교
		return a.length() < b.length();
	}
	else {
		int aa = 0, bb = 0;
		char aaa[50], bbb[50];
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= '0' && a[i] <= '9') {
				aa += a[i] - '0';
				aaa[i] = a[i];
			}
			if (b[i] >= '0' && b[i] <= '9') {
				bb += b[i] - '0';
				bbb[i] = b[i];
			}
		}
		if (aa != bb) return aa < bb;
		else {
			return a < b;
		}
	}
}

string output_serial(vector<string>& v) {

	if (v.size() == 1) return v[0];
	vector<string> ::iterator iter;
	string s = v[0];
	vector<string> ::iterator pivot = v.begin();
	for (iter = v.begin() + 1; iter != v.end(); iter++) {
		if (str_cmp(*pivot, *iter)) {	//비교해서 앞에올것들비교 리턴
			continue;
		}
		else {
			pivot = iter;
			s = *iter;
		}
	}
	v.erase(pivot);
	return s;
}
int main() {
	cin >> n;
	vector<string> serial_n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		serial_n.push_back(s);
	}
	for (int i = 0; i < n; i++) {
		cout << output_serial(serial_n) << endl;
	}
}