#include <iostream>
#include <fstream>
using namespace std;
//v 1.3 *ab*
void pariu_sportiv_in_trei(float cota_a, float cota_b, float cota_egal, float sum, float &val_a, float &val_egal, float &val_b, float &min_win, float &max_win) {
    short op = 0;
    for (float i = 10; i>0; i=i-0.1) {
        for (float j = 10-i; j>0; j=j-0.1) {
            float f = 10 - i - j;
            if (i+j+f == 10 && i*cota_egal > 10 && j*cota_a > 10 && f*cota_b > 10) {
                float a = i * cota_egal;
                float b = j * cota_a;
                float c = f * cota_b;
                if (a > b) {
                    float aux = a;
                    a = b;
                    b = aux;
                }
                if (b > c) {
                    float aux = b;
                    b = c;
                    c = aux;
                }
                if (a>b) {
                    float aux = a;
                    a = b;
                    b = aux;
                }
                if (min_win < a - 10) {
                    min_win = a - 10;
                    max_win = c - 10;
                    val_a = j;
                    val_egal = i;
                    val_b = f;
                }
                op=1;
            }
        }
    }
    if (op==0 || min_win < 0.5) cout << "Not worth it man" << endl;
    else if (op==1) {
        cout << "Bet rentabil după cum urmeaza:" << endl;
        cout << "Pe echipa A: " << sum / 10 * val_a << endl;
        cout << "Pe egal: " << sum / 10 * val_egal << endl;
        cout << "Pe echipa B: " << sum / 10 * val_b << endl;
        cout << "Castig maxim: " << sum / 10 * max_win << endl;
        cout << "Castig minim: " << sum / 10 * min_win << endl;
        cout << endl;
    }
}

void pariu_sportiv_simplu(float cota_a, float cota_b, float sum, float &val_a, float &val_b, float &min_win, float &max_win) {
    short op = 0;
    for (float i = 10; i>0; i=i-0.1) {
        float j = 10 - i;
        if (i+j==10 && i*cota_a>10 && j*cota_b>10) {
            float a = i*cota_a;
            float b = j*cota_b;
            if (a>b) {
                float aux = a;
                a = b;
                b = aux;
            }
            if (min_win<a-10) {
                min_win=a-10;
                max_win=b-10;
                val_a=i;
                val_b=j;
            }
            op=1;
        }
    }
    if (op==0 || min_win < 0.5) cout << "Not worth it man" << endl;
    else if (op==1) {
        cout << "Bet rentabil după cum urmeaza:" << endl;
        cout << "Pe echipa A: " << sum / 10 * val_a << endl;
        cout << "Pe echipa B: " << sum / 10 * val_b << endl;
        cout << "Castig maxim: " << sum / 10 * max_win << endl;
        cout << "Castig minim: " << sum / 10 * min_win << endl;
        cout << endl;
    }
}

int main () {
    float cota_a, cota_egal, cota_b, sum;
    float max_win, val_a, val_b, val_egal;
    float min_win = 0;
    char option;
    do {
        cout << "***************************************************************" << endl;
        cout << "Cota 1: "; cin >> cota_a;
        cout << "Cota egal (introdu -1 daca nu exista): "; cin >> cota_egal;
        cout << "Cota 2: "; cin >> cota_b;
        cout << "Valoare pariu: "; cin >> sum; cout << endl;
        if (cota_egal!=-1) pariu_sportiv_in_trei(cota_a, cota_b, cota_egal, sum, val_a, val_egal, val_b, min_win, max_win);
        else pariu_sportiv_simplu(cota_a, cota_b, sum, val_a, val_b, min_win, max_win);
        cout << "Salvezi aceste informatii? (y/n) "; cin >> option; cout << endl;
        if (option=='y'||option=='Y') {
            fstream file_output_information;
            file_output_information.open("Pariu_Sportiv.txt", fstream::app);
            file_output_information << "Informatii despre pariu:" << endl;
            file_output_information << "Cota 1: " << cota_a << " -> valoare: " << sum / 10 * val_a << endl;
            if (cota_egal!=-1) file_output_information << "Cota egal: " << cota_egal << " -> valoare: " << sum / 10 * val_egal << endl;
            file_output_information << "Cota 2: " << cota_b << " -> valoare: " << sum / 10 * val_b << endl;
            file_output_information << "Castig maxim: " << sum / 10 * max_win << endl;
            file_output_information << "Castig minim: " << sum / 10 * min_win << endl;
            file_output_information.close();
            cout << "Salvat!" << endl << endl;
        }
        cout << "Doresti sa continui? (y/n) "; cin >> option; cout << endl;
    } while (option=='y' || option=='Y');
}
