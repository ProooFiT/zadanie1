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

    //usun element z początku listy
    void usunZPoczatku() {
        if (head == nullptr) {
            cout << "Lista jest pusta!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete temp;
        current = head;
    }

    //usun element z końca listy
    void usunZKonca() {
        if (head == nullptr) {
            cout << "Lista jest pusta!" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        current = head;
    }

    // Usuń element z pod wskazanego indeksu
    void usunZIndeksu(int index) {
        if (index < 0 || head == nullptr) {
            cout << "Indeks poza zakresem lub lista jest pusta!" << endl;
            return;
        }

        if (index == 0) {
            usunZPoczatku();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Indeks poza zakresem!" << endl;
        } else if (temp == tail) {
            usunZKonca();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    //wyswietl liste
    void wyswietlListe() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    //wyświetl liste w odwrotnej kolejności
    void wyswietlListeOdwrotnie() {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    //wyświetl nastepny element
    void wyswietlNastepny() {
        if (current == nullptr || current->next == nullptr) {
            cout << "Brak następnego elementu!" << endl;
        } else {
            current = current->next;
            cout << "Następny element: " << current->data << endl;
        }
    }

    //wyświetl poprzedni element
    void wyswietlPoprzedni() {
        if (current == nullptr || current->prev == nullptr) {
            cout << "Brak poprzedniego elementu!" << endl;
        } else {
            current = current->prev;
            cout << "Poprzedni element: " << current->data << endl;
        }
    }

    //czysc liste
    void czyscListe() {
        while (head != nullptr) {
            usunZPoczatku();
        }
    }

    //Destruktor
    ~ListaDwukierunkowa() {
        czyscListe();
    }
   