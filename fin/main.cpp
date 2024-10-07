#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Stack
{
private:
    enum { MAX = 10 }; //(non-standard syntax)
    unsigned char st[MAX]; //stack: array of integers
    int top;
    int frq[260];//number of top of stack
public:
    Stack() //constructor
    {
        top = -1;
        for (int i = 0; i<260; i++)
            frq[i] = 0;
    }
    void push(unsigned char c) //put number on stack
    { st[++top] = c; frq[(int)c]++; }
    int pop() //take number off stack
    { unsigned char c = st[top]; frq[(int)c]--; return st[top--]; }
    unsigned char GetMax()
    {
        int mx = 0; unsigned char ans;
        for (int i = 0; i<260; i++)
        {
            if (mx < frq[i])
            {
                mx = frq[i]; ans = (unsigned char)i;
            }
        }
        return ans;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    Stack s;
    s.push(1);
    s.push(1);
    s.push(2);
    s.push(2);
    s.push(2);
    cout << s.GetMax() << endl;
    return 0;
}