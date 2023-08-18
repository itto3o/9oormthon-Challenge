#include <iostream>

#define INF 1000000000

using namespace std;

int N;

int SumBasedOnMaxLower(int* materials, int target, int base)
{	
	if(target < 0)
		return materials[base];
	
	if(materials[target] <= materials[base])
		return materials[base] + SumBasedOnMaxLower(materials, target - 1, base - 1);
	
	else
		return INF;
}

int SumBasedOnMaxUpper(int* materials, int base, int target)
{
	if(target >= N)
		return 0;
	
	if(materials[base] >= materials[target])
		return materials[target] + SumBasedOnMaxUpper(materials, base + 1, target + 1);
	
	else
		return INF;
}


int main() {	
	// 햄버거 만들기
	// N개의 재료를 순서대로 쌓아서 만드는데, 맛은 모든 재료의 합
	// 맛의 정도가 가장 높은 재료를 기준으로,
	// 위랑 아래로 갈수록 재료의 맛의 정도가 감소하거나 같아야 함
	// 위의 조건을 만족하지 못하면 0
	//  1 2 3 5 2 3 1 은 0이 됨
	
	cin >> N;
	if(N < 1 || N > 1000)
	{
		cout << "Invalid N" << endl;
		return -1;
	}
	
	// int 받아와서 동적 배열 만들기
	int* materials = new int[N];
	for(int i = 0; i < N; i++)
	{
		cin >> materials[i];
	}
	
	
	// max구하기
	int maxIdx = 0;
	for(int i = 0; i < N; i++)
	{
		if(materials[maxIdx] < materials[i])
			maxIdx = i;
	}
	
	int answer = 0;
	int sumLower = SumBasedOnMaxLower(materials, maxIdx - 1, maxIdx);
	int sumUpper = SumBasedOnMaxUpper(materials, maxIdx, maxIdx + 1);
	if(sumLower < INF && sumUpper < INF)
		answer = sumLower + sumUpper;
	
	
	cout << answer;
	
	delete[] materials;
	
	return 0;
}