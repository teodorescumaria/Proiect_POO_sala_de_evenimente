//
// Created by Mackbook Pro 14 on 08.01.2026.
//

#ifndef OOP_EXCEPTII_H
#define OOP_EXCEPTII_H

#include <stdexcept>
#include <string>


class EroareLocInvalid : public std::runtime_error {
public:
    explicit EroareLocInvalid(const std::string& mesaj) : std::runtime_error(mesaj) {}
};


#endif //OOP_EXCEPTII_H