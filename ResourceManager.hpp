#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
private:
    std::unique_ptr< Resource > resource; // Zarz�dzany wska�nik do Resource

public:
    // Konstruktor domy�lny - inicjalizuje zarz�dzany obiekt
    ResourceManager() : resource(std::make_unique< Resource >()) {}

    // Konstruktor kopiuj�cy
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique< Resource >(*other.resource))
    {}

    // Operator przypisania kopiuj�cego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) { // Unikni�cie samoprzydzia�u
            resource = std::make_unique< Resource >(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenosz�cy
    //ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenosz�cego
    //ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Destruktor - std::unique_ptr automatycznie zwolni zas�b
    ~ResourceManager() = default;

    // Metoda get, kt�ra wywo�uje metod� get na zarz�dzanym zasobie
    double get() const { return resource->get(); }

};
