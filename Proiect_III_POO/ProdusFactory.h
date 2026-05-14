#pragma once
#include <memory>
#include <vector>
#include <string>
#include "Produs.h"
#include "Fir.h"
#include "Ghiveci.h"
#include "Ornament.h"
#include "Buchet.h"


//DESIGN PATTERN 1
class ProdusFactory {
public:

    static std::unique_ptr<Produs> creeazaSimplu(int tip, std::string nume, float pret, int stoc, bool per, std::string detaliu) {
        if (tip == 1) return std::make_unique<Fir>(nume, pret, stoc, per, detaliu); // detaliu = culoare
        if (tip == 2) return std::make_unique<Ghiveci>(nume, pret, stoc, per, detaliu); // detaliu = material
        return nullptr;
    }

    
    static std::unique_ptr<Produs> creeazaComplex(int tip, std::string nume, float pret, int stoc, bool per, const std::vector<std::string>& culori, int nrFire = 0) {
        if (tip == 3) return std::make_unique<Ornament>(nume, pret, per, culori, stoc);
        if (tip == 4) return std::make_unique<Buchet>(nume, pret, per, culori, stoc, nrFire);
        return nullptr;
    }
};