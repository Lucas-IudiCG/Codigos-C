// CI?NCIA DA COMPUTA??O
// ESTRUTURA DE DADOS I
// PROF. ANDR? KISHIMOTO
// Exemplo de ponteiros em C++

#include <iostream>
#include <clocale>

using namespace std;

bool ShouldContinue(int page);
void Tutorial01();
void Tutorial01TLDR();
void Tutorial02();
void Tutorial02TLDR();
void SwapByRef(char& a, char& b);
void SwapByPointer(char* a, char* b);

int main()
{
    setlocale(LC_ALL, "pt_BR");

    int option = 0;
    do
    {
        cout << "//***** Exemplo de ponteiros em C++ - Prof. Andr? Kishimoto *****\n"
            << "// [1] Tutorial de ponteiros\n"
            << "// [2] Tutorial de ponteiros (TL;DR)\n"
            << "// [3] Passagem de par?metros por ponteiro\n"
            << "// [4] Passagem de par?metros por ponteiro (TL;DR)\n"
            << "// [0] Sair\n"
            << "// Escolha uma op??o: ";
        cin >> option;
        cout << '\n';

        switch (option)
        {
            case 1: Tutorial01(); break;
            case 2: Tutorial01TLDR(); break;
            case 3: Tutorial02(); break;
            case 4: Tutorial02TLDR(); break;
        }
    } while (option != 0);
}

bool ShouldContinue(int page)
{
    char key;
    cout << "// Continuar? (S/N) ";
    cin >> key;
    
    bool shouldContinue = toupper(key) != 'N';

    if (page > 0 && shouldContinue)
        cout << "//( " << page << " )////////////////////////////////////////////////////////////////////////////////////////";
    cout << "//\n//\n";

    return shouldContinue;
}

void Tutorial01()
{
    cout << "//( TUTORIAL DE PONTEIROS )//////////////////////////////////////////////////////////////////////\n\n";

    int num = 10;

    cout << "int num = 10; \t\t// num ? uma vari?vel do tipo int com valor " << num << ".\n\n";

    int* ptrNum = nullptr;

    cout << "int* ptrNum = nullptr; \t// ptrNum ? uma vari?vel do tipo \"ponteiro para int\" e, inicialmente, ? um ponteiro nulo.\n";
    cout << "\t\t\t// O valor inicial de ptrNum ?: " << ptrNum << ".\n\n";

    ptrNum = &num;

    cout << "ptrNum = &num; \t\t// ptrNum recebe o endere?o de mem?ria da vari?vel num (observe o & antes de num).\n";
    cout << "\t\t\t// Ou seja, ptrNum **aponta** para o endere?o de mem?ria de num.\n";
    cout << "\t\t\t// O valor atual de ptrNum ?: " << ptrNum << ".\n\n";

    cout << "// Como num ? uma vari?vel, podemos imprimir seu endere?o de mem?ria usando o operador & (refer?ncia/address-of).\n";
    cout << "// Com a instru??o cout << &num, obtemos o seguinte valor: " << &num << ".\n";
    cout << "// Observe que o valor impresso na linha acima ? o mesmo valor de ptrNum (" << ptrNum << ").\n//\n";

    if (!ShouldContinue(2)) return;

    cout << "// Para acessar o valor do endere?o de mem?ria apontado por ptrNum, devemos usar o operador indireto (*).\n";
    cout << "// Observe que o operador indireto usa o mesmo s?mbolo do operador de multiplica??o (o asterisco).\n";
    cout << "// No entanto, o operador indireto ? um operador un?rio, sendo colocado antes do ponteiro.\n";
    cout << "// Esse operador tamb?m ? conhecido como operador de derefer?ncia (dereference/indirection operator).\n//\n";

    cout << "// Portanto, para imprimir o valor armazenado no endere?o de mem?ria apontado por ptrNum, podemos usar a\n";
    cout << "// instru??o cout << *ptrNum. Com essa instru??o, nosso c?digo imprime o valor " << *ptrNum << ", que ? o valor armazenado\n";
    cout << "// pela vari?vel num (" << num << ").\n//\n";

    cout << "// Tamb?m podemos usar a \"indire??o\" para alterar o valor armazenado no endere?o de mem?ria apontado\n";
    cout << "// por um ponteiro. Por exemplo:\n\n";
    cout << "*ptrNum = 99;\n\n";

    *ptrNum = 99;

    cout << "// Observe que, fazendo isso, estamos alterando o **conte?do armazenado no endere?o de mem?ria**.\n";
    cout << "// Assim, a instru??o acima automaticamente altera o valor armazenado pela nossa vari?vel num.\n";
    cout << "// O valor atual da vari?vel num ?: " << num << ".\n";
    cout << "// (ou seja, o valor atribu?do na instru??o anterior usando a indire??o do ponteiro ptrNum).\n//\n";

    if (!ShouldContinue(3)) return;

    int xyz = 2;

    cout << "int xyz = 2; \t\t// xyz ? outra vari?vel do tipo int com valor " << xyz << " e endere?o " << &xyz << ".\n\n";

    ptrNum = &xyz;

    cout << "ptrNum = &xyz; \t\t// ptrNum agora recebe o endere?o de mem?ria da vari?vel xyz.\n";
    cout << "\t\t\t// Ou seja, ptrNum **aponta** para o endere?o de mem?ria de xyz.\n\n";

    cout << "// O valor atual de ptrNum ?: " << ptrNum << ".\n";
    cout << "// E o conte?do armazenado no endere?o de mem?ria apontado por ptrNum agora ?: " << *ptrNum << ".\n";
    cout << "// Portanto, ap?s a ?ltima instru??o (ptrNum = &xyz), ptrNum passou a apontar para o endere?o de xyz.\n//\n";
    
    cout << "// Considerando a pr?xima instru??o:\n\n";
    cout << "*ptrNum = *ptrNum * 2;\n\n";

    *ptrNum = *ptrNum * 2;

    cout << "// Qual ser? o valor armazenado nas vari?veis num, xyz e ptrNum?\n//\n";

    if (!ShouldContinue(4)) return;

    cout << "// Vejamos:\n";
    cout << "cout << num << '\\n'; \t\t// Exibe o n?mero " << num << ".\n";
    cout << "cout << xyz << '\\n'; \t\t// Exibe o n?mero " << xyz << ".\n";
    cout << "cout << ptrNum << '\\n'; \t// Exibe o endere?o " << ptrNum << ".\n";
    cout << "cout << *ptrNum << '\\n'; \t// Exibe o n?mero " << *ptrNum << ".\n\n";

    cout << "// Portanto, a instru??o:\n";
    cout << "// *ptrNum = *ptrNum * 2;\n//\n";
    cout << "// ? equivalente ?:\n";
    cout << "// xyz = xyz * 2;\n//\n";
    cout << "// J? que, agora, ptrNum aponta para o endere?o de xyz.\n//\n";

    cout << "// E a pr?xima instru??o \"reinicia\" o ponteiro (volta a ser nulo, isto ?, \"aponta para ningu?m\"):\n\n";
    cout << "ptrNum = nullptr;\n\n";

    ptrNum = nullptr;

    cout << "// Valor atual de ptrNum: " << ptrNum << ".\n//\n";

    if (!ShouldContinue(5)) return;

    Tutorial01TLDR();
}

void Tutorial01TLDR()
{
    cout << "//( TUTORIAL DE PONTEIROS - TL;DR )//////////////////////////////////////////////////////////////\n//\n";
    cout << "// --> Sintaxe para declarar um ponteiro:\n";
    cout << "// tipo_de_dado* nome_do_ponteiro;\n";
    cout << "// tipo_de_dado *nome_do_ponteiro;\n//\n";
    cout << "// Em ambos os casos, dizemos que \"nome_do_ponteiro ? um ponteiro para um tipo_de_dado\".\n//\n";
    cout << "// --> Definir que o ponteiro ? nulo:\n";
    cout << "// nome_do_ponteiro = nullptr;\n//\n";
    cout << "// Voc? pode encontrar tamb?m o uso de NULL ou 0 no lugar de nullptr, comum em linguagem C.\n";
    cout << "// Prefira usar nullptr, da linguagem C++ (a partir de C++11).\n//\n";
    cout << "// --> Atribuir um valor (endere?o de mem?ria) para um ponteiro:\n";
    cout << "// nome_do_ponteiro = &variavel_do_mesmo_tipo_de_dado;\n//\n";
    cout << "// --> Acessar o valor armazenado no endere?o de mem?ria apontado pelo ponteiro:\n";
    cout << "// cout << *nome_do_ponteiro; // Exemplo de leitura.\n";
    cout << "// *nome_do_ponteiro = valor_do_tipo_de_dado; // Exemplo de escrita.\n//\n";

    if (!ShouldContinue(0)) return;
}

void Tutorial02()
{
    cout << "//( PASSAGEM DE PAR?METROS POR PONTEIRO )////////////////////////////////////////////////////////\n//\n";

    cout << "// Al?m da passagem de par?metros de uma fun??o:\n";
    cout << "// - Por valor (o valor passado na chamada da fun??o ? copiado para o par?metro, que pode ser visto como uma\n";
    cout << "// vari?vel local da fun??o) e\n";
    cout << "// - Por refer?ncia (o valor passado na chamada da fun??o n?o ? copiado para o par?metro, pois o par?metro *?*\n";
    cout << "// a vari?vel passada para o par?metro da fun??o, pois usa o mesmo endere?o de mem?ria),\n//\n";
    
    cout << "// Temos um terceiro tipo de passagem de par?metros: por ponteiro.\n";
    cout << "// O funcionamento ? parecido com a passagem por refer?ncia (que usa o operador & nos par?metros): na\n";
    cout << "// passagem de par?metros por ponteiros, n?o h? c?pia de valores e a fun??o pode alterar o conte?do das\n";
    cout << "// vari?veis passadas por ponteiros (exceto quando os par?metros s?o marcados como constantes).\n//\n";
    
    cout << "// Na passagem por ponteiro, quem chama a fun??o deve passar endere?os de mem?ria nos par?metros (usando o\n";
    cout << "// operador de endere?o/refer?ncia &).\n//\n";

    if (!ShouldContinue(2)) return;
    
    cout << "// Para fins de compara??o, considere, por exemplo, a seguinte fun??o (passagem por refer?ncia):\n\n";

    cout << "void SwapByRef(char& a, char& b)\n";
    cout << "{\n";
    cout << "  char temp = a;\n";
    cout << "  a = b;\n";
    cout << "  b = temp;\n";
    cout << "}\n\n";

    cout << "// Para chamar a fun??o, podemos ter um c?digo como:\n\n";

    cout << "char val1 = '?';\n";
    cout << "char val2 = '!';\n";
    cout << "SwapByRef(val1, val2);\n";
    cout << "cout << \"val1: \" << val1 << \", val2: \" << val2 << \".\\n\"; // val1: !, val2: ?.\n\n";

    if (!ShouldContinue(3)) return;

    cout << "// A pr?xima fun??o ? um exemplo de passagem por ponteiro:\n\n";

    cout << "void SwapByPointer(char* a, char* b)\n";
    cout << "{\n";
    cout << "  char temp = *a;\n";
    cout << "  *a = *b;\n";
    cout << "  *b = temp;\n";
    cout << "}\n\n";

    cout << "// E, para chamar a nova fun??o, podemos escrever o seguinte c?digo de exemplo:\n\n";

    cout << "val1 = '?';\n";
    cout << "val2 = '!';\n";
    cout << "SwapByPointer(&val1, &val2);\n";
    cout << "cout << \"val1: \" << val1 << \", val2: \" << val2 << \".\\n\"; // val1: !, val2: ?.\n\n";

    if (!ShouldContinue(4)) return;

    cout << "// Observe o que muda na passagem por ponteiro:\n";
    cout << "// - Na fun??o SwapByPointer(), precisamos usar o operador indireto nos par?metros a e b para alterar seus\n";
    cout << "// valores. Repare que a vari?vel char temp *n?o* ? um ponteiro.\n";
    cout << "// - Ao chamar a fun??o SwapByPointer(), precisamos usar o operador de endere?o & nos par?metros passados\n";
    cout << "// para a fun??o.\n//\n";
    
    cout << "// Em ambos os casos, n?o ? poss?vel chamar as fun??es com valores literais, express?es e constantes, isto ?:\n//\n";
    
    cout << "// const char CONST_VAL = 'a';\n";
    cout << "// SwapByRef('x', 'y');\n";
    cout << "// SwapByPointer('x', 'y');\n";
    cout << "// SwapByRef(CONST_VAL, val2);\n";
    cout << "// SwapByPointer(&CONST_VAL, &val2);\n";
    cout << "// SwapByRef(val1 + 1, val2);\n";
    cout << "// SwapByPointer(&val1 + 1, &val2);\n//\n";
    
    cout << "// Resultam em erro de compila??o (o ?ltimo at? compila mas ? bem poss?vel que o programa ter? um comportamento\n";
    cout << "// inesperado).\n//\n";

    if (!ShouldContinue(5)) return;
    
    Tutorial02TLDR();
}

void Tutorial02TLDR()
{
    cout << "//( PASSAGEM DE PAR?METROS POR PONTEIRO - TL;DR )////////////////////////////////////////////////\n//\n";

    cout << "// --> A passagem de par?metros por ponteiro ? parecido com a passagem por refer?ncia: n?o h? c?pia de valores\n";
    cout << "// e a fun??o pode alterar o conte?do das vari?veis passadas por ponteiros (exceto quando const).\n//\n";
    
    cout << "// --> Passagem por ponteiro requer endere?o de mem?ria, portanto, ? necess?rio usar o operador & na vari?vel\n";
    cout << "// passada para o par?metro.\n//\n";

    cout << "// --> Exemplo:\n";
    cout << "void SwapByPointer(char* a, char* b)\n";
    cout << "{\n";
    cout << "  char temp = *a;\n";
    cout << "  *a = *b;\n";
    cout << "  *b = temp;\n";
    cout << "}\n\n";

    cout << "val1 = '?';\n";
    cout << "val2 = '!';\n";
    cout << "SwapByPointer(&val1, &val2);\n";
    cout << "cout << \"val1: \" << val1 << \", val2: \" << val2 << \".\\n\"; // val1: !, val2: ?.\n\n";

    cout << "// --> N?o ? poss?vel passar valores literais, express?es e constantes nos par?metros de uma fun??o quando h?\n";
    cout << "// passagem por ponteiro.\n//\n";

    if (!ShouldContinue(0)) return;
}

void SwapByRef(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

void SwapByPointer(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}