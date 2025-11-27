// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmulti_standard_rx__pch.h"

Vmulti_standard_rx__Syms::Vmulti_standard_rx__Syms(VerilatedContext* contextp, const char* namep, Vmulti_standard_rx* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(1260);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
}

Vmulti_standard_rx__Syms::~Vmulti_standard_rx__Syms() {
    // Tear down scopes
    // Tear down sub module instances
}
