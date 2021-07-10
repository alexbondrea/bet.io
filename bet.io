#include <iostream>
using namespace std;

int pariu_sportiv_in_trei(float cota_a, float cota_b, float cota_egal, float sum) {
    short op = 0;
    float min_win = 0;
    float max_win, val_a, val_egal, val_b;
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
    if (op==0 || min_win < 0.5) cout << "Pariul nu este rentabil." << endl;
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

int pariu_sportiv_simplu(float cota_a, float cota_b, float sum) {
    short op = 0;
    float min_win=0;
    float max_win, val_a, val_b;
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
    if (op==0 || min_win < 0.5) cout << "Pariul nu este rentabil." << endl;
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
    char option;
    do {
        cout << "***************************************************************" << endl;
        cout << "Cota 1: "; cin >> cota_a;
        cout << "Cota egal (introdu -1 daca nu exista): "; cin >> cota_egal;
        cout << "Cota 2: "; cin >> cota_b;
        cout << "Valoare pariu: "; cin >> sum; cout << endl;
        if (cota_egal!=-1) pariu_sportiv_in_trei(cota_a, cota_b, cota_egal, sum);
        else pariu_sportiv_simplu(cota_a, cota_b, sum);
        cout << "Doresti sa continui? (y/n) "; cin >> option; cout << endl;
    } while (option=='y' || option=='Y');
}
