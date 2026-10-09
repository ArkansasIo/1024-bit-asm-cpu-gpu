#include "uint10000.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>

int main() {
    using arkan10000::UInt10000;

    auto one = UInt10000::from_u64(1);
    UInt10000 result{};
    assert(!one.add(one, result));
    assert(result.limbs[0] == 2);

    UInt10000 zero{};
    assert(zero.sub(one, result));
    assert(result.limbs[0] == UINT64_MAX);
    assert(result.limbs.back() == UInt10000::top_mask);

    const auto all_ones = zero.bit_not();
    assert(all_ones.limbs.back() == UInt10000::top_mask);
    assert(all_ones.shift_left(10000).is_zero());
    assert(all_ones.shift_right(10000).is_zero());

    auto shifted = one.shift_left(9999);
    assert(shifted.limbs.back() == 0x8000U);
    assert(shifted.shift_right(9999) == one);

    UInt10000 top{};
    top.limbs.back() = UInt10000::top_mask;
    assert(!top.add(one, result));
    assert(result.limbs.back() == UInt10000::top_mask);
    assert(result.limbs[0] == 1); // independent low and top limbs

    std::cout << "UInt10000 tests passed\n";
    return 0;
}
