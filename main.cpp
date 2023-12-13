#include<iostream> //padrao input output
#include<conio.h> //linux
#include<cstdlib> //system
#include<cstring> //manipulacao de string
#include<cstdio> // input output de arquivos similar ao C
#include<windows.h> //windows
#include<unistd.h> //linux

using namespace std;

#include "Funcionarios.hpp"


int main(){
        Funcionarios f;
        void login();
          login();
            while(true){
                system("cls");
                cout<<"***********************************************************************\n\n\n";
                cout<<"                   Gerenciador de funcionarios                               \n\n";
                cout<<"***********************************************************************\n\n\n";
                cout<<"\n\t\t ------------------------------------------------";
                cout<<"\n\t\t 1 - Adicionar novo funcionario";
                cout<<"\n\t\t 2 - Ver todos os funcionarios";
                cout<<"\n\t\t 3 - Ver detalhes de um funcionario";
                cout<<"\n\t\t 4 - Editar funcionario ja existente";
                cout<<"\n\t\t 5 - Remover funcionario";
                cout<<"\n\t\t 6 - Valor total dos salarios";
                cout<<"\n\t\t 7 - Relatorio de funcionarios com salario maior ou menor ao informado";
                cout<<"\n\t\t 8 - Relatorio de funcionarios por setor pesquisado";
                cout<<"\n\t\t 0 - Sair   ";
                cout<<"\n\t\t ------------------------------------------------";
                cout<<"\n\n\t   Escolha uma opcao: ";

                int menu;
                cin>>menu;
                switch (menu) {
                    case 1:
                        f.AddFunc();
                        break;
                    case 2:
                        f.ListaFunc();
                        break;
                    case 3:
                        f.InfoFunc();
                        break;
                    case 4:
                        f.EditFunc();
                        break;
                    case 5:
                        f.DelFunci();
                        break;
                    case 6:
                        f.SomaSalar();
                        break;
                    case 7:
                        f.RelatSalar();
                        break;
                    case 8:
                        f.RelatSetor();
                        break;
                    default:
                        cout<<"\n Opcao invalida \n";
                        system("pause");
                        break;
                    case 0:
                    	system("cls");
                    	cout<<"Bye bye :^)" << endl;
                        return 0;
                }

            }

}

void login(){
    FILE *usernameFile;
    cout<<"***********************************************************************\n\n\n";
    cout<<"                   Gerenciador de funcionarios                               \n\n";
    cout<<"***********************************************************************\n\n\n";
    cout<<"\n\t\t ------------------------------------------------";
    cout<<"\n\t\t 1 - Registrar";
    cout<<"\n\t\t 2 - Fazer login";
    cout<<"\n\t\t ------------------------------------------------";
    cout<<"\n\n\t   Escolha uma opcao: ";
        int opcao;
        cin>>opcao;

    switch(opcao){
    case 1:{
        char rg_username[30],rg_senha[30];

        system("cls");
        cout<<"\nInsira o nome de usuario :";
        cin>>rg_username;
        cout<<"\nInsira uma senha :";
        cin>>rg_senha;

        usernameFile= fopen("userdata.txt","a");
        fprintf(usernameFile, "%s %s\n",rg_username,rg_senha);
        fclose(usernameFile);

        system("cls");
        cout<<"\nRegistration Sucessful\n";}
        login();
        break;

    case 2:{
        int pp=0;
        char user[30],senha[30],u[30],s[30];
        system("cls");
        cout<<"Insira a seguir"<<endl;
        cout<<"Nome de usuario :";
        cin>>user;
        cout<<"Senha :";
        cin>>senha;

        usernameFile= fopen("userdata.txt","r");
        while(fscanf(usernameFile,"%s %s\n",&u[0],&s[0])!=EOF)
        {
            if(strcmp(user,u) == 0  && strcmp(senha,s) == 0)
                {
                    pp=1;
                    system("cls");
                }
        }
        fclose(usernameFile);
        if(pp==1)
        {
                cout<<"\nOla "<<user<<"\n<Seu Login foi realizado com sucesso>\n";
                cin.ignore();
                cin.ignore();
                system("pause");
        }
        else
        {
                cout<<"\nErro ao iniciar sessao\n";
                system("pause");
                system("cls");
                main();
            }
        }break;

    default:
        system("cls");
        main();
    }
}


