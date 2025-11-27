// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmulti_standard_rx.h for the primary calling header

#include "Vmulti_standard_rx__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmulti_standard_rx___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vmulti_standard_rx___024root___eval_triggers__ico(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_triggers__ico\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmulti_standard_rx___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vmulti_standard_rx___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___trigger_anySet__ico\n"); );
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

void Vmulti_standard_rx___024root___ico_sequent__TOP__0(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___ico_sequent__TOP__0\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vmulti_standard_rx___024root___eval_ico(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_ico\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vmulti_standard_rx___024root___ico_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

bool Vmulti_standard_rx___024root___eval_phase__ico(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_phase__ico\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vmulti_standard_rx___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vmulti_standard_rx___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vmulti_standard_rx___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmulti_standard_rx___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vmulti_standard_rx___024root___eval_triggers__act(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_triggers__act\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.rst) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmulti_standard_rx___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vmulti_standard_rx___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___trigger_anySet__act\n"); );
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

extern const VlUnpacked<CData/*2:0*/, 8> Vmulti_standard_rx__ConstPool__TABLE_h8c663b9c_0;
extern const VlUnpacked<SData/*11:0*/, 8> Vmulti_standard_rx__ConstPool__TABLE_h8f8b67a3_0;
extern const VlUnpacked<CData/*7:0*/, 8> Vmulti_standard_rx__ConstPool__TABLE_h30ec8afa_0;
extern const VlUnpacked<CData/*3:0*/, 8> Vmulti_standard_rx__ConstPool__TABLE_h265e07c9_0;

void Vmulti_standard_rx___024root___nba_sequent__TOP__0(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___nba_sequent__TOP__0\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*6:0*/ __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
    __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re;
    __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im;
    __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_energy;
    __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_energy = 0;
    CData/*6:0*/ __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
    __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re;
    __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im;
    __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_energy;
    __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_energy = 0;
    CData/*6:0*/ __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
    __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re;
    __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im;
    __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_energy;
    __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_energy = 0;
    CData/*6:0*/ __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
    __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re;
    __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im;
    __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im = 0;
    QData/*47:0*/ __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_energy;
    __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_energy = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v0 = 0;
    SData/*15:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v0 = 0;
    SData/*15:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v0 = 0;
    SData/*15:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v0 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v0;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v0 = 0;
    SData/*15:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v1 = 0;
    SData/*15:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v1 = 0;
    IData/*31:0*/ __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v1;
    __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v1 = 0;
    CData/*6:0*/ __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v1;
    __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v1 = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_10;
    VlWide<3>/*95:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<3>/*95:0*/ __Vtemp_15;
    VlWide<3>/*95:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_17;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<3>/*95:0*/ __Vtemp_19;
    VlWide<3>/*95:0*/ __Vtemp_20;
    VlWide<3>/*95:0*/ __Vtemp_21;
    // Body
    __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re;
    __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im;
    __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re;
    __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im;
    __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re;
    __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im;
    __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re;
    __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im;
    __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_energy 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_energy;
    __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_energy 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_energy;
    __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_energy 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_energy;
    __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_energy 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_energy;
    __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
    __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
    __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
    __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr 
        = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
    if (vlSelfRef.rst) {
        __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re = 0ULL;
        __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im = 0ULL;
        __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re = 0ULL;
        __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im = 0ULL;
        __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re = 0ULL;
        __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im = 0ULL;
        __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re = 0ULL;
        __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im = 0ULL;
    } else if (vlSelfRef.din_valid) {
        __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re 
            = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re 
                                         + (((QData)((IData)(
                                                             (0x0000ffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re 
                                                                            >> 0x1fU)))))) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re)))) 
                                        - (((QData)((IData)(
                                                            (0x0000ffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re_delayed 
                                                                           >> 0x1fU)))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re_delayed)))));
        __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im 
            = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im 
                                         + (((QData)((IData)(
                                                             (0x0000ffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im 
                                                                            >> 0x1fU)))))) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im)))) 
                                        - (((QData)((IData)(
                                                            (0x0000ffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im_delayed 
                                                                           >> 0x1fU)))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im_delayed)))));
        __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re 
            = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re 
                                         + (((QData)((IData)(
                                                             (0x0000ffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re 
                                                                            >> 0x1fU)))))) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re)))) 
                                        - (((QData)((IData)(
                                                            (0x0000ffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re_delayed 
                                                                           >> 0x1fU)))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re_delayed)))));
        __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im 
            = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im 
                                         + (((QData)((IData)(
                                                             (0x0000ffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im 
                                                                            >> 0x1fU)))))) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im)))) 
                                        - (((QData)((IData)(
                                                            (0x0000ffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im_delayed 
                                                                           >> 0x1fU)))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im_delayed)))));
        __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re 
            = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re 
                                         + (((QData)((IData)(
                                                             (0x0000ffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re 
                                                                            >> 0x1fU)))))) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re)))) 
                                        - (((QData)((IData)(
                                                            (0x0000ffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re_delayed 
                                                                           >> 0x1fU)))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re_delayed)))));
        __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im 
            = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im 
                                         + (((QData)((IData)(
                                                             (0x0000ffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im 
                                                                            >> 0x1fU)))))) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im)))) 
                                        - (((QData)((IData)(
                                                            (0x0000ffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im_delayed 
                                                                           >> 0x1fU)))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im_delayed)))));
        __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re 
            = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re 
                                         + (((QData)((IData)(
                                                             (0x0000ffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re 
                                                                            >> 0x1fU)))))) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re)))) 
                                        - (((QData)((IData)(
                                                            (0x0000ffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re_delayed 
                                                                           >> 0x1fU)))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re_delayed)))));
        __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im 
            = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im 
                                         + (((QData)((IData)(
                                                             (0x0000ffffU 
                                                              & (- (IData)(
                                                                           (vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im 
                                                                            >> 0x1fU)))))) 
                                             << 0x00000020U) 
                                            | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im)))) 
                                        - (((QData)((IData)(
                                                            (0x0000ffffU 
                                                             & (- (IData)(
                                                                          (vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im_delayed 
                                                                           >> 0x1fU)))))) 
                                            << 0x00000020U) 
                                           | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im_delayed)))));
    }
    if (vlSelfRef.rst) {
        vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i = 0U;
        __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr = 0U;
        while (VL_GTS_III(32, 0x00000080U, vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i)) {
            __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__buf_re.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__buf_im.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__prod_re_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__prod_im_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__energy_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v0));
            vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i 
                = ((IData)(1U) + vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__i);
        }
    } else if (vlSelfRef.din_valid) {
        __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v1 
            = vlSelfRef.din_re_0;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__buf_re.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_re__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v1 
            = vlSelfRef.din_im_0;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__buf_im.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__buf_im__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__prod_re_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__prod_im_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_term;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__energy_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_0__DOT__energy_buf__v1));
        __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr 
            = (0x0000007fU & ((IData)(1U) + (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr)));
    }
    if (vlSelfRef.rst) {
        vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i = 0U;
        __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr = 0U;
        while (VL_GTS_III(32, 0x00000080U, vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i)) {
            __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__buf_re.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__buf_im.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__prod_re_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__prod_im_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__energy_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v0));
            vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i 
                = ((IData)(1U) + vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__i);
        }
    } else if (vlSelfRef.din_valid) {
        __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v1 
            = vlSelfRef.din_re_1;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__buf_re.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_re__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v1 
            = vlSelfRef.din_im_1;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__buf_im.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__buf_im__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__prod_re_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__prod_im_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_term;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__energy_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_1__DOT__energy_buf__v1));
        __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr 
            = (0x0000007fU & ((IData)(1U) + (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr)));
    }
    if (vlSelfRef.rst) {
        vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i = 0U;
        __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr = 0U;
        while (VL_GTS_III(32, 0x00000080U, vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i)) {
            __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__buf_re.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__buf_im.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__prod_re_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__prod_im_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__energy_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v0));
            vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i 
                = ((IData)(1U) + vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__i);
        }
    } else if (vlSelfRef.din_valid) {
        __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v1 
            = vlSelfRef.din_re_2;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__buf_re.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_re__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v1 
            = vlSelfRef.din_im_2;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__buf_im.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__buf_im__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__prod_re_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__prod_im_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_term;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__energy_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_2__DOT__energy_buf__v1));
        __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr 
            = (0x0000007fU & ((IData)(1U) + (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr)));
    }
    if (vlSelfRef.rst) {
        vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i = 0U;
        __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr = 0U;
        while (VL_GTS_III(32, 0x00000080U, vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i)) {
            __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__buf_re.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__buf_im.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__prod_re_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__prod_im_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v0));
            __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v0 
                = (0x0000007fU & vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i);
            vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__energy_buf.enqueue(0U, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v0));
            vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i 
                = ((IData)(1U) + vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__i);
        }
    } else if (vlSelfRef.din_valid) {
        __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v1 
            = vlSelfRef.din_re_3;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__buf_re.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_re__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v1 
            = vlSelfRef.din_im_3;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__buf_im.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__buf_im__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__prod_re_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__prod_im_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf__v1));
        __VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_term;
        __VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v1 
            = vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
        vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__energy_buf.enqueue(__VdlyVal__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v1, (IData)(__VdlyDim0__multi_standard_rx__DOT__u_sync_3__DOT__energy_buf__v1));
        __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr 
            = (0x0000007fU & ((IData)(1U) + (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr)));
    }
    if (vlSelfRef.rst) {
        vlSelfRef.multi_standard_rx__DOT__freq_offset_0 = 0U;
        vlSelfRef.multi_standard_rx__DOT__freq_offset_1 = 0U;
        vlSelfRef.multi_standard_rx__DOT__freq_offset_2 = 0U;
        vlSelfRef.multi_standard_rx__DOT__freq_offset_3 = 0U;
        __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_energy = 0ULL;
        vlSelfRef.multi_standard_rx__DOT__sync_found_0 = 0U;
        __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_energy = 0ULL;
        vlSelfRef.multi_standard_rx__DOT__sync_found_1 = 0U;
        __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_energy = 0ULL;
        vlSelfRef.multi_standard_rx__DOT__sync_found_2 = 0U;
        __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_energy = 0ULL;
        vlSelfRef.multi_standard_rx__DOT__sync_found_3 = 0U;
        vlSelfRef.bits_out_0 = 0U;
        vlSelfRef.bits_out_1 = 0U;
        vlSelfRef.bits_out_2 = 0U;
        vlSelfRef.bits_out_3 = 0U;
    } else {
        if (vlSelfRef.din_valid) {
            __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_energy 
                = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_energy 
                                             + (((QData)((IData)(
                                                                 (0x0000ffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_term 
                                                                                >> 0x1fU)))))) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_term)))) 
                                            - (((QData)((IData)(
                                                                (0x0000ffffU 
                                                                 & (- (IData)(
                                                                              (vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_delayed 
                                                                               >> 0x1fU)))))) 
                                                << 0x00000020U) 
                                               | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_delayed)))));
            vlSelfRef.multi_standard_rx__DOT__sync_found_0 
                = ((0x00000000000f4240ULL < vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_energy) 
                   && (vlSelfRef.multi_standard_rx__DOT__corr_E_0 
                       > VL_SHIFTR_QQI(64,64,32, vlSelfRef.multi_standard_rx__DOT__total_E_0, 1U)));
            __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_energy 
                = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_energy 
                                             + (((QData)((IData)(
                                                                 (0x0000ffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_term 
                                                                                >> 0x1fU)))))) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_term)))) 
                                            - (((QData)((IData)(
                                                                (0x0000ffffU 
                                                                 & (- (IData)(
                                                                              (vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_delayed 
                                                                               >> 0x1fU)))))) 
                                                << 0x00000020U) 
                                               | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_delayed)))));
            vlSelfRef.multi_standard_rx__DOT__sync_found_1 
                = ((0x00000000000f4240ULL < vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_energy) 
                   && (vlSelfRef.multi_standard_rx__DOT__corr_E_1 
                       > VL_SHIFTR_QQI(64,64,32, vlSelfRef.multi_standard_rx__DOT__total_E_1, 1U)));
            __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_energy 
                = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_energy 
                                             + (((QData)((IData)(
                                                                 (0x0000ffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_term 
                                                                                >> 0x1fU)))))) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_term)))) 
                                            - (((QData)((IData)(
                                                                (0x0000ffffU 
                                                                 & (- (IData)(
                                                                              (vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_delayed 
                                                                               >> 0x1fU)))))) 
                                                << 0x00000020U) 
                                               | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_delayed)))));
            vlSelfRef.multi_standard_rx__DOT__sync_found_2 
                = ((0x00000000000f4240ULL < vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_energy) 
                   && (vlSelfRef.multi_standard_rx__DOT__corr_E_2 
                       > VL_SHIFTR_QQI(64,64,32, vlSelfRef.multi_standard_rx__DOT__total_E_2, 1U)));
            __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_energy 
                = (0x0000ffffffffffffULL & ((vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_energy 
                                             + (((QData)((IData)(
                                                                 (0x0000ffffU 
                                                                  & (- (IData)(
                                                                               (vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_term 
                                                                                >> 0x1fU)))))) 
                                                 << 0x00000020U) 
                                                | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_term)))) 
                                            - (((QData)((IData)(
                                                                (0x0000ffffU 
                                                                 & (- (IData)(
                                                                              (vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_delayed 
                                                                               >> 0x1fU)))))) 
                                                << 0x00000020U) 
                                               | (QData)((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_delayed)))));
            vlSelfRef.multi_standard_rx__DOT__sync_found_3 
                = ((0x00000000000f4240ULL < vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_energy) 
                   && (vlSelfRef.multi_standard_rx__DOT__corr_E_3 
                       > VL_SHIFTR_QQI(64,64,32, vlSelfRef.multi_standard_rx__DOT__total_E_3, 1U)));
        }
        if (vlSelfRef.multi_standard_rx__DOT__sync_combined) {
            if ((0U == (IData)(vlSelfRef.multi_standard_rx__DOT__mod_type))) {
                vlSelfRef.bits_out_0 = ((0xfcU & (IData)(vlSelfRef.bits_out_0)) 
                                        | ((VL_GTES_III(32, 0U, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0))) 
                                            << 1U) 
                                           | VL_GTES_III(32, 0U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0)))));
                vlSelfRef.bits_out_1 = ((0xfcU & (IData)(vlSelfRef.bits_out_1)) 
                                        | ((VL_GTES_III(32, 0U, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1))) 
                                            << 1U) 
                                           | VL_GTES_III(32, 0U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1)))));
                vlSelfRef.bits_out_2 = ((0xfcU & (IData)(vlSelfRef.bits_out_2)) 
                                        | ((VL_GTES_III(32, 0U, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2))) 
                                            << 1U) 
                                           | VL_GTES_III(32, 0U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2)))));
                vlSelfRef.bits_out_3 = ((0xfcU & (IData)(vlSelfRef.bits_out_3)) 
                                        | ((VL_GTES_III(32, 0U, 
                                                        VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3))) 
                                            << 1U) 
                                           | VL_GTES_III(32, 0U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3)))));
            } else if ((1U == (IData)(vlSelfRef.multi_standard_rx__DOT__mod_type))) {
                vlSelfRef.bits_out_0 = ((0xf7U & (IData)(vlSelfRef.bits_out_0)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0))) 
                                           << 3U));
                vlSelfRef.bits_out_0 = ((0xfbU & (IData)(vlSelfRef.bits_out_0)) 
                                        | ((VL_LTS_III(32, 0U, 
                                                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0)))
                                             ? VL_LTS_III(32, 0x00004e20U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0)))
                                             : VL_LTS_III(32, 0xffffb1e0U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_0)))) 
                                           << 2U));
                vlSelfRef.bits_out_0 = ((0xfdU & (IData)(vlSelfRef.bits_out_0)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0))) 
                                           << 1U));
                vlSelfRef.bits_out_0 = ((0xfeU & (IData)(vlSelfRef.bits_out_0)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0)))
                                            ? VL_LTS_III(32, 0x00004e20U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0)))
                                            : VL_LTS_III(32, 0xffffb1e0U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_0)))));
                vlSelfRef.bits_out_1 = ((0xf7U & (IData)(vlSelfRef.bits_out_1)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1))) 
                                           << 3U));
                vlSelfRef.bits_out_1 = ((0xfbU & (IData)(vlSelfRef.bits_out_1)) 
                                        | ((VL_LTS_III(32, 0U, 
                                                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1)))
                                             ? VL_LTS_III(32, 0x00004e20U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1)))
                                             : VL_LTS_III(32, 0xffffb1e0U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_1)))) 
                                           << 2U));
                vlSelfRef.bits_out_1 = ((0xfdU & (IData)(vlSelfRef.bits_out_1)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1))) 
                                           << 1U));
                vlSelfRef.bits_out_1 = ((0xfeU & (IData)(vlSelfRef.bits_out_1)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1)))
                                            ? VL_LTS_III(32, 0x00004e20U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1)))
                                            : VL_LTS_III(32, 0xffffb1e0U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_1)))));
                vlSelfRef.bits_out_2 = ((0xf7U & (IData)(vlSelfRef.bits_out_2)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2))) 
                                           << 3U));
                vlSelfRef.bits_out_2 = ((0xfbU & (IData)(vlSelfRef.bits_out_2)) 
                                        | ((VL_LTS_III(32, 0U, 
                                                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2)))
                                             ? VL_LTS_III(32, 0x00004e20U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2)))
                                             : VL_LTS_III(32, 0xffffb1e0U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_2)))) 
                                           << 2U));
                vlSelfRef.bits_out_2 = ((0xfdU & (IData)(vlSelfRef.bits_out_2)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2))) 
                                           << 1U));
                vlSelfRef.bits_out_2 = ((0xfeU & (IData)(vlSelfRef.bits_out_2)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2)))
                                            ? VL_LTS_III(32, 0x00004e20U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2)))
                                            : VL_LTS_III(32, 0xffffb1e0U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_2)))));
                vlSelfRef.bits_out_3 = ((0xf7U & (IData)(vlSelfRef.bits_out_3)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3))) 
                                           << 3U));
                vlSelfRef.bits_out_3 = ((0xfbU & (IData)(vlSelfRef.bits_out_3)) 
                                        | ((VL_LTS_III(32, 0U, 
                                                       VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3)))
                                             ? VL_LTS_III(32, 0x00004e20U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3)))
                                             : VL_LTS_III(32, 0xffffb1e0U, 
                                                          VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_re_3)))) 
                                           << 2U));
                vlSelfRef.bits_out_3 = ((0xfdU & (IData)(vlSelfRef.bits_out_3)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3))) 
                                           << 1U));
                vlSelfRef.bits_out_3 = ((0xfeU & (IData)(vlSelfRef.bits_out_3)) 
                                        | (VL_LTS_III(32, 0U, 
                                                      VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3)))
                                            ? VL_LTS_III(32, 0x00004e20U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3)))
                                            : VL_LTS_III(32, 0xffffb1e0U, 
                                                         VL_EXTENDS_II(32,16, (IData)(vlSelfRef.din_im_3)))));
            }
        }
    }
    vlSelfRef.bits_valid_0 = ((1U & (~ (IData)(vlSelfRef.rst))) 
                              && (IData)(vlSelfRef.multi_standard_rx__DOT__sync_combined));
    vlSelfRef.bits_valid_1 = ((1U & (~ (IData)(vlSelfRef.rst))) 
                              && (IData)(vlSelfRef.multi_standard_rx__DOT__sync_combined));
    vlSelfRef.bits_valid_2 = ((1U & (~ (IData)(vlSelfRef.rst))) 
                              && (IData)(vlSelfRef.multi_standard_rx__DOT__sync_combined));
    vlSelfRef.bits_valid_3 = ((1U & (~ (IData)(vlSelfRef.rst))) 
                              && (IData)(vlSelfRef.multi_standard_rx__DOT__sync_combined));
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re 
        = __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re;
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im 
        = __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im;
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re 
        = __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re;
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im 
        = __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im;
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re 
        = __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re;
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im 
        = __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im;
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re 
        = __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re;
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im 
        = __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im;
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__prod_re_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__prod_im_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__energy_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__energy_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__buf_re.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__buf_re);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_0__DOT__buf_im.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__buf_im);
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr 
        = __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__prod_re_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__prod_im_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__energy_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__energy_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__buf_re.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__buf_re);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_1__DOT__buf_im.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__buf_im);
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr 
        = __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__prod_re_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__prod_im_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__energy_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__energy_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__buf_re.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__buf_re);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_2__DOT__buf_im.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__buf_im);
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr 
        = __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__prod_re_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__prod_im_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__energy_buf.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__energy_buf);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__buf_re.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__buf_re);
    vlSelfRef.__VdlyCommitQueuemulti_standard_rx__DOT__u_sync_3__DOT__buf_im.commit(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__buf_im);
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr 
        = __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__sum_energy 
        = __Vdly__multi_standard_rx__DOT__u_sync_0__DOT__sum_energy;
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__sum_energy 
        = __Vdly__multi_standard_rx__DOT__u_sync_1__DOT__sum_energy;
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__sum_energy 
        = __Vdly__multi_standard_rx__DOT__u_sync_2__DOT__sum_energy;
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__sum_energy 
        = __Vdly__multi_standard_rx__DOT__u_sync_3__DOT__sum_energy;
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
    __Vtemp_1[0U] = 0x003d0900U;
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    __Vtemp_3[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__corr_E_0);
    __Vtemp_3[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__corr_E_0 
                             >> 0x00000020U));
    __Vtemp_3[2U] = 0U;
    __Vtemp_4[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__corr_E_1);
    __Vtemp_4[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__corr_E_1 
                             >> 0x00000020U));
    __Vtemp_4[2U] = 0U;
    __Vtemp_5[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__corr_E_2);
    __Vtemp_5[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__corr_E_2 
                             >> 0x00000020U));
    __Vtemp_5[2U] = 0U;
    __Vtemp_6[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__corr_E_3);
    __Vtemp_6[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__corr_E_3 
                             >> 0x00000020U));
    __Vtemp_6[2U] = 0U;
    VL_ADD_W(3, __Vtemp_7, __Vtemp_5, __Vtemp_6);
    VL_ADD_W(3, __Vtemp_8, __Vtemp_4, __Vtemp_7);
    VL_ADD_W(3, __Vtemp_9, __Vtemp_3, __Vtemp_8);
    __Vtemp_10[0U] = __Vtemp_9[0U];
    __Vtemp_10[1U] = __Vtemp_9[1U];
    __Vtemp_10[2U] = (3U & __Vtemp_9[2U]);
    VL_SHIFTR_WWI(66,66,32, __Vtemp_12, vlSelfRef.multi_standard_rx__DOT__sum_total_E, 1U);
    __Vtemp_13[0U] = __Vtemp_12[0U];
    __Vtemp_13[1U] = __Vtemp_12[1U];
    __Vtemp_13[2U] = (3U & __Vtemp_12[2U]);
    vlSelfRef.multi_standard_rx__DOT__sync_combined 
        = ((1U & (~ (IData)(vlSelfRef.rst))) && (VL_LT_W(3, __Vtemp_1, vlSelfRef.multi_standard_rx__DOT__sum_total_E) 
                                                 && VL_GT_W(3, __Vtemp_10, __Vtemp_13)));
    __Vtableidx1 = (((IData)(vlSelfRef.mode_sel) << 1U) 
                    | (IData)(vlSelfRef.rst));
    if ((1U & Vmulti_standard_rx__ConstPool__TABLE_h8c663b9c_0
         [__Vtableidx1])) {
        vlSelfRef.multi_standard_rx__DOT__fft_len = 
            Vmulti_standard_rx__ConstPool__TABLE_h8f8b67a3_0
            [__Vtableidx1];
    }
    if ((2U & Vmulti_standard_rx__ConstPool__TABLE_h8c663b9c_0
         [__Vtableidx1])) {
        vlSelfRef.multi_standard_rx__DOT__cp_len = 
            Vmulti_standard_rx__ConstPool__TABLE_h30ec8afa_0
            [__Vtableidx1];
    }
    if ((4U & Vmulti_standard_rx__ConstPool__TABLE_h8c663b9c_0
         [__Vtableidx1])) {
        vlSelfRef.multi_standard_rx__DOT__mod_type 
            = Vmulti_standard_rx__ConstPool__TABLE_h265e07c9_0
            [__Vtableidx1];
    }
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
    __Vtemp_15[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__total_E_0);
    __Vtemp_15[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__total_E_0 
                              >> 0x00000020U));
    __Vtemp_15[2U] = 0U;
    __Vtemp_16[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__total_E_1);
    __Vtemp_16[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__total_E_1 
                              >> 0x00000020U));
    __Vtemp_16[2U] = 0U;
    __Vtemp_17[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__total_E_2);
    __Vtemp_17[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__total_E_2 
                              >> 0x00000020U));
    __Vtemp_17[2U] = 0U;
    __Vtemp_18[0U] = (IData)(vlSelfRef.multi_standard_rx__DOT__total_E_3);
    __Vtemp_18[1U] = (IData)((vlSelfRef.multi_standard_rx__DOT__total_E_3 
                              >> 0x00000020U));
    __Vtemp_18[2U] = 0U;
    VL_ADD_W(3, __Vtemp_19, __Vtemp_17, __Vtemp_18);
    VL_ADD_W(3, __Vtemp_20, __Vtemp_16, __Vtemp_19);
    VL_ADD_W(3, __Vtemp_21, __Vtemp_15, __Vtemp_20);
    vlSelfRef.multi_standard_rx__DOT__sum_total_E[0U] 
        = __Vtemp_21[0U];
    vlSelfRef.multi_standard_rx__DOT__sum_total_E[1U] 
        = __Vtemp_21[1U];
    vlSelfRef.multi_standard_rx__DOT__sum_total_E[2U] 
        = (3U & __Vtemp_21[2U]);
    vlSelfRef.sync_found_combined = vlSelfRef.multi_standard_rx__DOT__sync_combined;
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delay_len 
        = ((0x0100U == (IData)(vlSelfRef.multi_standard_rx__DOT__fft_len))
            ? 0x10U : ((0x0800U == (IData)(vlSelfRef.multi_standard_rx__DOT__fft_len))
                        ? 0x40U : ((0U == (IData)(vlSelfRef.multi_standard_rx__DOT__fft_len))
                                    ? 0x80U : 0x10U)));
    vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr 
        = (0x0000007fU & ((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr) 
                          - (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delay_len)));
    vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr 
        = (0x0000007fU & ((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr) 
                          - (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delay_len)));
    vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr 
        = (0x0000007fU & ((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr) 
                          - (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delay_len)));
    vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr 
        = (0x0000007fU & ((IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr) 
                          - (IData)(vlSelfRef.multi_standard_rx__DOT__u_sync_0__DOT__delay_len)));
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

void Vmulti_standard_rx___024root___eval_nba(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_nba\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vmulti_standard_rx___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

void Vmulti_standard_rx___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vmulti_standard_rx___024root___eval_phase__act(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_phase__act\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmulti_standard_rx___024root___eval_triggers__act(vlSelf);
    Vmulti_standard_rx___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vmulti_standard_rx___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vmulti_standard_rx___024root___eval_phase__nba(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_phase__nba\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vmulti_standard_rx___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vmulti_standard_rx___024root___eval_nba(vlSelf);
        Vmulti_standard_rx___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vmulti_standard_rx___024root___eval(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vmulti_standard_rx___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../rtl/multi_standard_rx.v", 2, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vmulti_standard_rx___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vmulti_standard_rx___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../rtl/multi_standard_rx.v", 2, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vmulti_standard_rx___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../rtl/multi_standard_rx.v", 2, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vmulti_standard_rx___024root___eval_phase__act(vlSelf));
    } while (Vmulti_standard_rx___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vmulti_standard_rx___024root___eval_debug_assertions(Vmulti_standard_rx___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmulti_standard_rx___024root___eval_debug_assertions\n"); );
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
    if (VL_UNLIKELY(((vlSelfRef.mode_sel & 0xfcU)))) {
        Verilated::overWidthError("mode_sel");
    }
    if (VL_UNLIKELY(((vlSelfRef.din_valid & 0xfeU)))) {
        Verilated::overWidthError("din_valid");
    }
}
#endif  // VL_DEBUG
