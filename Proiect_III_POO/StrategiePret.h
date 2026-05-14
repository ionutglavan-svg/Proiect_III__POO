#pragma once


class StrategiePret {
public:
    virtual ~StrategiePret() = default;

    virtual float getCoeficient() const = 0;
};