// Operation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct strNode
{
    int value;
    char opp;
    int left;
    int right;
} node[10001];

int N, a, num1, num2;
char a2[10000];

void input()
{
    scanf_s("%d %s", &a, a2);

    if (a2[0] >= '0' && a2[0] <= '9')
    {
        node[a].value = atoi(a2);
        node[a].left = 0;
        node[a].right = 0;
    }
    else
    {
        scanf_s("%d %d", &num1, &num2);
        node[a].opp = a2[0];
        node[a].left = num1;
        node[a].right = num2;
    }
}

void solve(int v)
{
    if (node[v].left > 0)
        solve(node[v].left);
    if (node[v].right > 0)
        solve(node[v].right);

    if (node[v].opp == '+')
        node[v].value = node[node[v].left].value + node[node[v].right].value;
    else if (node[v].opp == '-')
        node[v].value = node[node[v].left].value - node[node[v].right].value;
    else if (node[v].opp == '*')
        node[v].value = node[node[v].left].value * node[node[v].right].value;
    else if (node[v].opp == '/')
        node[v].value = node[node[v].left].value / node[node[v].right].value;
}

int main()
{
    int testCase;

    scanf_s("%d", &testCase);

    for (int i = 0; i < testCase; i++)
    {
        scanf_s("%d", &N);

        for (int j = 0; j < N; j++)
        {
            input();
        }

        solve(1);
        printf("#%d %d\n", testCase, node[1].value);

        for (int k = 1; k < N; k++)
        {
            node[k].left = 0;
            node[k].right = 0;
            node[k].value = 0;
            node[k].opp = ' ';
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
