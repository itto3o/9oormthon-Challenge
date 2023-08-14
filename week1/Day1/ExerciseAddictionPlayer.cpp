#include <iostream>
#include <cmath>

using namespace std;

int main() {	
	float W;
	float R;
	cin >> W >> R;
	
	// 예외 처리
	if(W < 1 || W > 1000000)
	{
		cout << "invalid W";
		return -1;
	}
	
	if(R < 1 || R > 100)
	{
		cout << "invalid R";
		return -1;
	}
	
	// W * ( 1 + R / 30 ), 소수점 이하의 값은 버림
	int rm = trunc(W * (1 + R / 30));
	cout << rm;
	
	return 0;
}