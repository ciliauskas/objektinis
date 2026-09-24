#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

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
    return 0;
}
