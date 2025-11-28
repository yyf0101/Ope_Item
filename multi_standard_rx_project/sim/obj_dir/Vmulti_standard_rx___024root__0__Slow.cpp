// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmulti_standard_rx.h for the primary calling header

#include "Vmulti_standard_rx__pch.h"

VL_ATTR_COLD void Vmulti_standard_rx___024root___eval_static(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_static\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
}

VL_ATTR_COLD void Vmulti_standard_rx___024root___eval_initial(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_initial\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmulti_standard_rx___024root___eval_final(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_final\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmulti_standard_rx___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmulti_standard_rx___024root___eval_phase__stl(Vmulti_standard_rx___024root* vlSelf);

VL_ATTR_COLD void Vmulti_standard_rx___024root___eval_settle(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_settle\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vmulti_standard_rx___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../rtl/../rtl/multi_standard_rx.v", 2, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vmulti_standard_rx___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vmulti_standard_rx___024root___eval_triggers__stl(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_triggers__stl\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmulti_standard_rx___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vmulti_standard_rx___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmulti_standard_rx___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vmulti_standard_rx___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vmulti_standard_rx___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<SData/*12:0*/, 4> Vmulti_standard_rx__ConstPool__TABLE_h638be961_0;
extern const VlUnpacked<SData/*8:0*/, 4> Vmulti_standard_rx__ConstPool__TABLE_h387259c0_0;
extern const VlUnpacked<CData/*3:0*/, 4> Vmulti_standard_rx__ConstPool__TABLE_h33cf680e_0;

VL_ATTR_COLD void Vmulti_standard_rx___024root___stl_sequent__TOP__0(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___stl_sequent__TOP__0\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*1:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    // Body
    vlSelfRef.sync_found_combined = vlSelfRef.multi_standard_rx__DOT__sync_combined;
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_term 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0))) 
           + VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_term 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1))) 
           + VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_term 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2))) 
           + VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_term 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3))) 
           + VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3))));
    vlSelfRef.multi_standard_rx__DOT__corr_E_0 = (VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re)) 
                                                  + 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im)));
    vlSelfRef.multi_standard_rx__DOT__corr_E_1 = (VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re)) 
                                                  + 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im)));
    vlSelfRef.multi_standard_rx__DOT__corr_E_2 = (VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re)) 
                                                  + 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im)));
    vlSelfRef.multi_standard_rx__DOT__corr_E_3 = (VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re)) 
                                                  + 
                                                  VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im)));
    vlSelfRef.multi_standard_rx__DOT__total_E_0 = VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_energy), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_energy));
    vlSelfRef.multi_standard_rx__DOT__total_E_1 = VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_energy), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_energy));
    vlSelfRef.multi_standard_rx__DOT__total_E_2 = VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_energy), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_energy));
    vlSelfRef.multi_standard_rx__DOT__total_E_3 = VL_MULS_QQQ(64, 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_energy), 
                                                              VL_EXTENDS_QQ(64,48, vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_energy));
    __Vtableidx1 = vlSelfRef.mode_sel;
    vlSelfRef.multi_standard_rx__DOT__fft_len = Vmulti_standard_rx__ConstPool__TABLE_h638be961_0
        [__Vtableidx1];
    vlSelfRef.multi_standard_rx__DOT__cp_len = Vmulti_standard_rx__ConstPool__TABLE_h387259c0_0
        [__Vtableidx1];
    vlSelfRef.multi_standard_rx__DOT__mod_type = Vmulti_standard_rx__ConstPool__TABLE_h33cf680e_0
        [__Vtableidx1];
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr 
        = (0x00000fffU & ((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr) 
                          - ((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len))
                              ? 0x0010U : ((0x0800U 
                                            == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len))
                                            ? 0x0040U
                                            : ((0x1000U 
                                                == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len))
                                                ? 0x0080U
                                                : 0x0040U)))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr 
        = (0x00000fffU & ((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr) 
                          - ((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len))
                              ? 0x0010U : ((0x0800U 
                                            == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len))
                                            ? 0x0040U
                                            : ((0x1000U 
                                                == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len))
                                                ? 0x0080U
                                                : 0x0040U)))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr 
        = (0x00000fffU & ((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr) 
                          - ((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len))
                              ? 0x0010U : ((0x0800U 
                                            == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len))
                                            ? 0x0040U
                                            : ((0x1000U 
                                                == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len))
                                                ? 0x0080U
                                                : 0x0040U)))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr 
        = (0x00000fffU & ((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr) 
                          - ((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len))
                              ? 0x0010U : ((0x0800U 
                                            == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len))
                                            ? 0x0040U
                                            : ((0x1000U 
                                                == (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len))
                                                ? 0x0080U
                                                : 0x0040U)))));
    __Vtemp_2[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__total_E_0);
    __Vtemp_2[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__total_E_0 
                             >> 0x00000020U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__total_E_1);
    __Vtemp_3[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__total_E_1 
                             >> 0x00000020U));
    __Vtemp_3[2U] = 0U;
    __Vtemp_4[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__total_E_2);
    __Vtemp_4[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__total_E_2 
                             >> 0x00000020U));
    __Vtemp_4[2U] = 0U;
    __Vtemp_5[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__total_E_3);
    __Vtemp_5[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__total_E_3 
                             >> 0x00000020U));
    __Vtemp_5[2U] = 0U;
    VL_ADD_W(3, __Vtemp_6, __Vtemp_4, __Vtemp_5);
    VL_ADD_W(3, __Vtemp_7, __Vtemp_3, __Vtemp_6);
    VL_ADD_W(3, __Vtemp_8, __Vtemp_2, __Vtemp_7);
    vlSelfRef.multi_standard_rx__DOT__sum_total_E[0U] 
        = __Vtemp_8[0U];
    vlSelfRef.multi_standard_rx__DOT__sum_total_E[1U] 
        = __Vtemp_8[1U];
    vlSelfRef.multi_standard_rx__DOT__sum_total_E[2U] 
        = (3U & __Vtemp_8[2U]);
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delayed_re 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__buf_re
        [vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delayed_im 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__buf_im
        [vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__delayed_re 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__buf_re
        [vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__delayed_im 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__buf_im
        [vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__delayed_re 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__buf_re
        [vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__delayed_im 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__buf_im
        [vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_delayed 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_buf
        [vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__delayed_re 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__buf_re
        [vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__delayed_im 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__buf_im
        [vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr];
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delayed_re))) 
           + VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delayed_im))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delayed_re))) 
           - VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delayed_im))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__delayed_re))) 
           + VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__delayed_im))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__delayed_re))) 
           - VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__delayed_im))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__delayed_re))) 
           + VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__delayed_im))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__delayed_re))) 
           - VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__delayed_im))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__delayed_re))) 
           + VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__delayed_im))));
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im 
        = (VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3)), 
                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__delayed_re))) 
           - VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3)), 
                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__delayed_im))));
}

VL_ATTR_COLD void Vmulti_standard_rx___024root____Vm_traceActivitySetAll(Vmulti_standard_rx___024root* vlSelf);

VL_ATTR_COLD void Vmulti_standard_rx___024root___eval_stl(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_stl\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vmulti_standard_rx___024root___stl_sequent__TOP__0(vlSelf);
        Vmulti_standard_rx___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vmulti_standard_rx___024root___eval_phase__stl(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_phase__stl\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmulti_standard_rx___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vmulti_standard_rx___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vmulti_standard_rx___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vmulti_standard_rx___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmulti_standard_rx___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vmulti_standard_rx___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vmulti_standard_rx___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmulti_standard_rx___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vmulti_standard_rx___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmulti_standard_rx___024root____Vm_traceActivitySetAll(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root____Vm_traceActivitySetAll\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
}

VL_ATTR_COLD void Vmulti_standard_rx___024root___ctor_var_reset(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___ctor_var_reset\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->mode_sel = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10611238142426516554ull);
    vlSelf->din_re_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14711404660530949383ull);
    vlSelf->din_im_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 468690345139991387ull);
    vlSelf->din_re_1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15890029932414307343ull);
    vlSelf->din_im_1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 810038348378617184ull);
    vlSelf->din_re_2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3969037676861010652ull);
    vlSelf->din_im_2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14063522716037664228ull);
    vlSelf->din_re_3 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14937376575934128639ull);
    vlSelf->din_im_3 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17765601830346695288ull);
    vlSelf->din_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10850846927420885006ull);
    vlSelf->bits_out_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14774623717065534246ull);
    vlSelf->bits_valid_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14382003003840148304ull);
    vlSelf->bits_out_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15838283843552615675ull);
    vlSelf->bits_valid_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 106826687132206166ull);
    vlSelf->bits_out_2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1294689027584825979ull);
    vlSelf->bits_valid_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7946248239403910990ull);
    vlSelf->bits_out_3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12396368174232462152ull);
    vlSelf->bits_valid_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16918268148187754229ull);
    vlSelf->sync_found_combined = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13617738379863895274ull);
    vlSelf->tready_global = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8262224071140035809ull);
    vlSelf->multi_standard_rx__DOT__fft_len = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 2475468519966770389ull);
    vlSelf->multi_standard_rx__DOT__cp_len = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 7240345714678099902ull);
    vlSelf->multi_standard_rx__DOT__mod_type = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12897575935566243651ull);
    vlSelf->multi_standard_rx__DOT__config_update = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1528554626118504902ull);
    vlSelf->multi_standard_rx__DOT__sync_found_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2212708803575190895ull);
    vlSelf->multi_standard_rx__DOT__sync_found_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12991037366044703276ull);
    vlSelf->multi_standard_rx__DOT__sync_found_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11584508745100249411ull);
    vlSelf->multi_standard_rx__DOT__sync_found_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11722314315168543744ull);
    vlSelf->multi_standard_rx__DOT__freq_offset_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7113187017908332305ull);
    vlSelf->multi_standard_rx__DOT__freq_offset_1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7013763694120205622ull);
    vlSelf->multi_standard_rx__DOT__freq_offset_2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4085745728432397349ull);
    vlSelf->multi_standard_rx__DOT__freq_offset_3 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10797311703040136270ull);
    vlSelf->multi_standard_rx__DOT__corr_E_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5365376794079151769ull);
    vlSelf->multi_standard_rx__DOT__corr_E_1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8534743224696940431ull);
    vlSelf->multi_standard_rx__DOT__corr_E_2 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16860006955550014109ull);
    vlSelf->multi_standard_rx__DOT__corr_E_3 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16522418863005375621ull);
    vlSelf->multi_standard_rx__DOT__total_E_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 13668174128640838306ull);
    vlSelf->multi_standard_rx__DOT__total_E_1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7639402016478154352ull);
    vlSelf->multi_standard_rx__DOT__total_E_2 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15560064287540002210ull);
    vlSelf->multi_standard_rx__DOT__total_E_3 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1239682470736554472ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->multi_standard_rx__DOT__sum_total_E, __VscopeHash, 4777916633079440834ull);
    vlSelf->multi_standard_rx__DOT__sync_combined = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15586220782834442424ull);
    vlSelf->multi_standard_rx__DOT__u_mode_ctrl__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4660086561852507353ull);
    vlSelf->multi_standard_rx__DOT__u_mode_ctrl__DOT__current_mode = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15518474288330263765ull);
    vlSelf->multi_standard_rx__DOT__u_mode_ctrl__DOT__timer = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12353605819522528361ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 7750980670311850929ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__buf_re[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5471936684030454941ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__buf_im[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1023995064859566445ull);
    }
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 17841449295457672559ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 1296711163957332177ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__delayed_re = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9985315256091487396ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__delayed_im = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11954256931659835543ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__prod_re = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8967757164189266089ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__prod_im = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16060801846227865869ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__energy_term = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5358295598196270269ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13597913982871054485ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3657153412517425325ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__energy_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10106871149002910063ull);
    }
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__prod_re_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18191619960120346318ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__prod_im_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5906810795125443713ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__energy_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10392000606990298807ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 17616613074850278072ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9734154761162318890ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__sum_energy = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3300751469116923333ull);
    vlSelf->multi_standard_rx__DOT__u_sync_0__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 677027171312029163ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 12451832019990786180ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__buf_re[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15044848978721467904ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__buf_im[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7057458430371495910ull);
    }
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 11205625645177872371ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 7798386761023826487ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__delayed_re = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16860285324106919519ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__delayed_im = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17548576259181193861ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__prod_re = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15320267861681673128ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__prod_im = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14310516941802130759ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__energy_term = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5686398339210365650ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13081604277534376179ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4755049111603532446ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__energy_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5087118873393668485ull);
    }
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__prod_re_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10303629255696510397ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__prod_im_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13266920393221383792ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__energy_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8558267836533541927ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 15713945529539017562ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1905315574036399266ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__sum_energy = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6435689634806668313ull);
    vlSelf->multi_standard_rx__DOT__u_sync_1__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8357676335449313956ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 15264848235491209338ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__buf_re[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3180855584828841668ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__buf_im[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14802921635744383190ull);
    }
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 2014514290564018748ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 4048513849236699461ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__delayed_re = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10619554934113277011ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__delayed_im = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18334282795488110941ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__prod_re = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5087456087039531982ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__prod_im = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2353302514886333848ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__energy_term = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14348283803970463838ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6682569130647873886ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6109922490550697265ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__energy_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3150535120909917410ull);
    }
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__prod_re_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8222722072045152638ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__prod_im_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13907771155447568614ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__energy_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2320862561707997273ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1927965555302033454ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 10953437357033882586ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__sum_energy = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 8256795877199381087ull);
    vlSelf->multi_standard_rx__DOT__u_sync_2__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5777631870577737731ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 858761316457514554ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__buf_re[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5304549415523354870ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__buf_im[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13951097043626923236ull);
    }
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 10451163018537656288ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 11347447523938443446ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__delayed_re = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16672840136393593388ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__delayed_im = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17279285546917449741ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__prod_re = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15684730620195779983ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__prod_im = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4030522953780758566ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__energy_term = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10816255638323201607ull);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11285100260138999537ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12967049952677589265ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__energy_buf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 70392337202750467ull);
    }
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__prod_re_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12742227694305771949ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__prod_im_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10800860412887567514ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__energy_delayed = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9355661560657641179ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 18252061227201341637ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 543608820946634956ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__sum_energy = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3245013450374987040ull);
    vlSelf->multi_standard_rx__DOT__u_sync_3__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8830529432682340ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
