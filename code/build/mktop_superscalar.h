/*
 * Generated by Bluespec Compiler, version 2023.07-31-ge4361d91 (build e4361d91)
 * 
 * On Tue May 14 00:48:26 EDT 2024
 * 
 */

/* Generation options: */
#ifndef __mktop_superscalar_h__
#define __mktop_superscalar_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mksuperscalar.h"
#include "mkCache32.h"
#include "mkCache.h"


/* Class declaration for the mktop_superscalar module */
class MOD_mktop_superscalar : public Module {
 
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
  MOD_BRAM<tUInt32,tUInt32,tUInt8> INST_bram_memory;
  MOD_Reg<tUInt8> INST_bram_serverAdapterA_cnt;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_cnt_1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_cnt_2;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_cnt_3;
  MOD_Reg<tUInt8> INST_bram_serverAdapterA_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_bram_serverAdapterA_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_outData_dequeueing;
  MOD_Wire<tUInt32> INST_bram_serverAdapterA_outData_enqw;
  MOD_Fifo<tUInt32> INST_bram_serverAdapterA_outData_ff;
  MOD_Reg<tUInt8> INST_bram_serverAdapterA_s1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_s1_1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterA_writeWithResp;
  MOD_Reg<tUInt8> INST_bram_serverAdapterB_cnt;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_cnt_1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_cnt_2;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_cnt_3;
  MOD_Reg<tUInt8> INST_bram_serverAdapterB_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_bram_serverAdapterB_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_outData_dequeueing;
  MOD_Wire<tUInt32> INST_bram_serverAdapterB_outData_enqw;
  MOD_Fifo<tUInt32> INST_bram_serverAdapterB_outData_ff;
  MOD_Reg<tUInt8> INST_bram_serverAdapterB_s1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_s1_1;
  MOD_Wire<tUInt8> INST_bram_serverAdapterB_writeWithResp;
  MOD_Reg<tUInt32> INST_cycle_count;
  MOD_Fifo<tUWide> INST_dreq;
  MOD_Fifo<tUWide> INST_ireq;
  MOD_Fifo<tUWide> INST_mmioreq;
  MOD_mksuperscalar INST_rv_core;
  MOD_mkCache32 INST_superCache_cacheD;
  MOD_Reg<tUWide> INST_superCache_cacheI_curReq;
  MOD_Wire<tUInt8> INST_superCache_cacheI_curState_port_0;
  MOD_Wire<tUInt8> INST_superCache_cacheI_curState_port_1;
  MOD_Reg<tUInt8> INST_superCache_cacheI_curState_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_superCache_cacheI_curState_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_superCache_cacheI_curState_register;
  MOD_Reg<tUInt32> INST_superCache_cacheI_cycles;
  MOD_BRAM<tUInt8,tUWide,tUInt64> INST_superCache_cacheI_dataArray_memory;
  MOD_Reg<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_outData_dequeueing;
  MOD_Wire<tUWide> INST_superCache_cacheI_dataArray_serverAdapter_outData_enqw;
  MOD_Fifo<tUWide> INST_superCache_cacheI_dataArray_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_dataArray_serverAdapter_writeWithResp;
  MOD_CReg<tUWide> INST_superCache_cacheI_fromMem_rv;
  MOD_CReg<tUWide> INST_superCache_cacheI_fromProc_rv;
  MOD_Wire<tUInt8> INST_superCache_cacheI_isHit_port_0;
  MOD_Wire<tUInt8> INST_superCache_cacheI_isHit_port_1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_isHit_port_2;
  MOD_Reg<tUInt8> INST_superCache_cacheI_isHit_readBeforeLaterWrites_0;
  MOD_Reg<tUInt8> INST_superCache_cacheI_isHit_readBeforeLaterWrites_1;
  MOD_Reg<tUInt8> INST_superCache_cacheI_isHit_readBeforeLaterWrites_2;
  MOD_Reg<tUInt8> INST_superCache_cacheI_isHit_register;
  MOD_BRAM<tUInt8,tUInt8,tUInt8> INST_superCache_cacheI_statusArray_memory;
  MOD_Reg<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_outData_dequeueing;
  MOD_Wire<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_outData_enqw;
  MOD_Fifo<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_statusArray_serverAdapter_writeWithResp;
  MOD_BRAM<tUInt8,tUInt32,tUInt8> INST_superCache_cacheI_tagArray_memory;
  MOD_Reg<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_outData_dequeueing;
  MOD_Wire<tUInt32> INST_superCache_cacheI_tagArray_serverAdapter_outData_enqw;
  MOD_Fifo<tUInt32> INST_superCache_cacheI_tagArray_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_superCache_cacheI_tagArray_serverAdapter_writeWithResp;
  MOD_CReg<tUWide> INST_superCache_cacheI_toMem_rv;
  MOD_CReg<tUWide> INST_superCache_cacheI_toProc_rv;
  MOD_mkCache INST_superCache_cacheL2;
  MOD_Fifo<tUWide> INST_superCache_dataReq;
  MOD_Fifo<tUWide> INST_superCache_instReq;
  MOD_Fifo<tUInt8> INST_superCache_isInstReq;
  MOD_BRAM<tUInt32,tUWide,tUInt8> INST_superCache_mainMem_bram_memory;
  MOD_Reg<tUInt8> INST_superCache_mainMem_bram_serverAdapter_cnt;
  MOD_Wire<tUInt8> INST_superCache_mainMem_bram_serverAdapter_cnt_1;
  MOD_Wire<tUInt8> INST_superCache_mainMem_bram_serverAdapter_cnt_2;
  MOD_Wire<tUInt8> INST_superCache_mainMem_bram_serverAdapter_cnt_3;
  MOD_Reg<tUInt8> INST_superCache_mainMem_bram_serverAdapter_outData_beforeDeq;
  MOD_Reg<tUInt8> INST_superCache_mainMem_bram_serverAdapter_outData_beforeEnq;
  MOD_Wire<tUInt8> INST_superCache_mainMem_bram_serverAdapter_outData_dequeueing;
  MOD_Wire<tUWide> INST_superCache_mainMem_bram_serverAdapter_outData_enqw;
  MOD_Fifo<tUWide> INST_superCache_mainMem_bram_serverAdapter_outData_ff;
  MOD_Reg<tUInt8> INST_superCache_mainMem_bram_serverAdapter_s1;
  MOD_Wire<tUInt8> INST_superCache_mainMem_bram_serverAdapter_s1_1;
  MOD_Wire<tUInt8> INST_superCache_mainMem_bram_serverAdapter_writeWithResp;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_0_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_10_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_11_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_12_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_13_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_14_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_15_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_16_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_17_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_18_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_19_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_1_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_2_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_3_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_4_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_5_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_6_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_7_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_8_rv;
  MOD_CReg<tUWide> INST_superCache_mainMem_dl_d_9_rv;
 
 /* Constructor */
 public:
  MOD_mktop_superscalar(tSimStateHdl simHdl, char const *name, Module *parent);
 
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
  tUInt8 DEF_superCache_dataReq_notEmpty____d625;
  tUInt8 DEF_IF_superCache_cacheI_tagArray_serverAdapter_ou_ETC___d520;
  tUWide DEF_superCache_cacheI_toMem_rv_port1__read____d609;
  tUWide DEF_superCache_cacheI_toMem_rv_port0__read____d526;
  tUWide DEF_superCache_cacheI_fromMem_rv_port1__read____d577;
  tUWide DEF_superCache_cacheI_fromMem_rv_port0__read____d641;
  tUWide DEF_superCache_mainMem_dl_d_19_rv_port0__read____d659;
  tUWide DEF_superCache_mainMem_dl_d_0_rv_port1__read____d304;
  tUWide DEF_superCache_cacheI_fromProc_rv_port1__read____d479;
  tUWide DEF_superCache_cacheI_fromProc_rv_port0__read____d669;
  tUWide DEF_superCache_cacheI_curReq___d518;
  tUWide DEF_superCache_cacheI_toProc_rv_port1__read____d677;
  tUWide DEF_superCache_cacheI_toProc_rv_port0__read____d522;
  tUInt32 DEF_x_wget__h16302;
  tUInt32 DEF_x_first__h16187;
  tUInt8 DEF_b__h18280;
  tUInt8 DEF_b__h16795;
  tUInt8 DEF_b__h15332;
  tUInt8 DEF_b__h3739;
  tUInt8 DEF_superCache_cacheI_curState_register__h20323;
  tUInt8 DEF_superCache_cacheI_statusArray_serverAdapter_s1___d441;
  tUInt8 DEF_superCache_cacheI_statusArray_serverAdapter_ou_ETC___d415;
  tUInt8 DEF_superCache_cacheI_tagArray_serverAdapter_s1___d393;
  tUInt8 DEF_superCache_cacheI_dataArray_serverAdapter_s1___d344;
  tUInt8 DEF_superCache_mainMem_bram_serverAdapter_s1___d133;
  tUInt8 DEF_bram_serverAdapterB_s1___d84;
  tUInt8 DEF_bram_serverAdapterA_s1___d35;
  tUInt8 DEF_superCache_isInstReq_first____d640;
  tUInt8 DEF_superCache_instReq_notEmpty____d619;
  tUInt8 DEF_superCache_cacheI_isHit_register__h21140;
  tUInt8 DEF_superCache_cacheI_statusArray_serverAdapter_cn_ETC___d420;
  tUInt8 DEF_superCache_cacheI_statusArray_serverAdapter_cn_ETC___d418;
  tUInt8 DEF_superCache_cacheI_statusArray_serverAdapter_cn_ETC___d417;
  tUInt8 DEF_superCache_cacheI_statusArray_serverAdapter_ou_ETC___d412;
  tUInt8 DEF_superCache_cacheI_tagArray_serverAdapter_cnt_3_ETC___d372;
  tUInt8 DEF_superCache_cacheI_tagArray_serverAdapter_cnt_2_ETC___d370;
  tUInt8 DEF_superCache_cacheI_tagArray_serverAdapter_cnt_1_ETC___d369;
  tUInt8 DEF_superCache_cacheI_tagArray_serverAdapter_outDa_ETC___d363;
  tUInt8 DEF_superCache_cacheI_dataArray_serverAdapter_cnt__ETC___d323;
  tUInt8 DEF_superCache_cacheI_dataArray_serverAdapter_cnt__ETC___d321;
  tUInt8 DEF_superCache_cacheI_dataArray_serverAdapter_cnt__ETC___d320;
  tUInt8 DEF_superCache_cacheI_dataArray_serverAdapter_outD_ETC___d314;
  tUInt8 DEF_superCache_mainMem_bram_serverAdapter_cnt_3_whas____d112;
  tUInt8 DEF_superCache_mainMem_bram_serverAdapter_cnt_2_whas____d110;
  tUInt8 DEF_superCache_mainMem_bram_serverAdapter_cnt_1_whas____d109;
  tUInt8 DEF_superCache_mainMem_bram_serverAdapter_outData__ETC___d103;
  tUInt8 DEF_bram_serverAdapterB_cnt_3_whas____d63;
  tUInt8 DEF_bram_serverAdapterB_cnt_2_whas____d61;
  tUInt8 DEF_bram_serverAdapterB_cnt_1_whas____d60;
  tUInt8 DEF_bram_serverAdapterA_cnt_3_whas____d13;
  tUInt8 DEF_bram_serverAdapterA_cnt_2_whas____d11;
  tUInt8 DEF_bram_serverAdapterA_cnt_1_whas____d10;
  tUInt32 DEF_x3__h25815;
  tUInt8 DEF_superCache_cacheI_toProc_rv_port1__read__77_BI_ETC___d681;
  tUInt8 DEF_superCache_cacheI_statusArray_serverAdapter_s1_ETC___d442;
  tUInt8 DEF_superCache_cacheI_tagArray_serverAdapter_s1_93_ETC___d394;
  tUInt8 DEF_superCache_cacheI_dataArray_serverAdapter_s1_4_ETC___d345;
  tUInt8 DEF_superCache_mainMem_bram_serverAdapter_s1_33_BIT_0___d134;
  tUInt8 DEF_bram_serverAdapterB_s1_4_BIT_0___d85;
  tUInt8 DEF_bram_serverAdapterA_s1_5_BIT_0___d36;
  tUInt32 DEF_v__h23150;
  tUInt32 DEF_x__h16400;
  tUInt8 DEF_NOT_IF_superCache_cacheI_statusArray_serverAda_ETC___d521;
  tUInt8 DEF_IF_superCache_cacheI_curState_port_0_whas__59__ETC___d462;
  tUInt8 DEF_IF_superCache_cacheI_isHit_port_0_whas__68_THE_ETC___d471;
  tUInt8 DEF_IF_superCache_cacheI_statusArray_serverAdapter_ETC___d513;
  tUInt8 DEF_IF_superCache_cacheI_curState_readBeforeLaterW_ETC___d498;
 
 /* Local definitions */
 private:
  tUInt8 DEF_next__h24769;
  tUInt8 DEF_x__h23638;
  tUWide DEF_superCache_cacheD_getToMem___d618;
  tUWide DEF_superCache_cacheL2_getToMem___d654;
  tUWide DEF_superCache_cacheL2_getToProc___d648;
  tUWide DEF_rv_core_getIReq___d674;
  tUWide DEF_rv_core_getMMIOReq___d716;
  tUWide DEF_rv_core_getDReq___d703;
  tUWide DEF_superCache_dataReq_first____d634;
  tUWide DEF_superCache_instReq_first____d633;
  tUWide DEF_superCache_mainMem_dl_d_19_rv_port1__read____d151;
  tUWide DEF_superCache_mainMem_dl_d_18_rv_port1__read____d160;
  tUWide DEF_superCache_mainMem_dl_d_18_rv_port0__read____d149;
  tUWide DEF_superCache_mainMem_dl_d_17_rv_port1__read____d168;
  tUWide DEF_superCache_mainMem_dl_d_17_rv_port0__read____d158;
  tUWide DEF_superCache_mainMem_dl_d_16_rv_port1__read____d176;
  tUWide DEF_superCache_mainMem_dl_d_16_rv_port0__read____d166;
  tUWide DEF_superCache_mainMem_dl_d_15_rv_port1__read____d184;
  tUWide DEF_superCache_mainMem_dl_d_15_rv_port0__read____d174;
  tUWide DEF_superCache_mainMem_dl_d_14_rv_port1__read____d192;
  tUWide DEF_superCache_mainMem_dl_d_14_rv_port0__read____d182;
  tUWide DEF_superCache_mainMem_dl_d_13_rv_port1__read____d200;
  tUWide DEF_superCache_mainMem_dl_d_13_rv_port0__read____d190;
  tUWide DEF_superCache_mainMem_dl_d_12_rv_port1__read____d208;
  tUWide DEF_superCache_mainMem_dl_d_12_rv_port0__read____d198;
  tUWide DEF_superCache_mainMem_dl_d_11_rv_port1__read____d216;
  tUWide DEF_superCache_mainMem_dl_d_11_rv_port0__read____d206;
  tUWide DEF_superCache_mainMem_dl_d_10_rv_port1__read____d224;
  tUWide DEF_superCache_mainMem_dl_d_10_rv_port0__read____d214;
  tUWide DEF_superCache_mainMem_dl_d_9_rv_port1__read____d232;
  tUWide DEF_superCache_mainMem_dl_d_9_rv_port0__read____d222;
  tUWide DEF_superCache_mainMem_dl_d_8_rv_port1__read____d240;
  tUWide DEF_superCache_mainMem_dl_d_8_rv_port0__read____d230;
  tUWide DEF_superCache_mainMem_dl_d_7_rv_port1__read____d248;
  tUWide DEF_superCache_mainMem_dl_d_7_rv_port0__read____d238;
  tUWide DEF_superCache_mainMem_dl_d_6_rv_port1__read____d256;
  tUWide DEF_superCache_mainMem_dl_d_6_rv_port0__read____d246;
  tUWide DEF_superCache_mainMem_dl_d_5_rv_port1__read____d264;
  tUWide DEF_superCache_mainMem_dl_d_5_rv_port0__read____d254;
  tUWide DEF_superCache_mainMem_dl_d_4_rv_port1__read____d272;
  tUWide DEF_superCache_mainMem_dl_d_4_rv_port0__read____d262;
  tUWide DEF_superCache_mainMem_dl_d_3_rv_port1__read____d280;
  tUWide DEF_superCache_mainMem_dl_d_3_rv_port0__read____d270;
  tUWide DEF_superCache_mainMem_dl_d_2_rv_port1__read____d288;
  tUWide DEF_superCache_mainMem_dl_d_2_rv_port0__read____d278;
  tUWide DEF_superCache_mainMem_dl_d_1_rv_port1__read____d296;
  tUWide DEF_superCache_mainMem_dl_d_1_rv_port0__read____d286;
  tUWide DEF_superCache_mainMem_dl_d_0_rv_port0__read____d294;
  tUWide DEF_x_wget__h14839;
  tUWide DEF_x_first__h14724;
  tUWide DEF_v__h15902;
  tUWide DEF_x_wget__h3246;
  tUWide DEF_x_first__h3131;
  tUWide DEF_v__h4309;
  tUWide DEF_mmioreq_first____d733;
  tUWide DEF_dreq_first____d709;
  tUWide DEF_ireq_first____d689;
  tUInt32 DEF__read__h27555;
  tUInt8 DEF_superCache_cacheI_curState_readBeforeLaterWrit_ETC___d487;
  tUWide DEF_superCache_cacheI_toMem_rv_port1__read__09_BIT_ETC___d614;
  tUWide DEF_x3__h26958;
  tUWide DEF_x__h27137;
  tUWide DEF_x__h25266;
  tUWide DEF_x__h14186;
  tUWide DEF_x__h13928;
  tUWide DEF_x__h13670;
  tUWide DEF_x__h13412;
  tUWide DEF_x__h13154;
  tUWide DEF_x__h12896;
  tUWide DEF_x__h12638;
  tUWide DEF_x__h12380;
  tUWide DEF_x__h12122;
  tUWide DEF_x__h11864;
  tUWide DEF_x__h11606;
  tUWide DEF_x__h11348;
  tUWide DEF_x__h11090;
  tUWide DEF_x__h10832;
  tUWide DEF_x__h10574;
  tUWide DEF_x__h10316;
  tUWide DEF_x__h10058;
  tUWide DEF_x__h9800;
  tUWide DEF_x__h9542;
  tUWide DEF_superCache_cacheI_fromProc_rv_port1__read__79__ETC___d496;
  tUWide DEF_rv_core_getIReq_74_BITS_68_TO_1___d675;
  tUWide DEF_superCache_cacheI_curReq_18_BITS_64_TO_0___d575;
  tUWide DEF_IF_superCache_cacheI_fromMem_rv_port1__read__7_ETC___d586;
  tUWide DEF_IF_superCache_cacheI_dataArray_serverAdapter_o_ETC___d545;
  tUInt8 DEF_x2__h21947;
  tUWide DEF_IF_superCache_instReq_notEmpty__19_THEN_superC_ETC___d635;
  tUWide DEF_v__h27004;
  tUWide DEF_x__h14937;
  tUWide DEF_IF_superCache_mainMem_bram_serverAdapter_outDa_ETC___d309;
  tUWide DEF_x__h3344;
  tUInt8 DEF_IF_superCache_cacheI_curState_readBeforeLaterW_ETC___d541;
  tUInt8 DEF__0_CONCAT_DONTCARE___d26;
  tUInt8 DEF_IF_superCache_cacheI_isHit_port_1_whas__66_THE_ETC___d472;
  tUInt8 DEF_NOT_superCache_cacheI_curReq_18_BITS_38_TO_35__ETC___d568;
  tUWide DEF__2_CONCAT_superCache_cacheI_curReq_18_BITS_64_T_ETC___d576;
  tUWide DEF__0_CONCAT_DONTCARE___d613;
  tUWide DEF__1_CONCAT_superCache_cacheL2_getToProc_48___d649;
  tUWide DEF__1_CONCAT_IF_superCache_mainMem_bram_serverAdap_ETC___d310;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_0_rv_port0__r_ETC___d301;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_1_rv_port0__r_ETC___d293;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_2_rv_port0__r_ETC___d285;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_3_rv_port0__r_ETC___d277;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_4_rv_port0__r_ETC___d269;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_5_rv_port0__r_ETC___d261;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_6_rv_port0__r_ETC___d253;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_7_rv_port0__r_ETC___d245;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_8_rv_port0__r_ETC___d237;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_9_rv_port0__r_ETC___d229;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_10_rv_port0___ETC___d221;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_11_rv_port0___ETC___d213;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_12_rv_port0___ETC___d205;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_13_rv_port0___ETC___d197;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_14_rv_port0___ETC___d189;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_15_rv_port0___ETC___d181;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_16_rv_port0___ETC___d173;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_18_rv_port0___ETC___d157;
  tUWide DEF__1_CONCAT_superCache_mainMem_dl_d_17_rv_port0___ETC___d165;
  tUWide DEF__0_CONCAT_DONTCARE___d155;
  tUWide DEF__1_CONCAT_rv_core_getIReq_74___d676;
  tUWide DEF__0_CONCAT_DONTCARE___d493;
  tUWide DEF_ireq_first__89_BITS_67_TO_32_90_CONCAT_superCa_ETC___d692;
  tUWide DEF_dreq_first__09_BITS_67_TO_32_10_CONCAT_superCa_ETC___d712;
  tUWide DEF_ireq_first__89_BITS_67_TO_64_93_CONCAT_ireq_fi_ETC___d697;
  tUWide DEF__1_CONCAT_SEL_ARR_IF_superCache_cacheI_dataArra_ETC___d572;
  tUWide DEF__1_CONCAT_SEL_ARR_IF_superCache_cacheI_fromMem__ETC___d607;
  tUWide DEF__0_CONCAT_DONTCARE___d688;
 
 /* Rules */
 public:
  void RL_bram_serverAdapterA_outData_enqueue();
  void RL_bram_serverAdapterA_outData_dequeue();
  void RL_bram_serverAdapterA_cnt_finalAdd();
  void RL_bram_serverAdapterA_s1__dreg_update();
  void RL_bram_serverAdapterA_stageReadResponseAlways();
  void RL_bram_serverAdapterA_moveToOutFIFO();
  void RL_bram_serverAdapterA_overRun();
  void RL_bram_serverAdapterB_outData_enqueue();
  void RL_bram_serverAdapterB_outData_dequeue();
  void RL_bram_serverAdapterB_cnt_finalAdd();
  void RL_bram_serverAdapterB_s1__dreg_update();
  void RL_bram_serverAdapterB_stageReadResponseAlways();
  void RL_bram_serverAdapterB_moveToOutFIFO();
  void RL_bram_serverAdapterB_overRun();
  void RL_superCache_mainMem_bram_serverAdapter_outData_enqueue();
  void RL_superCache_mainMem_bram_serverAdapter_outData_dequeue();
  void RL_superCache_mainMem_bram_serverAdapter_cnt_finalAdd();
  void RL_superCache_mainMem_bram_serverAdapter_s1__dreg_update();
  void RL_superCache_mainMem_bram_serverAdapter_stageReadResponseAlways();
  void RL_superCache_mainMem_bram_serverAdapter_moveToOutFIFO();
  void RL_superCache_mainMem_bram_serverAdapter_overRun();
  void RL_superCache_mainMem_dl_try_move();
  void RL_superCache_mainMem_dl_try_move_1();
  void RL_superCache_mainMem_dl_try_move_2();
  void RL_superCache_mainMem_dl_try_move_3();
  void RL_superCache_mainMem_dl_try_move_4();
  void RL_superCache_mainMem_dl_try_move_5();
  void RL_superCache_mainMem_dl_try_move_6();
  void RL_superCache_mainMem_dl_try_move_7();
  void RL_superCache_mainMem_dl_try_move_8();
  void RL_superCache_mainMem_dl_try_move_9();
  void RL_superCache_mainMem_dl_try_move_10();
  void RL_superCache_mainMem_dl_try_move_11();
  void RL_superCache_mainMem_dl_try_move_12();
  void RL_superCache_mainMem_dl_try_move_13();
  void RL_superCache_mainMem_dl_try_move_14();
  void RL_superCache_mainMem_dl_try_move_15();
  void RL_superCache_mainMem_dl_try_move_16();
  void RL_superCache_mainMem_dl_try_move_17();
  void RL_superCache_mainMem_dl_try_move_18();
  void RL_superCache_mainMem_deq();
  void RL_superCache_cacheI_dataArray_serverAdapter_outData_enqueue();
  void RL_superCache_cacheI_dataArray_serverAdapter_outData_dequeue();
  void RL_superCache_cacheI_dataArray_serverAdapter_cnt_finalAdd();
  void RL_superCache_cacheI_dataArray_serverAdapter_s1__dreg_update();
  void RL_superCache_cacheI_dataArray_serverAdapter_stageReadResponseAlways();
  void RL_superCache_cacheI_dataArray_serverAdapter_moveToOutFIFO();
  void RL_superCache_cacheI_dataArray_serverAdapter_overRun();
  void RL_superCache_cacheI_tagArray_serverAdapter_outData_enqueue();
  void RL_superCache_cacheI_tagArray_serverAdapter_outData_dequeue();
  void RL_superCache_cacheI_tagArray_serverAdapter_cnt_finalAdd();
  void RL_superCache_cacheI_tagArray_serverAdapter_s1__dreg_update();
  void RL_superCache_cacheI_tagArray_serverAdapter_stageReadResponseAlways();
  void RL_superCache_cacheI_tagArray_serverAdapter_moveToOutFIFO();
  void RL_superCache_cacheI_tagArray_serverAdapter_overRun();
  void RL_superCache_cacheI_statusArray_serverAdapter_outData_enqueue();
  void RL_superCache_cacheI_statusArray_serverAdapter_outData_dequeue();
  void RL_superCache_cacheI_statusArray_serverAdapter_cnt_finalAdd();
  void RL_superCache_cacheI_statusArray_serverAdapter_s1__dreg_update();
  void RL_superCache_cacheI_statusArray_serverAdapter_stageReadResponseAlways();
  void RL_superCache_cacheI_statusArray_serverAdapter_moveToOutFIFO();
  void RL_superCache_cacheI_statusArray_serverAdapter_overRun();
  void RL_superCache_cacheI_curState_canonicalize();
  void RL_superCache_cacheI_isHit_canonicalize();
  void RL_superCache_cacheI_cycle_count();
  void RL_superCache_cacheI_reset_isHit();
  void RL_superCache_cacheI_ready();
  void RL_superCache_cacheI_override();
  void RL_superCache_cacheI_lookup();
  void RL_superCache_cacheI_allocate();
  void RL_superCache_getInstMiss();
  void RL_superCache_getDataMiss();
  void RL_superCache_processL1Misses();
  void RL_superCache_processL2Response();
  void RL_superCache_reqFromL2ToMem();
  void RL_superCache_respFromMemtoL2();
  void RL_tic();
  void RL_requestI();
  void RL_responseI();
  void RL_requestD();
  void RL_responseD();
  void RL_requestMMIO();
  void RL_responseMMIO();
 
 /* Methods */
 public:
 
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
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mktop_superscalar &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mktop_superscalar &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mktop_superscalar &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mktop_superscalar &backing);
};

#endif /* ifndef __mktop_superscalar_h__ */
