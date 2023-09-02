#include <iostream>
using namespace std;
int main() {

	// 통증을 0으로 만들자
	// 2종류의 아이템으로 0으로 만드려는데 아이템의 최소 개수 구하기
	// 0으로 만들 수 없는 경우엔 -1출력
	// A < B, A와 B는 배수관계가 아니다.
	
	int N, Ap, Bp;
	cin >> N;
	cin >> Ap >> Bp;
	
	// A보다 B가 더 크니까
	// B로 나눌 수 있을 만큼 나누고, A로 0을 만들어야함
	// 이때 0이 되지 않으면 -1

	// 근데 무조건 B로 다 나눈 후에 A로 나누는게 아니라
	// B로 다 나누지 않고 A로 다 나눌 수 있는 경우가 있어서
	
	// --> 이 부분을 0이 되지 않으면, B로 나눌 수 있을 만큼 A로 빼자
	
	// 엇 근데 이 경우가 FAIL인 케이스가 있네... 뭐지?
	// 아 -1를 내야하는 경우인가
	// --> 이 경우는 어케 판별하지
	// Ap를 -되기 전까지 뺐는데도 Bp로 나눴을때 0으로 떨어지지 않는다면 -1
	
	int answer = 0;
	
	// Bp로 나눈 후 그의 나머지가 Ap로 다 안나누어 진다면
	if((N % Bp) % Ap != 0)
	{
		int N_copy = N;
		// Bp로 나누어 떨어질 때까지 Ap빼는 걸 반복
		while((N_copy % Bp != 0) && (N_copy > 0))
		{
			N_copy -= Ap;
			answer++;
		}
		
		// Bp로 나누어 떨어지지 않는다면 -1
		if(N_copy % Bp != 0)
			answer = -1;
		
		else
			answer += N_copy / Bp;
	}
	
	// Bp로 나눈 나머지를 Ap가 나눴을 때 나머지가 0이라면 그냥 그대로
	else
	{
		// Bp로 나눌 수 있을 만큼 나누고 Ap로 나누기
		answer += N / Bp;
		N %= Bp;
		answer += N / Ap;
	}
	
	
	cout << answer;

	return 0;
}