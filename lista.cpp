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

    //dodaj element na początek lsity
    void dodajnapoczatek(int element){
        Node* nowy = new Node(element); //nowy obiekt
        if(head == nullptr){ // jezeli jest pusta
            head = nowy;    //lista ma jeden element dlatego ostatni i pierwszy element
            tail = nowy;    //przypisujemy do tego samego obiektu nowy
        } else {
            nowy->next = head; //dla nowego następnym elemtem będzie head
            head->prev = nowy; //dla head poprzednim elementem będzie nowy 
            head = nowy;
        }
        current = head;
    } 