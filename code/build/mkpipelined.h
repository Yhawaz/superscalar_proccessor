/*
 * Generated by Bluespec Compiler, version 2023.07-31-ge4361d91 (build e4361d91)
 * 
 * On Tue May 14 00:48:12 EDT 2024
 * 
 */

/* Generation options: */
#ifndef __mkpipelined_h__
#define __mkpipelined_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkBRF.h"
#include "mkScoreboard.h"


/* Class declaration for the mkpipelined module */
class MOD_mkpipelined : public Module {
 
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
  MOD_Reg<tUInt64> INST_commit_id;
  MOD_Reg<tUInt32> INST_cycles;
  MOD_Fifo<tUWide> INST_d2e;
  MOD_Wire<tUInt64> INST_dataE_port_0;
  MOD_Wire<tUInt64> INST_dataE_port_1;
  MOD_Wire<tUInt64> INST_dataE_port_2;
  MOD_Reg<tUInt8> INST_dataE_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_dataE_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_dataE_readBeforeLaterWrites_2;
  MOD_Reg<tUInt64> INST_dataE_register;
  MOD_Wire<tUInt64> INST_dataW_port_0;
  MOD_Wire<tUInt64> INST_dataW_port_1;
  MOD_Wire<tUInt64> INST_dataW_port_2;
  MOD_Reg<tUInt8> INST_dataW_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_dataW_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_dataW_readBeforeLaterWrites_2;
  MOD_Reg<tUInt64> INST_dataW_register;
  MOD_Wire<tUInt8> INST_dstE_port_0;
  MOD_Wire<tUInt8> INST_dstE_port_1;
  MOD_Wire<tUInt8> INST_dstE_port_2;
  MOD_Reg<tUInt8> INST_dstE_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_dstE_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_dstE_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_dstE_register;
  MOD_Wire<tUInt8> INST_dstW_port_0;
  MOD_Wire<tUInt8> INST_dstW_port_1;
  MOD_Wire<tUInt8> INST_dstW_port_2;
  MOD_Reg<tUInt8> INST_dstW_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_dstW_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_dstW_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_dstW_register;
  MOD_Fifo<tUWide> INST_e2w;
  MOD_Fifo<tUWide> INST_f2d;
  MOD_Reg<tUInt64> INST_fresh_id;
  MOD_CReg<tUWide> INST_fromDmem_rv;
  MOD_CReg<tUWide> INST_fromImem_rv;
  MOD_CReg<tUWide> INST_fromMMIO_rv;
  MOD_Wire<tUInt8> INST_globalEpoch_port_0;
  MOD_Wire<tUInt8> INST_globalEpoch_port_1;
  MOD_Reg<tUInt8> INST_globalEpoch_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_globalEpoch_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_globalEpoch_register;
  MOD_Reg<tUInt32> INST_lfh;
  MOD_Wire<tUInt8> INST_mispredicted_port_0;
  MOD_Wire<tUInt8> INST_mispredicted_port_1;
  MOD_Reg<tUInt8> INST_mispredicted_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_mispredicted_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_mispredicted_register;
  MOD_Reg<tUInt32> INST_pc;
  MOD_Wire<tUInt32> INST_redirectPc_port_0;
  MOD_Wire<tUInt32> INST_redirectPc_port_1;
  MOD_Reg<tUInt8> INST_redirectPc_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_redirectPc_readBeforeLaterWrites_1;
  MOD_Reg<tUInt32> INST_redirectPc_register;
  MOD_Fifo<tUInt64> INST_retired;
  MOD_mkBRF INST_rf;
  MOD_mkScoreboard INST_sb;
  MOD_Fifo<tUInt64> INST_squashed;
  MOD_Reg<tUInt8> INST_starting;
  MOD_CReg<tUWide> INST_toDmem_rv;
  MOD_CReg<tUWide> INST_toImem_rv;
  MOD_CReg<tUWide> INST_toMMIO_rv;
 
 /* Constructor */
 public:
  MOD_mkpipelined(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUWide PORT_getIResp_a;
  tUWide PORT_getDResp_a;
  tUWide PORT_getMMIOResp_a;
  tUWide PORT_getIReq;
  tUWide PORT_getDReq;
  tUWide PORT_getMMIOReq;
 
 /* Publicly accessible definitions */
 public:
  tUWide DEF_toMMIO_rv_port1__read____d625;
  tUWide DEF_toDmem_rv_port1__read____d621;
  tUWide DEF_toImem_rv_port1__read____d617;
  tUInt8 DEF_d2e_first__84_BIT_112_89_EQ_IF_globalEpoch_rea_ETC___d294;
  tUInt8 DEF_d2e_first__84_BIT_183_96_OR_NOT_d2e_first__84__ETC___d300;
  tUInt8 DEF_d2e_first__84_BIT_183___d296;
  tUInt32 DEF_d2e_first__84_BITS_111_TO_80_01_PLUS_IF_d2e_fi_ETC___d341;
  tUWide DEF_d2e_first____d284;
  tUWide DEF_e2w_first____d541;
  tUWide DEF_fromMMIO_rv_port1__read____d554;
  tUWide DEF_fromMMIO_rv_port0__read____d627;
  tUWide DEF_toMMIO_rv_port0__read____d347;
  tUWide DEF_fromDmem_rv_port1__read____d556;
  tUWide DEF_fromDmem_rv_port0__read____d623;
  tUWide DEF_toDmem_rv_port0__read____d350;
  tUWide DEF_fromImem_rv_port1__read____d127;
  tUWide DEF_fromImem_rv_port0__read____d619;
  tUWide DEF_toImem_rv_port0__read____d105;
  tUInt8 DEF_rs2_idx__h10659;
  tUInt8 DEF_rs1_idx__h10658;
  tUInt8 DEF_currentVal__h15824;
  tUInt8 DEF_sb_search2_fromImem_rv_port1__read__27_BITS_24_ETC___d133;
  tUInt8 DEF_sb_search1_fromImem_rv_port1__read__27_BITS_19_ETC___d131;
  tUInt8 DEF_starting__h8970;
  tUInt32 DEF_d2e_first__84_BITS_111_TO_80___d301;
  tUInt32 DEF_addr__h12962;
  tUInt32 DEF_x__h13153;
  tUInt8 DEF_x__h12629;
  tUInt8 DEF_e2w_first__41_BITS_189_TO_187___d561;
  tUInt8 DEF_d2e_first__84_BIT_212___d302;
  tUInt8 DEF_d2e_first__84_BIT_208___d316;
  tUInt8 DEF_e2w_first__41_BIT_184___d552;
  tUInt8 DEF_e2w_first__41_BIT_116___d542;
  tUInt8 DEF_e2w_first__41_BIT_86___d547;
  tUInt32 DEF_imm__h12956;
  tUInt8 DEF_IF_d2e_first__84_BIT_212_02_THEN_d2e_first__84_ETC___d304;
  tUInt8 DEF_n__read__h12886;
  tUInt8 DEF_e2w_first__41_BITS_84_TO_83_48_EQ_0b0___d549;
  tUInt8 DEF_d2e_first__84_BITS_181_TO_180_97_EQ_0b0___d298;
  tUInt32 DEF_x__h13434;
  tUInt32 DEF_x__h13271;
  tUInt32 DEF_x__h13201;
 
 /* Local definitions */
 private:
  tUWide DEF__0_CONCAT_DONTCARE___d159;
  tUInt8 DEF_d2e_first__84_BIT_213___d285;
  tUInt32 DEF_TASK_fopen___d103;
  tUInt32 DEF_signed_0___d114;
  tUWide DEF_f2d_first____d274;
  tUInt64 DEF_dataW_register___d38;
  tUInt64 DEF_dataW_port_1_wget____d35;
  tUInt64 DEF_dataW_port_0_wget____d37;
  tUInt64 DEF_dataE_register___d28;
  tUInt64 DEF_dataE_port_1_wget____d25;
  tUInt64 DEF_dataE_port_0_wget____d27;
  tUInt32 DEF_currentVal__h15723;
  tUInt32 DEF_x_wget__h2402;
  tUInt32 DEF_x__h7653;
  tUInt32 DEF_lfh___d104;
  tUInt8 DEF_currentVal__h16430;
  tUInt8 DEF_x_wget__h6455;
  tUInt8 DEF_x_wget__h6406;
  tUInt8 DEF_currentVal__h12630;
  tUInt8 DEF_x_wget__h5644;
  tUInt8 DEF_x_wget__h5595;
  tUInt8 DEF_dataW_port_1_whas____d34;
  tUInt8 DEF_dataW_port_0_whas____d36;
  tUInt8 DEF_dataE_port_1_whas____d24;
  tUInt8 DEF_dataE_port_0_whas____d26;
  tUInt8 DEF_mispredicted_register__h9993;
  tUInt8 DEF_x_wget__h1796;
  tUWide DEF_f2d_first__74_BITS_112_TO_48___d275;
  tUInt32 DEF_x__h4408;
  tUInt32 DEF_x__h5375;
  tUInt8 DEF_x__h16429;
  tUInt8 DEF_dataE_register_8_BIT_32___d85;
  tUInt8 DEF_dataW_register_8_BIT_32___d68;
  tUInt32 DEF_IF_dataW_register_8_BIT_32_8_THEN_dataW_regist_ETC___d77;
  tUInt32 DEF_IF_dataE_register_8_BIT_32_5_THEN_dataE_regist_ETC___d94;
  tUInt32 DEF_def__h2710;
  tUInt8 DEF_def__h6830;
  tUInt8 DEF_def__h6023;
  tUInt8 DEF_def__h6948;
  tUInt8 DEF_def__h6141;
  tUInt8 DEF_IF_mispredicted_port_0_whas__7_THEN_mispredict_ETC___d20;
  tUInt8 DEF_def__h2106;
  tUWide DEF_IF_fromImem_rv_port1__read__27_BITS_6_TO_0_60__ETC___d280;
  tUWide DEF_rf_rv1_fromImem_rv_port1__read__27_BITS_19_TO__ETC___d279;
  tUWide DEF_NOT_d2e_first__84_BIT_183_96_61_AND_d2e_first__ETC___d536;
  tUWide DEF_IF_NOT_d2e_first__84_BIT_183_96_61_AND_d2e_fir_ETC___d535;
  tUWide DEF_d2e_first__84_BITS_216_TO_177_33_CONCAT_d2e_fi_ETC___d534;
  tUWide DEF_IF_IF_mispredicted_readBeforeLaterWrites_1_rea_ETC___d124;
  tUWide DEF__16_CONCAT_IF_IF_mispredicted_readBeforeLaterWr_ETC___d121;
  tUWide DEF__1_CONCAT_IF_d2e_first__84_BIT_182_65_THEN_IF_d_ETC___d383;
  tUWide DEF__1_CONCAT_getMMIOResp_a___d626;
  tUWide DEF__1_CONCAT_getDResp_a___d622;
  tUWide DEF__1_CONCAT_getIResp_a___d618;
 
 /* Rules */
 public:
  void RL_globalEpoch_canonicalize();
  void RL_redirectPc_canonicalize();
  void RL_mispredicted_canonicalize();
  void RL_dataE_canonicalize();
  void RL_dataW_canonicalize();
  void RL_dstE_canonicalize();
  void RL_dstW_canonicalize();
  void RL_tick();
  void RL_reset_ehr();
  void RL_do_tic_logging();
  void RL_fetch();
  void RL_decode();
  void RL_set_dstE();
  void RL_execute();
  void RL_set_dstW();
  void RL_writeback();
  void RL_administrative_konata_commit();
  void RL_administrative_konata_flush();
 
 /* Methods */
 public:
  tUWide METH_getIReq();
  tUInt8 METH_RDY_getIReq();
  void METH_getIResp(tUWide ARG_getIResp_a);
  tUInt8 METH_RDY_getIResp();
  tUWide METH_getDReq();
  tUInt8 METH_RDY_getDReq();
  void METH_getDResp(tUWide ARG_getDResp_a);
  tUInt8 METH_RDY_getDResp();
  tUWide METH_getMMIOReq();
  tUInt8 METH_RDY_getMMIOReq();
  void METH_getMMIOResp(tUWide ARG_getMMIOResp_a);
  tUInt8 METH_RDY_getMMIOResp();
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkpipelined &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkpipelined &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkpipelined &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkpipelined &backing);
};

#endif /* ifndef __mkpipelined_h__ */
