// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vmulti_standard_rx__Syms.h"


void Vmulti_standard_rx___024root__trace_chg_0_sub_0(Vmulti_standard_rx___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmulti_standard_rx___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root__trace_chg_0\n"); );
    // Body
    Vmulti_standard_rx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmulti_standard_rx___024root*>(voidSelf);
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vmulti_standard_rx___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vmulti_standard_rx___024root__trace_chg_0_sub_0(Vmulti_standard_rx___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root__trace_chg_0_sub_0\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+0,(vlSelfRef.multi_standard_rx__DOT__fft_len),13);
        bufp->chgSData(oldp+1,(vlSelfRef.multi_standard_rx__DOT__cp_len),9);
        bufp->chgCData(oldp+2,(vlSelfRef.multi_standard_rx__DOT__mod_type),4);
        bufp->chgIData(oldp+3,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_term),32);
        bufp->chgIData(oldp+4,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_term),32);
        bufp->chgIData(oldp+5,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_term),32);
        bufp->chgIData(oldp+6,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_term),32);
    }
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgIData(oldp+7,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re),32);
        bufp->chgIData(oldp+8,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im),32);
        bufp->chgIData(oldp+9,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re),32);
        bufp->chgIData(oldp+10,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im),32);
        bufp->chgIData(oldp+11,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re),32);
        bufp->chgIData(oldp+12,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im),32);
        bufp->chgIData(oldp+13,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re),32);
        bufp->chgIData(oldp+14,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+15,(vlSelfRef.multi_standard_rx__DOT__config_update));
        bufp->chgBit(oldp+16,(vlSelfRef.multi_standard_rx__DOT__sync_found_0));
        bufp->chgBit(oldp+17,(vlSelfRef.multi_standard_rx__DOT__sync_found_1));
        bufp->chgBit(oldp+18,(vlSelfRef.multi_standard_rx__DOT__sync_found_2));
        bufp->chgBit(oldp+19,(vlSelfRef.multi_standard_rx__DOT__sync_found_3));
        bufp->chgSData(oldp+20,(vlSelfRef.multi_standard_rx__DOT__freq_offset_0),16);
        bufp->chgSData(oldp+21,(vlSelfRef.multi_standard_rx__DOT__freq_offset_1),16);
        bufp->chgSData(oldp+22,(vlSelfRef.multi_standard_rx__DOT__freq_offset_2),16);
        bufp->chgSData(oldp+23,(vlSelfRef.multi_standard_rx__DOT__freq_offset_3),16);
        bufp->chgQData(oldp+24,(vlSelfRef.multi_standard_rx__DOT__corr_E_0),64);
        bufp->chgQData(oldp+26,(vlSelfRef.multi_standard_rx__DOT__corr_E_1),64);
        bufp->chgQData(oldp+28,(vlSelfRef.multi_standard_rx__DOT__corr_E_2),64);
        bufp->chgQData(oldp+30,(vlSelfRef.multi_standard_rx__DOT__corr_E_3),64);
        bufp->chgQData(oldp+32,(vlSelfRef.multi_standard_rx__DOT__total_E_0),64);
        bufp->chgQData(oldp+34,(vlSelfRef.multi_standard_rx__DOT__total_E_1),64);
        bufp->chgQData(oldp+36,(vlSelfRef.multi_standard_rx__DOT__total_E_2),64);
        bufp->chgQData(oldp+38,(vlSelfRef.multi_standard_rx__DOT__total_E_3),64);
        __Vtemp_2[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__corr_E_0);
        __Vtemp_2[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__corr_E_0 
                                 >> 0x00000020U));
        __Vtemp_2[2U] = 0U;
        __Vtemp_3[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__corr_E_1);
        __Vtemp_3[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__corr_E_1 
                                 >> 0x00000020U));
        __Vtemp_3[2U] = 0U;
        __Vtemp_4[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__corr_E_2);
        __Vtemp_4[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__corr_E_2 
                                 >> 0x00000020U));
        __Vtemp_4[2U] = 0U;
        __Vtemp_5[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__corr_E_3);
        __Vtemp_5[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__corr_E_3 
                                 >> 0x00000020U));
        __Vtemp_5[2U] = 0U;
        VL_ADD_W(3, __Vtemp_6, __Vtemp_4, __Vtemp_5);
        VL_ADD_W(3, __Vtemp_7, __Vtemp_3, __Vtemp_6);
        VL_ADD_W(3, __Vtemp_8, __Vtemp_2, __Vtemp_7);
        __Vtemp_9[0U] = __Vtemp_8[0U];
        __Vtemp_9[1U] = __Vtemp_8[1U];
        __Vtemp_9[2U] = (3U & __Vtemp_8[2U]);
        bufp->chgWData(oldp+40,(__Vtemp_9),66);
        bufp->chgWData(oldp+43,(vlSelfRef.multi_standard_rx__DOT__sum_total_E),66);
        bufp->chgBit(oldp+46,(vlSelfRef.multi_standard_rx__DOT__sync_combined));
        bufp->chgCData(oldp+47,(vlSelfRef.multi_standard_rx__DOT__u_mode_ctrl__DOT__state),3);
        bufp->chgCData(oldp+48,(vlSelfRef.multi_standard_rx__DOT__u_mode_ctrl__DOT__current_mode),2);
        bufp->chgCData(oldp+49,(vlSelfRef.multi_standard_rx__DOT__u_mode_ctrl__DOT__timer),8);
        bufp->chgSData(oldp+50,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len),13);
        bufp->chgSData(oldp+51,(((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len))
                                  ? 0x0010U : ((0x0800U 
                                                == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len))
                                                ? 0x0040U
                                                : (
                                                   (0x1000U 
                                                    == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len))
                                                    ? 0x0080U
                                                    : 0x0040U)))),12);
        bufp->chgSData(oldp+52,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr),12);
        bufp->chgSData(oldp+53,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr),12);
        bufp->chgSData(oldp+54,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delayed_re),16);
        bufp->chgSData(oldp+55,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delayed_im),16);
        bufp->chgIData(oldp+56,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re_delayed),32);
        bufp->chgIData(oldp+57,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im_delayed),32);
        bufp->chgIData(oldp+58,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_delayed),32);
        bufp->chgQData(oldp+59,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re),48);
        bufp->chgQData(oldp+61,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im),48);
        bufp->chgQData(oldp+63,(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_energy),48);
        bufp->chgSData(oldp+65,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len),13);
        bufp->chgSData(oldp+66,(((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len))
                                  ? 0x0010U : ((0x0800U 
                                                == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len))
                                                ? 0x0040U
                                                : (
                                                   (0x1000U 
                                                    == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len))
                                                    ? 0x0080U
                                                    : 0x0040U)))),12);
        bufp->chgSData(oldp+67,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr),12);
        bufp->chgSData(oldp+68,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr),12);
        bufp->chgSData(oldp+69,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__delayed_re),16);
        bufp->chgSData(oldp+70,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__delayed_im),16);
        bufp->chgIData(oldp+71,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re_delayed),32);
        bufp->chgIData(oldp+72,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im_delayed),32);
        bufp->chgIData(oldp+73,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_delayed),32);
        bufp->chgQData(oldp+74,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re),48);
        bufp->chgQData(oldp+76,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im),48);
        bufp->chgQData(oldp+78,(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_energy),48);
        bufp->chgSData(oldp+80,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len),13);
        bufp->chgSData(oldp+81,(((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len))
                                  ? 0x0010U : ((0x0800U 
                                                == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len))
                                                ? 0x0040U
                                                : (
                                                   (0x1000U 
                                                    == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len))
                                                    ? 0x0080U
                                                    : 0x0040U)))),12);
        bufp->chgSData(oldp+82,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr),12);
        bufp->chgSData(oldp+83,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr),12);
        bufp->chgSData(oldp+84,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__delayed_re),16);
        bufp->chgSData(oldp+85,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__delayed_im),16);
        bufp->chgIData(oldp+86,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re_delayed),32);
        bufp->chgIData(oldp+87,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im_delayed),32);
        bufp->chgIData(oldp+88,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_delayed),32);
        bufp->chgQData(oldp+89,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re),48);
        bufp->chgQData(oldp+91,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im),48);
        bufp->chgQData(oldp+93,(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_energy),48);
        bufp->chgSData(oldp+95,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len),13);
        bufp->chgSData(oldp+96,(((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len))
                                  ? 0x0010U : ((0x0800U 
                                                == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len))
                                                ? 0x0040U
                                                : (
                                                   (0x1000U 
                                                    == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len))
                                                    ? 0x0080U
                                                    : 0x0040U)))),12);
        bufp->chgSData(oldp+97,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr),12);
        bufp->chgSData(oldp+98,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr),12);
        bufp->chgSData(oldp+99,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__delayed_re),16);
        bufp->chgSData(oldp+100,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__delayed_im),16);
        bufp->chgIData(oldp+101,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re_delayed),32);
        bufp->chgIData(oldp+102,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im_delayed),32);
        bufp->chgIData(oldp+103,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_delayed),32);
        bufp->chgQData(oldp+104,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re),48);
        bufp->chgQData(oldp+106,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im),48);
        bufp->chgQData(oldp+108,(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_energy),48);
    }
    bufp->chgBit(oldp+110,(vlSelfRef.clk));
    bufp->chgBit(oldp+111,(vlSelfRef.rst));
    bufp->chgCData(oldp+112,(vlSelfRef.mode_sel),2);
    bufp->chgSData(oldp+113,(vlSelfRef.din_re_0),16);
    bufp->chgSData(oldp+114,(vlSelfRef.din_im_0),16);
    bufp->chgSData(oldp+115,(vlSelfRef.din_re_1),16);
    bufp->chgSData(oldp+116,(vlSelfRef.din_im_1),16);
    bufp->chgSData(oldp+117,(vlSelfRef.din_re_2),16);
    bufp->chgSData(oldp+118,(vlSelfRef.din_im_2),16);
    bufp->chgSData(oldp+119,(vlSelfRef.din_re_3),16);
    bufp->chgSData(oldp+120,(vlSelfRef.din_im_3),16);
    bufp->chgBit(oldp+121,(vlSelfRef.din_valid));
    bufp->chgCData(oldp+122,(vlSelfRef.bits_out_0),8);
    bufp->chgBit(oldp+123,(vlSelfRef.bits_valid_0));
    bufp->chgCData(oldp+124,(vlSelfRef.bits_out_1),8);
    bufp->chgBit(oldp+125,(vlSelfRef.bits_valid_1));
    bufp->chgCData(oldp+126,(vlSelfRef.bits_out_2),8);
    bufp->chgBit(oldp+127,(vlSelfRef.bits_valid_2));
    bufp->chgCData(oldp+128,(vlSelfRef.bits_out_3),8);
    bufp->chgBit(oldp+129,(vlSelfRef.bits_valid_3));
    bufp->chgBit(oldp+130,(vlSelfRef.sync_found_combined));
    bufp->chgBit(oldp+131,(vlSelfRef.tready_global));
}

void Vmulti_standard_rx___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root__trace_cleanup\n"); );
    // Body
    Vmulti_standard_rx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmulti_standard_rx___024root*>(voidSelf);
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
