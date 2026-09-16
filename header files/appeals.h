#pragma once

#include "animal.h"
#include "vet.h"

#include <iostream>
#include <string>
#include <string_view>

class Appeals
{
private:
    Vet vet;
    Animal animal;
    std::string date;
    std::string diagnosis;
    std::string treatment;
public:
    Appeals();
    Appeals(const Vet& vetTemp, const Animal& animalTemp, std::string_view dateTemp, std::string_view diagnosisTemp, std::string_view treatmentTemp);

    void setVet(const Vet& vetTemp);
    void setAnimal(const Animal& animalTemp);
    void setDate(std::string_view dateTemp);
    void setDiagnosis(std::string_view diagnosisTemp);
    void setTreatment(std::string_view treatmentTemp);

    Vet getVet() const;
    Animal getAnimal() const;
    std::string getDate() const;
    std::string getDiagnosis() const;
    std::string getTreatment() const;

    void info() const;
};
