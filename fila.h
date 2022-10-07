#include<string>
using namespace std;

const int TAM = 32;

class Queue
{   public:
        Queue();
        ~Queue();
        void Append(string name, int x, int y, int z, int h, string j);
        void Serve(string &name, int &x, int &y, int &z, int &h, string &j);
        void Embaralhar();      //Função para embaralhar a fila
        void Distribuir(Queue &p1, Queue &p2);      //Função para distribuir as cartas entre os jogadores
        bool Empty();
        bool Full();
        void Clear();
        int Size();

    private:
    // declaração de tipos
    
    struct cartas
    { 
        string modelo;
        int curbWeight;
        int engineSize;
        int horsepower;
        int price;
        string group;
    };
    int Head;
    int Tail;
    int count;
    cartas card[TAM+1];         //Vetor para cartas
    
};