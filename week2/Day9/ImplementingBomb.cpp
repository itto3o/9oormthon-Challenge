#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// enum {
// 	// SHARP = 0,
// 	ZERO = 1,
// 	AT = 2
// };

// struct Status
// {
// 	char status;
// 	int value;
// };

// // vector declar
// // vector<Point> bombs;
// vector<Point> ats;
// vector<Point> sharps;
// int answer_max = 0;

// // bool IfAt(Point point)
// // {
// // 	for(Point p : ats)
// // 	{
// // 		if((point.x == p.x) && (point.y == p.y))
// // 			return true;
// // 	}
	
// // 	return false;
// // }

// // bool IfSharp(Point point)
// // {
// // 	for(Point p : sharps)
// // 	{
// // 		if((point.x == p.x) && (point.y == p.y))
// // 			return true;
// // 	}
// // 	return false;
// // }

// void Bomb(int N, int** board, Point point)
// {
// 	// 얘네 부하가 심하니까?
// 	// 먼저 at이 있는지 보고,
// 	// 있다면 board에 +1을 미리 한 다음, sharp은 -1
// 	// 상하좌우 +1
// 	// 상하좌우 points
// 	// int 
	

	
// 	vector<Point> points;
// 	points.push_back({point.x, point.y});
// 	// 상
// 	if(point.x - 1 >= 0)
// 		points.push_back({point.x - 1, point.y});
	
// 	// 하
// 	if(point.x + 1 < N)
// 		points.push_back({point.x + 1, point. y});
	
// 	// 좌
// 	if(point.y - 1 >= 0)
// 		points.push_back({point.x, point.y - 1});
	
// 	// 우
// 	if(point.y + 1 < N)
// 		points.push_back({point.x, point.y + 1});
	
	
// 	for(Point p : points)
// 	{
// 		if()
// 		// @ 이라면
// 		if(std::find(ats.begin(), ats.end(), p) != ats.end())
// 		{
// 			board[p.x][p.y] += 1;
// 			// cout << "@ : " << p.x << ", " << p.y << endl;
// 		}
		
// 		// #이라면
// 		else if(std::find(sharps.begin(), sharps.end(), p) != sharps.end())
// 		{
// 						board[p.x][p.y] -= 1;
// 			// cout << "# : " << p.x << ", " << p.y << endl;
// 		}
		
// 		board[p.x][p.y] += 1;
		
// 		if(answer_max < board[p.x][p.y])
// 			answer_max = board[p.x][p.y];
// 	}
	
// 	// for(int i = 0; i < N; i++)
// 	// {
// 	// 	for(int j = 0; j < N; j++)
// 	// 	{
// 	// 		cout << board[i][j];
// 	// 	}
// 	// 	cout << endl;
// 	// }
// 	// cout << endl;
// }

int main() {
	// board에 땅의 상태를 받고
	// board에 폭탄이 떨어지는데, 이 폭탄은 본인, 상하좌우에 영향을 줌,
	// 땅의 상태에 따라 영향을 받는 정도가 다름
	
	// @인 곳은 항상 +2, #은 항상 0, 0은 +1
	// 좌표를 다 기억해두는게 좋을까 아니면 +2, +0인 곳만 적어두고?

	
	// N은 board의 길이, K는 폭탄 횟수
	int N, K;
	int answer_max = 0;
	cin >> N >> K;
	
	// board 만들기
	// 그냥 두개 만드는게 낫나..?
	char** board_status = new char*[N];
	for(int i = 0; i < N; i++)
		board_status[i] = new char[N];
	
	int** board = new int*[N];
	for(int i = 0; i < N; i++)
		board[i] = new int[N];
	
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			board[i][j] = 0;
			cin >> board_status[i][j];
		}
	}
	
	for(int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		
		// 인덱스에 맞게 -1해주기
		x--;
		y--;
		
		// 본인, 상하좌우의 애들을 char랑 비교해서 숫자 더하기
		if(board_status[x][y] == '@')
			board[x][y] += 2;
		
		else if(board_status[x][y] == '#')
			board[x][y] = 0;
		
		else
			board[x][y]++;
		
		if(answer_max < board[x][y])
			answer_max = board[x][y];
		
		int temp_x = x - 1;
		int temp_y = y;
		// 상이 index 범위 내라면
		if(temp_x >= 0)
		{
			if(board_status[temp_x][temp_y] == '@')
				board[temp_x][temp_y] += 2;

			else if(board_status[temp_x][temp_y] == '#')
				board[temp_x][temp_y] = 0;

			else
				board[temp_x][temp_y]++;
			
			if(answer_max < board[temp_x][temp_y])
				answer_max = board[temp_x][temp_y];
		}
	
			
		// 하
		temp_x = x + 1;
		if(temp_x < N)
		{
			if(board_status[temp_x][temp_y] == '@')
				board[temp_x][temp_y] += 2;

			else if(board_status[temp_x][temp_y] == '#')
				board[temp_x][temp_y] = 0;

			else
				board[temp_x][temp_y]++;			
			
			if(answer_max < board[temp_x][temp_y])
				answer_max = board[temp_x][temp_y];
		}
		
		// 좌
		temp_x = x;
		temp_y = y - 1;
		if(temp_y >= 0)
		{
			if(board_status[temp_x][temp_y] == '@')
				board[temp_x][temp_y] += 2;

			else if(board_status[temp_x][temp_y] == '#')
				board[temp_x][temp_y] = 0;

			else
				board[temp_x][temp_y]++;			
			
			if(answer_max < board[temp_x][temp_y])
				answer_max = board[temp_x][temp_y];
		}
		
		// 우
		temp_x = x;
		temp_y = y + 1;
		if(temp_y < N)
		{
			if(board_status[temp_x][temp_y] == '@')
				board[temp_x][temp_y] += 2;

			else if(board_status[temp_x][temp_y] == '#')
				board[temp_x][temp_y] = 0;

			else
				board[temp_x][temp_y]++;			
			
			if(answer_max < board[temp_x][temp_y])
				answer_max = board[temp_x][temp_y];
		}
	}
	
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < N; j++)
	// 	{
	// 		if(answer_max < board[i][j])
	// 			answer_max = board[i][j];
	// 	}
	// }
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < N; j++)
	// 	{
	// 		board[i][j] = 0;
			
			
	// 		char temp;
	// 		cin >> temp;
	// 		if(temp == '0')
	// 			continue;
			
	// 		if(temp == '@')
	// 			ats.push_back({i, j});
			
	// 		else if(temp == '#')
	// 			sharps.push_back({i, j});
	// 	}
	// }
	
	// for(int i = 0; i < K; i++)
	// {
	// 	Point point;
	// 	cin >> point.x >> point.y;
	// 	// 인덱스라 -1씩 해서 넣어주기
	// 	// bombs.push_back({point.x-1, point.y-1});
	// 	Bomb(N, board, {point.x-1, point.y-1});
	// }
	
	// bombs에 있는 상하좌우의 인덱스를 보고
	// board의 숫자를 올리기
	// 함수로 만들까..
	// for(int i = 0; i < K; i++)
	// {
	// 	Bomb(N, board, bombs.at(i));
	// }
	
	// max 구하기
	// int mx = *max_element(begin(board[0]), end(board[N-1]));
	// int max = 0;
	// for(int i = 0; i < N; i++)
	// {
	// 	for(int j = 0; j < N; j++)
	// 	{
	// 		if(board[i][j] == 0)
	// 			continue;
			
	// 		if(max < board[i][j])
	// 			max = board[i][j];
	// 	}
	// }
	
	cout << answer_max;
	
	for(int i = 0; i < N; i++)
		delete[] board[i];
	delete[] board;
	
	return 0;
}