#include <iostream>
#include <unordered_map>
#include <format>
using namespace std;

int main()
{
    unordered_map<unsigned int, unsigned int> hashes;
    int i = 1;
    unsigned int h;
    while (true)
    {
        printf("eval %u\n", i);
        fflush(stdout);
        scanf_s("%u", &h);
        fflush(stdout);
        if (hashes.count(h))
        {
            printf("answer %u %u\n", hashes[h], i);
            fflush(stdout);
            return 0;
        }
        hashes[h] = i;
        i++;
    }
}