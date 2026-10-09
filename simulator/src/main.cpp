#include <array>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string_view>

namespace arkan1024 {

struct UInt1024 {
    // Little-endian limbs: limb[0] contains bits 0..63.
    std::array<std::uint64_t, 16> limb{};

    [[nodiscard]] static constexpr UInt1024 from_u64(std::uint64_t value) noexcept {
        UInt1024 out{};
        out.limb[0] = value;
        return out;
    }

    [[nodiscard]] constexpr UInt1024 bit_and(const UInt1024& rhs) const noexcept {
        UInt1024 out{};
        for (std::size_t i = 0; i < limb.size(); ++i) out.limb[i] = limb[i] & rhs.limb[i];
        return out;
    }

    [[nodiscard]] constexpr UInt1024 bit_or(const UInt1024& rhs) const noexcept {
        UInt1024 out{};
        for (std::size_t i = 0; i < limb.size(); ++i) out.limb[i] = limb[i] | rhs.limb[i];
        return out;
    }

    [[nodiscard]] constexpr UInt1024 bit_xor(const UInt1024& rhs) const noexcept {
        UInt1024 out{};
        for (std::size_t i = 0; i < limb.size(); ++i) out.limb[i] = limb[i] ^ rhs.limb[i];
        return out;
    }

    [[nodiscard]] constexpr UInt1024 bit_not() const noexcept {
        UInt1024 out{};
        for (std::size_t i = 0; i < limb.size(); ++i) out.limb[i] = ~limb[i];
        return out;
    }

    // Unsigned modulo-2^1024 addition. Returns the carry beyond bit 1023.
    [[nodiscard]] constexpr bool add(const UInt1024& rhs, UInt1024& out) const noexcept {
        std::uint64_t carry = 0;
        for (std::size_t i = 0; i < limb.size(); ++i) {
            const std::uint64_t a = limb[i];
            const std::uint64_t b = rhs.limb[i];
            const std::uint64_t first = a + b;
            const bool carry1 = first < a;
            const std::uint64_t second = first + carry;
            const bool carry2 = second < first;
            out.limb[i] = second;
            carry = (carry1 || carry2) ? 1U : 0U;
        }
        return carry != 0;
    }

    // Unsigned modulo-2^1024 subtraction. Returns the borrow beyond bit 1023.
    [[nodiscard]] constexpr bool sub(const UInt1024& rhs, UInt1024& out) const noexcept {
        std::uint64_t borrow = 0;
        for (std::size_t i = 0; i < limb.size(); ++i) {
            const std::uint64_t a = limb[i];
            const std::uint64_t b = rhs.limb[i];
            const std::uint64_t first = a - b;
            const bool borrow1 = a < b;
            const std::uint64_t second = first - borrow;
            const bool borrow2 = first < borrow;
            out.limb[i] = second;
            borrow = (borrow1 || borrow2) ? 1U : 0U;
        }
        return borrow != 0;
    }

    [[nodiscard]] bool is_zero() const noexcept {
        for (const auto value : limb) if (value != 0) return false;
        return true;
    }

    void print_hex(std::ostream& os) const {
        const auto old_flags = os.flags();
        const auto old_fill = os.fill();
        os << "0x";
        bool started = false;
        for (std::size_t i = limb.size(); i-- > 0;) {
            if (!started) {
                if (limb[i] == 0 && i != 0) continue;
                os << std::hex << limb[i];
                started = true;
            } else {
                os << std::hex << std::setw(16) << std::setfill('0') << limb[i];
            }
        }
        if (!started) os << '0';
        os.flags(old_flags);
        os.fill(old_fill);
    }
};

static_assert(sizeof(UInt1024) == 128, "UInt1024 must occupy exactly 128 bytes");

} // namespace arkan1024

int main(int argc, char** argv) {
    using arkan1024::UInt1024;
    if (argc > 1 && std::string_view(argv[1]) == "--help") {
        std::cout << "Arkan1024 reference arithmetic prototype v0.1.0\n"
                     "Usage: arkan1024 [--help]\n"
                     "Implements 1024-bit unsigned arithmetic primitives; not yet a full CPU/OS.\n";
        return 0;
    }

    UInt1024 a = UInt1024::from_u64(0xFFFF'FFFF'FFFF'FFFFULL);
    UInt1024 b = UInt1024::from_u64(1);
    UInt1024 sum{};
    const bool carry = a.add(b, sum);

    std::cout << "Arkan1024 reference arithmetic prototype v0.1.0\n";
    std::cout << "Data width: 1024 bits (16 x 64-bit limbs)\n";
    std::cout << "Example: 0xFFFFFFFFFFFFFFFF + 1 = ";
    sum.print_hex(std::cout);
    std::cout << "\nCarry out: " << (carry ? "true" : "false") << "\n";

    UInt1024 zero{};
    UInt1024 difference{};
    const bool borrow = zero.sub(b, difference);
    std::cout << "Example: 0 - 1 (mod 2^1024) = ";
    difference.print_hex(std::cout);
    std::cout << "\nBorrow out: " << (borrow ? "true" : "false") << "\n";

    return 0;
}
