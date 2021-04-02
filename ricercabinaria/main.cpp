#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include "funzioni.hpp"

using namespace std;

/*! \mainpage <CENTER> La Ricerca per Codice </CENTER>
    * \author <B> Alessio Cusenza</B>
    * \version <B> V1.0 </B>
    * \date <B> Consegna progetto:   Mi hanno costretto, aiuto</B>
    *
    * \section caratteristiche CARATTERISTICHE DEL PROGETTO
    *
    *  Il software permette di:
    * - prendere in ingresso un file di testo
    * - genera un file di testo denominato thanos.txt
    * - dal file thanos sono eminate tutte le vocali
    *
    *\section UML DIAGRAMMA UML DEL PROGETTO
    * <IMG SRC = "uml.jpg" ALT = "Diagramma UML del progetto"/>
    *
    *\section CLASS DIAGRAMMA DELLE CLASSI PRESENTI NEL PROGETTO
    *<IMG SRC = "classi.jpg" ALT = "Diagramma delle classi del progetto"/>
    */

/*void lettura();
void scrittura();
void ricerca();
void modifica();
void cancella();

struct Rubrica{
       string nome;
       string cognome;
       int n_telefono;
       int codice_contatto;
}contatto[200], app;

const string lista="lista.dat";
int n;
*/

int main()
{
    //! \brief main nel quale tutto accade
    int c;
    do{
        cout << "\nPremi 1 per leggere"<<endl;
        cout << "Premi 2 per scrivere"<<endl;
        cout << "Premi 3 per ricercare il contatto in rubrica"<<endl;
        cout << "Premi 4 per modificare il contatto in rubrica"<<endl;
        cout << "Premi 5 per cancellare un contatto in rubrica"<<endl;
        cout << "Premi 6 per uscire"<<endl;
        cin>>c;
        switch (c)
        {
            case 1:

                    {
                        lettura();
                        break;
                    }
            case 2:
                    {
                        scrittura();
                        break;
                    }
            case 3:
                    {
                        ricerca();
                        break;
                    }
            case 4:
                    {
                        modifica();
                        break;
                    }
            case 5:
                    {
                        cancella();
                        break;
                    }
        }
    }while(c>0&&c<6);
    cout<<"Addio";
    return 0;
}

/*void lettura()
{
    int i=0;
    fstream fin;
    fin.open(lista.c_str(),ios::in | ios::binary);
    if(!fin)
        cout<<"Apertura del file impossibile";
    else
    {
        for(int c=0;fin.read((char*)&contatto[c],sizeof(contatto[c]));c++)
        {

            if(contatto[c].nome[0]=='\0')
                break;
            cout<<"Nome contatto:       "<<contatto[i].nome<<endl;
            cout<<"Cognome contatto:    "<<contatto[i].cognome<<endl;
            cout<<"Numero telefono:     "<<contatto[i].n_telefono<<endl;
            cout<<"Codice contatto:     "<<contatto[i].codice_contatto<<endl;
            i++;

        }

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
    while(c!=0&&i<200)
    {
        cout<<"\nInserisci nome contatto: ";
        fflush(stdin);
        getline(cin, contatto[i].nome);
        cout<<"\nInserisci cognome contatto: ";
        fflush(stdin);
        getline(cin, contatto[i].cognome);
        cout<<"\nInserisci numero di telefono: ";
        cin>>contatto[i].n_telefono;
        cout<<"\nInserisci codice contatto: ";
        cin>>contatto[i].codice_contatto;
        if(i!=199)
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
            fout.write((char*)&contatto,sizeof(contatto));
    }
    fout.close();
    n=i;
}

void ricerca()
{
    int codice;
    long counter;
    fstream fin;
    fin.open(lista.c_str(),ios::in|ios::binary);
    if(!fin)
        cout<<"Apertura file impossibile"<<endl;
    else{
        fin.clear();
        cout<<"Inserisci il codice da cercare:";
        cin>>codice;
        for(int c=0;c<n;c++)
        {
            if(codice==contatto[c].codice_contatto)
            {
                counter=((c)*(sizeof(app)));
            }
        }
        cout<<"il counter e' "<<counter<<endl;
        fin.seekg(counter);
        fin.read((char*)&app,sizeof(app));
        cout<<"Nome contatto :         "<<app.nome<<endl;
        cout<<"Cognome contatto :      "<<app.cognome<<endl;
        cout<<"Numero telefono:        "<<app.n_telefono<<endl;
        cout<<"Codice contatto:        "<<app.codice_contatto<<endl<<endl;

    }
    fin.close();
}

void modifica()
{
    int codice;
    long counter;
    string stringa;
    fstream fin;
    fin.open(lista.c_str(),ios::in|ios::binary);
    if(!fin)
        cout<<"Apertura file impossibile"<<endl;
    else{
        fin.clear();
        cout<<"Inserisci il codice da cercare:";
        cin>>codice;
        counter=((codice)*(sizeof(app)));
        cout<<"il counter e' "<<counter<<endl;
        fin.seekg(counter);
        fin.read((char*)&app,sizeof(app));
        cout<<"Nome contatto :         "<<app.nome<<endl;
        cout<<"Cognome contatto :      "<<app.cognome<<endl;
        cout<<"Numero telefono:        "<<app.n_telefono<<endl;
        cout<<"Codice contatto:        "<<app.codice_contatto<<endl<<endl;
        cout<<"\nQuale campo modificare?" <<endl;
        cout<<"1)Nome" <<endl;
        cout<<"2)Cognome" <<endl;
        cout<<"3)Numero telefono " <<endl;
        int scelta;
        cin>>scelta;
        switch(scelta)
        {
            case 1:
            {
                fflush(stdin);
                getline(cin,stringa);
                app.nome=stringa;
                break;
            }
            case 2:
            {
                fflush(stdin);
                getline(cin,stringa);
                app.cognome=stringa;
                break;
            }
            case 3:
            {
                int numero;
                cin>>numero;
                app.n_telefono=numero;
                break;
            }
        }
        cout<<"Nome contatto :         "<<app.nome<<endl;
        cout<<"Cognome contatto :      "<<app.cognome<<endl;
        cout<<"Numero telefono:        "<<app.n_telefono<<endl;
        cout<<"Codice contatto:        "<<app.codice_contatto<<endl<<endl;
    fin.close();
    fstream fout;
    fout.open(lista.c_str(),ios::out | ios::binary);
    for(int c=0;c<n;c++){
            if(codice==contatto[c].codice_contatto)
            {
                contatto[c]=app;
            }
            fout.write((char*)&contatto[c],sizeof(contatto[c]));
    }
    cout<<"\nSalvataggio su file..."<<endl;
    fout.close();
}
}

void cancella()
{
    int codice;
    long counter;
    string stringa;
    fstream fin;
    fin.open(lista.c_str(),ios::in|ios::binary);
    if(!fin)
        cout<<"Apertura file impossibile"<<endl;
    else{
        fin.clear();
        cout<<"Inserisci il codice del contatto da eliminare:";
        cin>>codice;
        counter=((codice)*(sizeof(app)));
        cout<<"il counter e' "<<counter<<endl;
        fin.seekg(counter);
        fin.read((char*)&app,sizeof(app));
        cout<<"Nome contatto :         "<<app.nome<<endl;
        cout<<"Cognome contatto :      "<<app.cognome<<endl;
        cout<<"Numero telefono:        "<<app.n_telefono<<endl;
        cout<<"Codice contatto:        "<<app.codice_contatto<<endl<<endl;
        cout<<"\nConfermi?" <<endl;
        fin.seekg(0);
        for(int i=0;i<(n-1);i++)
        {
            fin.read((char*)&app,sizeof(app));
            if(codice==app.codice_contatto)
            {
                fin.read((char*)&app,sizeof(app));
            }
            contatto[i]=app;
        cout<<"Nome contatto :         "<<contatto[i].nome<<endl;
        cout<<"Cognome contatto :      "<<contatto[i].cognome<<endl;
        cout<<"Numero telefono:        "<<contatto[i].n_telefono<<endl;
        cout<<"Codice contatto:        "<<contatto[i].codice_contatto<<endl<<endl;
        }
        n--;
    fin.close();

    //funzione di rinomina file inutile
    /*if(remove("inutile.txt" )==0)
        puts( "File successfully deleted" );
    else
        perror( "Error deleting file" );

    int result;
    char oldname[] ="lista.dat";
    char newname[] ="inutile.dat";
    result=rename(oldname,newname);
    if (result==0)
        puts( "File successfully renamed" );
    else
        perror( "Error renaming file" );

    fstream fout;
    fout.open(lista.c_str(),ios::out | ios::binary);
    for(int c=0;c<n;c++){
            fout.write((char*)&contatto[c],sizeof(contatto[c]));
    }
    cout<<"\nSalvataggio su file..."<<endl;
    fout.close();
}
}
*/
