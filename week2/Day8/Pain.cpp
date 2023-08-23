#include <iostream>
using namespace std;

enum {
	bandage = 1, medicine = 7, painkiller = 14
};

int main() {
	// 약간 자판기 같은데
	// 14로 줄일 수 있을만큼 줄이고, 그다음 7로 줄이고, 그다음 1...
	// 뭐지 진짜 그런거면 너무 쉬울거같은데
	
	int N;
	cin >> N;
	
	int leastItem = 0;
	
	leastItem += N / painkiller;
	N %= painkiller;
	
	leastItem += N / medicine;
	N %= medicine;
	
	leastItem += N / bandage;
	
	cout << leastItem;
	
	return 0;
}