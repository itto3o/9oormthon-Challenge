#include <iostream>
using namespace std;

struct Direction
{
	char command;
	int count;
	bool gVisit = false;
	bool pVisit = false;
};

// 이거 부하걸리면어떡하지
int goorm_GameStart(Direction** board, int N, int X, int Y)
{
	int score = 0;
	// 일단 처음 시작 방문
	board[X][Y].gVisit = true;
	score++;
	
	do
	{
		// 지금 위치 상태 뽑기
		Direction direction = board[X][Y];
		
		switch(direction.command)
		{
			case 'U' :
				// U으로 1칸씩 true로 만들고 Xg옮기기
				for(int i = 1; i <= direction.count; i++)
				{
					// 만약 이미 방문했다면 바로 score 반환
					if(board[(X - i + N) % N][Y].gVisit)
						return score;
					
					board[(X - i + N) % N][Y].gVisit = true;
					score++;
				}
				X = (X - direction.count + N) % N; // ex. (1 - 2 + 4) % 4
				break;
				
			case 'D' :
				for(int i = 1; i <= direction.count; i++)
				{
						if(board[(X + i) % N][Y].gVisit)
						return score;
					
					board[(X + i) % N][Y].gVisit = true;
					score++;
				}
				X = (X + direction.count) % N; // ex. (3 + 2) % 4
				break;
				
			case 'L' :
				for(int i = 1; i <= direction.count; i++)
				{
					if(board[X][(Y - i + N) % N].gVisit)
						return score;
					
					board[X][(Y - i + N) % N].gVisit = true;
					score++;
				}
				Y = (Y - direction.count + N) % N;
				break;
				
			case 'R' :
				for(int i = 1; i <= direction.count; i++)
				{
					if(board[X][(Y + i) % N].gVisit)
						return score;
					
					board[X][(Y + i) % N].gVisit = true;
					score++;
				}
				Y = (Y + direction.count) % N; 
				break;
		}
	} while(true);
		
	return score;
}

int player_GameStart(Direction** board, int N, int X, int Y)
{
	int score = 0;
	
	// 일단 처음 시작 방문
	board[X][Y].pVisit = true;
	score++;
	
	do
	{
		// 지금 위치 상태 뽑기
		Direction direction = board[X][Y];
		
		switch(direction.command)
		{
			case 'U' :
				// U으로 1칸씩 true로 만들고 Xg옮기기
				for(int i = 1; i <= direction.count; i++)
				{
					// 만약 이미 방문했다면 바로 score 반환
					if(board[(X - i + N) % N][Y].pVisit)
						return score;
					
					board[(X - i + N) % N][Y].pVisit = true;
					score++;
				}
				X = (X - direction.count + N) % N; // ex. (1 - 2 + 4) % 4
				break;
				
			case 'D' :
				for(int i = 1; i <= direction.count; i++)
				{
						if(board[(X + i) % N][Y].pVisit)
						return score;
					
					board[(X + i) % N][Y].pVisit = true;
					score++;
				}
				X = (X + direction.count) % N; // ex. (3 + 2) % 4
				break;
				
			case 'L' :
				for(int i = 1; i <= direction.count; i++)
				{
					if(board[X][(Y - i + N) % N].pVisit)
						return score;
					
					board[X][(Y - i + N) % N].pVisit = true;
					score++;
				}
				Y = (Y - direction.count + N) % N;
				break;
				
			case 'R' :
				for(int i = 1; i <= direction.count; i++)
				{
					if(board[X][(Y + i) % N].pVisit)
						return score;
					
					board[X][(Y + i) % N].pVisit = true;
					score++;
				}
				Y = (Y + direction.count) % N; 
				break;
		}
	} while(true);

	return score;
}

int main() {
	// 보드 위에 구름이, 플레이어가 말을 놓는다.
	// 보드의 각 칸에는 이동 방향과 이동 수를 적어놓았다.
	// 각 끝 칸에서 범위 밖으로 이동하면 처음 부분으로 돌아온다.
	// --> 근데 이게 아니라 그냥 범위 나가면 무조건 첫번째 칸으로 가는듯
	// 같은 칸을 밟게 되면 게임 오버, 게임오버 전까지 방문한 서로 다른 칸의 개수가 점수가 된다.
	// 승자 점수 <<로 출력한다
	
	// 원형 큐느낌으로 만들고 싶다.
	// U : 위, D : 아래, R : 오른쪾, L : 왼쪽
	// 칸의 지시 방향을 어떻게 받아오지?
	// 그냥 struct로 int char 이렇게 받아오면 하나씩 받아와지나?
	// --> 그렇게 받아와진다!
	// 1. 받아와서 분리한다. 2. 받아올 때 분리한다.
	// 받아올때 분리할건데,
	// 그럼 방향만 있는 곳, 거리만 있는 곳으로 나눠서 저장할까
	// 그냥 struct로 해도 될 것 같기도하고...
	
	// 그럼 방문한 칸이라는건 어떻게? vector에 인덱스 넣고 하면... 체크가 늦을 수 있을 것 같은데..
	// 그럼 보드 두개를 더 만들어서 하나는 구름이 방문, 하나는 플레이어 방문으로 할까
	
	// 입력값 받고
	// struct로 숫자, 방향을 따로 만들어서
	// 각각 따로 받아오고
	// 플레이어보드, 구름보드에 방문 표시
	// 보드에 적힌대로 이동하는데, %N만큼 이동(순환되어야 하니까?)
	// 3R이면 제자리니까 0R이 되겠지
	
	
	// 입력값 받기
	int N;
	cin >> N;
	// Xg : x축(행) 구름
	int Xg, Yg, Xp, Yp; 
	cin >> Xg >> Yg;
	cin >> Xp >> Yp;
	
	// 인덱스라 1씩 빼주기
	Xg--;
	Yg--;
	Xp--;
	Yp--;
	
	// 보드 만들기
	// 아니면 보드 자체에 방문 여부도 같이 넣을까
	Direction** board = new Direction*[N];
	for(int i = 0; i < N; i++)
		board[i] = new Direction[N];
	
	// 입력값 받기
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> board[i][j].count >> board[i][j].command;
		}
	}
	
	// 게임 시작
	// 아 4R이 제자리로 돌아오는 건 맞는데, 가는 길 모두 count를 하는 거구나.
	// 그럼 한칸마다 count를 해야겠네..
	// 그럼 goorm다 하고, player다 하고 난 뒤 score를 하면 될듯
	
	// goorm
	int gScore = goorm_GameStart(board, N, Xg, Yg);
	int pScore = player_GameStart(board, N, Xp, Yp);
	
	if(gScore < pScore)
	{
		cout << "player " << pScore;
	}
	
	else {
		cout << "goorm " << gScore;
	}
	
	for(int i = 0; i < N; i++)
		delete[] board[i];
	delete[] board;
	
	return 0;
}