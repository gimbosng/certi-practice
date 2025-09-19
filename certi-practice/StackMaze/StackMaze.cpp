// StackMaze.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct
{
    int X;
    int Y;
}PAIR;

int g_map[100][100];
char g_resultMap[100][100];
PAIR g_stack[10000];
int g_top;

int main()
{
    int testCase;
    int width, height;
    int startX, startY, nowX, nowY;
    char input[101];
    bool isFindPath = false;

    scanf_s("%d", &testCase);

    while (testCase--)
    {
        isFindPath = false;
        g_top = 0;

        scanf_s("%d%d", &width, &height);

        for (int i = 0; i < height; i++)
        {
            scanf_s("%s", input);

            for (int j = 0; j < width; j++)
            {
                if (input[j] == '2')
                {
                    startX = i;
                    startY = j;
                }
                g_map[i][j] = input[j] - '0';
            }
        }

        g_stack[g_top].X = startX;
        g_stack[g_top].Y = startY;
        g_top++;

        while (g_top)
        {
            nowX = g_stack[g_top - 1].X;
            nowY = g_stack[g_top - 1].Y;

            if (g_map[nowY][nowX] == 3)
            {
                isFindPath = true;
                break;
            }
            g_map[nowY][nowX] = 1;

            if (nowX > 0 && g_map[nowY][nowX - 1] != 1)
            {
                g_stack[g_top].X = nowX - 1;
                g_stack[g_top].Y = nowY;
                g_top++;
            }
            else if (nowX < width - 1 && g_map[nowY][nowX + 1] != 1)
            {
                g_stack[g_top].X = nowX + 1;
                g_stack[g_top].Y = nowY;
                g_top++;
            }
            else if (nowY > 0 && g_map[nowY - 1][nowX] != 1)
            {
                g_stack[g_top].X = nowX;
                g_stack[g_top].Y = nowY - 1;
                g_top++;
            }
            else if (nowX < height - 1 && g_map[nowY + 1][nowX] != 1)
            {
                g_stack[g_top].X = nowX;
                g_stack[g_top].Y = nowY + 1;
                g_top++;
            }
            else
            {
                g_top--;
            }
        }

        if (isFindPath == false)
        {
            printf("Can not fine path.\n");
        }
        else
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    g_resultMap[i][j] = 'X';
                }
            }

            while (g_top)
            {
                g_top--;
                nowX = g_stack[g_top].X;
                nowY = g_stack[g_top].Y;
                g_resultMap[nowY][nowX] = '.';
            }

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    printf("%c", g_resultMap[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
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
