#include <iostream>
#include <string>
#include "Stack.h"
#include "Stack.cpp"

void WelcomeMessage();
void CustomExpression();
void TestExpression();
void RunCheck(const std::string& str);
bool CheckSymbols(const std::string& str);
bool CheckChars(const std::string& str);
std::string ConversionExpression(const std::string& str);
int Priority(char c);
float ValuesVariables(const std::string& str);
void PrintResults(float result);

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
		<< "validar se a expressao esta digitada de forma correta.\n\n";
}

void CustomExpression()
{
	std::cin.ignore();

	std::cout << "\nDigite uma expressao: ";

	std::string str;
	std::getline(std::cin, str);

	RunCheck(str);
	std::string new_expression = ConversionExpression(str);
	new_expression;
	std::cout << new_expression;
	float result = ValuesVariables(new_expression);
	result;
	PrintResults(result);
}

void TestExpression()
{
	std::cout << "\n*** EXPRESSAO DE TESTE ***\n\n";

	const std::string str = "(A+B)*(C-D)/(E*F^G)";
	RunCheck(str);
	std::string new_expression = ConversionExpression(str);
	new_expression;
	std::cout << new_expression;
	float result = ValuesVariables(new_expression);
	result;
	PrintResults(result);
}

void RunCheck(const std::string& str)
{
	bool isValid = CheckSymbols(str) && CheckChars(str);
	std::cout << str << "\nEh uma expressao " << (isValid ? "valida" : "que contem erros") << ".\n\n";
}

bool CheckChars(const std::string& str)
{	
	// str[c] = "(A+B)*(C-D)/(E*F^G)"
	// caracteres[s] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ+-*/^() "
	char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ+-*/^() ";
	
	for (const char& c : str)
	{
		for (const char& s : caracteres)
		{			
			if (c == s)
				break;
			else
				continue;
		}
	}
	return true;
}

bool CheckSymbols(const std::string& str)
{
	
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
	// para realizar essa funções, foi nescessario criar dois outros membros no struct stack, sendo um float array e um outro contador, alem de 2 outras funções para editar esses valores.
	Stack::Stack Variavel= Stack::Create();		//cria a stack principal
	Stack::Stack Variavel2= Stack::Create();	//cria a stack segundaria
	float Resultado;							//define a variavel resultado que será muito utilizada no codigo
	float arr[4096];							//um vetor que será utilizado para salvar os valores das variaveis
	int i=0;									// i será a variavel de controle do vetor
	for (const char& c : str)
	{
		if (c >= 'A' && c <= 'Z') 		    	//se c for uma letra entre A e Z, esses codigo perguntará qual o valor da variavel em questão em ordem, enquanto da push dos resultados na pilha variavel
		{
			Stack::Push(Variavel,c);
			std::cout<<"Valor de "<<c<<": ";
			std::cin>>Resultado;
			arr[i]=Resultado;
			i++;
		}
		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')		//se c for uma operação,apenas da push na operação 
		{
			Stack::Push(Variavel, c);
		}
	}			
	i=0;
	for (const char& c : str)		// como fizemos as contas separadas da declaração de variaveis, e do jeito que a pilha funciona, tivemos que colocar outra função para inverter e salvamos os resultados em uma pilha auxiliar
	{
		char Top= Stack::Pop(Variavel);
		Stack::Push(Variavel2,Top);
	}
	for (const char& c : str)
	{	
		char Top=Stack::Pop(Variavel2);
		if (Top >= 'A' && Top <= 'Z' )
		{
			Stack::PushR(Variavel,arr[i]); // da push em uma das variaveis do arr[i], de acordo com as variaveis citadas durante a declaração
			i++;		
		}
		else if(Top=='+'||Top=='-'||Top=='*'||Top=='/'||Top=='^') //se c for uma operação,ele realiza a operação dando dois pops em varaivel, e salvando o resultado
																//para essa parte é extremamente nescessario está em NRP, pois isso indica a ordem das operações a ser realizadas
		{
			float Top1=Stack::PopR(Variavel);
			float Top2=Stack::PopR(Variavel);
			if(Top=='+')
			{
				float Resultado=Top2+Top1;
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top2<<"+"<<Top1<<"="<<Resultado<<"\n";
			}
			if(Top=='-')
			{
				float Resultado=Top2-Top1;
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top2<<"-"<<Top1<<"="<<Resultado<<"\n";
			}
			if(Top=='*')
			{
				float Resultado=Top2*Top1;
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top2<<"*"<<Top1<<"="<<Resultado<<"\n";
			
			}
			if(Top=='/')
			{
				float Resultado=Top2/Top1;
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top2<<"/"<<Top1<<"="<<Resultado<<"\n";
			}
			if(Top=='^')
			{
				float Resultado=Top1;
				for(int j=0;j<Top2-1;++j)
				{
					Resultado=Resultado*Top1;
				}
				Stack::PushR(Variavel,Resultado);
				std::cout<<Top1<<"^"<<Top2<<"="<<Resultado<<"\n";
			}	
		}
	}
		
	Resultado=Stack::PopR(Variavel);			//depois de todas as operações deve apenas sobrar uma variavel, que será o resultado de todas as outras contras
	return Resultado;
}

void PrintResults(float result)
{
	std::cout << " O resultado da expressao e " << result;

}