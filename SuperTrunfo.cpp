//Rodrigo Silva Berti

#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<sstream>
#include<math.h>
#include<time.h>
#include"fila.h"

using namespace std;
using std::getline;

int main(){

    ifstream cards("cards.csv",ios::in); //Abre o arquivo contendo as cartas
    Queue Baralho,deck1,deck2;           //Utilizando a classe pilha que foi criada
    char sep =',';
    int peso,cc,hp,price,x;
    string grupo,name,str,cmc;


    for(int i=0;i<33 ;i++){         //While para inserir as cartas na fila
        getline(cards,name,sep);
        //cout<<name<<endl;
        

        getline(cards,str,sep);
        stringstream ss1;                  //Função stringstream para converter uma string para um inteiro
        ss1 << str;
        ss1 >> peso;

        str = " ";
        getline(cards, str,sep);
        stringstream ss2;
        ss2 << str;
        ss2 >> cc;

        str = " ";
        getline(cards, str,sep);
        stringstream ss3;
        ss3 << str;
        ss3 >> hp;

        str = " ";
        getline(cards, str,sep);
        stringstream ss4;
        ss4 << str;
        ss4 >> price; 

        str = " ";
        getline(cards, grupo, '\n');

        if (i > 0)      // Esse if faz a exclusão da primeira linha que são apenas os tipos de cada item
        {
            Baralho.Append(name,peso,cc,hp,price,grupo);
        }
        
    }

    cout<<"==================================================="<<endl;          //Explicando as regras do jogo
    cout<<"          Regras do Jogo:                          "<<endl;
    cout<<"O jogo consiste em comparar as cartas e as usas habilidades ate que"<<endl;
    cout<<"um dos jogadores fique com todas as cartas e isso determina quem ganha e quem perde."<<endl;
    cout<<"Quando voce ganha uma rodada a carta do seu adiversario vai para o final do seu baralho."<<endl;
    cout<<"Sao 32 cartas no total e 16  cartas para cada jogador"<<endl;
    cout<<"A carta SUPER TRUNFO(1A) vence todas as cartas do baralho exeto castas que tenham a letra A no grupo "<<endl;
    cout<<"==================================================="<<endl;

    Baralho.Embaralhar();                   //Chama o procedimento de embaralhar
    Baralho.Distribuir(deck1, deck2);       //Chama o procedimento para distribuir as cartas em Deck1 e Deck2

    cout<<"Quer comecar o jogo?(1-Sim/2-Nao)"<<endl;
    cin>>x;

    int peso2,cc2,hp2,price2,win=1,y,i=0;       //Variaveis temporarias para o deck 2
    string grupo2,name2;

    deck1.Serve(name,peso,cc,hp,price,grupo);           //Dois serve para os temporarios para fazer as comparações
    deck2.Serve(name2,peso2,cc2,hp2,price2,grupo2);

    srand(time(0));
    
    if (x == 1)
    {

        do
        {
            cout<<"==================================================="<<endl;
            cout<<"Estamos na "<<i<<" rodada"<<endl;
            cout<<"Voce esta com "<<deck1.Size()+1<<" cartas"<<endl;
            cout<<"O seu adversario ta com "<<deck2.Size()+1<<" cartas"<<endl;
            cout<<"==================================================="<<endl;
            cout<<endl;

            cout<<"Sua carta atual e essa:"<<endl;
            cout<<"Nome: "<<name<<" Peso: "<<peso<<" Tamanho do motor: "<<cc<<" Potencia: "<<hp<<" Preco: "<<price<<" Grupo: "<<grupo<<endl;
            cout<<endl;

            if(win == 1){                   //If com as escolhas do jogador

                cout<<"1. Peso bruto"<<endl;
                cout<<"2. Cilindrada"<<endl;
                cout<<"3. Potencia (Cv)"<<endl;
                cout<<"4. Preco em dolar"<<endl;
                cout<<"Digite qual campo voce quer comparar: ";
                cin>>y;
                cout<<endl;
                while (y < 0 || y > 4)
                {
                    cout<<"Voce digitou um valor invalido.Tente novamente"<<endl;
                    cin>>y;
                }
                
                cout<<endl;
            }else{
                cout<<"E a vez do computador jogar, o campo para comparar e o: ";
                y = rand()%4+1;
                cout<<y<<endl;
            }
            
            if(grupo == "1A" || grupo2 == "1A" ){       //Filtro para saber se tem uma carta super trunfo
                if (grupo == "1A")
                {
                    if (grupo2 == "2A" || grupo2 == "3A" || grupo2 == "5A" || grupo2 == "8A" || grupo2 == "6A" || grupo2 == "4A" || grupo == "7A") //Filtro para cartas que o super trunfo perde
                    {
                        cout<<"Voce tem uma carta super trunfo mas o adiversario tem uma carta com o grupo A"<<endl;
                        win = 0;
                    }else{
                        cout<<"Voce tem uma carta super trunfo"<<endl;
                        win = 1;
                    }
                    
                }else if (grupo2 == "1A")
                {
                    if (grupo == "2A" || grupo == "3A" || grupo == "5A" || grupo == "8A" || grupo == "6A" || grupo == "4A" || grupo == "7A")  //Filtro para cartas que o super trunfo perde
                    {
                        cout<<"O adversario tem uma carta super trunfo mas voce tem uma carta com o grupo A"<<endl;
                        win = 1;
                    }else{
                        cout<<"O adversario tem uma carta super trufo"<<endl;
                        win = 0;
                    }             
                    
                }
                
            }else{
                if (y == 1)
                {
                    if (peso > peso2)       //If para fazer as comparações entre os atributos
                    {
                        cout<<"Voce ganhou essa rodada (:"<<endl;                     
                        win = 1;
                        
                    }else{                      
                        win = 0;
                        cout<<"Voce perdeu essa rodada ;-;"<<endl;
                                    
                    }
                }else if (y == 2)
                {
                    if (cc > cc2)
                    {         
                        cout<<"Voce ganhou essa rodada (:"<<endl;            
                        win = 1;
                                              
                    }else{
                        win = 0;   
                        cout<<"Voce perdeu essa rodada ;-;"<<endl;
                        
                    }
                }else if (y == 3)
                {
                    if (hp > hp2)
                    {
                        cout<<"Voce ganhou essa rodada (:"<<endl;                        
                        win = 1;
                        
                    }else{
                        win = 0;
                        cout<<"Voce perdeu essa rodada ;-;"<<endl;
                        
                    }
                }else if(y == 4)
                {
                    if (price > price2)
                    {
                        cout<<"Voce ganhou essa rodada (:"<<endl; 
                        win = 1;
                        
                        
                    }else{
                        win = 0;
                        cout<<"Voce perdeu essa rodada ;-;"<<endl;
                        
                    }
                }
            }

            if (win == 1)           //If para fazer as alocaçôes corretas de quando o usuario ganha ou perde
            {
                if (deck1.Size() == 30)
                {
                    deck1.Append(name2,peso2,cc2,hp2,price2,grupo2);
                    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
                    cout<<"------------------ Parabens voce ganhou o jogo ------------------"<<endl;
                    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
                    win = 2;

                }else{
                    deck1.Append(name2,peso2,cc2,hp2,price2,grupo2);        //Fazer os append e serve conforme os jogadores for ganhando
                    deck2.Serve(name2,peso2,cc2,hp2,price2,grupo2);
                }
            }else{
                if (deck2.Size() == 30)
                {
                    deck2.Append(name,peso,cc,hp,price,grupo);
                    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
                    cout<<"------------ Infelizmente voce perdeu.Tente novamente -----------"<<endl;
                    cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
                    win = 2;
                }else{
                    deck2.Append(name,peso,cc,hp,price,grupo);
                    deck1.Serve(name,peso,cc,hp,price,grupo);
                    
                }
            }
            i++;
        }while (win != 2);

    }

}