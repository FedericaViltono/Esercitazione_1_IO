#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

//Definisco la funzione che mappa i valori nell'intervallo [-1, 2] da [1,5]
double CambioValore(double val) {
    return ((3.0/4.0) * val - 7.0/4.0);
}

int main() {

    //Leggo il file
    std::ifstream file("data.txt");
    if (!file) {
        std::cerr << "Errore nell'apertura del file" << std::endl;
        return 1;
    }

    std::vector<double> dati;
    double valore;
    while (file >> valore) {
        dati.push_back(valore);
    }  //Se la lettura ha successo, il numero viene aggiunto al vettore dati

    file.close();

    //Converto i valori nell'intervallo [-1, 2]
    std::vector<double> ValoriMappati;
    for (double val : dati) {
        ValoriMappati.push_back(CambioValore(val));
    }

    //Calcolo la media progressiva
    double somma = 0.0;
    std::ofstream risultato("result.txt");
    risultato << "# N Mean" << std::endl;

    for (size_t i = 0; i < ValoriMappati.size(); ++i) {  //size_t indica una  variabile senza segno usata come indice
        somma += ValoriMappati[i];
        double media = somma / (i + 1); 
        risultato << std::scientific << std::setprecision(16) << (i + 1) << " " << media << std::endl;  //con std::scientific numeri vengono stampati in notazione scientifica 
    }

    risultato.close();

    std::cout << "Elaborazione completata con successo" << std::endl;
    return 0;
}

