#include <iostream>
#include <stdio.h> 
#include <time.h>
using namespace std;

int i,j; 
char casa[3][3];
bool fim=false,ganhou=false;
int VitoriaDoJogador1 = 0;
int VitoriaDoJogador2 = 0;
int JogosEmpatados = 0;

void ocuptab(){  //                 FUNCAO PARA PREENCHER A MATRIZ COM ESPAÇOS VAZIOS
        for ( i = 0; i < 3; i++)
        {
            for ( j = 0; j < 3; j++) 
            {
                casa[i][j]=' '; 
            }
        }
    } 

 void verificafim(){   //            FUNCAO PARA VERIFICAR SE A MATRIZ JA ESTA DEVIDAMENTE PREENCHIDA E SE O JOGO PODE SER ENCERRADO
     
     for (i = 0; i < 3; i++)
     {
         for ( j = 0; j < 3; j++)
         {
            if (casa[i][j]==' '){
                
                
            }else if(casa[i][j]=='X' || casa[i][j]=='O'){
               
                fim =true;
            }
        }
    }
}

void mostrartab(){  //            FUNCAO PARA APRESENTAR A TABELA AOS JOGADORES, INICIALMENTE VAZIA, MAS VAI SENDO PREENCHIDA CONFORME AS JOGADAS OCORREM
        cout<<endl;
    for(int i=0 ; i<3 ; i++){
        cout<<" "<< casa[i][0] <<"  |";
        cout<<" "<< casa[i][1] <<"  |";
        cout<<" "<< casa[i][2] <<endl;

        if(i!=2){
            cout<<" ___ ___ ____\n"<<endl;
        }
    }
}

bool verificawin(){
    // VERIFICANDO POSSIBILIDADES DE VITORIA
    
        if ((casa[0][0]=='X' && casa[0][1]=='X' && casa[0][2]=='X') || (casa[1][0]=='X' && casa[1][1]=='X' && casa[1][2]=='X') 
        || (casa[2][0]=='X' && casa[2][1]=='X' && casa[2][2]=='X')|| (casa[0][0]=='X' && casa[1][0]=='X' && casa[2][0]=='X') || 
        (casa[0][1]=='X' && casa[1][1]=='X' && casa[2][1]=='X') || (casa[0][2]=='X' && casa[1][2]=='X' && casa[2][2]=='X')  ||
         (casa[0][0]=='X' && casa[1][1]=='X' && casa[2][2]=='X') || (casa[0][2]=='X' && casa[1][1]=='X' && casa[2][0]=='X'))
        {
            
            VitoriaDoJogador1=VitoriaDoJogador1+1;
            ganhou=true;
            fim=true;
            return true;

        }if ((casa[0][0]=='O' && casa[0][1]=='O' && casa[0][2]=='O') || (casa[1][0]=='O' && casa[1][1]=='O' && casa[1][2]=='O') 
        || (casa[2][0]=='O' && casa[2][1]=='O' && casa[2][2]=='O')|| (casa[0][0]=='O' && casa[1][0]=='O' && casa[2][0]=='O') 
        || (casa[0][1]=='O' && casa[1][1]=='O' && casa[2][1]=='O') || (casa[0][2]=='O' && casa[1][2]=='O' && casa[2][2]=='O')|| 
        (casa[0][0]=='O' && casa[1][1]=='O' && casa[2][2]=='O') || (casa[0][2]=='O' && casa[1][1]=='O' && casa[2][0]=='O')) 
        {
            VitoriaDoJogador2=VitoriaDoJogador2+1;
            ganhou=true;
            fim=true;
            return true;
            
        }else if(casa[0][0]!=' ' && casa[0][1]!=' ' && casa[0][2]!=' ' && casa[1][0]!=' ' && casa[1][1]!=' ' && casa[1][2]!=' ' 
        && casa[2][0]!=' ' && casa[2][1]!=' ' && casa[2][2]!=' ')
        {
            JogosEmpatados=JogosEmpatados+1;
            ganhou=true;
            fim=true;
            return true;
        }       
    }

int main(int argc, char const *argv[])
{

    bool a, jogador1ativo = true;
    bool jogador2ativo = false;
    int l,c;
    int opcao;
    char aop;
    int tempo = clock();
    
    ocuptab();
    
    cout<<"Suas opcoes sao:"<<endl;
    cout<<"1: Novo Jogo"<<endl;
    cout<<"2: Sair"<<endl;
    cin>>opcao;
    system("cls");

    switch (opcao)
    {
    case 1:
    mostrartab();

    do
    {
        for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            
            do
            {
                // verifica se é a vez do jogador 1, se for, o jogador irá informar onde deseja jogar
                if (jogador1ativo)
            {
                
                system("cls");
                mostrartab();
                cout<<endl<<"Vez do Jogador 1:(X) "<<endl;
                cout<<"informe a linha: ";
                cin>>l;
                l--;
                cout<<"informe a coluna: ";
                cin>>c;
                c--;
                // se as condiçoes do if forem atendidas, a posicao que o jogador 1 escolheu receberá "X" e o proximo a jogar será o jogador 2
                if (casa[l][c]==' ' && (l>=0 && l<3) && (c>=0 && c<3))
                {
                casa[l][c]='X';
                jogador1ativo=false;
                jogador2ativo=true;
                mostrartab();
                verificafim();
                verificawin();
                // se as condiçoes do if não forem atendidas, a mensagem de erro será exibida e o jogador 1 terá de informar novos valores
                }else {
                    cout<<endl<<"Posicao ja preenchida ou fora do intervalo"<<endl;
                }
                
                // verifica se é a vez do jogador 2, se for, o jogador irá informar onde deseja jogar
            }else if(jogador2ativo){
                
                system("cls");
                mostrartab();
                cout<<endl<<"Vez do Jogador 2:(O) "<<endl;
                cout<<"informe a linha: ";
                cin>>l;
                l--;
                cout<<"informe a coluna: ";
                cin>>c;
                c--;
                // se as condiçoes do if forem atendidas, a posicao que o jogador 2 escolheu receberá "O" e o proximo a jogar será o jogador 1
                if (casa[l][c]==' ' && (l>=0 && l<3) && (c>=0 && c<3)) 
                {
                casa[l][c]='O';
                jogador1ativo=true;
                jogador2ativo=false;
                mostrartab();
                verificafim();
                verificawin();
                // se as condiçoes do if não forem atendidas, a mensagem de erro será exibida e o jogador 2 terá de informar novos valores
                }else {
                    cout<<endl<<"Posicao ja preenchida ou fora do intervalo"<<endl;
                }
            }
            // Ao fim de cada laço é verificado se há ou não um vencedor, ou se o jogo deu "velha"
            } while (ganhou==false);
        }
    }
            // Aqui o placar é exibido e em seguida é perguntado se desejam jogar novamente ou encerrar o jogo
            cout<<"Placar: "<<endl<<"Jogador 1: "<<VitoriaDoJogador1<<endl<<"Jogador 2: "<<VitoriaDoJogador2<<endl<<"Empates: "<<JogosEmpatados;
            cout<<endl<<"Deseja continuar: (s/n)";
            cin>>aop;
            ocuptab();
            ganhou=false;
            jogador1ativo=true;
            
    } while (aop=='s' || aop=='S');
        
    case 2:
        break;
    }
}