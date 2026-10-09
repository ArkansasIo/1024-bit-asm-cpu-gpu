// Experimental RTL block; not yet synthesized or FPGA-verified.
module arkan10000_regfile #(
    parameter int unsigned REG_COUNT = 32,
    parameter int unsigned ADDR_W = $clog2(REG_COUNT)
) (
    input  logic                 clk,
    input  logic                 rst_n,
    input  logic                 wr_en,
    input  logic [ADDR_W-1:0]    wr_addr,
    input  logic [9999:0]        wr_data,
    input  logic [ADDR_W-1:0]    rd_addr_a,
    input  logic [ADDR_W-1:0]    rd_addr_b,
    output logic [9999:0]        rd_data_a,
    output logic [9999:0]        rd_data_b
);
    logic [9999:0] regs [0:REG_COUNT-1];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int unsigned i = 0; i < REG_COUNT; i++)
                regs[i] <= '0;
        end else if (wr_en && (wr_addr < REG_COUNT)) begin
            regs[wr_addr] <= wr_data;
        end
    end

    always_comb begin
        rd_data_a = (rd_addr_a < REG_COUNT) ? regs[rd_addr_a] : '0;
        rd_data_b = (rd_addr_b < REG_COUNT) ? regs[rd_addr_b] : '0;
    end
endmodule
