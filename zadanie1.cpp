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