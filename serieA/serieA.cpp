#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void lettura();
void scrittura();
void classifica_punti();
void classifica_marcatori();
void ricerca();

struct squadra{
      string nome;
      int punti;
      string nome_capocannoniere;
      int capocannoniere_gol;
      int code;
}squadre[10], app;

const string lista="lista.dat";
int n;

int main()
{
    int c;
    do{
        cout << "\nPremi 1 per leggere"<<endl;
        cout << "Premi 2 per scrivere"<<endl;
        cout << "Premi 3 per stampare la classifica dei punti"<<endl;
        cout << "Premi 4 per stampare la classifica dei marcatori"<<endl;
        cout << "Premi 5 per cercare"<<endl;
        cout << "Premi 6 per uscire"<<endl;
        cin>>c;
        switch (c)
        {
            case 1:
                    lettura();
                    break;
            case 2:
                    scrittura();
                    break;
            case 3:
                    classifica_punti();
                    break;
            case 4:
                    classifica_marcatori();
                    break;
            case 5:
                    ricerca();
                    break;
        }
    }while(c>0&&c<6);
    cout<<"Addio";
    return 0;
}

void lettura()
{
    int i=0;
    string stringa;
    fstream fin;
    fin.open(lista.c_str(),ios::in | ios::binary);
    if(!fin)
        cout<<"Apertura del file impossibile";
    else
    {

        for(int c=0;fin.read((char*)&squadre[c],sizeof(squadre[c]));c++)

        {
            if(squadre[c].nome[0]=='\0')
                break;
            cout<<"Nome squadra:        "<<squadre[i].nome<<endl;
            cout<<"Punti squadra:       "<<squadre[i].punti<<endl;
            cout<<"Nome capocannoniere: "<<squadre[i].nome_capocannoniere<<endl;
            cout<<"Gol capocannoniere:  "<<squadre[i].capocannoniere_gol<<endl;
            cout<<"Codice squadra:      "<<squadre[i].code<<endl;
            i++;

        }
                    /*contatore=fin.tellg();
                    cout<<contatore<<endl;
        fin.read((char*)&squadre,sizeof(squadre));
        cout<<"Nome squadra:        "<<squadre[i].nome<<endl;
        cout<<"Punti squadra:       "<<squadre[i].punti<<endl;
        cout<<"Nome capocannoniere: "<<squadre[i].nome_capocannoniere<<endl;
        cout<<"Gol capocannoniere:  "<<squadre[i].capocannoniere_gol<<endl;
        i++;*/
    }
    fin.close();
    fflush(stdin);
    n=i;
}

void scrittura()
{
    int c=1, i=0;
    fstream fout;
    fout.open(lista.c_str(),ios::app | ios::binary);

    while(c!=0&&i<10)
    {
        cout<<"\nInserisci nome squadra: ";
        fflush(stdin);
        getline(cin, squadre[i].nome);
        cout<<"\nInserisci punti squadra: ";
        cin>>squadre[i].punti;
        cout<<"\nInserisci nome del capocannoniere: ";
        fflush(stdin);
        getline(cin, squadre[i].nome_capocannoniere);
        cout<<"\nInserisci gol del capocannoniere: ";
        cin>>squadre[i].capocannoniere_gol;
        cout<<"\nInserisci codice squadra: ";
        cin>>squadre[i].code;
        if(i!=9)
        {
            cout<<"\nPremi 0 per uscire"<<endl;
            cout<<"Premi 1 per inserire un altro record"<<endl;
            cin>>c;
        }
        if(c==1)
            i++;
    }
    cout<<"\nSalvataggio su file..."<<endl;

    for(int c=0;c<i;c++){
            fout.write((char*)&squadre,sizeof(squadre));
    }

    fout.close();
    n=i;

}

void classifica_punti()
{
    for(int i=0; i<=n; i++)
    {
         for(int j=i+1 ; j<n; j++)
         {
            if(squadre[i].punti<squadre[j].punti)
            {
                app=squadre[i];
                squadre[i]=squadre[j];
                squadre[j]=app;
            }
         }
    }
    cout<<"LA GRANDE CLASSIFICA DEI PUNTI DELLE SQUADRE (considerare per la schedina...)\n"<<endl;
    for(int I=0;I<n;I++)
    {
      cout<<"Con "<<squadre[I].punti<<" punti accumulati, la squadra ";
      cout<<squadre[I].nome<<endl<<endl;
    }
}

void classifica_marcatori()
{
   for(int i=0; i<=n; i++)
    {
         for(int j=i+1 ; j<n; j++)
         {
            if(squadre[i].capocannoniere_gol<squadre[j].capocannoniere_gol)
            {
                app=squadre[i];
                squadre[i]=squadre[j];
                squadre[j]=app;
            }
         }
    }
    cout<<"LA GRANDE CLASSIFICA DEI MARCATORI\n"<<endl;
    for(int I=0;I<n;I++)
    {
      cout<<"Con "<<squadre[I].capocannoniere_gol<<" gol segnati, il grande ";
      cout<<squadre[I].nome_capocannoniere;
      cout<<" della squadra "<<squadre[I].nome<<endl<<endl;
    }
}

void ricerca()
{
    int codice;
    long counter;
    fstream fin;
    fin.open(lista.c_str(),ios::app|ios::binary);
    if(!fin)
        cout<<"Apertura file impossibile"<<endl;
    else{
        cout<<"Inserisci il codice da cercare:";
        cin>>codice;
        //counter=((codice)*(sizeof(squadre[0])));
        cout<<"il counter e' "<<counter<<endl;
        fin.seekg(counter); //seekg non riesce a posizionarsi nel file, ho provato a leggere un solo record
                            //struct, ma non riesce in alcun modo. Ho optato per una soluzione stupida
        /*fin.read((char*)&squadre[0],sizeof(squadre[0]));
        int indice=(counter/(sizeof(squadre)));
        cout<<"indice e' "<<indice<<endl;*/
        cout<<"Nome squadra:        "<<squadre[codice].nome<<endl;
        cout<<"Punti squadra:       "<<squadre[codice].punti<<endl;
        cout<<"Nome capocannoniere: "<<squadre[codice].nome_capocannoniere<<endl;
        cout<<"Gol capocannoniere:  "<<squadre[codice].capocannoniere_gol<<endl<<endl;

    }
    fin.close();

}
