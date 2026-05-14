#include "PC.h"
#include <iostream>

void giveYaName(const Produs& p, Comanda& c) {


	const Fir* f = (dynamic_cast<const Fir*>(&p));
	const Ghiveci* g = (dynamic_cast<const Ghiveci*>(&p));
	const Ornament* o = (dynamic_cast<const Ornament*>(&p));
	const Buchet* b = (dynamic_cast<const Buchet*>(&p));

	if(f)
		c.produs = f->denumire;
	else
		if (g)
			c.produs = g->denumire;
		else
			if (o)
				c.produs = o->denumire;
			else
				if (b)
					c.produs = b->denumire;
}			


float autoCalcTotPrice(Produs& p, Comanda& c, int n)
{
	Fir *f = (dynamic_cast<Fir*>(&p));
	Ghiveci* g = (dynamic_cast<Ghiveci*>(&p));
	Ornament* o = (dynamic_cast<Ornament*>(&p));
	Buchet* b = (dynamic_cast<Buchet*>(&p));


	if (f)
		if (f->stoc >= n)
		{
			f->stoc -= n;
			
			return n * f->pret;
		}
		else {
			c.valid = false;
			return 0;
		}
	else
		if (g)
			if (g->stoc >= n)
			{
				g->stoc -= n;
				
				return n * g->pret;
			}
			else {
				c.valid = false;
				return 0;
			}
		else
			if (o)
				if (o->stoc >= n)
				{
					o->stoc -= n;

					return n * o->pret;
				}
				else {
					c.valid = false;
					return 0;
				}
			else
				if (b)
					if (b->stoc >= n)
					{
						b->stoc -= n;

						return n * b->pret;
					}
					else {
						c.valid = false;
						return 0;
					}
	return 0;
}
