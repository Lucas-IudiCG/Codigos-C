#include <iostream>
#include "Student.h"

int main()
{
    setlocale(LC_CTYPE, "Portuguese");

    std::cout << "Exemplo de TAD {Student}\n";

    std::string enrollment ="1234567890";
    std::string name = "Romero Britto";
    Student s1 = CreateStudent(enrollment,name);
    UpdateScoreN1(s1,1.5f);
    UpdateScoreN2(s1,3.5f);
    UpdateScoreSub(s1,5.5f);
    UpdateScoreExam(s1,7.5f);
    Print(s1);
}

