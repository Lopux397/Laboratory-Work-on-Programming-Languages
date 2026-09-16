#pragma once

#include "animal.h"
#include "vet.h"
#include "appeals.h"

#include <iostream>
#include <string_view>
#include <string>
#include <vector>

class VetClinic
{
private:
    std::vector<Animal> animal;
    std::vector<Vet> vet;
    std::vector<Appeals> appeals;
public:
    VetClinic();

    VetClinic(const VetClinic&) = delete;
    VetClinic& operator=(const VetClinic&) = delete;

    void setAnimal(const Animal& animalTemp);
    void setVet(const Vet& vetTemp);
    bool setAppeals(std::string_view vetSpeciality, std::string_view nameAnimal, std::string_view date, std::string_view diagnosis, std::string_view treatment);

    bool appointmentCheck(std::string_view vetSpeciality, std::string_view viewAnimal) const;

    void infoAnimal() const;
    void infoVet() const;
    void infoAppeals() const;
};
