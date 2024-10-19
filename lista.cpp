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

    //dodaj element na koniec listy
    void dodajNaKoniec(int element) {
        Node* nowy = new Node(element);
        if (head == nullptr) {
            head = tail = nowy;
        } else {
            tail->next = nowy; //dla tail nastpenym elementem bedzie nowy,
            nowy->prev = tail; //dla nowego poprzednim elementem bedzie tail
            tail = nowy;
        }
        if (current == nullptr) current = head;
    }


    // Dodaj element pod wskazany indeks
    void dodajNaIndeks(int index, int element) {
        if (index < 0) {
            cout << "Indeks poza zakresem!" << endl;
            return;
        }

        if (index == 0) {
            dodajNaPoczatek(element);
            return;
        }

        Node* nowy = new Node(element);
        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp == tail) {
            dodajNaKoniec(element);
        } else {
            nowy->next = temp->next;
            temp->next->prev = nowy;
            temp->next = nowy;
            nowy->prev = temp;
        }
    }