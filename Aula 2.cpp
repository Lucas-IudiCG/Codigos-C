#include <ionstream>

int main()
{
    cout<<"Digite um número inteiro: ";

    int N;
    std::cin>>N;

    if (N %2=0)
    {
        std::cout<<"Número é par.\n";
    }
    else
    {
        std::cout<<"Número é impar.\n";
    }
}
