#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace arkan10000 {

class UInt10000 {
public:
    static constexpr std::size_t bit_width = 10000;
    static constexpr std::size_t limb_bits = 64;
    static constexpr std::size_t limb_count = 157;
    static constexpr std::uint64_t top_mask = 0xFFFFULL;

    // Little-endian limbs. The highest limb stores only 16 significant bits.
    std::array<std::uint64_t, limb_count> limbs{};

    [[nodiscard]] static constexpr UInt10000 from_u64(std::uint64_t value) noexcept {
        UInt10000 result{};
        result.limbs[0] = value;
        return result;
    }

    constexpr void normalize() noexcept { limbs.back() &= top_mask; }

    [[nodiscard]] constexpr bool is_zero() const noexcept {
        for (const auto limb : limbs) if (limb != 0) return false;
        return true;
    }

    [[nodiscard]] constexpr bool add(const UInt10000& rhs, UInt10000& out) const noexcept {
        std::uint64_t carry = 0;
        for (std::size_t i = 0; i + 1 < limb_count; ++i) {
            const auto a = limbs[i];
            const auto b = rhs.limbs[i];
            const auto first = a + b;
            const bool c1 = first < a;
            const auto second = first + carry;
            const bool c2 = second < first;
            out.limbs[i] = second;
            carry = (c1 || c2) ? 1U : 0U;
        }
        const std::uint64_t top_sum = (limbs.back() & top_mask) +
                                      (rhs.limbs.back() & top_mask) + carry;
        out.limbs.back() = top_sum & top_mask;
        return top_sum > top_mask;
    }

    [[nodiscard]] constexpr bool sub(const UInt10000& rhs, UInt10000& out) const noexcept {
        std::uint64_t borrow = 0;
        for (std::size_t i = 0; i + 1 < limb_count; ++i) {
            const auto a = limbs[i];
            const auto b = rhs.limbs[i];
            const auto first = a - b;
            const bool b1 = a < b;
            const auto second = first - borrow;
            const bool b2 = first < borrow;
            out.limbs[i] = second;
            borrow = (b1 || b2) ? 1U : 0U;
        }
        const std::uint64_t a = limbs.back() & top_mask;
        const std::uint64_t b = (rhs.limbs.back() & top_mask) + borrow;
        const bool underflow = a < b;
        out.limbs.back() = (a - b) & top_mask;
        return underflow;
    }

    [[nodiscard]] constexpr UInt10000 bit_and(const UInt10000& rhs) const noexcept {
        UInt10000 out{};
        for (std::size_t i = 0; i < limb_count; ++i) out.limbs[i] = limbs[i] & rhs.limbs[i];
        out.normalize();
        return out;
    }

    [[nodiscard]] constexpr UInt10000 bit_or(const UInt10000& rhs) const noexcept {
        UInt10000 out{};
        for (std::size_t i = 0; i < limb_count; ++i) out.limbs[i] = limbs[i] | rhs.limbs[i];
        out.normalize();
        return out;
    }

    [[nodiscard]] constexpr UInt10000 bit_xor(const UInt10000& rhs) const noexcept {
        UInt10000 out{};
        for (std::size_t i = 0; i < limb_count; ++i) out.limbs[i] = limbs[i] ^ rhs.limbs[i];
        out.normalize();
        return out;
    }

    [[nodiscard]] constexpr UInt10000 bit_not() const noexcept {
        UInt10000 out{};
        for (std::size_t i = 0; i < limb_count; ++i) out.limbs[i] = ~limbs[i];
        out.normalize();
        return out;
    }

    [[nodiscard]] constexpr UInt10000 shift_left(std::size_t amount) const noexcept {
        UInt10000 out{};
        if (amount >= bit_width) return out;
        const std::size_t whole = amount / limb_bits;
        const std::size_t part = amount % limb_bits;
        for (std::size_t i = limb_count; i-- > whole;) {
            out.limbs[i] = limbs[i - whole] << part;
            if (part != 0 && i > whole) out.limbs[i] |= limbs[i - whole - 1] >> (limb_bits - part);
        }
        out.normalize();
        return out;
    }

    [[nodiscard]] constexpr UInt10000 shift_right(std::size_t amount) const noexcept {
        UInt10000 out{};
        if (amount >= bit_width) return out;
        const std::size_t whole = amount / limb_bits;
        const std::size_t part = amount % limb_bits;
        for (std::size_t i = 0; i + whole < limb_count; ++i) {
            out.limbs[i] = limbs[i + whole] >> part;
            if (part != 0 && i + whole + 1 < limb_count)
                out.limbs[i] |= limbs[i + whole + 1] << (limb_bits - part);
        }
        out.normalize();
        return out;
    }

    [[nodiscard]] constexpr bool operator==(const UInt10000& rhs) const noexcept {
        return limbs == rhs.limbs;
    }
};

static_assert(UInt10000::limb_count * UInt10000::limb_bits >= UInt10000::bit_width);
static_assert((UInt10000::limb_count - 1) * UInt10000::limb_bits + 16 == UInt10000::bit_width);
static_assert(sizeof(UInt10000) == 157 * sizeof(std::uint64_t));

} // namespace arkan10000
