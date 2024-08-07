#pragma once

#include <cstdint>
#include <iostream>
#include <iomanip>

namespace m6502 {
    // 8 bit unsigned int
    using byte = uint8_t;

    // 16 bit unsigned int
    using word = uint16_t;

    using fast_byte = uint_fast8_t;

    using fast_word = uint_fast16_t;

    union address {
        word value;
        struct {
            byte record;
            byte page;
        };

        address() = default;

        explicit address(int val) : value(val) {};

        address(byte page, byte record) : record(record), page(page) {};

        // Formats the address as a 4 character uppercase hexadecimal string prefixed with $.
        friend std::ostream &operator<<(std::ostream &os, const address &addr) {
            os << std::hex
               << std::uppercase
               << std::setfill('0')
               << std::setw(4)
               << addr.value;
            return os;
        }
    };
}