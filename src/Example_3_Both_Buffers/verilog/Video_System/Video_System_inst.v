	Video_System u0 (
		.SRAM_DQ_to_and_from_the_Pixel_Buffer (<connected-to-SRAM_DQ_to_and_from_the_Pixel_Buffer>), //   Pixel_Buffer_external_interface.DQ
		.SRAM_ADDR_from_the_Pixel_Buffer      (<connected-to-SRAM_ADDR_from_the_Pixel_Buffer>),      //                                  .ADDR
		.SRAM_LB_N_from_the_Pixel_Buffer      (<connected-to-SRAM_LB_N_from_the_Pixel_Buffer>),      //                                  .LB_N
		.SRAM_UB_N_from_the_Pixel_Buffer      (<connected-to-SRAM_UB_N_from_the_Pixel_Buffer>),      //                                  .UB_N
		.SRAM_CE_N_from_the_Pixel_Buffer      (<connected-to-SRAM_CE_N_from_the_Pixel_Buffer>),      //                                  .CE_N
		.SRAM_OE_N_from_the_Pixel_Buffer      (<connected-to-SRAM_OE_N_from_the_Pixel_Buffer>),      //                                  .OE_N
		.SRAM_WE_N_from_the_Pixel_Buffer      (<connected-to-SRAM_WE_N_from_the_Pixel_Buffer>),      //                                  .WE_N
		.VGA_CLK_from_the_VGA_Controller      (<connected-to-VGA_CLK_from_the_VGA_Controller>),      // VGA_Controller_external_interface.CLK
		.VGA_HS_from_the_VGA_Controller       (<connected-to-VGA_HS_from_the_VGA_Controller>),       //                                  .HS
		.VGA_VS_from_the_VGA_Controller       (<connected-to-VGA_VS_from_the_VGA_Controller>),       //                                  .VS
		.VGA_BLANK_from_the_VGA_Controller    (<connected-to-VGA_BLANK_from_the_VGA_Controller>),    //                                  .BLANK
		.VGA_SYNC_from_the_VGA_Controller     (<connected-to-VGA_SYNC_from_the_VGA_Controller>),     //                                  .SYNC
		.VGA_R_from_the_VGA_Controller        (<connected-to-VGA_R_from_the_VGA_Controller>),        //                                  .R
		.VGA_G_from_the_VGA_Controller        (<connected-to-VGA_G_from_the_VGA_Controller>),        //                                  .G
		.VGA_B_from_the_VGA_Controller        (<connected-to-VGA_B_from_the_VGA_Controller>),        //                                  .B
		.clk_0                                (<connected-to-clk_0>),                                //                      clk_0_clk_in.clk
		.reset_n                              (<connected-to-reset_n>),                              //                clk_0_clk_in_reset.reset_n
		.keycode_export                       (<connected-to-keycode_export>),                       //                           keycode.export
		.sdram_out_clk_clk                    (<connected-to-sdram_out_clk_clk>),                    //                     sdram_out_clk.clk
		.sdram_wire_addr                      (<connected-to-sdram_wire_addr>),                      //                        sdram_wire.addr
		.sdram_wire_ba                        (<connected-to-sdram_wire_ba>),                        //                                  .ba
		.sdram_wire_cas_n                     (<connected-to-sdram_wire_cas_n>),                     //                                  .cas_n
		.sdram_wire_cke                       (<connected-to-sdram_wire_cke>),                       //                                  .cke
		.sdram_wire_cs_n                      (<connected-to-sdram_wire_cs_n>),                      //                                  .cs_n
		.sdram_wire_dq                        (<connected-to-sdram_wire_dq>),                        //                                  .dq
		.sdram_wire_dqm                       (<connected-to-sdram_wire_dqm>),                       //                                  .dqm
		.sdram_wire_ras_n                     (<connected-to-sdram_wire_ras_n>),                     //                                  .ras_n
		.sdram_wire_we_n                      (<connected-to-sdram_wire_we_n>),                      //                                  .we_n
		.press_export                         (<connected-to-press_export>)                          //                             press.export
	);

