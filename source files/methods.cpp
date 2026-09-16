#include "animal.h"
#include "vet.h"
#include "appeals.h"
#include "vetClinic.h"

Animal::Animal() = default;
Animal::Animal(std::string_view nameTemp, std::string_view viewTemp, std::string_view breedTemp, unsigned int ageTemp, std::string_view ownerTemp)
: name(nameTemp), view(viewTemp), breed(breedTemp), age(ageTemp), owner(ownerTemp) {}

void Animal::setName(std::string_view nameTemp) { name = nameTemp; }
void Animal::setView(std::string_view viewTemp) { view = viewTemp; }
void Animal::setBreed(std::string_view breedTemp) { breed = breedTemp; }
void Animal::setAge(unsigned int ageTemp) { age = ageTemp; }
void Animal::setOwner(std::string_view ownerTemp) { owner = ownerTemp; }

std::string Animal::getName() const { return name; }
std::string Animal::getView() const { return view; }
std::string Animal::getBreed() const { return breed; }
unsigned int Animal::getAge() const{ return age; }
std::string Animal::getOwner() const{ return owner; }

void Animal::info() const
{
    std::cout << "Name: " << name << "\nView: " << view << "\nBreed: " << breed << "\nAge: " << age << "\nOwner: " << owner << std::endl;
}


Vet::Vet() = default;
Vet::Vet(std::string_view nameTemp, std::string_view specialityTemp)
: name(nameTemp), speciality(specialityTemp) {}

void Vet::setName(std::string_view nameTemp) { name = nameTemp; }
void Vet::setSpeciality(std::string_view specialityTemp) { speciality = specialityTemp; }

std::string Vet::getName() const { return name; }
std::string Vet::getSpeciality() const { return speciality; }

void Vet::info() const
{
    std::cout << "Name: "<< name << "\nSpeciality: " << speciality << std::endl;
}


Appeals::Appeals() = default;
Appeals::Appeals(const Vet& vetTemp, const Animal& animalTemp, std::string_view dateTemp, std::string_view diagnosisTemp, std::string_view treatmentTemp)
: vet(vetTemp), animal(animalTemp), date(dateTemp), diagnosis(diagnosisTemp), treatment(treatmentTemp) {}

void Appeals::setVet(const Vet& vetTemp) { vet = vetTemp; }
void Appeals::setAnimal(const Animal& animalTemp) { animal = animalTemp; }
void Appeals::setDate(std::string_view dateTemp) { date = dateTemp; }
void Appeals::setDiagnosis(std::string_view diagnosisTemp) { diagnosis = diagnosisTemp; }
void Appeals::setTreatment(std::string_view treatmentTemp) { treatment = treatmentTemp; }

Vet Appeals::getVet() const { return vet; }
Animal Appeals::getAnimal() const { return animal; }
std::string Appeals::getDate() const { return date; }
std::string Appeals::getDiagnosis() const { return diagnosis; }
std::string Appeals::getTreatment() const { return treatment; }

void Appeals::info() const 
{
    std::cout << "Vet: " << vet.getName() << "(" << vet.getSpeciality() << ")" << std::endl;
    std::cout << "Animal: " << animal.getName() << "(" << animal.getView() << ")" << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Diagnosis: " << diagnosis << std::endl;
    std::cout << "Treatment: " << treatment << std::endl;
}


VetClinic::VetClinic() = default;

bool VetClinic::appointmentCheck(std::string_view vetSpeciality, std::string_view viewAnimal) const
{
    if (vetSpeciality == "Орнитолог" && viewAnimal != "Птица") return false;
    if (vetSpeciality == "Ратолог" && viewAnimal != "Грызун") return false;
    if (vetSpeciality == "Терапевт" && (viewAnimal == "Птица" || viewAnimal == "Грызун")) return false;

    return true;
}

void VetClinic::setAnimal(const Animal& animalTemp)
{
    animal.push_back(animalTemp);
}

void VetClinic::setVet(const Vet& vetTemp)
{
    vet.push_back(vetTemp);
}

bool VetClinic::setAppeals(std::string_view vetSpeciality, std::string_view nameAnimal, std::string_view date, const std::string_view diagnosis, std::string_view treatment)
{
    const Vet* addsDoc = nullptr;
    for (int i = 0; i < vet.size(); i++)
    {
        if (vet[i].getSpeciality() == vetSpeciality)
        {
            addsDoc = &vet[i];
            break;
        }
    }
    if (!addsDoc)
    {
        std::cout<< "Vet not found" << std::endl;
        return false;
    }

    const Animal* addsAnimal = nullptr;
    for (int i = 0; i < animal.size(); i++)
    {
        if (animal[i].getName() == nameAnimal) {
            addsAnimal = &animal[i];
            break;
        }
    }
    if (!addsAnimal) 
    {
        std::cout << "Animal not found" << std::endl;
        return false;
    }

    if (!appointmentCheck(vetSpeciality, addsAnimal->getView())) 
    {
        std::cout << "A "<< vetSpeciality << " cannot treat a" << addsAnimal->getView() << std::endl;
        return false;
    }

    appeals.push_back(Appeals(*addsDoc, *addsAnimal, date, diagnosis, treatment));
    
    return true;
}

void VetClinic::infoAnimal() const
{
    for (int i = 0; i < animal.size(); i++) 
    {
        std::cout << "========= Animal[" << i + 1 << "] =========" << std::endl;
        animal[i].info();
        std::cout << "=============================\n" << std::endl;
    }
}

void VetClinic::infoVet() const 
{
    for (int i = 0; i < vet.size(); i++)
    {
        std::cout << "========= Vet[" << i + 1 << "] =========" << std::endl;
        vet[i].info();
        std::cout << "==========================\n" << std::endl;
    }
}

void VetClinic::infoAppeals() const 
{
    for (int i = 0; i < appeals.size(); i++)
    {
        std::cout << "========= Appeals[" << i + 1 << "] =========" << std::endl;
        appeals[i].info();
        std::cout << "==============================\n" << std::endl;
    }
}