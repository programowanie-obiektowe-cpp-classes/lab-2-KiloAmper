#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
private:
    std::unique_ptr< Resource > resource; // Zarz¹dzany wskaŸnik do Resource

public:
    // Konstruktor domyœlny - inicjalizuje zarz¹dzany obiekt
    ResourceManager() : resource(std::make_unique< Resource >()) {}

    // Konstruktor kopiuj¹cy
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique< Resource >(*other.resource))
    {}

    // Operator przypisania kopiuj¹cego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) { // Unikniêcie samoprzydzia³u
            resource = std::make_unique< Resource >(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenosz¹cy
    //ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenosz¹cego
    //ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Destruktor - std::unique_ptr automatycznie zwolni zasób
    ~ResourceManager() = default;

    // Metoda get, która wywo³uje metodê get na zarz¹dzanym zasobie
    double get() const { return resource->get(); }

};
