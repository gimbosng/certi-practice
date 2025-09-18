// Maze.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

#define MAX_MAZE_SIZE 100
#define IS_VISITED 1
#define NOT_VISITED 0
#define POSSIBLE_WAY 1
#define IMPOSSIBLE_WAY 0

int maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
int visited[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
char input[MAX_MAZE_SIZE];

int filePath(int x, int y)
{
	int result = 0;

	if (maze[x][y] == 1 || visited[x][y] == IS_VISITED)
	{
		return IMPOSSIBLE_WAY;
	}
	else if (maze[x][y] == 3)
	{
		return POSSIBLE_WAY;
	}
	else
	{
		visited[x][y] = IS_VISITED;

		result += filePath(x - 1, y);
		result += filePath(x + 1, y);
		result += filePath(x, y - 1);
		result += filePath(x, y + 1);

		visited[x][y] = NOT_VISITED;

		return result;
	}
}

int main()
{
	int testCase;
	int width, height;

	scanf_s("%d", &testCase);

	while (testCase--)
	{
		for (int i = 0; i < MAX_MAZE_SIZE; i++)
		{
			for (int j = 0; j < MAX_MAZE_SIZE; j++)
			{
				maze[i][j] = 1;
				visited[i][j] = NOT_VISITED;
			}
		}

		scanf_s("%d%d", &width, &height);

		for (int i = 0; i < height; i++)
		{
			scanf_s("%s", input);

			for (int j = 0; j < width; j++)
			{
				maze[i][j] = input[j] - '0';
			}
		}

		if (filePath(1, 1) > 0)
		{
			printf("1\n");
		}
		else
		{
			printf("0\n");
		}
	}
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
