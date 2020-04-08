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
bool chk[100020];
map<string, int> m;
bool cmp(const vector<string>& a, const vector<string>& b) {//마지막 sort함수로 계좌 알파벳 순으로 정렬하기 위한 bool함수
	return a < b;
}
int calint(string s) {//string -> int 변환 굳이 이거안쓰고 atoi()써도 됨
	int sum = 0;
	int tmp = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		int num = s[i] - '0';
		sum += num * tmp;
		tmp *= 10;
	}
	return sum;
}
string calstr(int num) {//int -> string 변환 이거도 머 함수 있음 대체할
	string s="";
	while (num) {
		char c;
		c = num % 10 + '0';
		s += c;
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
vector<vector<string>> cal(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
	for (int i = 0; i < snapshots.size(); i++) {//map이라는 자료구조에 넣음 그이유는 account이름으로 찾을 수 있다.
		int num = calint(snapshots[i][1]);
		m.insert({ snapshots[i][0] ,num});
	}
	for (int i = 0; i < transactions.size(); i++) {//트랜젝션 분석
		int id = calint(transactions[i][0]);//id int 형으로 변환
		if (chk[id]) continue;	// id 겹치면 넘어가게끔 chk로 표시
		int num = calint(transactions[i][3]);	//입출금 가격 int형으로 변환
		string tmpaccount = transactions[i][2]; //어카운트 이름 참조
		if (transactions[i][1] == "SAVE") {//저장 시에 어카운트이름으로 맵에서 찾고 없으면 insert해줌
			if (m.find(tmpaccount) == m.end()) {
				m.insert({ tmpaccount, num });
			}
			else m[tmpaccount] += num; //
		}
		else {//출금시에 어카운트이름이 없을 수 없으므로 값만 빼줌
			m[tmpaccount] -= num;
		}
	}
	
	map<string, int> ::iterator iter;//맵으로 반복문할라면iterator써야
	vector<vector<string>> ans;
	for (iter = m.begin(); iter != m.end(); iter++) {//맵전체 돌려서 새로운 return할 vector에 넣어줌
		vector<string> tmp;
		tmp.push_back(iter->first);
		tmp.push_back(calstr(iter->second));
		ans.push_back(tmp);
	}
	sort(ans.begin(), ans.end(), cmp);//어카운트 이름순으로 정렬
	return ans;
}
int main() {//여기는 문제 내용아님 참고하시길
	vector<vector<string>> snapshots;
	vector<vector<string>> transactions;
	while (1) {//snapshot 입력
		string s1,s2;
		vector<string> snapshot;
		cin >> s1>>s2;
		if (s1 == "end") {// end 치고 하나 더쳐야댐 s2까지 있어서
			break;
		}
		snapshot.push_back(s1);
		snapshot.push_back(s2);
		snapshots.push_back(snapshot);
	}
	
	while (1) {//transaction입력
		string s1,s2,s3,s4;
		vector<string> transaction;
		cin >> s1>>s2>>s3>>s4;
		if (s1 == "end") {//end 치고 이건 3개 더쳐야갬 s4까지라 ex) end 0 0 0 
			break;
		}
		transaction.push_back(s1);
		transaction.push_back(s2);
		transaction.push_back(s3);
		transaction.push_back(s4);
		transactions.push_back(transaction);
	}
	
	vector<vector<string>> ans=cal(snapshots,transactions);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][0] << " " << ans[i][1]<<endl;
	}
}
//답안예시 복붙하면댐
//account1 100	
//account2 150
//end 0
//1 SAVE account2 100
//2 WITHDRAW account1 50
//1 SAVE account2 100
//4 SAVE account3 500
//3 WITHDRAW account2 30
//end 0 0 0