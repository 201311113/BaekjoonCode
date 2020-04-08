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
int cal(string s) {//
	int answer = 0;
	stack<int> stk1, stk2, stk3, stk4;//괄호 ( = 1 { = 2 [ = 3 < = 4 스택따로 만드는 이유는 [(])도 된다고했기때문
	for (int i = 0; i < s.size(); i++) {//문자열하나하나검사
		if ((stk1.empty()&&s[i]==')')|| (stk2.empty() && s[i] == '}')|| (stk3.empty() && s[i] == ']')|| (stk4.empty() && s[i] == '>')) { //여는괄호없는 데 닫는괄호 나온경우
			answer = -1;
			break;
		}
		if (s[i] == '(') {//각각 여는 괄호 나올때마다 넣어줌 닫는 괄호면 빼줌
			stk1.push(1);
			answer++;	//또 여는괄호 뭐가나오든 answer변수값을 하나씩 더해줌
		}
		else if (s[i] == ')') stk1.pop();
		else if (s[i] == '{') {
			stk2.push(1);
			answer++;
		}
		else if (s[i] == '}') stk2.pop();
		else if (s[i] == '[') {
			stk3.push(1);
			answer++;
		}
		else if (s[i] == ']') stk3.pop();
		else if (s[i] == '<') {
			stk4.push(1);
			answer++;
		}
		else if (s[i] == '>') stk4.pop();
	}
	if (!stk1.empty() || !stk2.empty() || !stk3.empty() || !stk4.empty()) {//비어있지 않은 스택 하나라도 있으면 괄호 불완전 이므로 answer=-1
		answer = -1;
	}
	return answer;
}
int main() {
	string s[4] = {"Hello world!","line [plus]","if(Count of eggs is 4.){Buy milk}",">_<" };
	for (int i = 0; i < 4; i++) {//입력받을때마다 띄어쓰기에서 변수입력처리끝나서 입력받으면서 할라면 getline으로 해야함
		//string s;
		//cin >>s; 말고 getline
		cout << cal(s[i])<<endl;//endl은 띄어쓰기
	}
	

}