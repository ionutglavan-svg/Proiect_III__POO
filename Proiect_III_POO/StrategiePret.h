#pragma once

//DESIGN PATTERN 2
class StrategiePret {
public:
    virtual ~StrategiePret() = default;

    virtual float getCoeficient() const = 0;
};