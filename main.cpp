#include <lista.cpp>
#include <iostream>

int main() {
    ListaDwukierunkowa lista;

    // Dodaj elementy
    lista.dodajNaPoczatek(10);
    lista.dodajNaPoczatek(5);
    lista.dodajNaKoniec(30);
    lista.dodajNaIndeks(1, 15);

    // Wyświetl listę
    cout << "Lista: ";
    lista.wyswietlListe();

    // Wyświetl listę w odwrotnej kolejności
    cout << "Lista w odwrotnej kolejności: ";
    lista.wyswietlListeOdwrotnie();

    // Usuń element z początku i końca
    lista.usunZPoczatku();
    lista.usunZKonca();

    // Wyświetl listę po usunięciach
    cout << "Lista po usunięciu początku i końca: ";
    lista.wyswietlListe();

    // Przejdź do następnego i poprzedniego elementu
    lista.wyswietlNastepny();
    lista.wyswietlPoprzedni();

    // Wyczyszczenie całej listy
    lista.czyscListe();
    cout << "Lista po wyczyszczeniu: ";
    lista.wyswietlListe();

    return 0;
}



