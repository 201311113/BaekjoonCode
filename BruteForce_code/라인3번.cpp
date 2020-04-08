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
int cal(string s,int n) {//string검사해서 1연속된만큼 양수로 0연속된만큼 음수로 vector에 저장해서 풀었드아
	int continuous_1 = 0 , continuous_2 = 0;
	vector<int> arr;
	for (int i = 0; i < s.size(); i++) {	//1연속된만큼 vector에 넣고 0은 나올때마다 -1을 넣음
		if (s[i] == '1') {
			continuous_1++;
		}
		else if (s[i] == '0') {
			if (continuous_1) {
				arr.push_back(continuous_1);
				continuous_1 = 0;
			}
			arr.push_back(-1);
		}
	}
	if (continuous_1) {
		arr.push_back(continuous_1);
	}
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {//vector를 처음부터 검사해서 연속되는 값 검사
		int tmpn = n;
		int sum = 0;
		if (arr[i] == -1) {//0나오면 n--후 sum++하는 것으로 보수공사해주기
			tmpn--;
			sum++;
		}
		else {	//1나오면 그냥 더해주기
			sum += arr[i];
		}
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < 0 && tmpn == 0) break;//n을 다쓰고 0인 구간 나올때까지 계산
			if (arr[j] == -1) {
				tmpn--;
				sum++;
			}
			else {
				sum += arr[j];
			}
		}
		if (ans < sum) ans = sum;//가장 큰수 입력
	}
	return ans;
}
int main() {
	string s;
	int n;
	cin >> s>>n;
	cout << cal(s,n);
}