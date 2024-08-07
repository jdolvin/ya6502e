#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "types.h"

#define KB 0x400
#define MB 0x100000
#define GB 0x40000000

#define MAKE_KB(n) n * KB
#define MAKE_MB(n) n * MB
#define MAKE_GB(n) n * GB

#define BYTES_TO_KB(n) static_cast<float>(n) / static_cast<float>(KB)
#define BYTES_TO_MB(n) static_cast<float>(n) / static_cast<float>(MB)
#define BYTES_TO_GB(n) static_cast<float>(n) / static_cast<float>(GB)

#define MAKE_WORD(low, high) ((high << 8) | low)

#define GET_HIGH_BYTE(val) ((val >> 8) & 0xFF)
#define GET_LOW_BYTE(val) (val & 0xFF)
#define IS_NEGATIVE(val) (val & 0x80)

namespace m6502 {
    // Starting location of the stack.
    // The MOS6502 features a 256 byte stack starting at 0x0100
    // and reaching to 0x01FF.
    const word ADDRESS_STACK = 0x0100;

    // Memory address holding a pointer to the next PC when
    // a Non-Maskable Interrupt is fired.
    const word ADDRESS_NMI_VECTOR = 0xFFFA;

    // Memory address holding a pointer to the next PC when
    // a CPU Reset is fired.
    const word ADDRESS_RESET_VECTOR = 0xFFFC;

    // Memory address holding a pointer tp the next PC when
    // a Interrupt Request is fired.
    const word ADDRESS_IRQ_VECTOR = 0xFFFE;

    // Takes in a string of space-separated hexadecimal values
    // and converts that into a vector of bytes.
    std::vector<byte> ConvertHexStringToBytes(const std::string&);

    std::string Hex(byte value);
    std::string Hex(word value);
    std::string Hex(address addr);
}