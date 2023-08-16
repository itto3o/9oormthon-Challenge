#include <iostream>
using namespace std;

struct Formula
{
	int N1;
	char oper;
	int N2;
	int result;
};

int main() {
	// 정답
	int answer = 0;
	
	// 식의 개수
	int T;
	cin >> T;
	if(T < 1 || T > 100)
	{
		cout << "Invalid T" << endl;
		return -1;
	}
	
	for(int i = 0; i < T; i++)
	{
		Formula formula;
		cin >> formula.N1 >> formula.oper >> formula.N2;
		if(formula.N1 < 1 || formula.N1 > 1000 || formula.N2 < 1 || formula.N2 > 1000)
		{
			cout << "Invalid Operand" << endl;
			return -1;
		}
		
		switch(formula.oper)
		{
			case '+':
				formula.result = formula.N1 + formula.N2;
				break;
			case '-':
				formula.result = formula.N1 - formula.N2;
				break;
			case '/':
				formula.result = formula.N1 / formula.N2;
				break;
			case '*':
				formula.result = formula.N1 * formula.N2;
				break;
			default:
				cout<< "Invalid operator" << endl;
				return -1;
		}
		
		answer += formula.result;
	}
	
	cout << answer << endl;
	
	return 0;
	
}