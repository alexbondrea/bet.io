#include <iostream>
#include <fstream>
using namespace std;
//v 1.2 *ab*
int pariu_sportiv_in_trei(float cota_a, float cota_b, float cota_egal, float sum, float &val_a, float &val_egal, float &val_b, float &min_win, float &max_win) {
    short op = 0;
    for (float i = sum; i>0; i=i-0.1) {
        for (float j = sum-i; j>0; j=j-0.1) {
            float f = sum - i - j;
            if (i+j+f == sum && i*cota_egal > sum && j*cota_a > sum && f*cota_b > sum) {
                float max = 0, min = 0;
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
                if (min_win < a - sum) {
                    min_win = a - sum;
                    max_win = c - sum;
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
        cout << "Pe echipa A: " << val_a << endl;
        cout << "Pe egal: " << val_egal << endl;
        cout << "Pe echipa B: " << val_b << endl;
        cout << "Castig maxim: " << max_win << endl;
        cout << "Castig minim: " << min_win << endl;
        cout << endl;
    }
}

int pariu_sportiv_simplu(float cota_a, float cota_b, float sum, float &val_a, float &val_b, float &min_win, float &max_win) {
    short op = 0;
    for (float i = sum; i>0; i=i-0.1) {
        float j = sum - i;
        if (i+j==sum && i*cota_a>sum && j*cota_b>sum) {
            float a = i*cota_a;
            float b = j*cota_b;
            if (a>b) {
                float aux = a;
                a = b;
                b = aux;
            }
            if (min_win<a-sum) {
                min_win=a-sum;
                max_win=b-sum;
                val_a=i;
                val_b=j;
            }
            op=1;
        }
    }
    if (op==0 || min_win < 0.5) cout << "Not worth it man" << endl;
    else if (op==1) {
        cout << "Bet rentabil după cum urmeaza:" << endl;
        cout << "Pe echipa A: " << val_a << endl;
        cout << "Pe echipa B: " << val_b << endl;
        cout << "Castig maxim: " << max_win << endl;
        cout << "Castig minim: " << min_win << endl;
        cout << endl;
    }
}

int main () {
    float cota_a, cota_egal, cota_b, sum;
    float max_win, val_a, val_b;
    float min_win = 0;
    char option;
    do {
        cout << "***************************************************************" << endl;
        cout << "Cota 1: "; cin >> cota_a;
        cout << "Cota egal (introdu -1 daca nu exista): "; cin >> cota_egal;
        cout << "Cota 2: "; cin >> cota_b;
        cout << "Valoare pariu: "; cin >> sum; cout << endl;
        if (cota_egal!=-1) {float val_egal; pariu_sportiv_in_trei(cota_a, cota_b, cota_egal, sum, val_a, val_egal, val_b, min_win, max_win);}
        else pariu_sportiv_simplu(cota_a, cota_b, sum, val_a, val_b, min_win, max_win);
        cout << "Salvezi aceste informatii? (y/n) "; cin >> option; cout << endl;
        if (option=='y'||option=='Y') {
            ofstream file_output_information("Pariu_Sportiv.txt");
            file_output_information << "Informatii despre pariu:" << endl;
            file_output_information << "Cota 1: " << cota_a << " -> valoare: " << val_a << endl;
            if (cota_egal!=-1) file_output_information << "Cota egal: " << cota_egal << " -> valoare: " << val_egal << endl;
            file_output_information << "Cota 2: " << cota_b << " -> valoare: " << val_b << endl;
            file_output_information << "Castig maxim: " << max_win << endl;
            file_output_information << "Castig minim: " << min_win << endl;
            file_output_information.close();
            cout << "Salvat!" << endl << endl;
        }
        cout << "Doresti sa continui? (y/n) "; cin >> option; cout << endl;
    } while (option=='y' || option=='Y');
}
