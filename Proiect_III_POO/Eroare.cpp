#include "Eroare.h"


Eroare::Eroare(const std::string& m) : mesaj("Eroare Florarie: " + m) {}

const char* Eroare::what() const noexcept {
    return mesaj.c_str();
}

NumeProdusInexistentException::NumeProdusInexistentException(const std::string& nume)
    : Eroare("Produsul '" + nume + "' nu exista in inventar!") {
}

StocInsuficientException::StocInsuficientException() : Eroare("Nu sunt suficiente produse pe stoc!") {}

InputInvalidException::InputInvalidException() : Eroare("Datele introduse nu sunt in formatul corect!") {}