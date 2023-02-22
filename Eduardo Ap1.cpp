#include <iostream>
#include <string>
#include "Stack.h"


void WelcomeMessage();
void CustomExpression();
void TestExpression();
void RunCheck(const std::string& str);
bool CheckSymbols(const std::string& str);
bool CheckChar(const std::string& str);
std::string ConversionExpression(const std::string& str);
int ValuesVariables(const std::string& str);
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
	ValuesVariables(new_expression);
	//PrintResults();
}

void TestExpression()
{
	std::cout << "\n*** EXPRESSAO DE TESTE ***\n\n";

	const std::string str = "(A+B)*(C-D)/(E*F^2)";
	RunCheck(str);
	std::string new_expression = ConversionExpression(str);
	new_expression;
	ValuesVariables(new_expression);
	//PrintResults();
}

void RunCheck(const std::string& str)
{
	bool isValid = CheckSymbols(str) && CheckChar(str);
	std::cout << str << "\nEh uma expressao " << (isValid ? "valida" : "que contem erros") << ".\n\n";
}

bool CheckSymbols(const std::string& str)
{
	// Pilha para armazenar os simbolos do tipo "abre" que aparecem na string.
	Stack::Stack Symbols = Stack::Create();

	for (const char& c : str)
	{
		// Se estamos preocupados com esses quatro simbolos do tipo "abre": ( { [ <
		// Qualquer simbolo que nao pertenca a esse conjunto e ignorado (ou melhor, nao
		// e inserido na pilha), sendo processado no bloco de instrucoes do else.
		// Se encontrarmos um desses simbolos na string, empilhamos o simbolo. Assim,
		// sabemos qual foi o ultimo simbolo do tipo "abre" a aparecer na string.
		if (c == '(' || c == '[' || c == '{' || c == '<')
		{
			Stack::Push(Symbols, c);
		}
		else
		{
			// Encontramos um imbolo do tipo "fecha".
			// Se o ultimo simbolo do tipo "abre" que apareceu na string nao for o seu
			// par, entao a string ja possui um erro e paramos a checagem de simbolos,
			// retornando false.
			// Sabemos qual foi o ultimo simbolo do tipo "abre" que apareceu na string
			// olhando quem esta no topo da pilha.
			char top = Stack::Top(Symbols);

			if ((c == ')' && top != '(')
				|| (c == ']' && top != '[')
				|| (c == '}' && top != '{')
				|| (c == '>' && top != '<'))
			{
				return false;
			}

			// Encontramos um simbolo do tipo "fecha" && o ultimo simbolo do tipo "abre"
			// que apareceu na string (topo da pilha) e o seu par. OK, par encontrado,
			// desempilhamos o simbolo "abre" pois ele ja foi verificado.
			if ((c == ')' && top == '(')
				|| (c == ']' && top == '[')
				|| (c == '}' && top == '{')
				|| (c == '>' && top == '<'))
			{
				Stack::Pop(Symbols);
			}
		}
	}

	// Depois de processarmos todos os caracteres da string no loop for acima, a pilha
	// de simbolos deve estar vazia. Caso ainda exista algum simbolo empilhado apos
	// percorrermos toda a string, significa que faltou um ou mais simbolos do tipo "fecha"
	// para que a expressao esteja correta.
	return Stack::IsEmpty(Symbols);
}

bool CheckChar(const std::string& str)
{
	char caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ+-*/^()";
	for (const char& c : str)
	{
		for (const char& s : caracteres)
		{
			if (c != caracteres[s])
				return false;

		}
	}
	return true;
}

std::string ConversionExpression(const std::string& str)
{
	//Passar a expressao infixa para a RPN
	//return PostfixExpression;
}

int ValuesVariables(const std::string& str)
{
	//Atribuir valores as variaveis e realiza o calculo
	//return result;
}

void PrintResults(const std::string& str)
{
	//Print do resultado
}
