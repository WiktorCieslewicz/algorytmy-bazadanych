#include <iostream>

void wiezaHanoi(int n, char zrodlo, char pomocniczy, char cel) {
    if (n == 1) {
        std::cout << "Przenies dysk 1 z " << zrodlo << " do " << cel << std::endl;
        return;
    }

    wiezaHanoi(n - 1, zrodlo, cel, pomocniczy);
    std::cout << "Przenies dysk " << n << " z " << zrodlo << " do " << cel << std::endl;
    wiezaHanoi(n - 1, pomocniczy, zrodlo, cel);
}

int main() {
    int liczbaKrazkow = 5;
    char zrodlo = 'A';
    char pomocniczy = 'B';
    char cel = 'C';

    wiezaHanoi(liczbaKrazkow, zrodlo, pomocniczy, cel);

    return 0;
}