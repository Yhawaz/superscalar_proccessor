/*
 * Generated by Bluespec Compiler, version 2023.07-31-ge4361d91 (build e4361d91)
 * 
 * On Tue May 14 00:48:26 EDT 2024
 * 
 */

/* Generation options: */
#ifndef __mksuperscalar_h__
#define __mksuperscalar_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkBRF.h"
#include "mkScoreboard.h"


/* Class declaration for the mksuperscalar module */
class MOD_mksuperscalar : public Module {
 
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
  MOD_Wire<tUInt64> INST_commit_id_port_0;
  MOD_Wire<tUInt64> INST_commit_id_port_1;
  MOD_Reg<tUInt8> INST_commit_id_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_commit_id_readBeforeLaterWrites_1;
  MOD_Reg<tUInt64> INST_commit_id_register;
  MOD_Reg<tUInt32> INST_cycles;
  MOD_Wire<tUInt8> INST_d2e_dequeueFIFO_port_0;
  MOD_Wire<tUInt8> INST_d2e_dequeueFIFO_port_1;
  MOD_Reg<tUInt8> INST_d2e_dequeueFIFO_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_d2e_dequeueFIFO_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_d2e_dequeueFIFO_register;
  MOD_Wire<tUInt8> INST_d2e_enqueueFIFO_port_0;
  MOD_Wire<tUInt8> INST_d2e_enqueueFIFO_port_1;
  MOD_Reg<tUInt8> INST_d2e_enqueueFIFO_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_d2e_enqueueFIFO_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_d2e_enqueueFIFO_register;
  MOD_Fifo<tUWide> INST_d2e_internalFIFOs_0;
  MOD_Fifo<tUWide> INST_d2e_internalFIFOs_1;
  MOD_Wire<tUInt8> INST_d2e_want_deq1_port_0;
  MOD_Wire<tUInt8> INST_d2e_want_deq1_port_1;
  MOD_Reg<tUInt8> INST_d2e_want_deq1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_d2e_want_deq1_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_d2e_want_deq1_register;
  MOD_Wire<tUInt8> INST_d2e_want_deq2_port_0;
  MOD_Wire<tUInt8> INST_d2e_want_deq2_port_1;
  MOD_Reg<tUInt8> INST_d2e_want_deq2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_d2e_want_deq2_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_d2e_want_deq2_register;
  MOD_Wire<tUWide> INST_d2e_want_enq1_port_0;
  MOD_Wire<tUWide> INST_d2e_want_enq1_port_1;
  MOD_Reg<tUInt8> INST_d2e_want_enq1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_d2e_want_enq1_readBeforeLaterWrites_1;
  MOD_Reg<tUWide> INST_d2e_want_enq1_register;
  MOD_Wire<tUWide> INST_d2e_want_enq2_port_0;
  MOD_Wire<tUWide> INST_d2e_want_enq2_port_1;
  MOD_Reg<tUInt8> INST_d2e_want_enq2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_d2e_want_enq2_readBeforeLaterWrites_1;
  MOD_Reg<tUWide> INST_d2e_want_enq2_register;
  MOD_Wire<tUInt8> INST_decode_1_done_port_0;
  MOD_Wire<tUInt8> INST_decode_1_done_port_1;
  MOD_Reg<tUInt8> INST_decode_1_done_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_decode_1_done_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_decode_1_done_register;
  MOD_Wire<tUInt8> INST_double_retired_port_0;
  MOD_Wire<tUInt8> INST_double_retired_port_1;
  MOD_Reg<tUInt8> INST_double_retired_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_double_retired_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_double_retired_register;
  MOD_Wire<tUInt8> INST_double_squashed_port_0;
  MOD_Wire<tUInt8> INST_double_squashed_port_1;
  MOD_Reg<tUInt8> INST_double_squashed_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_double_squashed_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_double_squashed_register;
  MOD_Wire<tUInt8> INST_e2w_dequeueFIFO_port_0;
  MOD_Wire<tUInt8> INST_e2w_dequeueFIFO_port_1;
  MOD_Reg<tUInt8> INST_e2w_dequeueFIFO_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_e2w_dequeueFIFO_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_e2w_dequeueFIFO_register;
  MOD_Wire<tUInt8> INST_e2w_enqueueFIFO_port_0;
  MOD_Wire<tUInt8> INST_e2w_enqueueFIFO_port_1;
  MOD_Reg<tUInt8> INST_e2w_enqueueFIFO_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_e2w_enqueueFIFO_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_e2w_enqueueFIFO_register;
  MOD_Fifo<tUWide> INST_e2w_internalFIFOs_0;
  MOD_Fifo<tUWide> INST_e2w_internalFIFOs_1;
  MOD_Wire<tUInt8> INST_e2w_want_deq1_port_0;
  MOD_Wire<tUInt8> INST_e2w_want_deq1_port_1;
  MOD_Reg<tUInt8> INST_e2w_want_deq1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_e2w_want_deq1_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_e2w_want_deq1_register;
  MOD_Wire<tUInt8> INST_e2w_want_deq2_port_0;
  MOD_Wire<tUInt8> INST_e2w_want_deq2_port_1;
  MOD_Reg<tUInt8> INST_e2w_want_deq2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_e2w_want_deq2_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_e2w_want_deq2_register;
  MOD_Wire<tUWide> INST_e2w_want_enq1_port_0;
  MOD_Wire<tUWide> INST_e2w_want_enq1_port_1;
  MOD_Reg<tUInt8> INST_e2w_want_enq1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_e2w_want_enq1_readBeforeLaterWrites_1;
  MOD_Reg<tUWide> INST_e2w_want_enq1_register;
  MOD_Wire<tUWide> INST_e2w_want_enq2_port_0;
  MOD_Wire<tUWide> INST_e2w_want_enq2_port_1;
  MOD_Reg<tUInt8> INST_e2w_want_enq2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_e2w_want_enq2_readBeforeLaterWrites_1;
  MOD_Reg<tUWide> INST_e2w_want_enq2_register;
  MOD_Wire<tUInt8> INST_exec_1_alu_port_0;
  MOD_Wire<tUInt8> INST_exec_1_alu_port_1;
  MOD_Reg<tUInt8> INST_exec_1_alu_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_exec_1_alu_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_exec_1_alu_register;
  MOD_Wire<tUInt8> INST_execute_1_done_port_0;
  MOD_Wire<tUInt8> INST_execute_1_done_port_1;
  MOD_Reg<tUInt8> INST_execute_1_done_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_execute_1_done_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_execute_1_done_register;
  MOD_Wire<tUInt8> INST_execute_1_squashed_port_0;
  MOD_Wire<tUInt8> INST_execute_1_squashed_port_1;
  MOD_Reg<tUInt8> INST_execute_1_squashed_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_execute_1_squashed_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_execute_1_squashed_register;
  MOD_Wire<tUInt8> INST_f2d_dequeueFIFO_port_0;
  MOD_Wire<tUInt8> INST_f2d_dequeueFIFO_port_1;
  MOD_Reg<tUInt8> INST_f2d_dequeueFIFO_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_f2d_dequeueFIFO_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_f2d_dequeueFIFO_register;
  MOD_Wire<tUInt8> INST_f2d_enqueueFIFO_port_0;
  MOD_Wire<tUInt8> INST_f2d_enqueueFIFO_port_1;
  MOD_Reg<tUInt8> INST_f2d_enqueueFIFO_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_f2d_enqueueFIFO_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_f2d_enqueueFIFO_register;
  MOD_Fifo<tUWide> INST_f2d_internalFIFOs_0;
  MOD_Fifo<tUWide> INST_f2d_internalFIFOs_1;
  MOD_Wire<tUInt8> INST_f2d_want_deq1_port_0;
  MOD_Wire<tUInt8> INST_f2d_want_deq1_port_1;
  MOD_Reg<tUInt8> INST_f2d_want_deq1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_f2d_want_deq1_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_f2d_want_deq1_register;
  MOD_Wire<tUInt8> INST_f2d_want_deq2_port_0;
  MOD_Wire<tUInt8> INST_f2d_want_deq2_port_1;
  MOD_Reg<tUInt8> INST_f2d_want_deq2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_f2d_want_deq2_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_f2d_want_deq2_register;
  MOD_Wire<tUWide> INST_f2d_want_enq1_port_0;
  MOD_Wire<tUWide> INST_f2d_want_enq1_port_1;
  MOD_Reg<tUInt8> INST_f2d_want_enq1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_f2d_want_enq1_readBeforeLaterWrites_1;
  MOD_Reg<tUWide> INST_f2d_want_enq1_register;
  MOD_Wire<tUWide> INST_f2d_want_enq2_port_0;
  MOD_Wire<tUWide> INST_f2d_want_enq2_port_1;
  MOD_Reg<tUInt8> INST_f2d_want_enq2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_f2d_want_enq2_readBeforeLaterWrites_1;
  MOD_Reg<tUWide> INST_f2d_want_enq2_register;
  MOD_Reg<tUInt64> INST_fresh_id;
  MOD_CReg<tUWide> INST_fromDmem_rv;
  MOD_Wire<tUInt8> INST_fromImem_dequeueFIFO_port_0;
  MOD_Wire<tUInt8> INST_fromImem_dequeueFIFO_port_1;
  MOD_Reg<tUInt8> INST_fromImem_dequeueFIFO_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_fromImem_dequeueFIFO_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_fromImem_dequeueFIFO_register;
  MOD_Wire<tUInt8> INST_fromImem_enqueueFIFO_port_0;
  MOD_Wire<tUInt8> INST_fromImem_enqueueFIFO_port_1;
  MOD_Reg<tUInt8> INST_fromImem_enqueueFIFO_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_fromImem_enqueueFIFO_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_fromImem_enqueueFIFO_register;
  MOD_Fifo<tUWide> INST_fromImem_internalFIFOs_0;
  MOD_Fifo<tUWide> INST_fromImem_internalFIFOs_1;
  MOD_Wire<tUInt8> INST_fromImem_want_deq1_port_0;
  MOD_Wire<tUInt8> INST_fromImem_want_deq1_port_1;
  MOD_Reg<tUInt8> INST_fromImem_want_deq1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_fromImem_want_deq1_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_fromImem_want_deq1_register;
  MOD_Wire<tUInt8> INST_fromImem_want_deq2_port_0;
  MOD_Wire<tUInt8> INST_fromImem_want_deq2_port_1;
  MOD_Reg<tUInt8> INST_fromImem_want_deq2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_fromImem_want_deq2_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_fromImem_want_deq2_register;
  MOD_Wire<tUWide> INST_fromImem_want_enq1_port_0;
  MOD_Wire<tUWide> INST_fromImem_want_enq1_port_1;
  MOD_Reg<tUInt8> INST_fromImem_want_enq1_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_fromImem_want_enq1_readBeforeLaterWrites_1;
  MOD_Reg<tUWide> INST_fromImem_want_enq1_register;
  MOD_Wire<tUWide> INST_fromImem_want_enq2_port_0;
  MOD_Wire<tUWide> INST_fromImem_want_enq2_port_1;
  MOD_Reg<tUInt8> INST_fromImem_want_enq2_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_fromImem_want_enq2_readBeforeLaterWrites_1;
  MOD_Reg<tUWide> INST_fromImem_want_enq2_register;
  MOD_CReg<tUWide> INST_fromMMIO_rv;
  MOD_Wire<tUInt8> INST_globalEpoch_port_0;
  MOD_Wire<tUInt8> INST_globalEpoch_port_1;
  MOD_Wire<tUInt8> INST_globalEpoch_port_2;
  MOD_Reg<tUInt8> INST_globalEpoch_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_globalEpoch_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_globalEpoch_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_globalEpoch_register;
  MOD_Wire<tUInt8> INST_is_mem_inst_port_0;
  MOD_Wire<tUInt8> INST_is_mem_inst_port_1;
  MOD_Reg<tUInt8> INST_is_mem_inst_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_is_mem_inst_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_is_mem_inst_register;
  MOD_Reg<tUInt32> INST_lfh;
  MOD_Wire<tUInt8> INST_mispredicted_port_0;
  MOD_Wire<tUInt8> INST_mispredicted_port_1;
  MOD_Wire<tUInt8> INST_mispredicted_port_2;
  MOD_Reg<tUInt8> INST_mispredicted_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_mispredicted_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_mispredicted_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_mispredicted_register;
  MOD_Reg<tUInt32> INST_pc;
  MOD_Wire<tUInt32> INST_redirectPc_port_0;
  MOD_Wire<tUInt32> INST_redirectPc_port_1;
  MOD_Wire<tUInt32> INST_redirectPc_port_2;
  MOD_Reg<tUInt8> INST_redirectPc_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_redirectPc_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_redirectPc_readBeforeLaterWrites_2;
  MOD_Reg<tUInt32> INST_redirectPc_register;
  MOD_Fifo<tUInt64> INST_retired1;
  MOD_Fifo<tUInt64> INST_retired2;
  MOD_mkBRF INST_rf;
  MOD_mkScoreboard INST_sb;
  MOD_Fifo<tUInt64> INST_squashed1;
  MOD_Fifo<tUInt64> INST_squashed2;
  MOD_Reg<tUInt8> INST_starting;
  MOD_CReg<tUWide> INST_toDmem_rv;
  MOD_CReg<tUWide> INST_toImem_rv;
  MOD_CReg<tUWide> INST_toMMIO_rv;
  MOD_Wire<tUInt8> INST_writeback_1_done_port_0;
  MOD_Wire<tUInt8> INST_writeback_1_done_port_1;
  MOD_Reg<tUInt8> INST_writeback_1_done_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_writeback_1_done_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_writeback_1_done_register;
 
 /* Constructor */
 public:
  MOD_mksuperscalar(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUWide PORT_getIResp_a;
  tUWide PORT_getIResp2_a;
  tUWide PORT_getDResp_a;
  tUWide PORT_getMMIOResp_a;
  tUWide PORT_getIReq;
  tUWide PORT_getDReq;
  tUWide PORT_getMMIOReq;
 
 /* Publicly accessible definitions */
 public:
  tUWide DEF_toMMIO_rv_port1__read____d1822;
  tUWide DEF_toDmem_rv_port1__read____d1818;
  tUWide DEF_toImem_rv_port1__read____d1798;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BIT_112_ETC___d1372;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_20_ETC___d1384;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_20_ETC___d1380;
  tUInt32 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_11_ETC___d1425;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BIT_112_ETC___d1126;
  tUInt8 DEF_f2d_want_enq1_readBeforeLaterWrites_0_read____d635;
  tUInt8 DEF_f2d_want_enq2_readBeforeLaterWrites_0_read____d654;
  tUInt8 DEF_pa_offset__h48252;
  tUInt8 DEF_IF_mispredicted_readBeforeLaterWrites_2_read___ETC___d647;
  tUInt8 DEF_e2w_want_enq2_readBeforeLaterWrites_1_read____d493;
  tUInt8 DEF_e2w_want_enq1_readBeforeLaterWrites_1_read____d464;
  tUInt8 DEF_x__h36945;
  tUInt8 DEF_x__h35046;
  tUInt8 DEF_d2e_want_enq2_readBeforeLaterWrites_1_read____d356;
  tUInt8 DEF_d2e_want_enq1_readBeforeLaterWrites_1_read____d327;
  tUInt8 DEF_x__h26443;
  tUInt8 DEF_x__h24758;
  tUInt8 DEF_f2d_want_enq2_readBeforeLaterWrites_1_read____d217;
  tUInt8 DEF_f2d_want_enq1_readBeforeLaterWrites_1_read____d188;
  tUInt8 DEF_x__h17486;
  tUInt8 DEF_x__h16625;
  tUInt8 DEF_IF_fromImem_want_enq2_port_0_whas__4_THEN_from_ETC___d82;
  tUInt8 DEF_fromImem_want_enq2_readBeforeLaterWrites_1_read____d79;
  tUInt8 DEF_fromImem_want_enq1_readBeforeLaterWrites_1_read____d43;
  tUInt8 DEF_IF_fromImem_want_enq1_port_0_whas__7_THEN_from_ETC___d46;
  tUInt8 DEF_x__h5641;
  tUInt8 DEF_x__h4827;
  tUInt8 DEF_fromImem_want_enq2_readBeforeLaterWrites_0_read____d1810;
  tUInt8 DEF_fromImem_want_enq1_readBeforeLaterWrites_0_read____d1799;
  tUWide DEF_d2e_want_enq2_register___d310;
  tUWide DEF_d2e_want_enq2_port_0_wget____d309;
  tUWide DEF_d2e_want_enq1_register___d303;
  tUWide DEF_d2e_want_enq1_port_0_wget____d302;
  tUWide DEF_d2e_internalFIFOs_1_first____d1118;
  tUWide DEF_d2e_internalFIFOs_0_first____d1116;
  tUWide DEF_e2w_want_enq2_register___d447;
  tUWide DEF_e2w_want_enq2_port_0_wget____d446;
  tUWide DEF_e2w_want_enq1_register___d440;
  tUWide DEF_e2w_want_enq1_port_0_wget____d439;
  tUWide DEF_e2w_internalFIFOs_1_first____d1640;
  tUWide DEF_e2w_internalFIFOs_0_first____d1638;
  tUWide DEF_f2d_want_enq2_register___d171;
  tUWide DEF_f2d_want_enq2_port_0_wget____d170;
  tUWide DEF_f2d_want_enq1_register___d164;
  tUWide DEF_f2d_want_enq1_port_0_wget____d163;
  tUWide DEF_f2d_internalFIFOs_1_first____d695;
  tUWide DEF_f2d_internalFIFOs_0_first____d693;
  tUWide DEF_toImem_rv_port0__read____d643;
  tUWide DEF_fromImem_want_enq2_register___d26;
  tUWide DEF_fromImem_want_enq2_port_0_wget____d25;
  tUWide DEF_fromImem_want_enq1_register___d19;
  tUWide DEF_fromImem_want_enq1_port_0_wget____d18;
  tUWide DEF_fromMMIO_rv_port1__read____d1708;
  tUWide DEF_fromMMIO_rv_port0__read____d1824;
  tUWide DEF_toMMIO_rv_port0__read____d1431;
  tUWide DEF_fromDmem_rv_port1__read____d1710;
  tUWide DEF_fromDmem_rv_port0__read____d1820;
  tUWide DEF_toDmem_rv_port0__read____d1434;
  tUWide DEF_fromImem_internalFIFOs_1_first____d701;
  tUWide DEF_fromImem_internalFIFOs_0_first____d699;
  tUInt32 DEF_currentVal__h63583;
  tUInt32 DEF_x_wget__h10617;
  tUInt32 DEF_x_wget__h10568;
  tUInt8 DEF_rs2_idx__h50940;
  tUInt8 DEF_rs1_idx__h50939;
  tUInt8 DEF_rs2_idx__h53893;
  tUInt8 DEF_rs1_idx__h53892;
  tUInt32 DEF_pc_fetched__h48244;
  tUInt8 DEF_exec_1_alu_register__h43867;
  tUInt8 DEF_exec_1_alu_port_0_whas____d589;
  tUInt8 DEF_exec_1_alu_port_0_wget____d590;
  tUInt8 DEF_writeback_1_done_register__h43250;
  tUInt8 DEF_execute_1_done_register__h42016;
  tUInt8 DEF_decode_1_done_register__h41399;
  tUInt8 DEF_e2w_want_deq2_register__h65281;
  tUInt8 DEF_e2w_want_deq2_port_0_whas____d459;
  tUInt8 DEF_e2w_want_deq2_port_0_wget____d460;
  tUInt8 DEF_e2w_want_deq1_register__h65709;
  tUInt8 DEF_e2w_want_deq1_port_0_whas____d452;
  tUInt8 DEF_e2w_want_deq1_port_0_wget____d453;
  tUInt8 DEF_e2w_want_enq2_readBeforeLaterWrites_0_read____d1152;
  tUInt8 DEF_e2w_want_enq2_port_0_whas____d445;
  tUInt8 DEF_e2w_want_enq1_readBeforeLaterWrites_0_read____d1374;
  tUInt8 DEF_e2w_want_enq1_port_0_whas____d438;
  tUInt8 DEF_def__h39911;
  tUInt8 DEF_def__h38183;
  tUInt8 DEF_d2e_want_deq2_register__h57153;
  tUInt8 DEF_d2e_want_deq2_port_0_whas____d322;
  tUInt8 DEF_d2e_want_deq2_port_0_wget____d323;
  tUInt8 DEF_d2e_want_deq1_register__h60020;
  tUInt8 DEF_d2e_want_deq1_port_0_whas____d315;
  tUInt8 DEF_d2e_want_deq1_port_0_wget____d316;
  tUInt8 DEF_d2e_want_enq2_readBeforeLaterWrites_0_read____d735;
  tUInt8 DEF_d2e_want_enq2_port_0_whas____d308;
  tUInt8 DEF_d2e_want_enq1_readBeforeLaterWrites_0_read____d941;
  tUInt8 DEF_d2e_want_enq1_port_0_whas____d301;
  tUInt8 DEF_def__h29163;
  tUInt8 DEF_def__h27649;
  tUInt8 DEF_f2d_want_deq2_register__h51398;
  tUInt8 DEF_f2d_want_deq2_port_0_whas____d183;
  tUInt8 DEF_f2d_want_deq2_port_0_wget____d184;
  tUInt8 DEF_f2d_want_deq1_register__h54336;
  tUInt8 DEF_f2d_want_deq1_port_0_whas____d176;
  tUInt8 DEF_f2d_want_deq1_port_0_wget____d177;
  tUInt8 DEF_f2d_want_enq2_port_0_whas____d169;
  tUInt8 DEF_f2d_want_enq1_port_0_whas____d162;
  tUInt8 DEF_def__h19172;
  tUInt8 DEF_def__h18482;
  tUInt8 DEF_fromImem_want_deq2_register__h51612;
  tUInt8 DEF_fromImem_want_deq1_register__h54550;
  tUInt8 DEF_fromImem_want_enq2_port_0_whas____d24;
  tUInt8 DEF_fromImem_want_enq1_port_0_whas____d17;
  tUInt8 DEF_fromImem_internalFIFOs_1_i_notEmpty____d688;
  tUInt8 DEF_fromImem_internalFIFOs_1_i_notFull____d1807;
  tUInt8 DEF_fromImem_internalFIFOs_0_i_notEmpty____d687;
  tUInt8 DEF_fromImem_internalFIFOs_0_i_notFull____d1806;
  tUInt8 DEF_def__h7265;
  tUInt8 DEF_def__h6621;
  tUInt8 DEF_mispredicted_register__h47802;
  tUInt8 DEF_currentVal__h63684;
  tUInt8 DEF_x_wget__h9759;
  tUInt8 DEF_sb_search4_IF_SEL_ARR_fromImem_internalFIFOs_0_ETC___d724;
  tUInt8 DEF_sb_search3_IF_SEL_ARR_fromImem_internalFIFOs_0_ETC___d722;
  tUInt8 DEF_sb_search2_IF_SEL_ARR_fromImem_internalFIFOs_0_ETC___d929;
  tUInt8 DEF_sb_search1_IF_SEL_ARR_fromImem_internalFIFOs_0_ETC___d927;
  tUInt8 DEF_starting__h47045;
  tUInt8 DEF_x__h37087;
  tUInt8 DEF_x__h35203;
  tUInt8 DEF_x__h26585;
  tUInt8 DEF_x__h24915;
  tUInt8 DEF_x__h16782;
  tUInt8 DEF_x__h17628;
  tUInt32 DEF_d2e_internalFIFOs_0_first__116_BITS_208_TO_177___d1128;
  tUInt32 DEF_d2e_internalFIFOs_0_first__116_BITS_111_TO_80___d1191;
  tUInt32 DEF_d2e_internalFIFOs_1_first__118_BITS_208_TO_177___d1129;
  tUInt32 DEF_d2e_internalFIFOs_1_first__118_BITS_111_TO_80___d1192;
  tUInt32 DEF_e2w_internalFIFOs_0_first__638_BITS_111_TO_80___d1639;
  tUInt32 DEF_e2w_internalFIFOs_1_first__640_BITS_111_TO_80___d1641;
  tUInt32 DEF_f2d_internalFIFOs_0_first__93_BITS_112_TO_81___d694;
  tUInt32 DEF_f2d_internalFIFOs_1_first__95_BITS_112_TO_81___d696;
  tUInt32 DEF_x_first_addr__h50792;
  tUInt32 DEF_x_first_data__h50793;
  tUInt32 DEF_x_first_addr__h50798;
  tUInt32 DEF_x_first_data__h50799;
  tUInt32 DEF_addr__h60446;
  tUInt32 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_20_ETC___d1379;
  tUInt32 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_20_ETC___d1131;
  tUInt32 DEF_x__h60630;
  tUInt32 DEF_value__h53825;
  tUInt32 DEF_instr__h50937;
  tUInt32 DEF_rs1_val__h63143;
  tUInt8 DEF_x__h57418;
  tUInt32 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BITS_11_ETC___d1697;
  tUInt32 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BITS_11_ETC___d1643;
  tUInt8 DEF_dst__h62878;
  tUInt32 DEF_v__h47502;
  tUInt8 DEF_d2e_want_enq2_register_10_BIT_217___d360;
  tUInt8 DEF_d2e_want_enq2_port_0_wget__09_BIT_217___d358;
  tUInt8 DEF_d2e_want_enq1_register_03_BIT_217___d331;
  tUInt8 DEF_d2e_want_enq1_port_0_wget__02_BIT_217___d329;
  tUInt8 DEF_d2e_internalFIFOs_0_first__116_BIT_212___d1195;
  tUInt8 DEF_d2e_internalFIFOs_0_first__116_BIT_112___d1117;
  tUInt8 DEF_d2e_internalFIFOs_1_first__118_BIT_212___d1196;
  tUInt8 DEF_d2e_internalFIFOs_1_first__118_BIT_112___d1119;
  tUInt8 DEF_e2w_want_enq2_register_47_BIT_190___d497;
  tUInt8 DEF_e2w_want_enq2_port_0_wget__46_BIT_190___d495;
  tUInt8 DEF_e2w_want_enq1_register_40_BIT_190___d468;
  tUInt8 DEF_e2w_want_enq1_port_0_wget__39_BIT_190___d466;
  tUInt8 DEF_e2w_internalFIFOs_0_first__638_BIT_116___d1681;
  tUInt8 DEF_e2w_internalFIFOs_1_first__640_BIT_116___d1682;
  tUInt8 DEF_f2d_want_enq2_register_71_BIT_113___d221;
  tUInt8 DEF_f2d_want_enq2_port_0_wget__70_BIT_113___d219;
  tUInt8 DEF_f2d_want_enq1_register_64_BIT_113___d192;
  tUInt8 DEF_f2d_want_enq1_port_0_wget__63_BIT_113___d190;
  tUInt8 DEF_fromImem_want_enq2_register_6_BIT_68___d81;
  tUInt8 DEF_fromImem_want_enq1_register_9_BIT_68___d45;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BITS_11_ETC___d1698;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BITS_11_ETC___d1644;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_20_ETC___d1400;
  tUInt8 DEF_IF_d2e_internalFIFOs_0_first__116_BIT_212_195__ETC___d1200;
  tUInt8 DEF_IF_d2e_internalFIFOs_1_first__118_BIT_212_196__ETC___d1202;
  tUInt32 DEF_SEL_ARR_fromImem_internalFIFOs_0_first__99_BIT_ETC___d715;
  tUInt32 DEF_SEL_ARR_fromImem_internalFIFOs_0_first__99_BIT_ETC___d920;
  tUInt8 DEF_x__h5783;
  tUInt32 DEF_x_pc__h51911;
  tUInt32 DEF_SEL_ARR_fromImem_internalFIFOs_0_first__99_BIT_ETC___d704;
  tUInt8 DEF_SEL_ARR_IF_d2e_internalFIFOs_0_first__116_BIT__ETC___d1387;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BITS_18_ETC___d1723;
  tUInt8 DEF_x__h4987;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BIT_189_ETC___d1719;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BIT_184_ETC___d1706;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BIT_116_ETC___d1714;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BIT_212_ETC___d1386;
  tUInt8 DEF_x__h56617;
  tUInt8 DEF_x__h60336;
  tUInt8 DEF_SEL_ARR_fromImem_internalFIFOs_0_i_notEmpty__8_ETC___d690;
  tUInt8 DEF_SEL_ARR_fromImem_internalFIFOs_0_i_notEmpty__8_ETC___d917;
  tUInt8 DEF_IF_IF_mispredicted_readBeforeLaterWrites_2_rea_ETC___d653;
  tUInt32 DEF_imm__h60440;
  tUInt32 DEF_y__h50701;
  tUInt32 DEF_v__h47817;
  tUInt32 DEF_def__h10992;
  tUInt32 DEF_def__h11110;
  tUInt8 DEF_y__h60337;
  tUInt8 DEF_y__h56618;
  tUInt8 DEF_def__h10303;
  tUInt8 DEF_IF_mispredicted_port_1_whas__38_THEN_mispredic_ETC___d144;
  tUInt8 DEF_IF_writeback_1_done_port_0_whas__82_THEN_write_ETC___d585;
  tUInt8 DEF_IF_execute_1_done_port_0_whas__68_THEN_execute_ETC___d571;
  tUInt8 DEF_IF_decode_1_done_port_0_whas__61_THEN_decode_1_ETC___d564;
  tUInt8 DEF_SEL_ARR_f2d_internalFIFOs_0_first__93_BITS_112_ETC___d710;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_20_ETC___d1133;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_20_ETC___d1135;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BIT_189_ETC___d1724;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BITS_11_ETC___d1700;
  tUInt8 DEF_SEL_ARR_e2w_internalFIFOs_0_first__638_BITS_11_ETC___d1647;
  tUInt8 DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_20_ETC___d1382;
  tUInt8 DEF_NOT_e2w_want_enq2_readBeforeLaterWrites_1_read_ETC___d494;
  tUInt8 DEF_NOT_e2w_want_enq1_readBeforeLaterWrites_1_read_ETC___d465;
  tUInt8 DEF_NOT_d2e_want_enq2_readBeforeLaterWrites_1_read_ETC___d357;
  tUInt8 DEF_NOT_d2e_want_enq1_readBeforeLaterWrites_1_read_ETC___d328;
  tUInt8 DEF_NOT_f2d_want_enq2_readBeforeLaterWrites_1_read_ETC___d218;
  tUInt8 DEF_NOT_f2d_want_enq1_readBeforeLaterWrites_1_read_ETC___d189;
  tUInt8 DEF_NOT_fromImem_want_enq2_readBeforeLaterWrites_1_ETC___d104;
  tUInt8 DEF_NOT_fromImem_want_enq1_readBeforeLaterWrites_1_ETC___d74;
  tUInt32 DEF_x__h60996;
  tUInt32 DEF_x__h60791;
  tUInt32 DEF_x__h60700;
 
 /* Local definitions */
 private:
  tUInt8 DEF_IF_exec_1_alu_port_0_whas__89_THEN_exec_1_alu__ETC___d592;
  tUWide DEF__dfoo24;
  tUWide DEF_IF_e2w_want_enq1_port_0_whas__38_THEN_e2w_want_ETC___d522;
  tUWide DEF_IF_e2w_want_enq2_port_0_whas__45_THEN_e2w_want_ETC___d544;
  tUWide DEF__dfoo22;
  tUWide DEF__dfoo18;
  tUWide DEF_IF_d2e_want_enq1_port_0_whas__01_THEN_d2e_want_ETC___d385;
  tUWide DEF_IF_d2e_want_enq2_port_0_whas__08_THEN_d2e_want_ETC___d407;
  tUWide DEF__dfoo16;
  tUWide DEF__dfoo12;
  tUWide DEF_IF_f2d_want_enq1_readBeforeLaterWrites_1_read__ETC___d247;
  tUWide DEF_IF_f2d_want_enq2_readBeforeLaterWrites_1_read__ETC___d270;
  tUWide DEF__dfoo10;
  tUWide DEF__dfoo6;
  tUWide DEF_IF_fromImem_want_enq1_readBeforeLaterWrites_1__ETC___d59;
  tUWide DEF_IF_fromImem_want_enq2_readBeforeLaterWrites_1__ETC___d92;
  tUWide DEF__dfoo4;
  tUInt32 DEF_TASK_fopen___d633;
  tUInt32 DEF_signed_1___d1794;
  tUInt32 DEF_signed_0___d680;
  tUWide DEF_d2e_want_enq2_port_1_wget____d307;
  tUWide DEF_d2e_want_enq1_port_1_wget____d300;
  tUWide DEF_e2w_want_enq2_port_1_wget____d444;
  tUWide DEF_e2w_want_enq1_port_1_wget____d437;
  tUWide DEF_f2d_want_enq2_port_1_wget____d168;
  tUWide DEF_f2d_want_enq1_port_1_wget____d161;
  tUWide DEF_fromImem_want_enq2_port_1_wget____d23;
  tUWide DEF_fromImem_want_enq1_port_1_wget____d16;
  tUInt64 DEF_currentVal__h67578;
  tUInt64 DEF_x_wget__h8690;
  tUInt32 DEF_x__h45834;
  tUInt32 DEF_lfh___d634;
  tUInt8 DEF_double_squashed_register__h45718;
  tUInt8 DEF_is_mem_inst_register__h44484;
  tUInt8 DEF_execute_1_squashed_register__h42633;
  tUInt8 DEF_x_wget__h30539;
  tUInt8 DEF_x_wget__h29929;
  tUInt8 DEF_x_wget__h20338;
  tUInt8 DEF_x_wget__h19728;
  tUInt8 DEF_x_wget__h12802;
  tUInt8 DEF_x_wget__h12192;
  tUInt8 DEF_x_wget__h1025;
  tUInt8 DEF_x_wget__h412;
  tUInt8 DEF_x_wget__h9808;
  tUWide DEF_d2e_want_enq2_register_10_BITS_216_TO_0___d406;
  tUWide DEF_d2e_want_enq2_port_0_wget__09_BITS_216_TO_0___d405;
  tUWide DEF_d2e_want_enq1_register_03_BITS_216_TO_0___d384;
  tUWide DEF_d2e_want_enq1_port_0_wget__02_BITS_216_TO_0___d383;
  tUWide DEF_e2w_want_enq2_register_47_BITS_189_TO_0___d543;
  tUWide DEF_e2w_want_enq2_port_0_wget__46_BITS_189_TO_0___d542;
  tUWide DEF_e2w_want_enq1_register_40_BITS_189_TO_0___d521;
  tUWide DEF_e2w_want_enq1_port_0_wget__39_BITS_189_TO_0___d520;
  tUWide DEF_e2w_want_enq2_register_47_BITS_183_TO_0___d1356;
  tUWide DEF_f2d_want_enq2_register_71_BITS_112_TO_0___d268;
  tUWide DEF_f2d_want_enq2_port_0_wget__70_BITS_112_TO_0___d267;
  tUWide DEF_f2d_want_enq1_register_64_BITS_112_TO_0___d245;
  tUWide DEF_f2d_want_enq1_port_0_wget__63_BITS_112_TO_0___d244;
  tUWide DEF_fromImem_want_enq2_register_6_BITS_67_TO_0___d90;
  tUWide DEF_fromImem_want_enq2_port_0_wget__5_BITS_67_TO_0___d89;
  tUWide DEF_fromImem_want_enq1_port_0_wget__8_BITS_67_TO_0___d56;
  tUWide DEF_fromImem_want_enq1_register_9_BITS_67_TO_0___d57;
  tUInt64 DEF_d2e_internalFIFOs_0_first__116_BITS_47_TO_0___d1176;
  tUInt64 DEF_d2e_internalFIFOs_1_first__118_BITS_47_TO_0___d1177;
  tUInt64 DEF_e2w_internalFIFOs_0_first__638_BITS_79_TO_32___d1669;
  tUInt64 DEF_e2w_internalFIFOs_1_first__640_BITS_79_TO_32___d1670;
  tUInt64 DEF_f2d_internalFIFOs_0_first__93_BITS_47_TO_0___d908;
  tUInt64 DEF_f2d_internalFIFOs_1_first__95_BITS_47_TO_0___d909;
  tUInt32 DEF_d2e_internalFIFOs_0_first__116_BITS_176_TO_145___d1180;
  tUInt32 DEF_d2e_internalFIFOs_0_first__116_BITS_79_TO_48___d1257;
  tUInt32 DEF_d2e_internalFIFOs_1_first__118_BITS_176_TO_145___d1181;
  tUInt32 DEF_d2e_internalFIFOs_1_first__118_BITS_79_TO_48___d1258;
  tUInt32 DEF_e2w_internalFIFOs_0_first__638_BITS_151_TO_120___d1687;
  tUInt32 DEF_e2w_internalFIFOs_1_first__640_BITS_151_TO_120___d1688;
  tUInt32 DEF_f2d_internalFIFOs_0_first__93_BITS_80_TO_49___d898;
  tUInt32 DEF_f2d_internalFIFOs_1_first__95_BITS_80_TO_49___d899;
  tUInt8 DEF_d2e_internalFIFOs_0_first__116_BIT_216___d1335;
  tUInt8 DEF_d2e_internalFIFOs_0_first__116_BIT_215___d1339;
  tUInt8 DEF_d2e_internalFIFOs_0_first__116_BIT_214___d1343;
  tUInt8 DEF_d2e_internalFIFOs_0_first__116_BIT_213___d1347;
  tUInt8 DEF_d2e_internalFIFOs_1_first__118_BIT_216___d1336;
  tUInt8 DEF_d2e_internalFIFOs_1_first__118_BIT_215___d1340;
  tUInt8 DEF_d2e_internalFIFOs_1_first__118_BIT_214___d1344;
  tUInt8 DEF_d2e_internalFIFOs_1_first__118_BIT_213___d1348;
  tUInt8 DEF_f2d_internalFIFOs_0_first__93_BIT_48___d902;
  tUInt8 DEF_f2d_internalFIFOs_1_first__95_BIT_48___d903;
  tUInt8 DEF_NOT_e2w_internalFIFOs_0_first__638_BIT_119_674___d1675;
  tUInt8 DEF_NOT_e2w_internalFIFOs_1_first__640_BIT_119_676___d1677;
  tUWide DEF_IF_d2e_want_enq2_port_1_whas__06_THEN_d2e_want_ETC___d312;
  tUWide DEF_IF_d2e_want_enq2_port_0_whas__08_THEN_d2e_want_ETC___d311;
  tUWide DEF_IF_d2e_want_enq1_port_0_whas__01_THEN_d2e_want_ETC___d304;
  tUWide DEF_IF_d2e_want_enq1_port_1_whas__99_THEN_d2e_want_ETC___d305;
  tUWide DEF_IF_d2e_want_enq1_readBeforeLaterWrites_0_read__ETC___d1112;
  tUWide DEF_IF_IF_SEL_ARR_fromImem_internalFIFOs_0_i_notEm_ETC___d1111;
  tUWide DEF_IF_d2e_want_enq2_readBeforeLaterWrites_0_read__ETC___d915;
  tUWide DEF_IF_IF_SEL_ARR_fromImem_internalFIFOs_0_i_notEm_ETC___d914;
  tUWide DEF_IF_e2w_want_enq2_port_1_whas__43_THEN_e2w_want_ETC___d449;
  tUWide DEF_IF_e2w_want_enq2_port_0_whas__45_THEN_e2w_want_ETC___d448;
  tUWide DEF_IF_e2w_want_enq1_port_0_whas__38_THEN_e2w_want_ETC___d441;
  tUWide DEF_IF_e2w_want_enq1_port_1_whas__36_THEN_e2w_want_ETC___d442;
  tUWide DEF_IF_e2w_want_enq1_readBeforeLaterWrites_0_read__ETC___d1634;
  tUWide DEF_NOT_SEL_ARR_d2e_internalFIFOs_0_first__116_BIT_ETC___d1633;
  tUWide DEF_IF_e2w_want_enq2_readBeforeLaterWrites_0_read__ETC___d1357;
  tUWide DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_11_ETC___d1355;
  tUWide DEF_IF_f2d_want_enq2_port_1_whas__67_THEN_f2d_want_ETC___d173;
  tUWide DEF_IF_f2d_want_enq2_port_0_whas__69_THEN_f2d_want_ETC___d172;
  tUWide DEF_IF_f2d_want_enq1_port_0_whas__62_THEN_f2d_want_ETC___d165;
  tUWide DEF_IF_f2d_want_enq1_port_1_whas__60_THEN_f2d_want_ETC___d166;
  tUWide DEF_IF_f2d_want_enq2_readBeforeLaterWrites_0_read__ETC___d685;
  tUWide DEF_IF_IF_mispredicted_readBeforeLaterWrites_2_rea_ETC___d684;
  tUWide DEF_IF_f2d_want_enq1_readBeforeLaterWrites_0_read__ETC___d676;
  tUWide DEF_IF_IF_mispredicted_readBeforeLaterWrites_2_rea_ETC___d675;
  tUWide DEF_IF_f2d_want_enq2_port_0_whas__69_THEN_f2d_want_ETC___d269;
  tUWide DEF_IF_f2d_want_enq1_port_0_whas__62_THEN_f2d_want_ETC___d246;
  tUWide DEF_IF_fromImem_want_enq2_port_1_whas__2_THEN_from_ETC___d28;
  tUWide DEF_IF_fromImem_want_enq2_port_0_whas__4_THEN_from_ETC___d27;
  tUWide DEF_IF_fromImem_want_enq1_port_0_whas__7_THEN_from_ETC___d20;
  tUWide DEF_IF_fromImem_want_enq1_port_1_whas__5_THEN_from_ETC___d21;
  tUWide DEF_IF_fromImem_want_enq2_readBeforeLaterWrites_0__ETC___d1812;
  tUWide DEF_IF_fromImem_want_enq1_readBeforeLaterWrites_0__ETC___d1801;
  tUWide DEF_IF_fromImem_want_enq2_port_0_whas__4_THEN_from_ETC___d91;
  tUWide DEF_IF_fromImem_want_enq1_port_0_whas__7_THEN_from_ETC___d58;
  tUInt64 DEF_def__h8998;
  tUInt8 DEF_IF_double_squashed_port_0_whas__10_THEN_double_ETC___d613;
  tUInt8 DEF_IF_is_mem_inst_port_0_whas__96_THEN_is_mem_ins_ETC___d599;
  tUInt8 DEF_IF_execute_1_squashed_port_0_whas__75_THEN_exe_ETC___d578;
  tUInt8 DEF_IF_e2w_want_deq2_port_0_whas__59_THEN_e2w_want_ETC___d462;
  tUInt8 DEF_def__h30848;
  tUInt8 DEF_IF_e2w_want_deq1_port_0_whas__52_THEN_e2w_want_ETC___d455;
  tUInt8 DEF_def__h30242;
  tUInt8 DEF_IF_d2e_want_deq2_port_0_whas__22_THEN_d2e_want_ETC___d325;
  tUInt8 DEF_def__h20647;
  tUInt8 DEF_IF_d2e_want_deq1_port_0_whas__15_THEN_d2e_want_ETC___d318;
  tUInt8 DEF_def__h20041;
  tUInt8 DEF_IF_f2d_want_deq2_port_0_whas__83_THEN_f2d_want_ETC___d186;
  tUInt8 DEF_def__h13111;
  tUInt8 DEF_IF_f2d_want_deq1_port_0_whas__76_THEN_f2d_want_ETC___d179;
  tUInt8 DEF_def__h12505;
  tUInt8 DEF_def__h10185;
  tUInt8 DEF_IF_fromImem_want_deq2_port_0_whas__8_THEN_from_ETC___d41;
  tUInt8 DEF_def__h1334;
  tUInt8 DEF_IF_fromImem_want_deq1_port_0_whas__1_THEN_from_ETC___d34;
  tUInt8 DEF_def__h728;
  tUWide DEF_d2e_want_enq1_readBeforeLaterWrites_0_read__41_ETC___d1113;
  tUWide DEF_d2e_want_enq2_readBeforeLaterWrites_0_read__35_ETC___d916;
  tUWide DEF_NOT_d2e_want_enq1_readBeforeLaterWrites_1_read_ETC___d395;
  tUWide DEF_NOT_d2e_want_enq2_readBeforeLaterWrites_1_read_ETC___d419;
  tUWide DEF_SEL_ARR_f2d_internalFIFOs_0_first__93_BITS_80__ETC___d913;
  tUWide DEF_SEL_ARR_f2d_internalFIFOs_0_first__93_BITS_80__ETC___d1110;
  tUWide DEF_e2w_want_enq1_readBeforeLaterWrites_0_read__37_ETC___d1635;
  tUWide DEF_e2w_want_enq2_readBeforeLaterWrites_0_read__15_ETC___d1358;
  tUWide DEF_NOT_e2w_want_enq1_readBeforeLaterWrites_1_read_ETC___d532;
  tUWide DEF_NOT_e2w_want_enq2_readBeforeLaterWrites_1_read_ETC___d556;
  tUWide DEF_IF_NOT_SEL_ARR_d2e_internalFIFOs_0_first__116__ETC___d1632;
  tUWide DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BIT_216_ETC___d1354;
  tUWide DEF_SEL_ARR_d2e_internalFIFOs_0_first__116_BITS_47_ETC___d1631;
  tUWide DEF_rf_rv3_IF_SEL_ARR_fromImem_internalFIFOs_0_i_n_ETC___d912;
  tUWide DEF_rf_rv1_IF_SEL_ARR_fromImem_internalFIFOs_0_i_n_ETC___d1109;
  tUWide DEF_f2d_want_enq2_readBeforeLaterWrites_0_read__54_ETC___d686;
  tUWide DEF_f2d_want_enq1_readBeforeLaterWrites_0_read__35_ETC___d677;
  tUWide DEF_NOT_f2d_want_enq1_readBeforeLaterWrites_1_read_ETC___d257;
  tUWide DEF_NOT_f2d_want_enq2_readBeforeLaterWrites_1_read_ETC___d282;
  tUWide DEF__16_CONCAT_IF_IF_mispredicted_readBeforeLaterWr_ETC___d679;
  tUWide DEF__0_CONCAT_DONTCARE___d1797;
  tUWide DEF__1_CONCAT_IF_SEL_ARR_d2e_internalFIFOs_0_first__ETC___d1471;
  tUWide DEF__1_CONCAT_getMMIOResp_a___d1823;
  tUWide DEF__1_CONCAT_getDResp_a___d1819;
  tUWide DEF__0_CONCAT_DONTCARE___d1752;
  tUWide DEF_fromImem_want_enq2_readBeforeLaterWrites_0_rea_ETC___d1813;
  tUWide DEF_fromImem_want_enq1_readBeforeLaterWrites_0_rea_ETC___d1802;
  tUWide DEF_NOT_fromImem_want_enq1_readBeforeLaterWrites_1_ETC___d76;
  tUWide DEF_NOT_fromImem_want_enq2_readBeforeLaterWrites_1_ETC___d106;
 
 /* Rules */
 public:
  void RL_fromImem_enqueueFIFO_canonicalize();
  void RL_fromImem_dequeueFIFO_canonicalize();
  void RL_fromImem_want_enq1_canonicalize();
  void RL_fromImem_want_enq2_canonicalize();
  void RL_fromImem_want_deq1_canonicalize();
  void RL_fromImem_want_deq2_canonicalize();
  void RL_fromImem_canonicalize();
  void RL_commit_id_canonicalize();
  void RL_globalEpoch_canonicalize();
  void RL_redirectPc_canonicalize();
  void RL_mispredicted_canonicalize();
  void RL_f2d_enqueueFIFO_canonicalize();
  void RL_f2d_dequeueFIFO_canonicalize();
  void RL_f2d_want_enq1_canonicalize();
  void RL_f2d_want_enq2_canonicalize();
  void RL_f2d_want_deq1_canonicalize();
  void RL_f2d_want_deq2_canonicalize();
  void RL_f2d_canonicalize();
  void RL_d2e_enqueueFIFO_canonicalize();
  void RL_d2e_dequeueFIFO_canonicalize();
  void RL_d2e_want_enq1_canonicalize();
  void RL_d2e_want_enq2_canonicalize();
  void RL_d2e_want_deq1_canonicalize();
  void RL_d2e_want_deq2_canonicalize();
  void RL_d2e_canonicalize();
  void RL_e2w_enqueueFIFO_canonicalize();
  void RL_e2w_dequeueFIFO_canonicalize();
  void RL_e2w_want_enq1_canonicalize();
  void RL_e2w_want_enq2_canonicalize();
  void RL_e2w_want_deq1_canonicalize();
  void RL_e2w_want_deq2_canonicalize();
  void RL_e2w_canonicalize();
  void RL_decode_1_done_canonicalize();
  void RL_execute_1_done_canonicalize();
  void RL_execute_1_squashed_canonicalize();
  void RL_writeback_1_done_canonicalize();
  void RL_exec_1_alu_canonicalize();
  void RL_is_mem_inst_canonicalize();
  void RL_double_retired_canonicalize();
  void RL_double_squashed_canonicalize();
  void RL_tick();
  void RL_do_tic_logging();
  void RL_fetch();
  void RL_decode_2();
  void RL_decode_1();
  void RL_execute2();
  void RL_execute1();
  void RL_writeback2();
  void RL_writeback1();
  void RL_administrative_konata_commit1();
  void RL_administrative_konata_commit2();
  void RL_administrative_konata_flush1();
  void RL_administrative_konata_flush2();
 
 /* Methods */
 public:
  tUWide METH_getIReq();
  tUInt8 METH_RDY_getIReq();
  void METH_getIResp(tUWide ARG_getIResp_a);
  tUInt8 METH_RDY_getIResp();
  void METH_getIResp2(tUWide ARG_getIResp2_a);
  tUInt8 METH_RDY_getIResp2();
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mksuperscalar &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mksuperscalar &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mksuperscalar &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mksuperscalar &backing);
};

#endif /* ifndef __mksuperscalar_h__ */
