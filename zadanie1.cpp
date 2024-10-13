#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class lista {
    private:
        vector<int> lista;
        int currIndex;
}
    public:
        lista() : currIndex(-1) {}
        
        void dodajnapoczatek(int element){
            lista.insert(lista.begin(), element);
        }
        void dodajnakoniec(int element){
            lista.push_back(element);
        }
        void dodajdoindexu(int index, int element){
            if (index >=0 && index <= lista.size()){
                lista.insert(lista.begin()+index, element);
            } else {
                cout << "index poza zakresem";
                endl;
            }
        }
        void usunzkonca(){
            if(!lista.empty()){
                lista.pop_back();
            } else {
                cout << "lista jest pusta";
                endl;
            }
        }

        void usunzindexu(int index){
            if(index >= 0 && index < lista.size()){
                lista.erase(lista.begin()+index);
            } else {
                cout << "index poza zakresem";
                endl;
            }
        }
        void usunzpoczatku(int index){
            if(!ista.empty()){
                lista.pop_front();
            } else {
                cout << "lista jest pusta";
                endl;
            }
        }
        