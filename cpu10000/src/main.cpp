#include "uint10000.hpp"

#include <cstdint>
#include <iostream>

int main() {
    using arkan10000::UInt10000;
    const auto a = UInt10000::from_u64(0xFFFF'FFFF'FFFF'FFFFULL);
    const auto b = UInt10000::from_u64(1);
    UInt10000 sum{};
    const bool carry = a.add(b, sum);

    std::cout << "Arkan-10000 reference arithmetic v0.1.0\n"
              << "Architectural data width: " << UInt10000::bit_width << " bits\n"
              << "Storage: " << UInt10000::limb_count << " x 64-bit limbs; top limb masked to 16 bits\n"
              << "Low-limb addition carry-out: " << (carry ? "true" : "false") << "\n"
              << "Result limb[0]: " << sum.limbs[0] << "\n";
    return 0;
}
