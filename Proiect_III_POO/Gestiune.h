#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Gestiune {
    std::vector<T> elemente;
    T ultimulAdaugat; 
public:
    Gestiune() = default;

   
    void adauga(T elem) {
        elemente.push_back(elem);
        ultimulAdaugat = elem;
    }
   
    template <typename U>
    friend void afiseazaInfoGestiune(const Gestiune<U>& g);

    template <typename V>
    friend void afiseazaElementeLog(const Gestiune<V>& g);
};

template <typename U>
void afiseazaInfoGestiune(const Gestiune<U>& g) {
    std::cout << "---Log-ul contine: " << g.elemente.size() << " elemente.\n"
        <<"Ultima actiune efectuata: "<< g.ultimulAdaugat<<"---\n\n";
}

template <typename V>
void afiseazaElementeLog(const Gestiune<V>& g) {
    std::cout << "---Continut actual log: \n";
    for (auto const& el : g.elemente)
        std::cout << el << "\n";
    std::cout << "---\n";
}