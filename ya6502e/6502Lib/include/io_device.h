#pragma once

#include <vector>

#include "types.h"

namespace m6502 {
    class IODevice {
    public:
        virtual byte ReadByte(const address &addr) const = 0;

        virtual word ReadWord(const address &addr) const = 0;

        virtual void WriteByte(const address &addr, byte data) = 0;

        virtual void WriteWord(const address &addr, word data) = 0;

        virtual void WriteBytes(const address &offset, const std::vector<byte> &bytes) = 0;

        virtual void Write(const address &addr, const byte data) { WriteByte(addr, data); }

        virtual void Write(const address &addr, const word data) { WriteWord(addr, data); }

        virtual void Write(const address &addr, const std::vector<byte> &data) { WriteBytes(addr, data); }
    };

    using ioptr = std::shared_ptr<IODevice>;
}