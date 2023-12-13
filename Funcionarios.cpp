#include "Funcionarios.hpp"

void Funcionarios::AddFunc(){
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o primeiro nome do funcionario: ";
            cin>>m_nome;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o segundo nome do funcionario: ";
            cin>>m_sobrenome;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira a idade do funcionario: ";
            cin>>m_idade;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o sexo (M = Masculino / F = Feminino): ";
            do{cin>>
                m_sexo;
                if(m_sexo!='M' && m_sexo!='F'){
                cout<<"\nOpcao invalida tente novamente "<<endl;}
            }while(m_sexo!='M' && m_sexo!='F');
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o CPF do funcionario: ";
            cin>>m_cpf;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o nivel de instrucao do funcionario(I=Infantil / F=Fundamental / M=Medio / S=Superior): ";
            do{
            cin>>m_instrucao;
            if(m_instrucao!='I' && m_instrucao!='F' && m_instrucao!='M' && m_instrucao!='S'){
                cout<<"\nOpcao invalida tente novamente "<<endl;
            }
            }while(m_instrucao!='I' && m_instrucao!='F' && m_instrucao!='M' && m_instrucao!='S');
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o numero de matricula [max 4 digitos]: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira a sua funcao: ";
            cin>>m_funcao;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o seu setor(1=ADM/2=Financeiro/3=RH/4=Comercial/5=Producao): ";
            do{
            cin>>m_setor;
            if(m_setor != 1 && m_setor != 2 && m_setor != 3 && m_setor != 4 && m_setor != 5){
                cout<<"\nOpcao invalida tente novamente "<<endl;
            }
            }while(m_setor != 1 && m_setor != 2 && m_setor != 3 && m_setor != 4 && m_setor != 5);
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o CBO do funcionario: ";
            cin>>m_cbo;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o tempo de contribuicao do funcionario: ";
            cin>>m_tmp_contri;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o tempo de experiencia do funcionario na area: ";
            cin>>m_exp;
            cout<<"\n----------------------------------------";
            cout<<"\n Insira o salario contratual(Inicial): ";
            cin>>m_salario_contratual;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\n\n\n\nCONFIRMACAO\n Pressione ''Y'' para confirmar a exclussao \n Presione outra tecla para negar \n";
            cin>>ch;
            if(ch=='y' || ch=='Y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", m_nome,m_sobrenome, id, m_funcao, m_idade, m_tmp_contri, m_exp, m_sexo, m_salario_contratual, m_cpf, m_cbo, m_instrucao,m_setor);
                fclose(file);
                cout<<"\nNova funcionario cadastrado\n";
            }
            else{
                AddFunc();}
                system("pause");
        };

void Funcionarios::InfoFunc(){
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nInsira o ID do funcionario: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!=EOF)
                if(strcmp(checkId,id)==0){
                	cout<<"\n---------------------";
                    cout<<"\nNome: "<<m_nome<<" "<<m_sobrenome;
                    cout<<"\n---------------------";
                    cout<<"\nIdade: "<<m_idade;
                    cout<<"\n---------------------";
                    if(m_sexo=='F'){
                    cout<<"\nSexo: Feminino";}
                    else if(m_sexo=='M'){
                        cout<<"\nSexo: Masculino";
                    }
                    cout<<"\n---------------------";
                    cout<<"\nCPF: "<<m_cpf;
                    cout<<"\n---------------------";
                    cout<<"\nGrau de instrucao: "<<m_instrucao<<" (I=Infantil / F=Fundamental / M=Medio / S=Superior)";
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nFuncao: "<<m_funcao;
                    cout<<"\n---------------------";
                    cout<<"\nSetor: "<<m_setor<<" (1=ADM/2=Financeiro/3=RH/4=Comercial/5=Producao)";
                    cout<<"\n---------------------";
                    cout<<"\nCBO: "<<m_cbo;
                    cout<<"\n---------------------";
                    cout<<"\nTempo de contribuicao: "<<m_tmp_contri;
                    cout<<"\n---------------------";
                    cout<<"\nTempo de experiencia: "<<m_exp;
                    cout<<"\n---------------------";
                    cout<<"\nSalario: "<<m_salario_contratual;
                    cout<<"\n---------------------";
                    cout<< endl;
                }
            fclose(file);
            system("pause");
                   };

void Funcionarios::ListaFunc(){
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n\t      Lista de funcionarios\n";
            cout<<"\n----------------------------------------------";
            cout<<"\n Nome        |     ID     |     Funcao\n";
            cout<<"----------------------------------------------";
            cout<< endl;
            while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
                cout<<"\n"<<m_nome<<" "<<m_sobrenome <<"\t\t"<<id<<"\t\t"<<m_funcao;
                cout<< endl;}
            fclose(file);
            system("pause");
        };


 void Funcionarios::DelFunci(){
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nInsira o ID para ser removido: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\nCONFIRMACAO\n Pressione ''Y'' para confirmar a exclussao \n Presione outra tecla para negar \n";
            cin>>ch;
            if(ch=='y' || ch=='Y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", m_nome,m_sobrenome, id, m_funcao, m_idade, m_tmp_contri, m_exp, m_sexo, m_salario_contratual, m_cpf, m_cbo, m_instrucao,m_setor );
                fclose(file);
                fclose(tempfile);
                int isRemoved = remove("data.txt");
                int isRenamed = rename("temp.txt", "data.txt");
                cout<<"\nFuncionario removido\n";
                system("pause");            }
            else{
                cout<<"\n Operacao abortada \n";
                system("pause");}
        };

void Funcionarios::EditFunc(){
            system("cls");
            char checkId[5];
            cout<<"\nInsira o ID do funcionario: ";
            cin>>checkId;
            char NovaFuncao[30];
            cout<<"\n-----------------------------";
            cout<<"\nInsira a nova funcao: ";
            cin>>NovaFuncao;
            char NovaCBO[6];
            cout<<"\n-----------------------------";
            cout<<"\nInsira a novo CBO: ";
            cin>>NovaCBO;
            int NovoTmp;
            cout<<"------------------------------";
            cout<<"\nInsira o novo tempo de contribuicao: ";
            cin>>NovoTmp;
            float NovoSalario;
            cout<<"------------------------------";
            cout<<"\nInsira o novo salario: ";
            cin>>NovoSalario;
            char NovoInstrucao;
            cout<<"------------------------------";
            cout<<"\nInsira o novo grau de instrucao(I=Infantil / F=Fundamental / M=Medio / S=Superior): ";
            cin>>NovoInstrucao;
            int NovaExp;
            cout<<"------------------------------";
            cout<<"\nInsira o novo tempo de experiencia: ";
            cin>>NovaExp;
            int NovaIdade;
            cout<<"------------------------------";
            cout<<"\nInsira a nova idade: ";
            cin>>NovaIdade;


            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d", &m_nome[0],&m_sobrenome[0], &id[0], &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", m_nome,m_sobrenome, id, NovaFuncao, NovaIdade, NovoTmp, NovaExp, m_sexo, NovoSalario, m_cpf, NovaCBO, NovoInstrucao,m_setor);
                else
                    fprintf(tempfile, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", m_nome,m_sobrenome, id, m_funcao, m_idade, m_tmp_contri, m_exp, m_sexo, m_salario_contratual, m_cpf, m_cbo, m_instrucao,m_setor );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            system("pause");
        };

void Funcionarios::SomaSalar(){
            float SomaSalarial = 0;
            system("cls");
            FILE *file;
            file = fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
            SomaSalarial = SomaSalarial+m_salario_contratual;
            }
            cout<< "O total dos salarios eh de: " << SomaSalarial << endl;
            fclose(file);
            system("pause");

};

void Funcionarios::RelatSalar(){
            float SalarioRelat;
            int option;
            FILE *file;

            system("cls");
            cout << "Insira um salario para fazer o relatorio" << endl;
            cin >> SalarioRelat;
            cout<<"\n\t\t ------------------------------------------------";
            cout<<"\n\t\t 1 - Relatorio salarios maior ou igual ao informado";
            cout<<"\n\t\t 2 - Relatorio salarios menor ou igual ao informado";
            cout<<"\n\t\t ------------------------------------------------";

            cin>> option;

            switch(option){
                case 1:
                    system("cls");
                    file =fopen("data.txt", "r");
                    while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
                        if(m_salario_contratual >= SalarioRelat){
                            cout<< "\n\t\tFuncionario: " <<m_nome<<" "<<m_sobrenome <<" - "<<" ID: "<< id<<" - "<< "Salario: "<< m_salario_contratual<< endl;
                            cout<<"\n\t\t------------------------------------------------"<<endl;
                            cout<<endl;
                        }
            }
                            fclose(file);
                            system("pause");
                    break;
                case 2:
                    system("cls");
                    file =fopen("data.txt", "r");
                    while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
                        if(m_salario_contratual <= SalarioRelat){
                            cout<< "\n\t\tFuncionario: " <<m_nome<<" "<<m_sobrenome <<" - "<<" ID: "<< id<<" - "<< "Salario: "<< m_salario_contratual<< endl;
                            cout<<"\n\t\t------------------------------------------------"<<endl;
                            cout<<endl;
                        }
            }
                            fclose(file);
                            system("pause");
                    }
            };
void Funcionarios::RelatSetor(){
            int option;
            int funcicont = 0;
            FILE *file;

            system("cls");
            cout << "Insira um setor para fazer o relatorio" << endl;
            cout<<"\n\t\t ------------------------------------------------";
            cout<<"\n\t\t 1 - Relatorio funcionarios do setor administrativo";
            cout<<"\n\t\t 2 - Relatorio funcionarios do setor financeiro";
            cout<<"\n\t\t 3 - Relatorio funcionarios do setor recursos humanos";
            cout<<"\n\t\t 4 - Relatorio funcionarios do setor comercial";
            cout<<"\n\t\t 5 - Relatorio funcionarios do setor producao";
            cout<<"\n\t\t ------------------------------------------------";
            cout<<endl;
            cin >> option;

            switch(option){
            case 1:
                    system("cls");
                    file = fopen("data.txt","r");
                    while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
                        if(m_setor == 1){
                            cout<< "\n\t\tFuncionario: " <<m_nome<<" "<<m_sobrenome <<" - "<<" ID: "<< id<<" - "<< "Setor: Administrativo"<<endl;
                            cout<<"\n\t\t------------------------------------------------"<<endl;
                            cout<<endl;
                            funcicont++;
                        }
                    }
                     if(funcicont == 0){
                        cout<<"Nenhum funcionario encontrado neste setor"<<endl;
                    }
                    fclose(file);
                    system("pause");
                    break;
            case 2:
                    system("cls");
                    file = fopen("data.txt","r");
                    while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
                        if(m_setor == 2){
                            cout<< "\n\t\tFuncionario: " <<m_nome <<" "<<m_sobrenome <<" - "<<" ID: "<< id<<" - "<< "Setor: Financeiro"<<endl;
                            cout<<"\n\t\t------------------------------------------------"<<endl;
                            cout<<endl;
                            funcicont++;
                        }
                    }
                     if(funcicont == 0){
                        cout<<"Nenhum funcionario encontrado neste setor"<<endl;
                    }
                    fclose(file);
                    system("pause");
                    break;
            case 3:
                    system("cls");
                    file = fopen("data.txt","r");
                    while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
                        if(m_setor == 3){
                            cout<< "\n\t\tFuncionario: " <<m_nome<<" "<<m_sobrenome <<" - "<<" ID: "<< id<<" - "<< "Setor: Recursos humanos"<<endl;
                            cout<<"\n\t\t------------------------------------------------"<<endl;
                            cout<<endl;
                            funcicont++;
                        }
                    }
                    if(funcicont == 0){
                        cout<<"Nenhum funcionario encontrado neste setor"<<endl;
                    }
                    fclose(file);
                    system("pause");
                    break;
            case 4:
                    system("cls");
                    file = fopen("data.txt","r");
                    while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
                        if(m_setor == 4){
                            cout<< "\n\t\tFuncionario: " <<m_nome<<" "<<m_sobrenome <<" - "<<" ID: "<< id<<" - "<< "Setor: Comercial"<<endl;
                            cout<<"\n\t\t------------------------------------------------"<<endl;
                            cout<<endl;
                            funcicont++;
                        }
                    }
                     if(funcicont == 0){
                        cout<<"Nenhum funcionario encontrado neste setor"<<endl;
                    }
                    fclose(file);
                    system("pause");
                    break;
            case 5:
                    system("cls");
                    file = fopen("data.txt","r");
                    while(fscanf(file, "%s %s %s %s %d %d %d %c %f %s %s %c %d\n", &m_nome[0],&m_sobrenome[0], &id[0] , &m_funcao[0], &m_idade, &m_tmp_contri, &m_exp, &m_sexo, &m_salario_contratual, &m_cpf[0], &m_cbo[0], &m_instrucao,&m_setor)!= EOF){
                        if(m_setor == 5){
                            cout<< "\n\t\tFuncionario: " <<m_nome<<" "<<m_sobrenome <<" - "<<" ID: "<< id<<" - "<< "Setor: Producao"<<endl;
                            cout<<"\n\t\t------------------------------------------------"<<endl;
                            cout<<endl;
                            funcicont++;
                        }
                    }
                     if(funcicont == 0){
                        cout<<"Nenhum funcionario encontrado neste setor"<<endl;
                    }
                    fclose(file);
                    system("pause");
                    break;
            default:
                    system("cls");
                    cout<<"\n\t\tOpcao invalida"<<endl;
                    system("pause");
                }



};
