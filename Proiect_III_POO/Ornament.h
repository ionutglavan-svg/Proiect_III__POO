#pragma once
#include <iostream>
#include "Produs.h"
class Ornament : public Produs
{
	std::string denumire;
	float pret;
	int stoc;
	std::vector<std::string> cromatica;
public:
	Ornament(const std::string& sir, double p, bool per, const std::vector<std::string>& cul, int s);

	std::string getDen() const override;
	void setStoc(int n)override;

	void afisare();

	void afisareCrom();

	std::string specificatii();


	void aplicaReducere(int procent);

	std::unique_ptr<Produs> clone() const override;

	friend void giveYaName(const Produs& p, Comanda& c);
	friend float autoCalcTotPrice(Produs& p, Comanda& c, int n);
	friend bool verName(std::vector<std::unique_ptr<Produs>>& inventar, std::string s);

	~Ornament();
};
