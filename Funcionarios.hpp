#ifndef FUNCIONARIOS_HPP_INCLUDED
#define FUNCIONARIOS_HPP_INCLUDED
#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<unistd.h>

using namespace std;

class Funcionarios{
    protected:
        char m_nome[30];
        char m_sobrenome[30];
        int m_idade;
        char m_sexo;
        char m_cpf[15];
        char m_instrucao;
        char id[5];
        char m_funcao[30];
        int m_setor = 0;
        char m_cbo[6]; //3171-10 programacao para exemplo
        int m_tmp_contri;
        int m_exp;
        float m_salario_contratual;

    public:

        ~Funcionarios(){};

        void AddFunc();
        void InfoFunc();
        void ListaFunc();
        void DelFunci();
        void EditFunc();
        void SomaSalar();
        void RelatSalar();
        void RelatSetor();


    };


#endif // FUNCIONARIOS_HPP_INCLUDED
