/*
 * Generated by Bluespec Compiler, version 2023.07-31-ge4361d91 (build e4361d91)
 * 
 * On Tue May 14 00:48:12 EDT 2024
 * 
 */

/* Generation options: */
#ifndef __mkScoreboard_h__
#define __mkScoreboard_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"


/* Class declaration for the mkScoreboard module */
class MOD_mkScoreboard : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Wire<tUInt8> INST_buff_0_port_0;
  MOD_Wire<tUInt8> INST_buff_0_port_1;
  MOD_Wire<tUInt8> INST_buff_0_port_2;
  MOD_Wire<tUInt8> INST_buff_0_port_3;
  MOD_Wire<tUInt8> INST_buff_0_port_4;
  MOD_Wire<tUInt8> INST_buff_0_port_5;
  MOD_Reg<tUInt8> INST_buff_0_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_0_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_0_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_0_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_0_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_0_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_0_register;
  MOD_Wire<tUInt8> INST_buff_10_port_0;
  MOD_Wire<tUInt8> INST_buff_10_port_1;
  MOD_Wire<tUInt8> INST_buff_10_port_2;
  MOD_Wire<tUInt8> INST_buff_10_port_3;
  MOD_Wire<tUInt8> INST_buff_10_port_4;
  MOD_Wire<tUInt8> INST_buff_10_port_5;
  MOD_Reg<tUInt8> INST_buff_10_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_10_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_10_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_10_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_10_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_10_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_10_register;
  MOD_Wire<tUInt8> INST_buff_11_port_0;
  MOD_Wire<tUInt8> INST_buff_11_port_1;
  MOD_Wire<tUInt8> INST_buff_11_port_2;
  MOD_Wire<tUInt8> INST_buff_11_port_3;
  MOD_Wire<tUInt8> INST_buff_11_port_4;
  MOD_Wire<tUInt8> INST_buff_11_port_5;
  MOD_Reg<tUInt8> INST_buff_11_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_11_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_11_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_11_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_11_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_11_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_11_register;
  MOD_Wire<tUInt8> INST_buff_12_port_0;
  MOD_Wire<tUInt8> INST_buff_12_port_1;
  MOD_Wire<tUInt8> INST_buff_12_port_2;
  MOD_Wire<tUInt8> INST_buff_12_port_3;
  MOD_Wire<tUInt8> INST_buff_12_port_4;
  MOD_Wire<tUInt8> INST_buff_12_port_5;
  MOD_Reg<tUInt8> INST_buff_12_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_12_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_12_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_12_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_12_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_12_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_12_register;
  MOD_Wire<tUInt8> INST_buff_13_port_0;
  MOD_Wire<tUInt8> INST_buff_13_port_1;
  MOD_Wire<tUInt8> INST_buff_13_port_2;
  MOD_Wire<tUInt8> INST_buff_13_port_3;
  MOD_Wire<tUInt8> INST_buff_13_port_4;
  MOD_Wire<tUInt8> INST_buff_13_port_5;
  MOD_Reg<tUInt8> INST_buff_13_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_13_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_13_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_13_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_13_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_13_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_13_register;
  MOD_Wire<tUInt8> INST_buff_14_port_0;
  MOD_Wire<tUInt8> INST_buff_14_port_1;
  MOD_Wire<tUInt8> INST_buff_14_port_2;
  MOD_Wire<tUInt8> INST_buff_14_port_3;
  MOD_Wire<tUInt8> INST_buff_14_port_4;
  MOD_Wire<tUInt8> INST_buff_14_port_5;
  MOD_Reg<tUInt8> INST_buff_14_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_14_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_14_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_14_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_14_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_14_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_14_register;
  MOD_Wire<tUInt8> INST_buff_15_port_0;
  MOD_Wire<tUInt8> INST_buff_15_port_1;
  MOD_Wire<tUInt8> INST_buff_15_port_2;
  MOD_Wire<tUInt8> INST_buff_15_port_3;
  MOD_Wire<tUInt8> INST_buff_15_port_4;
  MOD_Wire<tUInt8> INST_buff_15_port_5;
  MOD_Reg<tUInt8> INST_buff_15_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_15_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_15_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_15_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_15_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_15_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_15_register;
  MOD_Wire<tUInt8> INST_buff_16_port_0;
  MOD_Wire<tUInt8> INST_buff_16_port_1;
  MOD_Wire<tUInt8> INST_buff_16_port_2;
  MOD_Wire<tUInt8> INST_buff_16_port_3;
  MOD_Wire<tUInt8> INST_buff_16_port_4;
  MOD_Wire<tUInt8> INST_buff_16_port_5;
  MOD_Reg<tUInt8> INST_buff_16_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_16_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_16_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_16_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_16_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_16_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_16_register;
  MOD_Wire<tUInt8> INST_buff_17_port_0;
  MOD_Wire<tUInt8> INST_buff_17_port_1;
  MOD_Wire<tUInt8> INST_buff_17_port_2;
  MOD_Wire<tUInt8> INST_buff_17_port_3;
  MOD_Wire<tUInt8> INST_buff_17_port_4;
  MOD_Wire<tUInt8> INST_buff_17_port_5;
  MOD_Reg<tUInt8> INST_buff_17_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_17_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_17_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_17_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_17_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_17_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_17_register;
  MOD_Wire<tUInt8> INST_buff_18_port_0;
  MOD_Wire<tUInt8> INST_buff_18_port_1;
  MOD_Wire<tUInt8> INST_buff_18_port_2;
  MOD_Wire<tUInt8> INST_buff_18_port_3;
  MOD_Wire<tUInt8> INST_buff_18_port_4;
  MOD_Wire<tUInt8> INST_buff_18_port_5;
  MOD_Reg<tUInt8> INST_buff_18_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_18_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_18_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_18_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_18_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_18_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_18_register;
  MOD_Wire<tUInt8> INST_buff_19_port_0;
  MOD_Wire<tUInt8> INST_buff_19_port_1;
  MOD_Wire<tUInt8> INST_buff_19_port_2;
  MOD_Wire<tUInt8> INST_buff_19_port_3;
  MOD_Wire<tUInt8> INST_buff_19_port_4;
  MOD_Wire<tUInt8> INST_buff_19_port_5;
  MOD_Reg<tUInt8> INST_buff_19_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_19_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_19_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_19_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_19_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_19_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_19_register;
  MOD_Wire<tUInt8> INST_buff_1_port_0;
  MOD_Wire<tUInt8> INST_buff_1_port_1;
  MOD_Wire<tUInt8> INST_buff_1_port_2;
  MOD_Wire<tUInt8> INST_buff_1_port_3;
  MOD_Wire<tUInt8> INST_buff_1_port_4;
  MOD_Wire<tUInt8> INST_buff_1_port_5;
  MOD_Reg<tUInt8> INST_buff_1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_1_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_1_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_1_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_1_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_1_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_1_register;
  MOD_Wire<tUInt8> INST_buff_20_port_0;
  MOD_Wire<tUInt8> INST_buff_20_port_1;
  MOD_Wire<tUInt8> INST_buff_20_port_2;
  MOD_Wire<tUInt8> INST_buff_20_port_3;
  MOD_Wire<tUInt8> INST_buff_20_port_4;
  MOD_Wire<tUInt8> INST_buff_20_port_5;
  MOD_Reg<tUInt8> INST_buff_20_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_20_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_20_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_20_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_20_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_20_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_20_register;
  MOD_Wire<tUInt8> INST_buff_21_port_0;
  MOD_Wire<tUInt8> INST_buff_21_port_1;
  MOD_Wire<tUInt8> INST_buff_21_port_2;
  MOD_Wire<tUInt8> INST_buff_21_port_3;
  MOD_Wire<tUInt8> INST_buff_21_port_4;
  MOD_Wire<tUInt8> INST_buff_21_port_5;
  MOD_Reg<tUInt8> INST_buff_21_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_21_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_21_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_21_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_21_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_21_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_21_register;
  MOD_Wire<tUInt8> INST_buff_22_port_0;
  MOD_Wire<tUInt8> INST_buff_22_port_1;
  MOD_Wire<tUInt8> INST_buff_22_port_2;
  MOD_Wire<tUInt8> INST_buff_22_port_3;
  MOD_Wire<tUInt8> INST_buff_22_port_4;
  MOD_Wire<tUInt8> INST_buff_22_port_5;
  MOD_Reg<tUInt8> INST_buff_22_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_22_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_22_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_22_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_22_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_22_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_22_register;
  MOD_Wire<tUInt8> INST_buff_23_port_0;
  MOD_Wire<tUInt8> INST_buff_23_port_1;
  MOD_Wire<tUInt8> INST_buff_23_port_2;
  MOD_Wire<tUInt8> INST_buff_23_port_3;
  MOD_Wire<tUInt8> INST_buff_23_port_4;
  MOD_Wire<tUInt8> INST_buff_23_port_5;
  MOD_Reg<tUInt8> INST_buff_23_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_23_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_23_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_23_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_23_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_23_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_23_register;
  MOD_Wire<tUInt8> INST_buff_24_port_0;
  MOD_Wire<tUInt8> INST_buff_24_port_1;
  MOD_Wire<tUInt8> INST_buff_24_port_2;
  MOD_Wire<tUInt8> INST_buff_24_port_3;
  MOD_Wire<tUInt8> INST_buff_24_port_4;
  MOD_Wire<tUInt8> INST_buff_24_port_5;
  MOD_Reg<tUInt8> INST_buff_24_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_24_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_24_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_24_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_24_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_24_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_24_register;
  MOD_Wire<tUInt8> INST_buff_25_port_0;
  MOD_Wire<tUInt8> INST_buff_25_port_1;
  MOD_Wire<tUInt8> INST_buff_25_port_2;
  MOD_Wire<tUInt8> INST_buff_25_port_3;
  MOD_Wire<tUInt8> INST_buff_25_port_4;
  MOD_Wire<tUInt8> INST_buff_25_port_5;
  MOD_Reg<tUInt8> INST_buff_25_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_25_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_25_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_25_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_25_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_25_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_25_register;
  MOD_Wire<tUInt8> INST_buff_26_port_0;
  MOD_Wire<tUInt8> INST_buff_26_port_1;
  MOD_Wire<tUInt8> INST_buff_26_port_2;
  MOD_Wire<tUInt8> INST_buff_26_port_3;
  MOD_Wire<tUInt8> INST_buff_26_port_4;
  MOD_Wire<tUInt8> INST_buff_26_port_5;
  MOD_Reg<tUInt8> INST_buff_26_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_26_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_26_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_26_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_26_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_26_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_26_register;
  MOD_Wire<tUInt8> INST_buff_27_port_0;
  MOD_Wire<tUInt8> INST_buff_27_port_1;
  MOD_Wire<tUInt8> INST_buff_27_port_2;
  MOD_Wire<tUInt8> INST_buff_27_port_3;
  MOD_Wire<tUInt8> INST_buff_27_port_4;
  MOD_Wire<tUInt8> INST_buff_27_port_5;
  MOD_Reg<tUInt8> INST_buff_27_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_27_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_27_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_27_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_27_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_27_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_27_register;
  MOD_Wire<tUInt8> INST_buff_28_port_0;
  MOD_Wire<tUInt8> INST_buff_28_port_1;
  MOD_Wire<tUInt8> INST_buff_28_port_2;
  MOD_Wire<tUInt8> INST_buff_28_port_3;
  MOD_Wire<tUInt8> INST_buff_28_port_4;
  MOD_Wire<tUInt8> INST_buff_28_port_5;
  MOD_Reg<tUInt8> INST_buff_28_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_28_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_28_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_28_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_28_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_28_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_28_register;
  MOD_Wire<tUInt8> INST_buff_29_port_0;
  MOD_Wire<tUInt8> INST_buff_29_port_1;
  MOD_Wire<tUInt8> INST_buff_29_port_2;
  MOD_Wire<tUInt8> INST_buff_29_port_3;
  MOD_Wire<tUInt8> INST_buff_29_port_4;
  MOD_Wire<tUInt8> INST_buff_29_port_5;
  MOD_Reg<tUInt8> INST_buff_29_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_29_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_29_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_29_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_29_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_29_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_29_register;
  MOD_Wire<tUInt8> INST_buff_2_port_0;
  MOD_Wire<tUInt8> INST_buff_2_port_1;
  MOD_Wire<tUInt8> INST_buff_2_port_2;
  MOD_Wire<tUInt8> INST_buff_2_port_3;
  MOD_Wire<tUInt8> INST_buff_2_port_4;
  MOD_Wire<tUInt8> INST_buff_2_port_5;
  MOD_Reg<tUInt8> INST_buff_2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_2_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_2_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_2_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_2_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_2_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_2_register;
  MOD_Wire<tUInt8> INST_buff_30_port_0;
  MOD_Wire<tUInt8> INST_buff_30_port_1;
  MOD_Wire<tUInt8> INST_buff_30_port_2;
  MOD_Wire<tUInt8> INST_buff_30_port_3;
  MOD_Wire<tUInt8> INST_buff_30_port_4;
  MOD_Wire<tUInt8> INST_buff_30_port_5;
  MOD_Reg<tUInt8> INST_buff_30_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_30_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_30_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_30_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_30_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_30_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_30_register;
  MOD_Wire<tUInt8> INST_buff_31_port_0;
  MOD_Wire<tUInt8> INST_buff_31_port_1;
  MOD_Wire<tUInt8> INST_buff_31_port_2;
  MOD_Wire<tUInt8> INST_buff_31_port_3;
  MOD_Wire<tUInt8> INST_buff_31_port_4;
  MOD_Wire<tUInt8> INST_buff_31_port_5;
  MOD_Reg<tUInt8> INST_buff_31_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_31_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_31_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_31_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_31_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_31_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_31_register;
  MOD_Wire<tUInt8> INST_buff_3_port_0;
  MOD_Wire<tUInt8> INST_buff_3_port_1;
  MOD_Wire<tUInt8> INST_buff_3_port_2;
  MOD_Wire<tUInt8> INST_buff_3_port_3;
  MOD_Wire<tUInt8> INST_buff_3_port_4;
  MOD_Wire<tUInt8> INST_buff_3_port_5;
  MOD_Reg<tUInt8> INST_buff_3_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_3_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_3_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_3_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_3_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_3_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_3_register;
  MOD_Wire<tUInt8> INST_buff_4_port_0;
  MOD_Wire<tUInt8> INST_buff_4_port_1;
  MOD_Wire<tUInt8> INST_buff_4_port_2;
  MOD_Wire<tUInt8> INST_buff_4_port_3;
  MOD_Wire<tUInt8> INST_buff_4_port_4;
  MOD_Wire<tUInt8> INST_buff_4_port_5;
  MOD_Reg<tUInt8> INST_buff_4_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_4_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_4_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_4_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_4_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_4_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_4_register;
  MOD_Wire<tUInt8> INST_buff_5_port_0;
  MOD_Wire<tUInt8> INST_buff_5_port_1;
  MOD_Wire<tUInt8> INST_buff_5_port_2;
  MOD_Wire<tUInt8> INST_buff_5_port_3;
  MOD_Wire<tUInt8> INST_buff_5_port_4;
  MOD_Wire<tUInt8> INST_buff_5_port_5;
  MOD_Reg<tUInt8> INST_buff_5_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_5_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_5_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_5_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_5_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_5_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_5_register;
  MOD_Wire<tUInt8> INST_buff_6_port_0;
  MOD_Wire<tUInt8> INST_buff_6_port_1;
  MOD_Wire<tUInt8> INST_buff_6_port_2;
  MOD_Wire<tUInt8> INST_buff_6_port_3;
  MOD_Wire<tUInt8> INST_buff_6_port_4;
  MOD_Wire<tUInt8> INST_buff_6_port_5;
  MOD_Reg<tUInt8> INST_buff_6_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_6_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_6_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_6_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_6_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_6_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_6_register;
  MOD_Wire<tUInt8> INST_buff_7_port_0;
  MOD_Wire<tUInt8> INST_buff_7_port_1;
  MOD_Wire<tUInt8> INST_buff_7_port_2;
  MOD_Wire<tUInt8> INST_buff_7_port_3;
  MOD_Wire<tUInt8> INST_buff_7_port_4;
  MOD_Wire<tUInt8> INST_buff_7_port_5;
  MOD_Reg<tUInt8> INST_buff_7_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_7_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_7_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_7_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_7_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_7_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_7_register;
  MOD_Wire<tUInt8> INST_buff_8_port_0;
  MOD_Wire<tUInt8> INST_buff_8_port_1;
  MOD_Wire<tUInt8> INST_buff_8_port_2;
  MOD_Wire<tUInt8> INST_buff_8_port_3;
  MOD_Wire<tUInt8> INST_buff_8_port_4;
  MOD_Wire<tUInt8> INST_buff_8_port_5;
  MOD_Reg<tUInt8> INST_buff_8_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_8_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_8_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_8_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_8_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_8_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_8_register;
  MOD_Wire<tUInt8> INST_buff_9_port_0;
  MOD_Wire<tUInt8> INST_buff_9_port_1;
  MOD_Wire<tUInt8> INST_buff_9_port_2;
  MOD_Wire<tUInt8> INST_buff_9_port_3;
  MOD_Wire<tUInt8> INST_buff_9_port_4;
  MOD_Wire<tUInt8> INST_buff_9_port_5;
  MOD_Reg<tUInt8> INST_buff_9_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_buff_9_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_buff_9_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_buff_9_readBeforeLaterWrites_3;
  MOD_Reg<tUInt8> INST_buff_9_readBeforeLaterWrites_4;
  MOD_Reg<tUInt8> INST_buff_9_readBeforeLaterWrites_5;
  MOD_Reg<tUInt8> INST_buff_9_register;
 
 /* Constructor */
 public:
  MOD_mkScoreboard(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
 
 /* Publicly accessible definitions */
 public:
 
 /* Local definitions */
 private:
  tUInt8 DEF_x_wget__h2451;
  tUInt8 DEF_def__h123068;
  tUInt8 DEF_x_wget__h38333;
  tUInt8 DEF_x_wget__h38287;
  tUInt8 DEF_x_wget__h38241;
  tUInt8 DEF_x_wget__h38195;
  tUInt8 DEF_x_wget__h38149;
  tUInt8 DEF_def__h122824;
  tUInt8 DEF_x_wget__h37140;
  tUInt8 DEF_x_wget__h37094;
  tUInt8 DEF_x_wget__h37048;
  tUInt8 DEF_x_wget__h37002;
  tUInt8 DEF_x_wget__h36956;
  tUInt8 DEF_def__h122580;
  tUInt8 DEF_x_wget__h35947;
  tUInt8 DEF_x_wget__h35901;
  tUInt8 DEF_x_wget__h35855;
  tUInt8 DEF_x_wget__h35809;
  tUInt8 DEF_x_wget__h35763;
  tUInt8 DEF_def__h122336;
  tUInt8 DEF_x_wget__h34754;
  tUInt8 DEF_x_wget__h34708;
  tUInt8 DEF_x_wget__h34662;
  tUInt8 DEF_x_wget__h34616;
  tUInt8 DEF_x_wget__h34570;
  tUInt8 DEF_def__h122092;
  tUInt8 DEF_x_wget__h33561;
  tUInt8 DEF_x_wget__h33515;
  tUInt8 DEF_x_wget__h33469;
  tUInt8 DEF_x_wget__h33423;
  tUInt8 DEF_x_wget__h33377;
  tUInt8 DEF_def__h121848;
  tUInt8 DEF_x_wget__h32368;
  tUInt8 DEF_x_wget__h32322;
  tUInt8 DEF_x_wget__h32276;
  tUInt8 DEF_x_wget__h32230;
  tUInt8 DEF_x_wget__h32184;
  tUInt8 DEF_def__h121604;
  tUInt8 DEF_x_wget__h31175;
  tUInt8 DEF_x_wget__h31129;
  tUInt8 DEF_x_wget__h31083;
  tUInt8 DEF_x_wget__h31037;
  tUInt8 DEF_x_wget__h30991;
  tUInt8 DEF_def__h121360;
  tUInt8 DEF_x_wget__h29982;
  tUInt8 DEF_x_wget__h29936;
  tUInt8 DEF_x_wget__h29890;
  tUInt8 DEF_x_wget__h29844;
  tUInt8 DEF_x_wget__h29798;
  tUInt8 DEF_def__h121116;
  tUInt8 DEF_x_wget__h28789;
  tUInt8 DEF_x_wget__h28743;
  tUInt8 DEF_x_wget__h28697;
  tUInt8 DEF_x_wget__h28651;
  tUInt8 DEF_x_wget__h28605;
  tUInt8 DEF_def__h120872;
  tUInt8 DEF_x_wget__h27596;
  tUInt8 DEF_x_wget__h27550;
  tUInt8 DEF_x_wget__h27504;
  tUInt8 DEF_x_wget__h27458;
  tUInt8 DEF_x_wget__h27412;
  tUInt8 DEF_def__h120628;
  tUInt8 DEF_x_wget__h26403;
  tUInt8 DEF_x_wget__h26357;
  tUInt8 DEF_x_wget__h26311;
  tUInt8 DEF_x_wget__h26265;
  tUInt8 DEF_x_wget__h26219;
  tUInt8 DEF_def__h120384;
  tUInt8 DEF_x_wget__h25210;
  tUInt8 DEF_x_wget__h25164;
  tUInt8 DEF_x_wget__h25118;
  tUInt8 DEF_x_wget__h25072;
  tUInt8 DEF_x_wget__h25026;
  tUInt8 DEF_def__h120140;
  tUInt8 DEF_x_wget__h24017;
  tUInt8 DEF_x_wget__h23971;
  tUInt8 DEF_x_wget__h23925;
  tUInt8 DEF_x_wget__h23879;
  tUInt8 DEF_x_wget__h23833;
  tUInt8 DEF_def__h119896;
  tUInt8 DEF_x_wget__h22824;
  tUInt8 DEF_x_wget__h22778;
  tUInt8 DEF_x_wget__h22732;
  tUInt8 DEF_x_wget__h22686;
  tUInt8 DEF_x_wget__h22640;
  tUInt8 DEF_def__h119652;
  tUInt8 DEF_x_wget__h21631;
  tUInt8 DEF_x_wget__h21585;
  tUInt8 DEF_x_wget__h21539;
  tUInt8 DEF_x_wget__h21493;
  tUInt8 DEF_x_wget__h21447;
  tUInt8 DEF_def__h119408;
  tUInt8 DEF_x_wget__h20438;
  tUInt8 DEF_x_wget__h20392;
  tUInt8 DEF_x_wget__h20346;
  tUInt8 DEF_x_wget__h20300;
  tUInt8 DEF_x_wget__h20254;
  tUInt8 DEF_def__h119164;
  tUInt8 DEF_x_wget__h19245;
  tUInt8 DEF_x_wget__h19199;
  tUInt8 DEF_x_wget__h19153;
  tUInt8 DEF_x_wget__h19107;
  tUInt8 DEF_x_wget__h19061;
  tUInt8 DEF_def__h118920;
  tUInt8 DEF_x_wget__h18052;
  tUInt8 DEF_x_wget__h18006;
  tUInt8 DEF_x_wget__h17960;
  tUInt8 DEF_x_wget__h17914;
  tUInt8 DEF_x_wget__h17868;
  tUInt8 DEF_def__h118676;
  tUInt8 DEF_x_wget__h16859;
  tUInt8 DEF_x_wget__h16813;
  tUInt8 DEF_x_wget__h16767;
  tUInt8 DEF_x_wget__h16721;
  tUInt8 DEF_x_wget__h16675;
  tUInt8 DEF_def__h118432;
  tUInt8 DEF_x_wget__h15666;
  tUInt8 DEF_x_wget__h15620;
  tUInt8 DEF_x_wget__h15574;
  tUInt8 DEF_x_wget__h15528;
  tUInt8 DEF_x_wget__h15482;
  tUInt8 DEF_def__h118188;
  tUInt8 DEF_x_wget__h14473;
  tUInt8 DEF_x_wget__h14427;
  tUInt8 DEF_x_wget__h14381;
  tUInt8 DEF_x_wget__h14335;
  tUInt8 DEF_x_wget__h14289;
  tUInt8 DEF_def__h117944;
  tUInt8 DEF_x_wget__h13280;
  tUInt8 DEF_x_wget__h13234;
  tUInt8 DEF_x_wget__h13188;
  tUInt8 DEF_x_wget__h13142;
  tUInt8 DEF_x_wget__h13096;
  tUInt8 DEF_def__h117700;
  tUInt8 DEF_x_wget__h12087;
  tUInt8 DEF_x_wget__h12041;
  tUInt8 DEF_x_wget__h11995;
  tUInt8 DEF_x_wget__h11949;
  tUInt8 DEF_x_wget__h11903;
  tUInt8 DEF_def__h117456;
  tUInt8 DEF_x_wget__h10894;
  tUInt8 DEF_x_wget__h10848;
  tUInt8 DEF_x_wget__h10802;
  tUInt8 DEF_x_wget__h10756;
  tUInt8 DEF_x_wget__h10710;
  tUInt8 DEF_def__h117212;
  tUInt8 DEF_x_wget__h9701;
  tUInt8 DEF_x_wget__h9655;
  tUInt8 DEF_x_wget__h9609;
  tUInt8 DEF_x_wget__h9563;
  tUInt8 DEF_x_wget__h9517;
  tUInt8 DEF_def__h116968;
  tUInt8 DEF_x_wget__h8508;
  tUInt8 DEF_x_wget__h8462;
  tUInt8 DEF_x_wget__h8416;
  tUInt8 DEF_x_wget__h8370;
  tUInt8 DEF_x_wget__h8324;
  tUInt8 DEF_def__h116724;
  tUInt8 DEF_x_wget__h7315;
  tUInt8 DEF_x_wget__h7269;
  tUInt8 DEF_x_wget__h7223;
  tUInt8 DEF_x_wget__h7177;
  tUInt8 DEF_x_wget__h7131;
  tUInt8 DEF_def__h116480;
  tUInt8 DEF_x_wget__h6122;
  tUInt8 DEF_x_wget__h6076;
  tUInt8 DEF_x_wget__h6030;
  tUInt8 DEF_x_wget__h5984;
  tUInt8 DEF_x_wget__h5938;
  tUInt8 DEF_def__h116236;
  tUInt8 DEF_x_wget__h4929;
  tUInt8 DEF_x_wget__h4883;
  tUInt8 DEF_x_wget__h4837;
  tUInt8 DEF_x_wget__h4791;
  tUInt8 DEF_x_wget__h4745;
  tUInt8 DEF_def__h115992;
  tUInt8 DEF_x_wget__h3736;
  tUInt8 DEF_x_wget__h3690;
  tUInt8 DEF_x_wget__h3644;
  tUInt8 DEF_x_wget__h3598;
  tUInt8 DEF_x_wget__h3552;
  tUInt8 DEF_def__h115748;
  tUInt8 DEF_x_wget__h2543;
  tUInt8 DEF_x_wget__h2497;
  tUInt8 DEF_x_wget__h2405;
  tUInt8 DEF_x_wget__h2359;
  tUInt8 DEF_def__h115504;
  tUInt8 DEF_x_wget__h1342;
  tUInt8 DEF_x_wget__h1293;
  tUInt8 DEF_x_wget__h1244;
  tUInt8 DEF_x_wget__h1195;
  tUInt8 DEF_x_wget__h1146;
  tUInt8 DEF_n__read__h108075;
  tUInt8 DEF_n__read__h108077;
  tUInt8 DEF_n__read__h108079;
  tUInt8 DEF_n__read__h108081;
  tUInt8 DEF_n__read__h108083;
  tUInt8 DEF_n__read__h108085;
  tUInt8 DEF_n__read__h108087;
  tUInt8 DEF_n__read__h108089;
  tUInt8 DEF_n__read__h108091;
  tUInt8 DEF_n__read__h108093;
  tUInt8 DEF_n__read__h108095;
  tUInt8 DEF_n__read__h108097;
  tUInt8 DEF_n__read__h108099;
  tUInt8 DEF_n__read__h108101;
  tUInt8 DEF_n__read__h108103;
  tUInt8 DEF_n__read__h108105;
  tUInt8 DEF_n__read__h108107;
  tUInt8 DEF_n__read__h108109;
  tUInt8 DEF_n__read__h108111;
  tUInt8 DEF_n__read__h108113;
  tUInt8 DEF_n__read__h108115;
  tUInt8 DEF_n__read__h108117;
  tUInt8 DEF_n__read__h108119;
  tUInt8 DEF_n__read__h108121;
  tUInt8 DEF_n__read__h108123;
  tUInt8 DEF_n__read__h108125;
  tUInt8 DEF_n__read__h108127;
  tUInt8 DEF_n__read__h108129;
  tUInt8 DEF_n__read__h108131;
  tUInt8 DEF_n__read__h108133;
  tUInt8 DEF_n__read__h108135;
  tUInt8 DEF_n__read__h108137;
  tUInt8 DEF_n__read__h43361;
  tUInt8 DEF_n__read__h43363;
  tUInt8 DEF_n__read__h43365;
  tUInt8 DEF_n__read__h43367;
  tUInt8 DEF_n__read__h43369;
  tUInt8 DEF_n__read__h43371;
  tUInt8 DEF_n__read__h43373;
  tUInt8 DEF_n__read__h43375;
  tUInt8 DEF_n__read__h43377;
  tUInt8 DEF_n__read__h43379;
  tUInt8 DEF_n__read__h43381;
  tUInt8 DEF_n__read__h43383;
  tUInt8 DEF_n__read__h43385;
  tUInt8 DEF_n__read__h43387;
  tUInt8 DEF_n__read__h43389;
  tUInt8 DEF_n__read__h43391;
  tUInt8 DEF_n__read__h43393;
  tUInt8 DEF_n__read__h43395;
  tUInt8 DEF_n__read__h43397;
  tUInt8 DEF_n__read__h43399;
  tUInt8 DEF_n__read__h43401;
  tUInt8 DEF_n__read__h43403;
  tUInt8 DEF_n__read__h43405;
  tUInt8 DEF_n__read__h43407;
  tUInt8 DEF_n__read__h43409;
  tUInt8 DEF_n__read__h43411;
  tUInt8 DEF_n__read__h43413;
  tUInt8 DEF_n__read__h43415;
  tUInt8 DEF_n__read__h43417;
  tUInt8 DEF_n__read__h43419;
  tUInt8 DEF_n__read__h43421;
  tUInt8 DEF_n__read__h43423;
  tUInt8 DEF_def__h39126;
  tUInt8 DEF_def__h37933;
  tUInt8 DEF_def__h36740;
  tUInt8 DEF_def__h35547;
  tUInt8 DEF_def__h34354;
  tUInt8 DEF_def__h33161;
  tUInt8 DEF_def__h31968;
  tUInt8 DEF_def__h30775;
  tUInt8 DEF_def__h29582;
  tUInt8 DEF_def__h28389;
  tUInt8 DEF_def__h27196;
  tUInt8 DEF_def__h26003;
  tUInt8 DEF_def__h24810;
  tUInt8 DEF_def__h23617;
  tUInt8 DEF_def__h22424;
  tUInt8 DEF_def__h21231;
  tUInt8 DEF_def__h20038;
  tUInt8 DEF_def__h18845;
  tUInt8 DEF_def__h17652;
  tUInt8 DEF_def__h16459;
  tUInt8 DEF_def__h15266;
  tUInt8 DEF_def__h14073;
  tUInt8 DEF_def__h12880;
  tUInt8 DEF_def__h11687;
  tUInt8 DEF_def__h10494;
  tUInt8 DEF_def__h9301;
  tUInt8 DEF_def__h8108;
  tUInt8 DEF_def__h6915;
  tUInt8 DEF_def__h5722;
  tUInt8 DEF_def__h4529;
  tUInt8 DEF_def__h3336;
  tUInt8 DEF_def__h2143;
  tUInt8 DEF_def__h39144;
  tUInt8 DEF_def__h37951;
  tUInt8 DEF_def__h36758;
  tUInt8 DEF_def__h35565;
  tUInt8 DEF_def__h34372;
  tUInt8 DEF_def__h33179;
  tUInt8 DEF_def__h31986;
  tUInt8 DEF_def__h30793;
  tUInt8 DEF_def__h29600;
  tUInt8 DEF_def__h28407;
  tUInt8 DEF_def__h27214;
  tUInt8 DEF_def__h26021;
  tUInt8 DEF_def__h24828;
  tUInt8 DEF_def__h23635;
  tUInt8 DEF_def__h22442;
  tUInt8 DEF_def__h21249;
  tUInt8 DEF_def__h20056;
  tUInt8 DEF_def__h18863;
  tUInt8 DEF_def__h17670;
  tUInt8 DEF_def__h16477;
  tUInt8 DEF_def__h15284;
  tUInt8 DEF_def__h14091;
  tUInt8 DEF_def__h12898;
  tUInt8 DEF_def__h11705;
  tUInt8 DEF_def__h10512;
  tUInt8 DEF_def__h9319;
  tUInt8 DEF_def__h8126;
  tUInt8 DEF_def__h6933;
  tUInt8 DEF_def__h5740;
  tUInt8 DEF_def__h4547;
  tUInt8 DEF_def__h3354;
  tUInt8 DEF_def__h2161;
  tUInt8 DEF_def__h39162;
  tUInt8 DEF_def__h37969;
  tUInt8 DEF_def__h36776;
  tUInt8 DEF_def__h35583;
  tUInt8 DEF_def__h34390;
  tUInt8 DEF_def__h33197;
  tUInt8 DEF_def__h32004;
  tUInt8 DEF_def__h30811;
  tUInt8 DEF_def__h29618;
  tUInt8 DEF_def__h28425;
  tUInt8 DEF_def__h27232;
  tUInt8 DEF_def__h26039;
  tUInt8 DEF_def__h24846;
  tUInt8 DEF_def__h23653;
  tUInt8 DEF_def__h22460;
  tUInt8 DEF_def__h21267;
  tUInt8 DEF_def__h20074;
  tUInt8 DEF_def__h18881;
  tUInt8 DEF_def__h17688;
  tUInt8 DEF_def__h16495;
  tUInt8 DEF_def__h15302;
  tUInt8 DEF_def__h14109;
  tUInt8 DEF_def__h12916;
  tUInt8 DEF_def__h11723;
  tUInt8 DEF_def__h10530;
  tUInt8 DEF_def__h9337;
  tUInt8 DEF_def__h8144;
  tUInt8 DEF_def__h6951;
  tUInt8 DEF_def__h5758;
  tUInt8 DEF_def__h4565;
  tUInt8 DEF_def__h3372;
  tUInt8 DEF_def__h2179;
  tUInt8 DEF_def__h39108;
  tUInt8 DEF_def__h38906;
  tUInt8 DEF_def__h37915;
  tUInt8 DEF_def__h37713;
  tUInt8 DEF_def__h36722;
  tUInt8 DEF_def__h36520;
  tUInt8 DEF_def__h35529;
  tUInt8 DEF_def__h35327;
  tUInt8 DEF_def__h34336;
  tUInt8 DEF_def__h34134;
  tUInt8 DEF_def__h33143;
  tUInt8 DEF_def__h32941;
  tUInt8 DEF_def__h31950;
  tUInt8 DEF_def__h31748;
  tUInt8 DEF_def__h30757;
  tUInt8 DEF_def__h30555;
  tUInt8 DEF_def__h29564;
  tUInt8 DEF_def__h29362;
  tUInt8 DEF_def__h28371;
  tUInt8 DEF_def__h28169;
  tUInt8 DEF_def__h27178;
  tUInt8 DEF_def__h26976;
  tUInt8 DEF_def__h25985;
  tUInt8 DEF_def__h25783;
  tUInt8 DEF_def__h24792;
  tUInt8 DEF_def__h24590;
  tUInt8 DEF_def__h23599;
  tUInt8 DEF_def__h23397;
  tUInt8 DEF_def__h22406;
  tUInt8 DEF_def__h22204;
  tUInt8 DEF_def__h21213;
  tUInt8 DEF_def__h21011;
  tUInt8 DEF_def__h20020;
  tUInt8 DEF_def__h19818;
  tUInt8 DEF_def__h18827;
  tUInt8 DEF_def__h18625;
  tUInt8 DEF_def__h17634;
  tUInt8 DEF_def__h17432;
  tUInt8 DEF_def__h16441;
  tUInt8 DEF_def__h16239;
  tUInt8 DEF_def__h15248;
  tUInt8 DEF_def__h15046;
  tUInt8 DEF_def__h14055;
  tUInt8 DEF_def__h13853;
  tUInt8 DEF_def__h12862;
  tUInt8 DEF_def__h12660;
  tUInt8 DEF_def__h11669;
  tUInt8 DEF_def__h11467;
  tUInt8 DEF_def__h10476;
  tUInt8 DEF_def__h10274;
  tUInt8 DEF_def__h9283;
  tUInt8 DEF_def__h9081;
  tUInt8 DEF_def__h8090;
  tUInt8 DEF_def__h7888;
  tUInt8 DEF_def__h6897;
  tUInt8 DEF_def__h6695;
  tUInt8 DEF_def__h5704;
  tUInt8 DEF_def__h5502;
  tUInt8 DEF_def__h4511;
  tUInt8 DEF_def__h4309;
  tUInt8 DEF_def__h3318;
  tUInt8 DEF_def__h3116;
  tUInt8 DEF_def__h2125;
  tUInt8 DEF_def__h1923;
 
 /* Rules */
 public:
  void RL_buff_0_canonicalize();
  void RL_buff_1_canonicalize();
  void RL_buff_2_canonicalize();
  void RL_buff_3_canonicalize();
  void RL_buff_4_canonicalize();
  void RL_buff_5_canonicalize();
  void RL_buff_6_canonicalize();
  void RL_buff_7_canonicalize();
  void RL_buff_8_canonicalize();
  void RL_buff_9_canonicalize();
  void RL_buff_10_canonicalize();
  void RL_buff_11_canonicalize();
  void RL_buff_12_canonicalize();
  void RL_buff_13_canonicalize();
  void RL_buff_14_canonicalize();
  void RL_buff_15_canonicalize();
  void RL_buff_16_canonicalize();
  void RL_buff_17_canonicalize();
  void RL_buff_18_canonicalize();
  void RL_buff_19_canonicalize();
  void RL_buff_20_canonicalize();
  void RL_buff_21_canonicalize();
  void RL_buff_22_canonicalize();
  void RL_buff_23_canonicalize();
  void RL_buff_24_canonicalize();
  void RL_buff_25_canonicalize();
  void RL_buff_26_canonicalize();
  void RL_buff_27_canonicalize();
  void RL_buff_28_canonicalize();
  void RL_buff_29_canonicalize();
  void RL_buff_30_canonicalize();
  void RL_buff_31_canonicalize();
 
 /* Methods */
 public:
  void METH_insert(tUInt8 ARG_insert_dst);
  tUInt8 METH_RDY_insert();
  tUInt8 METH_search1(tUInt8 ARG_search1_src);
  tUInt8 METH_RDY_search1();
  tUInt8 METH_search2(tUInt8 ARG_search2_src);
  tUInt8 METH_RDY_search2();
  void METH_remove1(tUInt8 ARG_remove1_dst);
  tUInt8 METH_RDY_remove1();
  void METH_remove2(tUInt8 ARG_remove2_dst);
  tUInt8 METH_RDY_remove2();
  void METH_remove3(tUInt8 ARG_remove3_dst);
  tUInt8 METH_RDY_remove3();
  void METH_remove4(tUInt8 ARG_remove4_dst);
  tUInt8 METH_RDY_remove4();
  tUInt8 METH_search3(tUInt8 ARG_search3_src);
  tUInt8 METH_RDY_search3();
  tUInt8 METH_search4(tUInt8 ARG_search4_src);
  tUInt8 METH_RDY_search4();
  void METH_insert1(tUInt8 ARG_insert1_dst);
  tUInt8 METH_RDY_insert1();
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkScoreboard &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkScoreboard &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkScoreboard &backing);
};

#endif /* ifndef __mkScoreboard_h__ */
