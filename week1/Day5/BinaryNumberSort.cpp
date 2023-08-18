#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinaryNumOfOne(int dec)
{
	int theNumberOfOne = 0;
	while(dec > 0)
	{
		if(dec % 2 == 1)
			theNumberOfOne++;
		
		dec /= 2;
	}
	
	return theNumberOfOne;
}

// int MaxIdx(vector<int> elements)
// {
// 	int maxIdx = 0;
// 	int max = elements.at(0);
// 	for(int i = 0; i < (int)elements.size(); i++)
// 	{
// 		if(max < elements.at(i))
// 		{
// 			max = elements.at(i);
// 			maxIdx = i;
// 		}
// 	}
	
// 	return maxIdx;
// }


int main() {
	// N개의 10진수 정수
	// 2진수로 나타냈을때 1의 개수를 기준으로 내림차순 정렬
	// 1의 개수가 같다면 10진수를 기준으로
	// K번째에 위치한 수는?
	// N K
	// a1 a2 ... aN
	
	// 정수는 50만개까지, 각 수는 2의 20승까지(2048)
	
	// 1. 입력받은 수들을 내림차순 정렬(큰 수부터 정렬해두면 나중에 편하려나?)
	// 실제 수와 2진수의 개수는 짝으로 만들고, (파이썬이면 간단할텐데)
	// 후.. 해시테이블 만들고 싶다..
	// 같은걸 pool에 넣고 거기서 정렬 시키기?
	// 근데 20개면 ㄹㅇ 해쉬만들어도 되겠는데
	
	// 먼저 내림차순 정렬, 큰 수부터 2진수 개수 구해서 정렬
	// 먼저 2진수 개수구해서 해시테이블에 넣고 하나씩 꺼내오기만..?
	
	// 첫 줄 받아오기
	int N, K;
	cin >> N >> K;
	if(N < 1 || N > 500000)
	{
		cout <<"Error : Invalid N";
		return -1;
	}
	
	if(K < 1 || K > N)
	{
		cout << "Error : Invalid K";
		return -1;
	}
	
	vector<int> descSortNumber;
	for(int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if(temp < 1 || temp > 1048576) // 2^20 = 1048576
		{
			cout << "Error : Invalid Number";
			return -1;
		}
		
		// vector에 담아서 먼저 내림차순 정렬을 한 후에 순서대로
		descSortNumber.push_back(temp);
		// binNumber[BinaryNumOfOne(temp)].push_back(temp);
	}
	
	// 내림차순 정렬
	sort(descSortNumber.begin(), descSortNumber.end());
	// reverse(descSortNumber.begin(), descSortNumber.end());
	

	
	vector<int> binNumber[21];
	// 뒤에서부터 1의 개수 구하기
	for(int i = descSortNumber.size() - 1; i >= 0; i--)
	{
		int current = descSortNumber.at(i);
		binNumber[BinaryNumOfOne(current)].push_back(current);
	}
		
	
	// 순서대로 K번째까지 반복
	int k = 0;
	for(int i = 20; i >= 0; i--)
	{
		for(int j = 0; j < (int)binNumber[i].size(); j++)
		{
			if(k == K - 1)
			{
				cout << binNumber[i].at(j);
				return 0;
			}
			
			k++;
		}
	}	
	
	
	// binNumber[1의 개수]에 십진수들이 vector로 들어가 있음
	// --> binNumber의 뒷 인덱스부터 반복문으로 큰 수부터 결과 배열에 담으면 됨
	
	// vector<int> sortedNum;
	// for(int i = 20; i >= 0; i--)
	// {
	// 	// 그냥 각 줄마다 내림차순 정렬하고
	// 	// 순서대로 vector에 담으면 되는데
	// 	// 이걸 가장 큰 값을 구해서 그걸 vector에 넣고 원래 vector에선 지우고 다시 반복하려니
	// 	// 부하가 커서 타임아웃 걸림 ㅠㅠ
	// 	// 그냥 sort함수 써야겠다.. 그거 안쓰려고 이런건데
		
	// 	int size = binNumber[i].size();
	// 	while(size > 0)
	// 	{
	// 		// 가장 큰 값 구하기
	// 		int maxIdx = MaxIdx(binNumber[i]);
	// 		// int maxIdx = 0;
	// 		// int max = binNumber[i].at(0);
	// 		// for(int i = 0; i < (int)binNumber[i].size(); i++)
	// 		// {
	// 		// 	if(max < binNumber[i].at(i))
	// 		// 	{
	// 		// 		max = binNumber[i].at(i);
	// 		// 		maxIdx = i;
	// 		// 	}
	// 		// }
			
	// 		// 가장 큰 값을 최종 벡터에 넣고
	// 		sortedNum.push_back(binNumber[i].at(maxIdx));
			
	// 		// 벡터에선 제거
	// 		binNumber[i].erase(binNumber[i].begin() + maxIdx);
			
	// 		// 다시 사이즈 구하기
	// 		size = binNumber[i].size();
	// 	}
	// }
	
	// for(int i = 0; i < (int)sortedNum.size(); i++)
	// 	cout << sortedNum.at(i) << " ";
	
	// cout << sortedNum.at(K - 1);
	
	return 0;
}