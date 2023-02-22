#include <iostream>
#include <string>
#include "Stack.h"
#include "Stack.cpp"

void WelcomeMessage();
void CustomExpression();
void TestExpression();
void RunCheck(const std::string& str);
bool CheckSymbols(const std::string& str);
bool CheckVariables(const std::string& str);
std::string ConversionExpression(const std::string& str);
int Priority(char c);
float ValuesVariables(const std::string& str);
void PrintResults(const std::string& str);

int main()
{
	setlocale(LC_CTYPE, "Portuguese");

	WelcomeMessage();

	std::string input;
	int option = 0;

	do
	{
		std::cout << "\n*** AVALIADOR DE EXPRESSOES MATEMATICAS ***\n"
			<< "[1] Inserir uma expressao\n"
			<< "[2] Usar expressoes definidas pelo programa\n"
			<< "[0] Encerrar\n"
			<< "Escolha uma opcao: ";
		std::cin >> input;

		// Tenta converter o valor da string input (o que o usuario digitou) para o int option.
		// Se nao for possivel realizar a conversao (por exemplo, a pessoa digitou uma palavra),
		// entao std::stoi() lanca uma excecao, que e capturada no catch (...).
		// Nesse caso, vamos definir option = -1 para que o codigo caia no switch-case default
		// e mostre a mensagem de opcao invalida.
		try
		{
			option = std::stoi(input);
		}
		catch (const std::exception& e)
		{
			option = -1;
		}
		switch (option)
		{
		case 1: CustomExpression(); break;
		case 2: TestExpression(); break;

		default:
			if (option != 0)
				std::cout << "\n*** OPCAO INVALIDA! ***\n";
			break;
		}
	} while (option != 0);
}

void WelcomeMessage()
{
	std::cout << "*** Avaliador de expressões matemática \n\n"
		<< "Este programa realiza a conversão de uma expressão em notação infixa\n"
		<< "para a Reverse Polonese Notation.\n"
		<< "Para isso, o usuário digita a expressão somente com parenteses para \n"
		<< "definir a prioridade e cada variavel representada por uma única letra.\n"
		<< "Além de aceitar somente os cinco operadores (soma, subtracao, divisao,\n"
		<< "multiplicacao e exponenciacao."
		<< "Após inserir a expressão, o programa realiza uma verificacao para\n"
		<< "validar se a expressao esta digitada de forma correta.";
}

void CustomExpression()
{
	// Usamos o std::cin.ignore() para corrigir um "bug" quando usamos std::getline() apos std::cin(),
	// pois o '\n' do std::cin() (enter pressionado pelo usuurio) e repassado para o std::getline(),
	// sendo que std::getline() e encerrada quando encontra uma quebra de linha ('\n').
	// std::cin.ignore(), sem parametros, ignora o ultimo caracter do std::cin() (no caso, o '\n').
	std::cin.ignore();

	std::cout << "\nDigite uma expressao: ";

	std::string str;
	std::getline(std::cin, str);

	RunCheck(str);
	std::string new_expression = ConversionExpression(str);
	new_expression;
	std::cout << new_expression<<"\n";
	ValuesVariables(new_expression);
}

void TestExpression()
{
	std::cout << "\n*** EXPRESSAO DE TESTE ***\n\n";

	const std::string str = "(A+B)*(C-D)/(E*F^G)\n";
	RunCheck(str);
	std::string new_expression = ConversionExpression(str);
	new_expression;
	std::cout << new_expression;
	float Resultado=ValuesVariables(new_expression);
	std::cout<<"Resultado: "<<Resultado<<"\n";
	//PrintResults();
}

void RunCheck(const std::string& str)
{
	bool isValid = CheckSymbols(str) & CheckVariables(str);
	std::cout << str << "\nEh uma expressao " << (isValid ? "valida" : "que contem erros") << ".\n\n";
}


bool CheckSymbols(const std::string& str)
{
	// Pilha para armazenar os simbolos do tipo "abre" que aparecem na string.
	Stack::Stack Symbols = Stack::Create();
	for (const char& c : str)
	{
		if (c == '(')
		{
			Stack::Push(Symbols, c);
		}
		else
		{
			char top = Stack::Top(Symbols);

			if ((c == ')' && top != '('))
			{
				return false;
			}
			if ((c == ')' && top == '('))
			{
				Stack::Pop(Symbols);
			}
		}
	}
	return Stack::IsEmpty(Symbols);
}

bool CheckVariables(const std::string& str)
{
	bool Var=true;
	char arr[4096];
	int arr2[4096];
	Stack::Stack Variables = Stack::Create();
	int i =0;
	int j =0;
	for (const char& c : str)
	{
		if (c >= 'A' && c <= 'Z')
		{
			Stack::Push(Variables,c);
			arr[i]=c;
			std::cout<<arr[i]<<"| ";
			arr2[i]=j;
			std::cout<<arr2[i]<<"| \n";
			++i;
		}
		++j;
				
}	
	
	return Var;
}

std::string ConversionExpression(const std::string& str)
{
	Stack::Stack Expression = Stack::Create();
	std::string PostfixExpression;
	//Passar a expressao infixa para a RPN
	for (const char& c : str)
	{
		if (c >= 'A' && c <= 'Z')
		{
			PostfixExpression += c;
		}

		else if(c == '(')
		{
			Stack::Push(Expression, c);
		}

		else if (c == ')')
		{
			while((Stack::Top(Expression)!='(') && (!Stack::IsEmpty(Expression)))
			{
				char temp=Stack::Top(Expression);
				PostfixExpression+=temp;
				Stack::Pop(Expression);
			}
			if(Stack::Top(Expression)=='(')
			{
				Stack::Pop(Expression);
			}
		}
		
		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		{
			if(Stack::IsEmpty(Expression))
			{
				Stack::Push(Expression, c);
			}
			else
			{
				if(Priority(c)>Priority(Stack::Top(Expression)))
				{
					Stack::Push(Expression, c);
				}	
				else if((Priority(c)==Priority(Stack::Top(Expression)))&&(c=='^'))
				{
					Stack::Push(Expression, c);
				}
				else
				{
					while((!Stack::IsEmpty(Expression))&&( Priority(c)<=Priority(Stack::Top(Expression))))
					{
						PostfixExpression+=Stack::Top(Expression);
						Stack::Pop(Expression);
					}
					Stack::Push(Expression, c);
				}
			}
		}	
	}

	while(!Stack::IsEmpty(Expression))
	{
		PostfixExpression+=Stack::Top(Expression);
		Stack::Pop(Expression);
	}
	
	return PostfixExpression;
}

int Priority(char c) 

{ 
    if(c == '^') return 3; 
    else if(c == '*' || c == '/') return 2; 
    else if(c == '+' || c == '-') return 1; 
    return -1; 
} 

float ValuesVariables(const std::string& str)
{
	Stack::Stack Variavel= Stack::Create();
	Stack::Stack Variavel2= Stack::Create();
	float Resultado;
	//Passar a expressao infixa para a RPN
	float arr[4096];
	int i=0;
	for (const char& c : str)
	{
		if (c >= 'A' && c <= 'Z')
		{
			Stack::Push(Variavel,c);
			std::cout<<"Valor de "<<c<<": ";
			std::cin>>Resultado;
			arr[i]=Resultado;
			i++;
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
		{
				Stack::Push(Variavel, c);
			}
}	
	i=0;
for (const char& c : str)
	{
		char Top= Stack::Pop(Variavel);
		Stack::Push(Variavel2,Top);
}
	for (const char& c : str)
	{	
		char Top=Stack::Pop(Variavel2);
		if (Top >= 'A' && Top <= 'Z' )
		{
			Stack::PushR(Variavel,arr[i]);
			i++;		
		}
		else if(Top=='+'||Top=='-'||Top=='*'||Top=='/'||Top=='^')
		{
			float Top1=Stack::PopR(Variavel);
			float Top2=Stack::PopR(Variavel);
			if(Top=='+'){
				float Resultado=Top2+Top1;
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top2<<"+"<<Top1<<"="<<Resultado<<"\n";
			}
			if(Top=='-'){
				float Resultado=Top2-Top1;
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top2<<"-"<<Top1<<"="<<Resultado<<"\n";
			}
			if(Top=='*'){
				float Resultado=Top2*Top1;
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top2<<"*"<<Top1<<"="<<Resultado<<"\n";
			
			}
			if(Top=='/'){
				float Resultado=Top2/Top1;
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top2<<"/"<<Top1<<"="<<Resultado<<"\n";
			}
			if(Top=='^'){
				float Resultado=Top1;
				for(int j=0;j<Top2-1;++j){
					Resultado=Resultado*Top1;
				}
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top1<<"^"<<Top2<<"="<<Resultado<<"\n";
			}	
		}
}
		
	Resultado=Stack::PopR(Variavel);
	return Resultado;
}


void PrintResults(const std::string& str)
{
	//Print do resultado
}