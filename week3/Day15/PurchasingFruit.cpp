#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Fruits
{
	// (fullness / price)
	long long value;
	long long quantity = 0;
	
	bool operator<(const Fruits& rhs) const
	{
		return value >= rhs.value;
	}
	
	bool operator()(Fruits const& v) const {
		return v.value == value;
	}
};

int main() {
	// 과일 N종류, 가격은 Pi, 포만감은 Ci,
	// 가격이 p면 과일을 p개의 조각으로 자르고 몇 개의 조각을 얻을 수 있음,
	// 이때 가격은 1, 포만감은 Ci/Pi
	// K만큼의 돈을 갖고 있을 때 포만감 합이 가장 크게 되도록 선택했을 때 최대 포만감 합
	
	// N, K
	// Pi, Ci, ci는 항상 Pi의 배수
	
	// 약간 가성비가 좋은 애를 사는게 낫겠는데
	// 모두 다 나눠서 큰 수부터..?
	// 가격이 1일때 살수있는 것부터 하면 되자나
	
	// 가격, 수량을 vector에 넣자
	
	int N, K;
	cin >> N >> K;
	
	vector<Fruits> fruits;
	
	for(int i = 0; i < N; i++)
	{
		long long p, c;
		cin >> p >> c;
		
		Fruits f;
		f.value = c / p;
		f.quantity = p;
	
		
		int idx = -1;
		vector<Fruits>::iterator it = find_if(fruits.begin(), fruits.end(), f);
		// 없을 경우 그냥 push back
		if(it == fruits.end())
		{
			fruits.push_back(f);
		}
		
		// 있을 경우 idx에 += p
		else
		{
			idx = distance(fruits.begin(), it);
			fruits.at(idx).quantity += p;
		}
	}
	
	// fruits에는 가성비, 개수가 들어가 있음
	long long maxFullness = 0;
	
	// 흠,,, 가성비 중에 제일 큰 값부터 개수만큼 maxFullness에 더하기

		// 매순간 max값을 구해서 개수 -1, K-1
		// max 한 번 다 구해서 개수 모두 0, K - 개수

	
	// 그냥 정렬 한번 한 다음에, 큰 순서대로 ㄱㄱ
	sort(fruits.begin(), fruits.end());

	
	// quantity만큼 K에서 빼기
	int i = 0;
	// while(K > 0)
	// 모든 과일을 구매하고 난 다음 돈이 남을 경우 ...와 그런 경우가 있구나.....
	while(K > 0 && i < (int)fruits.size())
	{
		if(K < fruits.at(i).quantity)
		{
			maxFullness += fruits.at(i).value * K;
			break;
		}
		
		else
		{
			maxFullness += fruits.at(i).value * fruits.at(i).quantity;
			K -= fruits.at(i).quantity;
			i++;
		}
	}
	
	cout << maxFullness;
	
	return 0;
}