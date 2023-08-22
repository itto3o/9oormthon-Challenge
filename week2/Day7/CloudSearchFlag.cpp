#include <iostream>
#include <vector>

using namespace std;

// x가 세로, y가 가로
int SearchOne(int** board, int N, int x, int y)
{
	int numOfOne = 0;
	// 범위 정하기, 0보다 작으면 0으로
	int minX = x - 1 < 0 ? 0 : x - 1;
	// N보다 크거나 같으면 최대치인 N-1로
	int maxX = x + 1 >= N ? N - 1 : x + 1;
	int minY = y - 1 < 0 ? 0 : y - 1;
	int maxY = y + 1 >= N ? N - 1 : y + 1;
	
	//cout << minX << maxX << minY << maxY << endl;
	for(int i = minX; i <= maxX; i++)
	{
		for(int j = minY; j <= maxY; j++)
		{
			// 자기 칸 제외
			if(i == x && j == y)
				continue;
			
			//cout << "(" << i << ", " << j << ")"<<endl;
			if(board[i][j] == 1)
				numOfOne++;
		}
	}
	
	return numOfOne;
}

int main() {
	// 지뢰찾기인데..?
	// 0은 그냥 칸, 1은 지뢰인데
	// 지뢰찾기에서 칸 눌러서 근처 지뢰가 있으면 숫자가 뜨는 것처럼
	// 0인 칸 기준으로 주위 8개 칸에 있는 지뢰의 개수를 깃발로 세우려고 하는데,
	// 이때 입력값으로 받은 값의 깃발이 몇개 있는지
	
	// 입력값을 받고
	// 배열을 받고
	// 전체 순회 하면서 0인 칸에 대하여, 주위 칸에 1이 있으면 카운트 +1, 얘를 vector에 넣어
	
	// 전체 순회할때 0인 칸에 대하여 주위 접근을 어떻게 할 것인지
	// 그냥 마이너스거나 N보다 크게 되면 continue해야겠는데
	
	// 입력값 받기
	int N, K;
	cin >> N >> K;
	if(N < 1 || N > 1000 || K < 1 || K > 8)
	{
		cout << "N OR K Invalid value";
		return -1;
	}
	
	// 동적 2차원 배열을 만들고 입력값 받기
	int** board = new int*[N];
	for(int i = 0; i < N; i++)
	{
		board[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			if(board[i][j] != 0 && board[i][j] != 1)
			{
				cout << "Error : Invalid value";
				return -1;
			}
		}
	}
	
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < N; j++)
	// 	{
	// 		cout << board[i][j];
	// 	}
	// 	cout << endl;
	// }
	
	// 전체 순회 하면서 0에 값에 대하여 주위 1의 개수 구하기
	// 함수로 만들어서 위치보내주면 1의 개수 반환되게 할까
	vector<int> flags;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// 0인 값일때
			if(board[i][j] == 0)
			{
				int searchOne = SearchOne(board, N, i, j);
				flags.push_back(searchOne);
			}
		}
	}
	
	// vector를 돌면서 K가 몇번 나타나는지
	int answer = 0;
	for(int flag : flags)
	{
		if(flag == K)
			answer++;
	}
	
	cout << answer;
	
	for(int i = 0; i < N; i++)
		delete[] board[i];
	delete[] board;
	
	return 0;
}