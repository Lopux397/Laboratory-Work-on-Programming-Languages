#pragma once

#include <iostream>
#include <string>
#include <string_view>


class Vet
{
private:
    std::string name;
    std::string speciality;
public:
    Vet();
    Vet(std::string_view nameTemp, std::string_view specialityTemp);

    void setName(std::string_view nameTemp);
    void setSpeciality(std::string_view specialityTemp);

    std::string getName() const;
    std::string getSpeciality() const;

    void info() const;
};

