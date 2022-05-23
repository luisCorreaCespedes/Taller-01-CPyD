#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

#define ARCHIVO "../pruebas.csv"

using namespace std;

int main() {

    //Presentación grupo
    cout << "Taller N°1 Computación Paralela y Distribuida" << endl;
    cout << "Integrantes:" << "\n" << "Alexis Abarca Arias" << "\n" << "Luis Correa Céspedes" << "\n" << endl;

    //Archivos csv a usar
    ifstream archivo(ARCHIVO);
    ofstream salida("resultado.csv");
    salida << "Token" << ";" << "Preguntas correctas" << ";" << "Preguntas incorrectas" << ";" << "Preguntas omitidas" << ";" << "Puntaje" << ";" << "Nota" << endl;
    
    //Variables declaradas
    string linea, token, p1, p2, p3, p4 ,p5, p6, p7, p8, p9, p10, p11, p12;
    string respuestaPrueba[12] = {"A", "E", "C", "B", "B", "D", "A", "B", "E", "C", "B", "D"};
    char separador = ';';
    clock_t tiempoTotal;
    getline(archivo, linea);
    cout << "Inicio del programa..." << endl;
    tiempoTotal = clock();

    //Comienzo de la función
    while(getline(archivo, linea)){
        int correctas = 0;
        int incorrectas = 0;
        int omitidas = 0;
        float puntajeFinal = 0;
        float notaFinal = 0;
        stringstream stream(linea);

        //Obtención de datos
        getline(stream, token, separador);
        getline(stream, p1, separador);
        getline(stream, p2, separador);
        getline(stream, p3, separador);
        getline(stream, p4, separador);
        getline(stream, p5, separador);
        getline(stream, p6, separador);
        getline(stream, p7, separador);
        getline(stream, p8, separador);
        getline(stream, p9, separador);
        getline(stream, p10, separador);
        getline(stream, p11, separador);
        getline(stream, p12, separador);

        //Eliminación de comillas
        token.erase(remove(token.begin(), token.end(), '\"'), token.end());
        p1.erase(remove(p1.begin(), p1.end(), '\"'), p1.end());
        p2.erase(remove(p2.begin(), p2.end(), '\"'), p2.end());
        p3.erase(remove(p3.begin(), p3.end(), '\"'), p3.end());
        p4.erase(remove(p4.begin(), p4.end(), '\"'), p4.end());
        p5.erase(remove(p5.begin(), p5.end(), '\"'), p5.end());
        p6.erase(remove(p6.begin(), p6.end(), '\"'), p6.end());
        p7.erase(remove(p7.begin(), p7.end(), '\"'), p7.end());
        p8.erase(remove(p8.begin(), p8.end(), '\"'), p8.end());
        p9.erase(remove(p9.begin(), p9.end(), '\"'), p9.end());
        p10.erase(remove(p10.begin(), p10.end(), '\"'), p10.end());
        p11.erase(remove(p11.begin(), p11.end(), '\"'), p11.end());
        p12.erase(remove(p12.begin(), p12.end(), '\"'), p12.end());
        
        string respuestaEstudiante[12] = {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12};

        //Cálculo puntaje y nota
        for (int i = 0; i < 12; i++) {
            if (respuestaEstudiante[i] == respuestaPrueba[i]) {
                correctas = correctas + 1;
            }
            else if (respuestaEstudiante[i] == "\"-\"") {
                omitidas = omitidas + 1;
            }
            else {
               incorrectas = incorrectas + 1; 
            }
        }

        puntajeFinal = (correctas * 0.5) - (incorrectas * 0.12);
        notaFinal = puntajeFinal + 1;
        notaFinal = roundf(notaFinal*10)/10;
        if (notaFinal < 1) notaFinal = 1;

        //Registro en csv externo
        salida << token << ";" << correctas << ";" << incorrectas << ";" << omitidas << ";" << puntajeFinal << ";" << notaFinal << endl;
    }

    //Medición tiempo
    tiempoTotal = clock() - tiempoTotal;
    tiempoTotal = (float)tiempoTotal/CLOCKS_PER_SEC;

    //Cierre de archivos csv
    salida.close();
    archivo.close();

    //Fin programa
    cout << "Fin del programa." << endl;
    cout << "Tiempo de ejecución: " << (float)tiempoTotal/60 << " minutos" << endl;
    return 0;
}