#include <iostream>
#include "fstream"
#include "unordered_map"
using namespace std;

int a, b, c;
unsigned long long M;

uint64_t func(uint64_t s) {
    return (s * s * a + s * b + c) % M;
}

int main() {
    cin >> M >> a >> b >> c;
    unsigned long long state = 1;
    int cntRnd = 1;

    unordered_map <unsigned long long, int> map;

    while (map[state] == 0)
    {
        map[state] = cntRnd; // записываем за рандомным числом его индекс/порядковый номер
        cntRnd++;
        state = func(state);
    }

    cout << map[state] - 1 << ' ' << cntRnd - 1;
}