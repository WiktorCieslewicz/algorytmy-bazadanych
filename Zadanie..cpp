#include <iostream>
#include <vector>

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

    return 0;
}

