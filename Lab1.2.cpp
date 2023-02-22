#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> pilha;
    pilha.push (0);
    pilha.push (100);
    pilha.push (200);
    pilha.push (300);
    pilha.push (400);
    pilha.push (500);
    pilha.push (600);
    pilha.push (700);
    pilha.push (800);
    pilha.push (900);

    cout<<pilha.top()<<endl;
    cout<<pilha.size()<<endl;

    while(!pilha.empty()){
            cout << pilha.top()<<"\n";
            pilha.pop();

    }
}
