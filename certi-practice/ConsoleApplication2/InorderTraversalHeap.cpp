// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <malloc.h>

typedef struct n Node;
typedef struct n
{
    int value;
    Node *left;
    Node *right;
};
Node* Root;

void init(int value)
{
    Root = (Node*)malloc(sizeof(Node));
    Root->value = value;
    Root->left = NULL;
    Root->right = NULL;
}

void insert(int value)
{
    Node* temp = Root;
    Node* New;
    New = (Node*)malloc(sizeof(Node));
    New->value = value;
    New->left = NULL;
    New->right = NULL;

    while (1)
    {
        if (temp->value < New->value)
        {
            if (temp->right == NULL)
            {
                temp->right = New;
                break;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            if (temp->left == NULL)
            {
                temp->left = New;
                break;
            }
            else
            {
                temp = temp->left;
            }
        }
    }
}

int deleteNode(int value)
{
    Node* temp = Root;
    Node* parent = Root;
    Node* child_p;
    Node* child;

    while (temp)
    {
        if (temp->value < value)
        {
            parent = temp;
            temp = temp->right;
        }
        else if (temp->value > value)
        {
            parent = temp;
            temp = temp->left;
        }
        else if (temp->value == value)
        {
            if (temp->right == NULL && temp->left == NULL)
            {
                if (parent->right == temp)
                {
                    parent->right = NULL;
                }
                else
                {
                    parent->left = NULL;
                }
            }
            else if (temp->right != NULL && temp->left != NULL)
            {
                child_p = temp;
                child = temp->left;

                while (child->right != NULL)
                {
                    child_p = child;
                    child = child->right;
                }

                if (child_p->left == child)
                {
                    child_p->left = child->right;
                }
                else
                {
                    child_p->right = child->right;
                }

                temp->value = child->value;
                temp = child;
            }
            else
            {
                if (temp->right != NULL)
                {
                    if (parent->right == temp)
                    {
                        parent->right = temp->right;
                    }
                    else
                    {
                        parent->left = temp->right;
                    }
                }
                else
                {
                    if (parent->right == temp)
                    {
                        parent->right = temp->left;
                    }
                    else
                    {
                        parent->left = temp->left;
                    }
                }
            }
        }

        free(temp);
        return 1;
    }

    return 0;
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
