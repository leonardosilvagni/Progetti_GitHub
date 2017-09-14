//
//  main.cpp
//  Randomizer_Nomi
//
//  Created by Leonardo Silvagni on 12/09/17.
//  Copyright © 2017 Leonardo Silvagni. All rights reserved.
//

#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <fstream>      // std::ostream, std::ifstream

using namespace std;

int randomizer (int i) { return rand()%i;}

int main(int argc, const char * argv[]) {
    string line;
    ifstream lista("/Users/Shared/Randomizer Nomi/lista.txt");
    ofstream result("/Users/Shared/Randomizer Nomi/risultato.txt") ;
    int i = 0, j = 1, gruppo = 2;
    srand ( unsigned ( time(0) ) );
    vector<string> listaIN;
    int persone = 2; // Il numero di persone per gruppo
    
    cout << "\nI nomi nella lista chiamata lista.txt stanno per essere randomizzati\nPer far si che cio\' avvenga assicurarsi di creare i documenti \"lista.txt\" e \"risultato.txt\" nella stessa cartella del programma!" << endl ;
    cout << "Inserire Il numero di persone per gruppo che si desidera avere" << endl;
    cin >> persone;
    cout << endl;
    if (lista.is_open()) /* Apro la lista e assegno i valori di 
                          ogni riga a un valore della stringa a*/
    {
            while (getline (lista,line) )
            {
                listaIN.push_back(line);
                i++;
            }
        lista.close();
    }
    
    else {cout << "Impossibile aprire il file \"lista.txt\"";}
    random_shuffle ( listaIN.begin(), listaIN.end() );
    random_shuffle ( listaIN.begin(), listaIN.end(), randomizer);
    if (result.is_open()){
        result << "I risultati della creazione dei gruppi sono i seguenti:"<<endl;
        result << "Gruppo 1: ";
    for (vector<string>::iterator it=listaIN.begin(); it!=listaIN.end(); ++it){
        result <<"\""<< *it <<"\""<< "\t"  ;
        if (j % persone == 0) {
            result << endl << "Gruppo " << gruppo << ": ";
            gruppo++;
        }j++;
        }
        cout<<"Il file e' stato randomizzato con successo!!"<<endl;
    }else cout << "\n\tImpossibile aprire il file \"risultato.txt\"" << endl ;
}
