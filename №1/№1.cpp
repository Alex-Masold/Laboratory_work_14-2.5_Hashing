#include <iostream>
#include <fstream>
using namespace std;

class HashTable
{
    class Node {
    public:
        int data;
        Node* next;
        Node(int data_ = INT32_MIN)
        {
            data = data_;
            next = nullptr;
        }
    };

public:
    Node* arr;
    int arrsize;

    HashTable(int size)
    {
        arr = new Node[size];
        arrsize = size;
    }

    unsigned  int hash(int num, int n)
    {
        return (num %= n) >= 0 ? num : -num;
    }

    bool push(int num)
    {
        unsigned int hashNum = hash(num, arrsize);
        if (arr[hashNum].data == INT_MIN)
        {
            arr[hashNum].data = num;
            return true;
        }
        Node* tmp = arr + hashNum;

        while (tmp->next != nullptr && tmp->data != num)
            tmp = tmp->next;

        if (tmp->data != num)
        {
            tmp->next = new Node(num);
            return true;
        }
        return false;
    }
};



int main() {
    int n, cnt = 0;
    ifstream in("input.bin", ios::binary);
    ofstream out("output.bin", ios::binary);

    in.read((char*)&n, sizeof(int));
    out.write((char*)&n, sizeof(int));

    int* arr = new int[n];
    HashTable ht(n);

    in.read((char*)arr, sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        if (ht.push(arr[i]))
        {
            out.write((char*)&arr[i], sizeof(int));
            cnt++;
        }
    }
    out.seekp(0, ios::beg);
    out.write((char*)&cnt, sizeof(int));

    in.close();
    out.close();
}