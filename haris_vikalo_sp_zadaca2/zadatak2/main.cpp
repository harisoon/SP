#include <iostream>
#include "MojVektor.hpp"


class Polinom {
private:
    MojVektor<int> koeficijenti;

public:
    // Konstruktor koji prima vektor koeficijenata
    Polinom(const MojVektor<int>& koefs) : koeficijenti(koefs) {}

    // Sabiranje polinoma
    Polinom operator+(const Polinom& drugi) const {
        size_t max_size = std::max(koeficijenti.size(), drugi.koeficijenti.size());
        MojVektor<int> rezultat(max_size);

        for (size_t i = 0; i < max_size; ++i) {
            int koef1 = i < koeficijenti.size() ? koeficijenti[i] : 0;
            int koef2 = i < drugi.koeficijenti.size() ? drugi.koeficijenti[i] : 0;
            rezultat[i] = koef1 + koef2;
        }

        return Polinom(rezultat);
    }

    // Oduzimanje polinoma
    Polinom operator-(const Polinom& drugi) const {
        size_t max_size = std::max(koeficijenti.size(), drugi.koeficijenti.size());
        MojVektor<int> rezultat(max_size);

        for (size_t i = 0; i < max_size; ++i) {
            int koef1 = i < koeficijenti.size() ? koeficijenti[i] : 0;
            int koef2 = i < drugi.koeficijenti.size() ? drugi.koeficijenti[i] : 0;
            rezultat[i] = koef1 - koef2;
        }

        return Polinom(rezultat);
    }

       // Množenje polinoma
    Polinom operator*(const Polinom& drugi) const {
        size_t rez_size = koeficijenti.size() + drugi.koeficijenti.size() - 1;
        MojVektor<int> rezultat(rez_size);

        for (size_t i = 0; i < koeficijenti.size(); ++i) {
            for (size_t j = 0; j < drugi.koeficijenti.size(); ++j) {
                rezultat[i + j] += koeficijenti[i] * drugi.koeficijenti[j];
            }
        }

        return Polinom(rezultat);
    }

    // Izračunavanje vrijednosti polinoma za dato x
    int operator()(int x) const {
        int rezultat = 0;
        int trenutni_stepen = 1;

        for (int koef : koeficijenti) {
            rezultat += koef * trenutni_stepen;
            trenutni_stepen *= x;
        }

        return rezultat;
    }

    // Izračunavanje prvog izvoda polinoma
    Polinom izvod() const {
        MojVektor<int> izvod_koeficijenti;
        if(koeficijenti.size()>0){
            izvod_koeficijenti[0]=0;
        }
        for (size_t i = 1; i < koeficijenti.size(); ++i) {
            izvod_koeficijenti.push_back(i * koeficijenti[i]);
        }

        return Polinom(izvod_koeficijenti);
    }

    // Ispis polinoma
    void ispisi() const {
        for (size_t i = 0; i < koeficijenti.size(); ++i) {
            std::cout << koeficijenti[i] << "x^" << i;
            if (i < koeficijenti.size() - 1) std::cout << " + ";
        }
        std::cout << std::endl;
    }
};

int main() {

    return 0;
}
