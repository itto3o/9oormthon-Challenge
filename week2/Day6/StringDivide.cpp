#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


struct PartialString
{
	string s1;
	string s2;
	string s3;
	int score;
};

int main() {
	// 문자열 S를 받아서 3부분으로 나누는데, 각 부분은 서로 연결되어 있어야 한다.
	// 나눌 수 있는 모든 부분집합 중에서
	// 최대로 높은 점수를 받을 수 있는 집합의 점수를 구하기.
	// 점수는 중복을 제거한 부분집합들의 나열 중에서 집합의 원소가 나오는 차례? 순서?의 번호이다
	// a b c d를 나눌땐 a ab b bc c cd d 의 경우가 있고, 
	// ab c d로 나눴을 때, ab는 2번째에, c는 5번째에, d는 7번째에 나오므로 점수는 14이다.
	
	// 나눌 수 있는 경우의 수를 모두 구하고
	// set에 순서대로 넣고
	// 경우마다 점수 구하기? <-- 이거밖에 없을까?
	//   어차피 max구하는거니까 위방식처럼 해도 될듯
	
	// 경우의 수 모두 구하기
	// 부분집합 구하기 같은데... 어떤 게 있지
	// abc
	// a b c <--1
	// abcd : a ab b bc c cd d
	// abcde : a ab abc b bc bcd c cd cde d de e
	
	// 그냥 문자열 안에 작대기 2개 넣는다고 생각하고 모든 경우의 수 구하면 되지 않을까
	// 중복 for문처럼 int i = 0; i++ / int j = i; j++ << 이런식으로 해서 구한 애들을 set에 넣기, 그리고 경우의 수에도 넣기
	// c++ set이 되던가..? 되네 set<String> 으로 해야겠는데
	// 여기다 다 넣으면, 어차피 정렬은 자동으로 된댔으니까 확인한번만 해주고
	
	// 각 케이스마다 점수를 적어야되는데...
	// 이 케이스들을 모아두는 구조체(string, string, string, int(최종 점수))을 선언하고 걔를 받는 vector? 잇으면 좋겠다
	// 그럼 저 int부분에 최종 점수를 넣고, 걔네 중에서 max값을 구하면 끝
	
	// 입력값 받기
	int N;
	string S;
	
	cin >> N;
	if(N < 3 || N > 100)
	{
		cout << "Error : Invalid N";
		return -1;
	}
	
	cin >> S;
	
	// 경우의 수 구하기
	// i가 0이면 0번째 원소 뒤에 ,를 뒀단 얘기
	vector<PartialString> cases;
	set<string> setPartialString;
	for(int i = 1; i < N - 1; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			PartialString ps;
			
			ps.s1 = S.substr(0, i);
			ps.s2 = S.substr(i, j - i);
			ps.s3 = S.substr(j);
			
			// vector와 set에 모두 밀어 넣기
			cases.push_back(ps);
			
			setPartialString.insert(ps.s1);
			setPartialString.insert(ps.s2);
			setPartialString.insert(ps.s3);
		}
	}

	// 모두 넣었으면 점수 계산
	// vector에 있는 원소들을 모두 돌면서 s1이 set.find로 어디있는지 파악, 점수를 합해서 score에 넣기
	int i = 0;
	for(PartialString ps : cases)
	{
		int score = 0;
		set<string>::iterator it = setPartialString.find(ps.s1);
		int idx = distance(setPartialString.begin(), it) + 1;
		score += idx;
		
		it = setPartialString.find(ps.s2);
		idx = distance(setPartialString.begin(), it) + 1;
		score += idx;
		
		it = setPartialString.find(ps.s3);
		idx = distance(setPartialString.begin(), it) + 1;
		score += idx;
		
		// 여기에 ps.score에 반영이 안되는듯?
		// ps.score = score;
		cases.at(i).score = score;
		i++;
	}
	
	int max = 0;
	for(PartialString ps : cases)
	{
		if(max < ps.score)
			max = ps.score;
	}
	
	cout << max;
	
	return 0;
}