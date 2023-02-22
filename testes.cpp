#include<iostream>

using namespace std;

int main()
{
    std::string input;
     std::cout << "Digite o Calculo: ";
    std::getline (std::cin,input);
for(int i = 0; i < input.length(); ++i) {
 if (input[i] >='A' && input[i] <= 'Z'||input[i] >='a' && input[i] <= 'z' ){
    std::cout<<input[i]<<"\n";
 }
}
 	return 0;
}
