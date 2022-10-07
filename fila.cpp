#include"fila.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>

using namespace std;

//Rodrigo Silva Berti

Queue::Queue()
{
    Head = 1;               //Pré-Condição: Não tem
    Tail = 0;               //Pós-Condições: Fila criada e iniciada como vazio
    count = 0;
}

Queue::~Queue()
{   
    int x;
    while ( ! Empty() ){

    }
    //Serve(x);
}

bool Queue::Empty()
{
    return (count == 0);            //Pré-Condição: A fila já tenha sido criada 
}                                   //Pós-Condições: Retorna false se a fila está cheia e true se está vazia

bool Queue::Full()
{
    return (count == 32);          //Pré-Condição: A fila já tenha sido criada 
}                                   //Pós-Condições: Retorna true se a fila está cheia e false se está vazia

int Queue::Size(){
    return count;
}

void Queue::Append(string name, int x, int y, int z, int h, string j)
{   
    if(Full())
    { 
        cout<<"Memoria cheia"<<endl;
        abort();
    }
    count++;
    Tail = (Tail%TAM)+1;                      //Pré-Condição: A fila já tenha sido criada e não está cheia
    card[Tail].modelo = name;                   //Pós-Condições: Os itens das cartas é armazenado no vetor de struct
    card[Tail].curbWeight = x;
    card[Tail].engineSize = y;
    card[Tail].horsepower = z;
    card[Tail].price = h;
    card[Tail].group = j;
}
void Queue::Serve(string &name, int &x, int &y, int &z, int &h, string &j)
{   
    if (Empty())
    { 
        cout << "Fila Vazia"<<endl;
        abort();
    }
    
    name = card[Head].modelo;                   //Pré-Condição: A fila já tenha sido criada e não está vazia
    x = card[Head].curbWeight;                  //Pós-Condições: os itens de inicio é removido do vetor e retornado para as variaveis no main
    y = card[Head].engineSize;
    z = card[Head].horsepower;
    h = card[Head].price;
    j = card[Head].group;
    count = count - 1;
    Head = (Head%TAM)+1;
}

void Queue::Embaralhar(){

    if (Empty())
    { 
        cout << "Fila Vazia"<<endl;
        abort();
    }

    cartas aux;
    int j,k;
    srand(time(0));

    for (int i = 0; i < 50; i++)
    {
        j = rand()%31+1;
        k = rand()%31+1;
        aux.modelo = card[j].modelo;
        aux.curbWeight = card[j].curbWeight;            //Pré-Condição: Já tenha salvo as cartas do arquivo na fila
        aux.engineSize = card[j].engineSize;            //Pós-Condições: Retorna os itens embaralhados para o baralho
        aux.horsepower = card[j].horsepower;
        aux.price = card[j].price;
        aux.group = card[j].group;

        card[j].modelo = card[k].modelo;
        card[j].curbWeight = card[k].curbWeight;
        card[j].engineSize = card[k].engineSize;
        card[j].horsepower = card[k].horsepower;
        card[j].price = card[k].price;
        card[j].group = card[k].group;

        card[k].modelo = aux.modelo;
        card[k].curbWeight = aux.curbWeight;
        card[k].engineSize = aux.engineSize;
        card[k].horsepower = aux.horsepower;
        card[k].price = aux.price;
        card[k].group = aux.group;

    }
    
}

void Queue::Distribuir(Queue &p1, Queue &p2){
    if (Empty())
    { 
        cout << "Fila Vazia"<<endl;
        abort();
    }

    int peso,cc,hp,price;
    string grupo,name;

    for (int i = 1; i <= 32; i++)
    {
        name = card[i].modelo;          //Pré-Condição: Já tenha salvo as cartas do arquivo na fila e embaralhado
        peso = card[i].curbWeight;      //Pós-Condições: Retorna os itens para o player 1 e 2
        cc = card[i].engineSize;
        hp = card[i].horsepower;
        price = card[i].price;
        grupo = card[i].group;
        p1.Append(name,peso,cc,hp,price,grupo);
        i++;
        name = card[i].modelo;
        peso = card[i].curbWeight;
        cc = card[i].engineSize;
        hp = card[i].horsepower;
        price = card[i].price;
        grupo = card[i].group;
        p2.Append(name,peso,cc,hp,price,grupo);
    }
   
}
