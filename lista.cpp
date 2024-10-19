#include <iostream>
using namespace std;

class lista{
    private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
        Node* head; //pierwszy element listy
        Node* tail; // ostatni element listy
        Node* current; //wskaźnik do przemieszczania sie po liscie

    public:
    lista() : head(nullptr), tail(nullptr), current(nullptr) {} //konstruktor
    }