#include <iostream>
#include <vector>
#include <string>
#include <random>

void wiezaHanoi(int n, char zrodlo, char pomocniczy, char cel) {
    if (n == 1) {
        std::cout << "Przenies dysk 1 z " << zrodlo << " do " << cel << std::endl;
        return;
    }

    wiezaHanoi(n - 1, zrodlo, cel, pomocniczy);
    std::cout << "Przenies dysk " << n << " z " << zrodlo << " do " << cel << std::endl;
    wiezaHanoi(n - 1, pomocniczy, zrodlo, cel);
}

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

void sortowanie_przez_wstawianie(std::vector<int>& lista) {
    for (int i = 1; i < lista.size(); ++i) {
        int klucz = lista[i];
        int j = i - 1;
        while (j >= 0 && klucz < lista[j]) {
            lista[j + 1] = lista[j];
            --j;
        }
        lista[j + 1] = klucz;
    }
}

void sortowanie_babelkowe(std::vector<int>& lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (lista[j] > lista[j + 1]) {
                // Zamiana miejscami
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int main() {
    int wybor;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Wieza Hanoi" << std::endl;
        std::cout << "2. Sortowanie babelkowe" << std::endl;
        std::cout << "3. Szyfrowanie XOR" << std::endl;
        std::cout << "4. Sortowanie przez wstawianie" << std::endl;
        std::cout << "0. Wyjście" << std::endl;

        std::cout << "Wybierz opcję: ";
        std::cin >> wybor;

        switch (wybor) {
            case 1: {
                int liczbaKrazkow = 5;
                char zrodlo = 'A';
                char pomocniczy = 'B';
                char cel = 'C';
                wiezaHanoi(liczbaKrazkow, zrodlo, pomocniczy, cel);
                break;
            }
            case 2: {
                std::vector<int> lista;
                int liczba;
                char opcja;

                do {
                    std::cout << "Podaj liczbe: ";
                    std::cin >> liczba;

                    lista.push_back(liczba);

                    std::cout << "Czy chcesz dodac kolejna liczbe? (T/N): ";
                    std::cin >> opcja;
                } while (opcja == 'T' || opcja == 't');

                sortowanie_babelkowe(lista);

                std::cout << "Posortowana lista: ";
                for (const auto& element : lista) {
                    std::cout << element << " ";
                }
                std::cout << std::endl;

                break;
            }
            case 3: {
                std::string tekst;
                std::cout << "Podaj tekst do zaszyfrowania: ";
                std::cin.ignore();
                std::getline(std::cin, tekst);

                int dlugosc_klucza;
                std::cout << "Podaj długość klucza: ";
                std::cin >> dlugosc_klucza;

                std::string klucz = generuj_klucz(dlugosc_klucza);
                std::cout << "Wygenerowany klucz: " << klucz << std::endl;

                std::string zaszyfrowany_tekst = xor_szyfrowanie(tekst, klucz);
                std::cout << "Zaszyfrowany tekst: " << zaszyfrowany_tekst << std::endl;

                break;
            }
            case 4: {
                std::vector<int> lista = {9, 5, 2, 7, 1, 0};
                sortowanie_przez_wstawianie(lista);

                std::cout << "Posortowana lista: ";
                for (const auto& liczba : lista) {
                    std::cout << liczba << " ";
                }
                std::cout << std::endl;

                break;
            }
            case 0:
                std::cout << "Wyjście z programu" << std::endl;
                break;
            default:
                std::cout << "Nieprawidłowy wybór" << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (wybor != 0);

    return 0;
}
