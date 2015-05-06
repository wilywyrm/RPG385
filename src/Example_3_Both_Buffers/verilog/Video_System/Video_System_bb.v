
module Video_System (
	SRAM_DQ_to_and_from_the_Pixel_Buffer,
	SRAM_ADDR_from_the_Pixel_Buffer,
	SRAM_LB_N_from_the_Pixel_Buffer,
	SRAM_UB_N_from_the_Pixel_Buffer,
	SRAM_CE_N_from_the_Pixel_Buffer,
	SRAM_OE_N_from_the_Pixel_Buffer,
	SRAM_WE_N_from_the_Pixel_Buffer,
	VGA_CLK_from_the_VGA_Controller,
	VGA_HS_from_the_VGA_Controller,
	VGA_VS_from_the_VGA_Controller,
	VGA_BLANK_from_the_VGA_Controller,
	VGA_SYNC_from_the_VGA_Controller,
	VGA_R_from_the_VGA_Controller,
	VGA_G_from_the_VGA_Controller,
	VGA_B_from_the_VGA_Controller,
	clk_0,
	reset_n,
	keycode_export,
	sdram_out_clk_clk,
	sdram_wire_addr,
	sdram_wire_ba,
	sdram_wire_cas_n,
	sdram_wire_cke,
	sdram_wire_cs_n,
	sdram_wire_dq,
	sdram_wire_dqm,
	sdram_wire_ras_n,
	sdram_wire_we_n,
	press_export);	

	inout	[15:0]	SRAM_DQ_to_and_from_the_Pixel_Buffer;
	output	[19:0]	SRAM_ADDR_from_the_Pixel_Buffer;
	output		SRAM_LB_N_from_the_Pixel_Buffer;
	output		SRAM_UB_N_from_the_Pixel_Buffer;
	output		SRAM_CE_N_from_the_Pixel_Buffer;
	output		SRAM_OE_N_from_the_Pixel_Buffer;
	output		SRAM_WE_N_from_the_Pixel_Buffer;
	output		VGA_CLK_from_the_VGA_Controller;
	output		VGA_HS_from_the_VGA_Controller;
	output		VGA_VS_from_the_VGA_Controller;
	output		VGA_BLANK_from_the_VGA_Controller;
	output		VGA_SYNC_from_the_VGA_Controller;
	output	[7:0]	VGA_R_from_the_VGA_Controller;
	output	[7:0]	VGA_G_from_the_VGA_Controller;
	output	[7:0]	VGA_B_from_the_VGA_Controller;
	input		clk_0;
	input		reset_n;
	input	[7:0]	keycode_export;
	output		sdram_out_clk_clk;
	output	[12:0]	sdram_wire_addr;
	output	[1:0]	sdram_wire_ba;
	output		sdram_wire_cas_n;
	output		sdram_wire_cke;
	output		sdram_wire_cs_n;
	inout	[31:0]	sdram_wire_dq;
	output	[3:0]	sdram_wire_dqm;
	output		sdram_wire_ras_n;
	output		sdram_wire_we_n;
	input	[7:0]	press_export;
endmodule
