// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmulti_standard_rx__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmulti_standard_rx::Vmulti_standard_rx(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmulti_standard_rx__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , mode_sel{vlSymsp->TOP.mode_sel}
    , din_valid{vlSymsp->TOP.din_valid}
    , bits_out_0{vlSymsp->TOP.bits_out_0}
    , bits_valid_0{vlSymsp->TOP.bits_valid_0}
    , bits_out_1{vlSymsp->TOP.bits_out_1}
    , bits_valid_1{vlSymsp->TOP.bits_valid_1}
    , bits_out_2{vlSymsp->TOP.bits_out_2}
    , bits_valid_2{vlSymsp->TOP.bits_valid_2}
    , bits_out_3{vlSymsp->TOP.bits_out_3}
    , bits_valid_3{vlSymsp->TOP.bits_valid_3}
    , sync_found_combined{vlSymsp->TOP.sync_found_combined}
    , din_re_0{vlSymsp->TOP.din_re_0}
    , din_im_0{vlSymsp->TOP.din_im_0}
    , din_re_1{vlSymsp->TOP.din_re_1}
    , din_im_1{vlSymsp->TOP.din_im_1}
    , din_re_2{vlSymsp->TOP.din_re_2}
    , din_im_2{vlSymsp->TOP.din_im_2}
    , din_re_3{vlSymsp->TOP.din_re_3}
    , din_im_3{vlSymsp->TOP.din_im_3}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vmulti_standard_rx::Vmulti_standard_rx(const char* _vcname__)
    : Vmulti_standard_rx(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmulti_standard_rx::~Vmulti_standard_rx() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmulti_standard_rx___024root___eval_debug_assertions(Vmulti_standard_rx___024root* vlSelf);
#endif  // VL_DEBUG
void Vmulti_standard_rx___024root___eval_static(Vmulti_standard_rx___024root* vlSelf);
void Vmulti_standard_rx___024root___eval_initial(Vmulti_standard_rx___024root* vlSelf);
void Vmulti_standard_rx___024root___eval_settle(Vmulti_standard_rx___024root* vlSelf);
void Vmulti_standard_rx___024root___eval(Vmulti_standard_rx___024root* vlSelf);

void Vmulti_standard_rx::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmulti_standard_rx::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmulti_standard_rx___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmulti_standard_rx___024root___eval_static(&(vlSymsp->TOP));
        Vmulti_standard_rx___024root___eval_initial(&(vlSymsp->TOP));
        Vmulti_standard_rx___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmulti_standard_rx___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmulti_standard_rx::eventsPending() { return false; }

uint64_t Vmulti_standard_rx::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmulti_standard_rx::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmulti_standard_rx___024root___eval_final(Vmulti_standard_rx___024root* vlSelf);

VL_ATTR_COLD void Vmulti_standard_rx::final() {
    Vmulti_standard_rx___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmulti_standard_rx::hierName() const { return vlSymsp->name(); }
const char* Vmulti_standard_rx::modelName() const { return "Vmulti_standard_rx"; }
unsigned Vmulti_standard_rx::threads() const { return 1; }
void Vmulti_standard_rx::prepareClone() const { contextp()->prepareClone(); }
void Vmulti_standard_rx::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmulti_standard_rx::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmulti_standard_rx___024root__trace_decl_types(VerilatedVcd* tracep);

void Vmulti_standard_rx___024root__trace_init_top(Vmulti_standard_rx___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmulti_standard_rx___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmulti_standard_rx___024root*>(voidSelf);
    Vmulti_standard_rx__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vmulti_standard_rx___024root__trace_decl_types(tracep);
    Vmulti_standard_rx___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmulti_standard_rx___024root__trace_register(Vmulti_standard_rx___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmulti_standard_rx::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmulti_standard_rx::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmulti_standard_rx___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
