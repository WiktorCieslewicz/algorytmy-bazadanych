#include <iostream>
#include <vector>

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

int main() {
    std::vector<int> lista = {9, 5, 2, 7, 1, 0};

    sortowanie_przez_wstawianie(lista);

    for (const auto& liczba : lista) {
        std::cout << liczba << " ";
    }
    std::cout << std::endl;

    return 0;
}