#ifndef STUDENT_H__
#define STUDENT_H__

#include <iostream>

struct Student
{
    std::string enrollment;
    std::string name;
    float n1;
    float n2;
    float sub;
    float exam;
};

Student CreateStudent(std::string enrollment,std::string name)
{
    Student student ={enrollment,name,0.0f,0.0f,0.0f,0.0f };

    return student;
}

void UpdateScoreN1(Student &student,float score)
{
    student.n1 =score;
}

void UpdateScoreN2(Student &student,float score)
{
    student.n2 =score;
}

void UpdateScoreSub(Student &student,float score)
{
    student.sub =score;
}

void UpdateScoreExam(Student &student,float score)
{
    student.exam =score;
}
void Print(const Student student)
{
    std::cout << "Matrícula: "<< student.enrollment << "\n"
        << "Nome: " << student.name <<"\n"
        <<"N1: " << student.n1 <<"\n"
        <<"N2: " << student.n2 <<"\n"
        <<"Sub: " << student.sub <<"\n"
        <<"Exame: " <<student.exam <<"\n";
}
#endif
