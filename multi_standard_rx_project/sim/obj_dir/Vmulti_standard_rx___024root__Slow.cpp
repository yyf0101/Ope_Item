// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmulti_standard_rx.h for the primary calling header

#include "Vmulti_standard_rx__pch.h"

void Vmulti_standard_rx___024root___ctor_var_reset(Vmulti_standard_rx___024root* vlSelf);

Vmulti_standard_rx___024root::Vmulti_standard_rx___024root(Vmulti_standard_rx__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vmulti_standard_rx___024root___ctor_var_reset(this);
}

void Vmulti_standard_rx___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmulti_standard_rx___024root::~Vmulti_standard_rx___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
