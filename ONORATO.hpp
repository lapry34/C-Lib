#ifndef ONORATO_HPP_INCLUDED
#define ONORATO_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <typeinfo>
#include <bits/stdc++.h>


#ifdef _WIN32
    #include "windows.h"
    #include "conio.h"
    void showCursor(bool);

#endif // _WIN32


using namespace std;

//prototipazione
double stod(string&);
int stoi(string&);
string itos(int);
string dtos(double);
bool containsDigit(string);
long long splitDigit(long long, long long);
long long countDigit(long long);
long long binToDec(long long);
long long decToBin(long long);

string toupper(string);
string tolower(string);
bool isupper(string);
bool islower(string);
bool strcmp(char*, const char*);
size_t concatenate(size_t, size_t);

template <class T>
void array_normalize(T*, size_t);

template <class T>
void bubbleSort(T*, size_t);

template <class T>
void reverse(T*, size_t);
void reverse(string&);
void reverse(char*);

template <class T>
void merge(T*, size_t, T*, size_t, T*);

void cls(void);

double newton_sqrt(double);
double recursive_pow(double, double);
double n_root(double, int);
double generate_pi(unsigned long);
double generate_e(double);
double cal_sin(double, int);
double fact(double);

template <typename T>
T protectedInput(string);

const double PI = generate_pi(10e5);
const double e = generate_e(10e5);

//Funziona sia con i puntatori a caratteri, array e stringhe.
double stod(string &str){

    stringstream ss(str);

    double d;

    ss >> d;

    return d;
}

int stoi(string &str){

    stringstream ss(str);

    int i;

    ss >> i;

    return i;
}

string itos(int num){

    stringstream ss;

    ss << num;

    return ss.str();
}

string dtos(double num){

    stringstream ss;

    ss << num;

    return ss.str();
}

bool containsDigit(string str){

    for(size_t i = 0; i < str.size(); i++){
        if(isdigit(str[i])) return true;
    }

    return false;
}



template <class T>
void bubbleSort(T *p, size_t n){

    bool b = true;  //in caso non sia stato effettuato nessuno scambio il vettore è già in ordine e si conclude l'algoritmo

    for(int i = 0; i < n-1 && b; i++){//n-1 perché essendo in caso già ordinate tutte le caselle precedenti del vettore l'ultima è già obbligatoriamente ordinata.

        b = false;
        for(int j = 0; j < n-i-1; j++){    //n-i-1 viene utilizzato poiché la i, che conta quante volte viene
            if(p[j] > p[j+1]){        //completato un controllo essendo che il valore n-1 è già stato quindi posizionato non viene più ricontrollato.
                swap(p[j], p[j+1]);   //grazie a questo +1 si accede anche all'ultima casella, permettendo di ordinare appunto anche quest'ultima.
                b = true;
            }
        }

    }
}


template <class T>
void array_normalize(T *p, size_t n){

    T min = p[0];
    T max = p[0];
    for(size_t i = 0; i < n; i++){
        if(p[i] < min)
            min = p[i];
        if(p[i] > max)
            max = p[i];
    }
    for(size_t i = 0; i < n; i++){
        p[i] = (p[i] - min) / (max - min);
    }
}

template <class T>
void reverse(T *p, size_t n){

    for(int i = 0, j = n-1; i < n; i++, j--){
        swap(p[i], p[j]);
        if((i == j + 1 && n % 2 == 0) || (i == j && n % 2 != 0)) break;
    }

}

void reverse(string &str){

    for(size_t i = 0, j = str.size() -1; i < str.size(); i++, j--){
        swap(str[i], str[j]);
        if((i == j + 1 && str.size() % 2 == 0) || (i == j && str.size() % 2 != 0)) break;
    }
}

void reverse(char *str){

    for(size_t i = 0, j = strlen(str) -1; i < strlen(str); i++, j--){
        swap(str[i], str[j]);
        if((i == j + 1 && strlen(str) % 2 == 0) || (i == j && strlen(str) % 2 != 0)) break;
    }
}

template <class T>
void merge(T *a, size_t na, T *b, size_t nb, T *c){

	int i = 0, j = 0, k = 0;

	while(i < na && j < nb) {
		if(a[i] < b[j])
            c[k++] = a[i++];
		else
			c[k++] = b[j++];
    }

	while(i < na)
		c[k++] = a[i++];

	while(j < nb)
		c[k++] = b[j++];

	if(na != nb)
		bubbleSort(c, na + nb);
}

void cls(void){
    #ifdef _WIN32
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD coord = {0, 0};
        DWORD count;                            //fa robe
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hStdOut, &csbi);
        FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    #else
        printf("\f");
#endif
}

long long splitDigit(long long cifra, long long numero){
    //cifra--;
    while(cifra--) numero /= 10;
    return numero % 10;
}

long long countDigit(long long numero) {
    long long contatore = 1;

    while(numero /= 10) contatore++;
    return contatore;
}

long long binToDec(long long n)
{
    long long decimalNumber = 0, i = 0, remainder;
    while (n != 0){
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2,i);
        ++i;
    }
    return decimalNumber;
}

long long decToBin(long long n){

    return stoi(bitset<8>(n).to_string());
}


string toupper(string str){

    for(size_t i = 0; i < str.size(); i++){
        str[i] = toupper(str[i]);
    }

    return str;
}

string tolower(string str){

    for(size_t i = 0; i < str.size(); i++){
        str[i] = tolower(str[i]);
    }

    return str;
}


bool isupper(string str){

    for(size_t i = 0; i < str.size(); i++){
        if(islower(str[i])) return false;
    }
    return true;
}

bool islower(string str){

    for(size_t i = 0; i < str.size(); i++){
        if(isupper(str[i])) return false;
    }
    return true;
}

bool strcmp(char *str1, const char *str2){

    int len;

    if(strlen(str1) > strlen(str2)) len = strlen(str2);
    else len = strlen(str1);

    for(size_t i = 0; str1[i] != '\0' || str2[i] != '\0' ; i++){
        if(str1[i] != str2[i]) return false;
    }

    return true;

}

size_t concatenate(size_t n1, size_t n2){

    size_t pow = 10;

   while(n2 >= pow)
        pow *= 10;
    return n1 * pow + n2;

}
   //https://it.wikipedia.org/wiki/Formula_di_Leibniz_per_pi
double generate_pi(unsigned long prec){

    double ris = 0;

    for(size_t i = 0; i < prec; i++){
        ris += pow(-1, i) / (2.0 * i + 1);
    }

    return ris * 4;
}
    //https://www.mathscareers.org.uk/article/calculating-eulers-constant-e/
double generate_e(double prec){
    return pow((1 + 1 / prec), prec);
}


double newton_sqrt(double x){

    if(x < 0) return 0;

    srand(time(NULL));

    double g = (rand() % 100);

    while(abs((g * g) - x) >= 10e-12){
        g = (g + (x / g)) / 2;
    }

    return g;
}

double recursive_pow(double base, double esp){


    if(esp - (int)esp == 0)
        return esp > 0 ? base * recursive_pow(base, esp -1) :
               esp < 0 ? recursive_pow(base, esp +1) / base :
               1; //esp == 0
    else {
        int i;

        for(i = 0; esp - (int)esp != 0; i++){
            esp *= 10;
        }


        i = recursive_pow(10, i);

        double ris  = recursive_pow(base, esp);

        return n_root(ris, i);

    }


}

double n_root(double x, int base){    //https://en.wikipedia.org/wiki/Nth_root_algorithm

    if(x <= 0 || base <= 0) return 0;

    srand(time(NULL));

    double g = (rand() % 100);

    while(abs(recursive_pow(g, base) - x) >= 10e-12){
        g = (((base -1) * g) + (x / recursive_pow(g, base-1))) / base;
    }

    return g;
}

double fact(double in){
    return in == 0 ? 1 : in > 1 ? in * fact(in-1) : in;
}

template <typename T>
T protectedInput(string str){

    T type;

    while(true){
        cout << str;
        cin >> type;

        if(cin.fail()){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Errore! premi un tasto per continuare...";
            getchar();
            cls();
            continue;
        } else break;
    }
}

#ifdef _WIN32
    void showCursor(bool visible) {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_CURSOR_INFO cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = visible;
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    string passInput(void){

        string s = "";
        char ch;

        while(true){
            ch = getch();
            if (ch == 13) break;
            if (ch == 8){
                printf("\b \b");
                s.pop_back();
            }

            else {
                cout << "*";
                s.push_back(ch);
           }
        }

        cout << endl;

        return s;
    }
#endif // _WIN32


#endif // ONORATO_HPP_INCLUDED
