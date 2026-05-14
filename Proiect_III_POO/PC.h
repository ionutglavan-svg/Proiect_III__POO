#pragma once
#include "Produs.h"
#include "Comanda.h"

void giveYaName(const Produs& p, Comanda& c);

float autoCalcTotPrice(Produs& p, Comanda& c, int n);
