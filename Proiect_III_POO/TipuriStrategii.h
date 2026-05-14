#pragma once
#include "StrategiePret.h"
#include <string>

class StrategieStandard : public StrategiePret {
public:
    float getCoeficient() const override { return 1.0f; }
    
};


class StrategieSarbatori : public StrategiePret {
public:
    float getCoeficient() const override { return 0.8f; }
   
};


class StrategieFidelitate : public StrategiePret {
public:
    float getCoeficient() const override { return 0.9f; }
 
};