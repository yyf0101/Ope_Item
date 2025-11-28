// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmulti_standard_rx.h for the primary calling header

#ifndef VERILATED_VMULTI_STANDARD_RX___024ROOT_H_
#define VERILATED_VMULTI_STANDARD_RX___024ROOT_H_  // guard

#include "verilated.h"


class Vmulti_standard_rx__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmulti_standard_rx___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_IN8(mode_sel,1,0);
        VL_IN8(din_valid,0,0);
        VL_OUT8(bits_out_0,7,0);
        VL_OUT8(bits_valid_0,0,0);
        VL_OUT8(bits_out_1,7,0);
        VL_OUT8(bits_valid_1,0,0);
        VL_OUT8(bits_out_2,7,0);
        VL_OUT8(bits_valid_2,0,0);
        VL_OUT8(bits_out_3,7,0);
        VL_OUT8(bits_valid_3,0,0);
        VL_OUT8(sync_found_combined,0,0);
        VL_OUT8(tready_global,0,0);
        CData/*3:0*/ multi_standard_rx__DOT__mod_type;
        CData/*0:0*/ multi_standard_rx__DOT__config_update;
        CData/*0:0*/ multi_standard_rx__DOT__sync_found_0;
        CData/*0:0*/ multi_standard_rx__DOT__sync_found_1;
        CData/*0:0*/ multi_standard_rx__DOT__sync_found_2;
        CData/*0:0*/ multi_standard_rx__DOT__sync_found_3;
        CData/*0:0*/ multi_standard_rx__DOT__sync_combined;
        CData/*2:0*/ multi_standard_rx__DOT__u_mode_ctrl__DOT__state;
        CData/*1:0*/ multi_standard_rx__DOT__u_mode_ctrl__DOT__current_mode;
        CData/*7:0*/ multi_standard_rx__DOT__u_mode_ctrl__DOT__timer;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
        VL_IN16(din_re_0,15,0);
        VL_IN16(din_im_0,15,0);
        VL_IN16(din_re_1,15,0);
        VL_IN16(din_im_1,15,0);
        VL_IN16(din_re_2,15,0);
        VL_IN16(din_im_2,15,0);
        VL_IN16(din_re_3,15,0);
        VL_IN16(din_im_3,15,0);
        SData/*12:0*/ multi_standard_rx__DOT__fft_len;
        SData/*8:0*/ multi_standard_rx__DOT__cp_len;
        SData/*15:0*/ multi_standard_rx__DOT__freq_offset_0;
        SData/*15:0*/ multi_standard_rx__DOT__freq_offset_1;
        SData/*15:0*/ multi_standard_rx__DOT__freq_offset_2;
        SData/*15:0*/ multi_standard_rx__DOT__freq_offset_3;
        SData/*12:0*/ multi_standard_rx__DOT__u_sync_0__DOT__active_fft_len;
        SData/*11:0*/ multi_standard_rx__DOT__u_sync_0__DOT__wr_ptr;
        SData/*11:0*/ multi_standard_rx__DOT__u_sync_0__DOT__rd_ptr;
        SData/*15:0*/ multi_standard_rx__DOT__u_sync_0__DOT__delayed_re;
        SData/*15:0*/ multi_standard_rx__DOT__u_sync_0__DOT__delayed_im;
        SData/*12:0*/ multi_standard_rx__DOT__u_sync_1__DOT__active_fft_len;
        SData/*11:0*/ multi_standard_rx__DOT__u_sync_1__DOT__wr_ptr;
        SData/*11:0*/ multi_standard_rx__DOT__u_sync_1__DOT__rd_ptr;
        SData/*15:0*/ multi_standard_rx__DOT__u_sync_1__DOT__delayed_re;
        SData/*15:0*/ multi_standard_rx__DOT__u_sync_1__DOT__delayed_im;
        SData/*12:0*/ multi_standard_rx__DOT__u_sync_2__DOT__active_fft_len;
        SData/*11:0*/ multi_standard_rx__DOT__u_sync_2__DOT__wr_ptr;
        SData/*11:0*/ multi_standard_rx__DOT__u_sync_2__DOT__rd_ptr;
        SData/*15:0*/ multi_standard_rx__DOT__u_sync_2__DOT__delayed_re;
        SData/*15:0*/ multi_standard_rx__DOT__u_sync_2__DOT__delayed_im;
        SData/*12:0*/ multi_standard_rx__DOT__u_sync_3__DOT__active_fft_len;
        SData/*11:0*/ multi_standard_rx__DOT__u_sync_3__DOT__wr_ptr;
        SData/*11:0*/ multi_standard_rx__DOT__u_sync_3__DOT__rd_ptr;
        SData/*15:0*/ multi_standard_rx__DOT__u_sync_3__DOT__delayed_re;
        SData/*15:0*/ multi_standard_rx__DOT__u_sync_3__DOT__delayed_im;
        VlWide<3>/*65:0*/ multi_standard_rx__DOT__sum_total_E;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_0__DOT__prod_re;
    };
    struct {
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_0__DOT__prod_im;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_0__DOT__energy_term;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_0__DOT__prod_re_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_0__DOT__prod_im_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_0__DOT__energy_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_0__DOT__i;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_1__DOT__prod_re;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_1__DOT__prod_im;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_1__DOT__energy_term;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_1__DOT__prod_re_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_1__DOT__prod_im_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_1__DOT__energy_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_1__DOT__i;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_2__DOT__prod_re;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_2__DOT__prod_im;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_2__DOT__energy_term;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_2__DOT__prod_re_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_2__DOT__prod_im_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_2__DOT__energy_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_2__DOT__i;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_3__DOT__prod_re;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_3__DOT__prod_im;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_3__DOT__energy_term;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_3__DOT__prod_re_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_3__DOT__prod_im_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_3__DOT__energy_delayed;
        IData/*31:0*/ multi_standard_rx__DOT__u_sync_3__DOT__i;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ multi_standard_rx__DOT__corr_E_0;
        QData/*63:0*/ multi_standard_rx__DOT__corr_E_1;
        QData/*63:0*/ multi_standard_rx__DOT__corr_E_2;
        QData/*63:0*/ multi_standard_rx__DOT__corr_E_3;
        QData/*63:0*/ multi_standard_rx__DOT__total_E_0;
        QData/*63:0*/ multi_standard_rx__DOT__total_E_1;
        QData/*63:0*/ multi_standard_rx__DOT__total_E_2;
        QData/*63:0*/ multi_standard_rx__DOT__total_E_3;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_re;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_0__DOT__sum_prod_im;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_0__DOT__sum_energy;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_re;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_1__DOT__sum_prod_im;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_1__DOT__sum_energy;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_re;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_2__DOT__sum_prod_im;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_2__DOT__sum_energy;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_re;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_3__DOT__sum_prod_im;
        QData/*47:0*/ multi_standard_rx__DOT__u_sync_3__DOT__sum_energy;
        VlUnpacked<SData/*15:0*/, 4096> multi_standard_rx__DOT__u_sync_0__DOT__buf_re;
        VlUnpacked<SData/*15:0*/, 4096> multi_standard_rx__DOT__u_sync_0__DOT__buf_im;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_0__DOT__prod_re_buf;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_0__DOT__prod_im_buf;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_0__DOT__energy_buf;
        VlUnpacked<SData/*15:0*/, 4096> multi_standard_rx__DOT__u_sync_1__DOT__buf_re;
        VlUnpacked<SData/*15:0*/, 4096> multi_standard_rx__DOT__u_sync_1__DOT__buf_im;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_1__DOT__prod_re_buf;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_1__DOT__prod_im_buf;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_1__DOT__energy_buf;
        VlUnpacked<SData/*15:0*/, 4096> multi_standard_rx__DOT__u_sync_2__DOT__buf_re;
        VlUnpacked<SData/*15:0*/, 4096> multi_standard_rx__DOT__u_sync_2__DOT__buf_im;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_2__DOT__prod_re_buf;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_2__DOT__prod_im_buf;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_2__DOT__energy_buf;
        VlUnpacked<SData/*15:0*/, 4096> multi_standard_rx__DOT__u_sync_3__DOT__buf_re;
    };
    struct {
        VlUnpacked<SData/*15:0*/, 4096> multi_standard_rx__DOT__u_sync_3__DOT__buf_im;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_3__DOT__prod_re_buf;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_3__DOT__prod_im_buf;
        VlUnpacked<IData/*31:0*/, 4096> multi_standard_rx__DOT__u_sync_3__DOT__energy_buf;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vmulti_standard_rx__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmulti_standard_rx___024root(Vmulti_standard_rx__Syms* symsp, const char* namep);
    ~Vmulti_standard_rx___024root();
    VL_UNCOPYABLE(Vmulti_standard_rx___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
