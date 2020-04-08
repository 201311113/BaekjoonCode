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
int cal(string answer_sheet, vector<string> sheets) {
	int ans = 0;
	for (int i = 0; i < sheets.size(); i++) {	//sheets끼리 비교 ex) 1 2 3 4 - > 1 2 / 1 3 / 1 4 / 2 3 / 2 4/ 3 4 비교해서 총 6번 비교
		for (int j = i + 1; j < sheets.size(); j++) {
			int tmp = 0;
			int sum = 0;
			int max_long = 0;
			for (int k = 0; k < answer_sheet.size(); k++) {// 문자하나하나 비교
				if (sheets[i][k] != answer_sheet[k] && sheets[i][k] == sheets[j][k]) {//둘다 문제 틀렸을때 
					tmp++;
				}
				else {	//아닌 문항 나오면 연속으로 의심문항 나오는 갯수 계산하는 tmp초기화 및 총의심문항 더해주기 및 최장 의심문항개수가 tmp보다 작으면 tmp로 초기화 해주기
					sum += tmp;
					if (max_long < tmp) max_long = tmp;
					tmp = 0;
				}
			}
			if (tmp) {//마지막에 문제가 의심문항이면 위의 반복문에서는 계산이안되서 tmp가 남았을때 또 그만큼 계산해줘야함
				if (max_long < tmp)max_long = tmp;//
				sum += tmp;
			}
			
			int tmp_ans = sum + (max_long * max_long); //다체크했으면 의심계수 계산
			if (ans < tmp_ans) {	//의심계수 초기화
				ans = tmp_ans;
			}
		}
	}
	
	return ans;
}
int main() {	
	vector<string> arr;
	string answer_sheet;
	cin >> answer_sheet;	//먼저 answer_sheet 입력
	while (1) {	//각자의 sheets입력
		string s;
		cin >> s;
		if (s == "end") break;	//sheets의 수가 testcase마다 달라서 end를 입력해야 마무리되게끔함
		arr.push_back(s);
	}
	cout << cal(answer_sheet, arr);//입력끝나면 cal함수에서 계산후 답출력
}