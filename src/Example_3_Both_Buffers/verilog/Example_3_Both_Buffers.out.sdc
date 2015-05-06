## Generated SDC file "Example_3_Both_Buffers.out.sdc"

## Copyright (C) 1991-2014 Altera Corporation. All rights reserved.
## Your use of Altera Corporation's design tools, logic functions 
## and other software and tools, and its AMPP partner logic 
## functions, and any output files from any of the foregoing 
## (including device programming or simulation files), and any 
## associated documentation or information are expressly subject 
## to the terms and conditions of the Altera Program License 
## Subscription Agreement, the Altera Quartus II License Agreement,
## the Altera MegaCore Function License Agreement, or other 
## applicable license agreement, including, without limitation, 
## that your use is for the sole purpose of programming logic 
## devices manufactured by Altera and sold by Altera or its 
## authorized distributors.  Please refer to the applicable 
## agreement for further details.


## VENDOR  "Altera"
## PROGRAM "Quartus II"
## VERSION "Version 14.0.0 Build 200 06/17/2014 SJ Web Edition"

## DATE    "Sun May  3 19:37:03 2015"

##
## DEVICE  "EP4CE115F29C7"
##


#**************************************************************
# Time Information
#**************************************************************

set_time_format -unit ns -decimal_places 3



#**************************************************************
# Create Clock
#**************************************************************

create_clock -name {altera_reserved_tck} -period 100.000 -waveform { 0.000 50.000 } [get_ports {altera_reserved_tck}]


#**************************************************************
# Create Generated Clock
#**************************************************************



#**************************************************************
# Set Clock Latency
#**************************************************************



#**************************************************************
# Set Clock Uncertainty
#**************************************************************



#**************************************************************
# Set Input Delay
#**************************************************************



#**************************************************************
# Set Output Delay
#**************************************************************



#**************************************************************
# Set Clock Groups
#**************************************************************

set_clock_groups -asynchronous -group [get_clocks {altera_reserved_tck}] 


#**************************************************************
# Set False Path
#**************************************************************

set_false_path -from [get_registers {*altera_avalon_st_clock_crosser:*|in_data_buffer*}] -to [get_registers {*altera_avalon_st_clock_crosser:*|out_data_buffer*}]
set_false_path -to [get_keepers {*altera_std_synchronizer:*|din_s1}]
set_false_path -from [get_keepers {*rdptr_g*}] -to [get_keepers {*ws_dgrp|dffpipe_2v8:dffpipe16|dffe17a*}]
set_false_path -from [get_keepers {*delayed_wrptr_g*}] -to [get_keepers {*rs_dgwp|dffpipe_1v8:dffpipe12|dffe13a*}]
set_false_path -to [get_pins -nocase -compatibility_mode {*|alt_rst_sync_uq1|altera_reset_synchronizer_int_chain*|clrn}]
set_false_path -from [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_nios2_oci_break:the_Video_System_CPU_nios2_oci_break|break_readreg*}] -to [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_jtag_debug_module_wrapper:the_Video_System_CPU_jtag_debug_module_wrapper|Video_System_CPU_jtag_debug_module_tck:the_Video_System_CPU_jtag_debug_module_tck|*sr*}]
set_false_path -from [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_nios2_oci_debug:the_Video_System_CPU_nios2_oci_debug|*resetlatch}] -to [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_jtag_debug_module_wrapper:the_Video_System_CPU_jtag_debug_module_wrapper|Video_System_CPU_jtag_debug_module_tck:the_Video_System_CPU_jtag_debug_module_tck|*sr[33]}]
set_false_path -from [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_nios2_oci_debug:the_Video_System_CPU_nios2_oci_debug|monitor_ready}] -to [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_jtag_debug_module_wrapper:the_Video_System_CPU_jtag_debug_module_wrapper|Video_System_CPU_jtag_debug_module_tck:the_Video_System_CPU_jtag_debug_module_tck|*sr[0]}]
set_false_path -from [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_nios2_oci_debug:the_Video_System_CPU_nios2_oci_debug|monitor_error}] -to [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_jtag_debug_module_wrapper:the_Video_System_CPU_jtag_debug_module_wrapper|Video_System_CPU_jtag_debug_module_tck:the_Video_System_CPU_jtag_debug_module_tck|*sr[34]}]
set_false_path -from [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_nios2_ocimem:the_Video_System_CPU_nios2_ocimem|*MonDReg*}] -to [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_jtag_debug_module_wrapper:the_Video_System_CPU_jtag_debug_module_wrapper|Video_System_CPU_jtag_debug_module_tck:the_Video_System_CPU_jtag_debug_module_tck|*sr*}]
set_false_path -from [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_jtag_debug_module_wrapper:the_Video_System_CPU_jtag_debug_module_wrapper|Video_System_CPU_jtag_debug_module_tck:the_Video_System_CPU_jtag_debug_module_tck|*sr*}] -to [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_jtag_debug_module_wrapper:the_Video_System_CPU_jtag_debug_module_wrapper|Video_System_CPU_jtag_debug_module_sysclk:the_Video_System_CPU_jtag_debug_module_sysclk|*jdo*}]
set_false_path -from [get_keepers {sld_hub:*|irf_reg*}] -to [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_jtag_debug_module_wrapper:the_Video_System_CPU_jtag_debug_module_wrapper|Video_System_CPU_jtag_debug_module_sysclk:the_Video_System_CPU_jtag_debug_module_sysclk|ir*}]
set_false_path -from [get_keepers {sld_hub:*|sld_shadow_jsm:shadow_jsm|state[1]}] -to [get_keepers {*Video_System_CPU:*|Video_System_CPU_nios2_oci:the_Video_System_CPU_nios2_oci|Video_System_CPU_nios2_oci_debug:the_Video_System_CPU_nios2_oci_debug|monitor_go}]


#**************************************************************
# Set Multicycle Path
#**************************************************************



#**************************************************************
# Set Maximum Delay
#**************************************************************



#**************************************************************
# Set Minimum Delay
#**************************************************************



#**************************************************************
# Set Input Transition
#**************************************************************

