#pragma once
#include <iostream>
#include "Produs.h"
class Buchet: public Produs
{
	std::string denumire;
	float pret;
	std::vector<std::string> cromatica;
	int stoc;
	int nrFire;
public:
	Buchet(const std::string& den, double p, bool per, const std::vector<std::string>& cul, int s, int f);

	std::string getDen() const override;
	void setStoc(int n)override;

	void afisare();


	std::string specificatii();


	void aplicaReducere(int procent);

	std::unique_ptr<Produs> clone() const override;

	friend void giveYaName(const Produs& p, Comanda& c);
	friend float autoCalcTotPrice(Produs& p, Comanda& c, int n);
	friend bool verName(std::vector<std::unique_ptr<Produs>>& inventar, std::string s);

	~Buchet();
};

