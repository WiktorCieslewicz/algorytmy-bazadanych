#include <iostream>
#include <string>
#include <random>

std::string generuj_klucz(int dlugosc) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::string klucz;
    klucz.reserve(dlugosc);

    for (int i = 0; i < dlugosc; ++i) {
        klucz.push_back(static_cast<char>(dis(gen)));
    }

    return klucz;
}

std::string xor_szyfrowanie(const std::string& tekst, const std::string& klucz) {
    std::string zaszyfrowany_tekst;
    for (size_t i = 0; i < tekst.length(); ++i) {
        zaszyfrowany_tekst.push_back(tekst[i] ^ klucz[i % klucz.length()]);
    }
    return zaszyfrowany_tekst;
}

int main() {
    std::string tekst;
    std::cout << "Podaj tekst do zaszyfrowania: ";
    std::getline(std::cin, tekst);

    int dlugosc_klucza;
    std::cout << "Podaj długość klucza: ";
    std::cin >> dlugosc_klucza;

    std::string klucz = generuj_klucz(dlugosc_klucza);
    std::cout << "Wygenerowany klucz: " << klucz << std::endl;

    std::string zaszyfrowany_tekst = xor_szyfrowanie(tekst, klucz);
    std::cout << "Zaszyfrowany tekst: " << zaszyfrowany_tekst << std::endl;

    return 0;
}
