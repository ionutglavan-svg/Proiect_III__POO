#pragma once
#include "Comanda.h"
#include "Livrare.h"

void strgLivrareComanda(std::vector<std::unique_ptr<Comanda>>& comenzi, std::vector<std::unique_ptr<Livrare>>& livrari, int id);

void conectComToLiv(Comanda& c, std::vector<std::unique_ptr<Livrare>>& livrari);
