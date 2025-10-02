// Validation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <malloc.h>

struct strNode
{
    int value;
    char opp;
    int left;
    int right;
} Node[1001];

int count, a;
char a2[20];
int state = 1;

void input()
{
    int b[3] = { 0, }, top = 0;

    scanf_s("%d", &a);
    gets_s(a2);

    int t = 1;
    for (int i = 1; a2[i]; i++)
    {
        if (a2[i] >= '0' && a2[i] <= '9')
        {
            a2[i] = a2[i] - '0';
            b[top] = b[top] * t + a2[i];
            t = 10;
        }
        else if (a2[i] != ' ')
        {
            if (top == 0)
            {
                Node[a].opp = a2[i];
            }
            else if (top == 1)
            {
                Node[a].left = a2[i];
            }
            else
            {
                Node[a].right = a2[i];
            }

            b[top] = -1, top++, t = 1;
            continue;
        }

        if (a2[i + 1] == ' ' || a2[i + 1] == '\0')
        {
            if (b[top] != -1)
            {
                if (top == 0)
                {
                    Node[a].value = b[top];
                }
                else if (top == 1)
                {
                    Node[a].left = b[top];
                }
                else
                {
                    Node[a].right = b[top];
                }
            }
            top++, t = 1;
        }
    }
}

void solve(int v)
{
    if (Node[v].left > 0)
    {
        solve(Node[v].left);
    }

    if (Node[v].opp >= 42 && Node[v].opp <= 47)
    {
        if (Node[v].left == 0 || Node[v].right == 0)
        {
            state = 0;
        }
    }
    else if (Node[v].value > 0)
    {
        if ((Node[v].left == 0 && Node[v].right == 0) == false)
        {
            state = 0;
        }
    }

    if (Node[v].right > 0)
    {
        solve(Node[v].right);
    }
}

int main()
{
    
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
