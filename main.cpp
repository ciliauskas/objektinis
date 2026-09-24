#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> nd;
    int egzaminas;
    double gvidurkis;
    double gmediana;
};

double svidurkis(vector<int> v) {
    if (v.size() == 0) return 0.0;
    double suma = 0.0;
    for (int i = 0; i < v.size(); i++) suma += v[i];
    return suma / v.size();
}
double smediana(vector<int> v) {
    if (v.size() == 0) return 0.0;
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 != 0) return (double)(v[n / 2]);
    else return (double)(v[n / 2 - 1] + v[n / 2]) / 2.0;
}

void galutinis(Studentas &s) {
    s.gvidurkis = 0.4 * svidurkis(s.nd) + 0.6 * s.egzaminas;
    s.gmediana = 0.4 * smediana(s.nd) + 0.6 * s.egzaminas;
}

int main() {
    srand(time(NULL));
    vector<Studentas> studentai;
    int pasirinkimai;

    do {
        cout << "\n1 ivesti duomenis\n0. baigti\npasirinkite: ";
        cin >> pasirinkimai;

        if (pasirinkimai == 1) {
            Studentas s;
            cout << "vardas: "; cin >> s.vardas;
            cout << "pavarde: "; cin >> s.pavarde;
            char dar;
            do {
                int balas;
                cout << "iveskite nd bala (0-10): "; cin >> balas;
                s.nd.push_back(balas);
                cout << "ar norite ivesti dar nd? (t/n): "; cin >> dar;
            } while (dar == 't'|| dar == 'T');
            cout << "egzamino balas: "; cin >> s.egzaminas;
            galutinis(s);
            studentai.push_back(s);
        }   

        else if (pasirinkimai ==2) {
    Studentas s;
    cout << "vardas: "; cin >> s.vardas;
    cout << "pavarde: "; cin >> s.pavarde;
    int ndKiekis = rand() % 10 + 1;
    for (int i = 0; i < ndKiekis; i++) s.nd.push_back(rand() % 10 + 1);
    s.egzaminas = rand() % 10 + 1;
    galutinis(s);
    studentai.push_back(s);
    cout << "sukurti atsitiktiniai duomenys. \n ";
        }
    } while (pasirinkimai != 0);
    return 0;
}

bool pagalV(Studentas a, Studentas b) { return a.vardas < b.vardas; }

void ivestiStudentus(vector<Studentas> studentai) {
    if (studentai.size() == 0) { cout << "nera duomenu. \n"; return; }
    sort (studentai.begin(), studentai.end(), pagalV);
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.) \n" << string(70, '-') << "\n";
    for (int i = 0; i < studentai.size(); i++) {
        cout << left << setw(15) << studentai[i].vardas << setw(15) << studentai[i].pavarde <<fixed << setprecision(2) << setw(20) << studentai[i].gvidurkis << setw(20) << studentai[i].gmediana << "\n";
    }
}
