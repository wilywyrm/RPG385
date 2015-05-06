/******************************************************************************
 * License Agreement                                                          *
 *                                                                            *
 * Copyright (c) 1991-2010 Altera Corporation, San Jose, California, USA.     *
 * All rights reserved.                                                       *
 *                                                                            *
 * Any megafunction design, and related net list (encrypted or decrypted),    *
 *  support information, device programming or simulation file, and any other *
 *  associated documentation or information provided by Altera or a partner   *
 *  under Altera's Megafunction Partnership Program may be used only to       *
 *  program PLD devices (but not masked PLD devices) from Altera.  Any other  *
 *  use of such megafunction design, net list, support information, device    *
 *  programming or simulation file, or any other related documentation or     *
 *  information is prohibited for any other purpose, including, but not       *
 *  limited to modification, reverse engineering, de-compiling, or use with   *
 *  any other silicon devices, unless such use is explicitly licensed under   *
 *  a separate agreement with Altera or a megafunction partner.  Title to     *
 *  the intellectual property, including patents, copyrights, trademarks,     *
 *  trade secrets, or maskworks, embodied in any such megafunction design,    *
 *  net list, support information, device programming or simulation file, or  *
 *  any other related documentation or information provided by Altera or a    *
 *  megafunction partner, remains with Altera, the megafunction partner, or   *
 *  their respective licensors.  No other licenses, including any licenses    *
 *  needed under any third party's intellectual property, are provided herein.*
 *  Copying or modifying any file, or portion thereof, to which this notice   *
 *  is attached violates this copyright.                                      *
 *                                                                            *
 * THIS FILE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR    *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    *
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    *
 * FROM, OUT OF OR IN CONNECTION WITH THIS FILE OR THE USE OR OTHER DEALINGS  *
 * IN THIS FILE.                                                              *
 *                                                                            *
 * This agreement shall be governed in all respects by the laws of the State  *
 *  of California and by the laws of the United States of America.            *
 *                                                                            *
 ******************************************************************************/

module Example_3_Both_Buffers (
	// Inputs
	CLOCK_50,
	KEY,

	// Bidirectionals
	//  Memory (SRAM)
	SRAM_DQ,
	//  Memory (SDRAM)
	DRAM_DQ,
	
	// Outputs
	// 	Memory (SRAM)
	SRAM_ADDR,

	SRAM_CE_N,
	SRAM_WE_N,
	SRAM_OE_N,
	SRAM_UB_N,
	SRAM_LB_N,
	//		Memory (SDRAM)
	DRAM_ADDR,

	DRAM_BA,
	DRAM_CAS_N,
	DRAM_CKE,
	DRAM_CS_N,
	DRAM_DQM,
	DRAM_RAS_N,
	DRAM_WE_N,
	DRAM_CLK,
	
	//PS2 keyboard
	PS2_CLK,
	PS2_DAT,
	
	/*
	// USB 
	OTG_DATA,
	OTG_ADDR,
	OTG_CS_N,
	OTG_RD_N,
	OTG_WR_N,
	OTG_RST_N,
	OTG_INT,
	*/
	
	//  VGA
	VGA_CLK,
	VGA_HS,
	VGA_VS,
	VGA_BLANK,
	VGA_SYNC,
	VGA_R,
	VGA_G,
	VGA_B,
	
	// LED indicator
	PRESS_LED
);

/*****************************************************************************
 *                           Parameter Declarations                          *
 *****************************************************************************/


/*****************************************************************************
 *                             Port Declarations                             *
 *****************************************************************************/
// Inputs
input				CLOCK_50;
input		[3:0]	KEY;

// Bidirectionals
// 	Memory (SRAM)
inout		[15:0]	SRAM_DQ;
//		Memory (SDRAM)
inout		[31:0]	DRAM_DQ;

// Outputs
// 	Memory (SRAM)
output		[17:0]	SRAM_ADDR;

output				SRAM_CE_N;
output				SRAM_WE_N;
output				SRAM_OE_N;
output				SRAM_UB_N;
output				SRAM_LB_N;

// 	Memory (SDRAM)
output [12:0]	DRAM_ADDR;

output [3:0]	DRAM_DQM;
output [1:0]	DRAM_BA;
output	DRAM_CAS_N,
	DRAM_CKE,
	DRAM_CS_N,
	DRAM_RAS_N,
	DRAM_WE_N,
	DRAM_CLK;

//PS2 Keyboard
input PS2_CLK;
input PS2_DAT;
	
//  VGA
output				VGA_CLK;
output				VGA_HS;
output				VGA_VS;
output				VGA_BLANK;
output				VGA_SYNC;
output		[ 9: 0]	VGA_R;
output		[ 9: 0]	VGA_G;
output		[ 9: 0]	VGA_B;

// LED indicator
output PRESS_LED;

/*
// CY7C67200 Interface
inout [15:0]  OTG_DATA;						//	CY7C67200 Data bus 16 Bits
output [1:0]  OTG_ADDR;						//	CY7C67200 Address 2 Bits
output        OTG_CS_N;						//	CY7C67200 Chip Select
output		 OTG_RD_N;						//	CY7C67200 Write
output		 OTG_WR_N;						//	CY7C67200 Read
output		 OTG_RST_N;						//	CY7C67200 Reset
input			 OTG_INT;						//	CY7C67200 Interrupt
*/

/*****************************************************************************
 *                 Internal Wires and Registers Declarations                 *
 *****************************************************************************/
// Internal Wires

// Internal Registers

// State Machine Registers

/*****************************************************************************
 *                         Finite State Machine(s)                           *
 *****************************************************************************/


/*****************************************************************************
 *                             Sequential Logic                              *
 *****************************************************************************/


/*****************************************************************************
 *                            Combinational Logic                            *
 *****************************************************************************/


/*****************************************************************************
 *                              Internal Modules                             *
 *****************************************************************************/

 wire Reset_h;
assign {Reset_h}=~ (KEY[0]);  // The push buttons are active low
wire[7:0] keycode;
wire[7:0] press;
assign PRESS_LED = press;

 
Video_System Char_Buffer_System (
	// 1) global signals:
	.clk_0									(CLOCK_50),
	.reset_n								(KEY[0]),

	// the_Pixel_Buffer
	.SRAM_DQ_to_and_from_the_Pixel_Buffer	(SRAM_DQ),
	.SRAM_ADDR_from_the_Pixel_Buffer		(SRAM_ADDR),
	.SRAM_LB_N_from_the_Pixel_Buffer		(SRAM_LB_N),
	.SRAM_UB_N_from_the_Pixel_Buffer		(SRAM_UB_N),
	.SRAM_CE_N_from_the_Pixel_Buffer		(SRAM_CE_N),
	.SRAM_OE_N_from_the_Pixel_Buffer		(SRAM_OE_N),
	.SRAM_WE_N_from_the_Pixel_Buffer		(SRAM_WE_N),

	// the_vga_controller
	.VGA_CLK_from_the_VGA_Controller		(VGA_CLK),
	.VGA_HS_from_the_VGA_Controller			(VGA_HS),
	.VGA_VS_from_the_VGA_Controller			(VGA_VS),
	.VGA_BLANK_from_the_VGA_Controller		(VGA_BLANK),
	.VGA_SYNC_from_the_VGA_Controller		(VGA_SYNC),
	.VGA_R_from_the_VGA_Controller			(VGA_R),
	.VGA_G_from_the_VGA_Controller			(VGA_G),
	.VGA_B_from_the_VGA_Controller			(VGA_B),
	
	// the sdram controller
	.sdram_out_clk_clk (DRAM_CLK),
	.sdram_wire_addr			(DRAM_ADDR),         //           sdram_wire_wire.addr
	.sdram_wire_ba           (DRAM_BA),//                                  .ba
	.sdram_wire_cas_n       (DRAM_CAS_N),//                                  .cas_n
	.sdram_wire_cke          (DRAM_CKE),//                                  .cke
	.sdram_wire_cs_n         (DRAM_CS_N),//                                  .cs_n
	.sdram_wire_dq           (DRAM_DQ),//                                  .dq
	.sdram_wire_dqm          (DRAM_DQM),//                                  .dqm
	.sdram_wire_ras_n        (DRAM_RAS_N),//                                  .ras_n
	.sdram_wire_we_n          (DRAM_WE_N),//                                  .we_n
	
	// keyboard input
	.keycode_export(keycode),
	.press_export(press)
	/*
	.usb_DATA(OTG_DATA),    
	 .usb_ADDR(OTG_ADDR),    
	 .usb_RD_N(OTG_RD_N),    
	 .usb_WR_N(OTG_WR_N),    
	 .usb_CS_N(OTG_CS_N),    
	 .usb_RST_N(OTG_RST_N),   
	 .usb_INT(OTG_INT),*/                            //                                  .INT
	//.keycode_export,                       //                           keycode.export
	//.usb_out_clk_clk
);

keyboard			     PS2 (.Clk(CLOCK_50), 
								.psClk(PS2_CLK), 
								.psData(PS2_DAT), 
								 .keycode(keycode),
								 .press(press),
								 .Reset(Reset_h)
								);

endmodule

