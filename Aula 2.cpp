#include <ionstream>

int main()
{
    cout<<"Digite um n�mero inteiro: ";

    int N;
    std::cin>>N;

    if (N %2=0)
    {
        std::cout<<"N�mero � par.\n";
    }
    else
    {
        std::cout<<"N�mero � impar.\n";
    }
}
