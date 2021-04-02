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
    * - leggere un file binario
    * - genera un file binario
    * - dal file possono essere eliminati, modificati o cercati record specifici
    *
    *\section UML DIAGRAMMA UML DEL PROGETTO
    * <IMG SRC = "uml.jpg" ALT = "Diagramma UML del progetto"/>
    *
    *\section CLASS DIAGRAMMA DELLE CLASSI PRESENTI NEL PROGETTO
    *<IMG SRC = "classi.jpg" ALT = "Diagramma delle classi del progetto"/>
    */


int main()
{
    //! \brief main, menu principale
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
