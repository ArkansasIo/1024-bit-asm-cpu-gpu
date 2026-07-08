#include "execute.hpp"

#include "alu.hpp"
#include "decode.hpp"
#include "fetch.hpp"

namespace cpu_gpu_1024::modules::cpu {

bool Execute::step(CpuState& state, std::span<const std::uint64_t> memory) {
    const auto raw = Fetch::read_opcode(memory, state.pc);
    const auto op = Decode::split(raw);

    auto& dst = state.regs.at(op.dst);
    auto& src = state.regs.at(op.src);

    switch (op.op) {
    case CpuOp::halt:
        return false;
    case CpuOp::mov_imm:
        Alu::load_imm64(dst, op.imm);
        ++state.pc;
        return true;
    case CpuOp::add:
        Alu::add(dst, src);
        ++state.pc;
        return true;
    case CpuOp::sub:
        Alu::sub(dst, src);
        ++state.pc;
        return true;
    case CpuOp::beq:
        if (Alu::equal(dst, src)) {
            state.pc = memory[static_cast<std::size_t>(state.pc + 1)];
        } else {
            state.pc += 2;
        }
        return true;
    default:
        ++state.pc;
        return true;
    }
}

} // namespace cpu_gpu_1024::modules::cpu
