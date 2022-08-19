#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
  int A[6];
  int top;

public:
  Stack()
  {
    top = -1;
  }

  void Push(int n)
  {
    if (top == 6 - 1)
    {
      printf("Error : stack overflow\n");
      return;
    }
    A[++top] = n;
  }

  void Pop()
  {
    if (top == -1)
    {
      printf("No item to pop\n");
      return;
    }
    top--;
  }

  int Top()
  {
    return A[top];
  }

  int isEmpty()
  {
    if (top == -1)
      return 1;
    return 0;
  }
};

int main()
{
  Stack S;
  S.Push(1);
  S.Push(2);
  S.Push(3);
  S.Push(4);
  S.Push(5);
  S.Push(6);
  S.Push(7);
  S.Push(8);
  S.Pop();
  S.Pop();
  S.Pop();
  S.Pop();
  S.Pop();
  S.Pop();
  S.Pop();
  S.Pop();
  S.Pop();
}