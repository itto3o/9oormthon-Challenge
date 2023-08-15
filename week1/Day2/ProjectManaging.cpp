#include <iostream>
#include <vector>

using namespace std;
int main() {	
	// 일의 개수, 각 일이 걸리는 시간, 시작 시간을 모두 인자로 받고
	// 모든 일이 끝난 후의 시각을 구하기
	// 23시 59분에서 1을 더하면 0시 0분이 되어야함
	
	int N, T, M;
	cin >> N;
	cin >> T >> M;
	
	// 예외
	if(N < 1 || N > 100)
	{
		cout << "N invalid int" << endl;
		return -1;
	}
	
	if(T < 0 || T > 23 || M < 0 || M > 59)
	{
		cout<<"invalid time" << endl;
		return -1;
	}

	// Ci 벡터를 만들고 일감 추가
	vector<int> Ci;
	int temp;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		if(temp < 0 || temp > 1000)
		{
			cout << "invalid Ci" << endl;
			return -1;
		}
		Ci.push_back(temp);
	}

	// 시간 더하기
	// 1. 미리 모든 일감들의 시, 분 모두 계산해서 더하기 --> 어차피 더하면 마지막에 또 계산해야 함
	// 2. 하나하나 더하기 --> 매번 시, 분 계산해야하지만? 이게 더 for문에 적합할 것 같다.
	for(int i = 0; i < N; i++)
	{
		M += Ci.at(i);
		
		while(M > 59) // 일감 처리 시간이 180분 이럴수도 있으니까 반복
		{
			// M이 59보다 클 때
			if(M > 59)
			{
				T++;
				M -= 60; // 1시간 빼주기
			}
			
			if(T > 23)
			{
				T = 0;
			}
		}
	}
	
	cout << T << " " << M << endl;
	return 0;
}