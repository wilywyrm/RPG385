	component Video_System is
		port (
			SRAM_DQ_to_and_from_the_Pixel_Buffer : inout std_logic_vector(15 downto 0) := (others => 'X'); -- DQ
			SRAM_ADDR_from_the_Pixel_Buffer      : out   std_logic_vector(19 downto 0);                    -- ADDR
			SRAM_LB_N_from_the_Pixel_Buffer      : out   std_logic;                                        -- LB_N
			SRAM_UB_N_from_the_Pixel_Buffer      : out   std_logic;                                        -- UB_N
			SRAM_CE_N_from_the_Pixel_Buffer      : out   std_logic;                                        -- CE_N
			SRAM_OE_N_from_the_Pixel_Buffer      : out   std_logic;                                        -- OE_N
			SRAM_WE_N_from_the_Pixel_Buffer      : out   std_logic;                                        -- WE_N
			VGA_CLK_from_the_VGA_Controller      : out   std_logic;                                        -- CLK
			VGA_HS_from_the_VGA_Controller       : out   std_logic;                                        -- HS
			VGA_VS_from_the_VGA_Controller       : out   std_logic;                                        -- VS
			VGA_BLANK_from_the_VGA_Controller    : out   std_logic;                                        -- BLANK
			VGA_SYNC_from_the_VGA_Controller     : out   std_logic;                                        -- SYNC
			VGA_R_from_the_VGA_Controller        : out   std_logic_vector(7 downto 0);                     -- R
			VGA_G_from_the_VGA_Controller        : out   std_logic_vector(7 downto 0);                     -- G
			VGA_B_from_the_VGA_Controller        : out   std_logic_vector(7 downto 0);                     -- B
			clk_0                                : in    std_logic                     := 'X';             -- clk
			reset_n                              : in    std_logic                     := 'X';             -- reset_n
			keycode_export                       : in    std_logic_vector(7 downto 0)  := (others => 'X'); -- export
			sdram_out_clk_clk                    : out   std_logic;                                        -- clk
			sdram_wire_addr                      : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_wire_ba                        : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_wire_cas_n                     : out   std_logic;                                        -- cas_n
			sdram_wire_cke                       : out   std_logic;                                        -- cke
			sdram_wire_cs_n                      : out   std_logic;                                        -- cs_n
			sdram_wire_dq                        : inout std_logic_vector(31 downto 0) := (others => 'X'); -- dq
			sdram_wire_dqm                       : out   std_logic_vector(3 downto 0);                     -- dqm
			sdram_wire_ras_n                     : out   std_logic;                                        -- ras_n
			sdram_wire_we_n                      : out   std_logic;                                        -- we_n
			press_export                         : in    std_logic_vector(7 downto 0)  := (others => 'X')  -- export
		);
	end component Video_System;

	u0 : component Video_System
		port map (
			SRAM_DQ_to_and_from_the_Pixel_Buffer => CONNECTED_TO_SRAM_DQ_to_and_from_the_Pixel_Buffer, --   Pixel_Buffer_external_interface.DQ
			SRAM_ADDR_from_the_Pixel_Buffer      => CONNECTED_TO_SRAM_ADDR_from_the_Pixel_Buffer,      --                                  .ADDR
			SRAM_LB_N_from_the_Pixel_Buffer      => CONNECTED_TO_SRAM_LB_N_from_the_Pixel_Buffer,      --                                  .LB_N
			SRAM_UB_N_from_the_Pixel_Buffer      => CONNECTED_TO_SRAM_UB_N_from_the_Pixel_Buffer,      --                                  .UB_N
			SRAM_CE_N_from_the_Pixel_Buffer      => CONNECTED_TO_SRAM_CE_N_from_the_Pixel_Buffer,      --                                  .CE_N
			SRAM_OE_N_from_the_Pixel_Buffer      => CONNECTED_TO_SRAM_OE_N_from_the_Pixel_Buffer,      --                                  .OE_N
			SRAM_WE_N_from_the_Pixel_Buffer      => CONNECTED_TO_SRAM_WE_N_from_the_Pixel_Buffer,      --                                  .WE_N
			VGA_CLK_from_the_VGA_Controller      => CONNECTED_TO_VGA_CLK_from_the_VGA_Controller,      -- VGA_Controller_external_interface.CLK
			VGA_HS_from_the_VGA_Controller       => CONNECTED_TO_VGA_HS_from_the_VGA_Controller,       --                                  .HS
			VGA_VS_from_the_VGA_Controller       => CONNECTED_TO_VGA_VS_from_the_VGA_Controller,       --                                  .VS
			VGA_BLANK_from_the_VGA_Controller    => CONNECTED_TO_VGA_BLANK_from_the_VGA_Controller,    --                                  .BLANK
			VGA_SYNC_from_the_VGA_Controller     => CONNECTED_TO_VGA_SYNC_from_the_VGA_Controller,     --                                  .SYNC
			VGA_R_from_the_VGA_Controller        => CONNECTED_TO_VGA_R_from_the_VGA_Controller,        --                                  .R
			VGA_G_from_the_VGA_Controller        => CONNECTED_TO_VGA_G_from_the_VGA_Controller,        --                                  .G
			VGA_B_from_the_VGA_Controller        => CONNECTED_TO_VGA_B_from_the_VGA_Controller,        --                                  .B
			clk_0                                => CONNECTED_TO_clk_0,                                --                      clk_0_clk_in.clk
			reset_n                              => CONNECTED_TO_reset_n,                              --                clk_0_clk_in_reset.reset_n
			keycode_export                       => CONNECTED_TO_keycode_export,                       --                           keycode.export
			sdram_out_clk_clk                    => CONNECTED_TO_sdram_out_clk_clk,                    --                     sdram_out_clk.clk
			sdram_wire_addr                      => CONNECTED_TO_sdram_wire_addr,                      --                        sdram_wire.addr
			sdram_wire_ba                        => CONNECTED_TO_sdram_wire_ba,                        --                                  .ba
			sdram_wire_cas_n                     => CONNECTED_TO_sdram_wire_cas_n,                     --                                  .cas_n
			sdram_wire_cke                       => CONNECTED_TO_sdram_wire_cke,                       --                                  .cke
			sdram_wire_cs_n                      => CONNECTED_TO_sdram_wire_cs_n,                      --                                  .cs_n
			sdram_wire_dq                        => CONNECTED_TO_sdram_wire_dq,                        --                                  .dq
			sdram_wire_dqm                       => CONNECTED_TO_sdram_wire_dqm,                       --                                  .dqm
			sdram_wire_ras_n                     => CONNECTED_TO_sdram_wire_ras_n,                     --                                  .ras_n
			sdram_wire_we_n                      => CONNECTED_TO_sdram_wire_we_n,                      --                                  .we_n
			press_export                         => CONNECTED_TO_press_export                          --                             press.export
		);

