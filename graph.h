/**
 * Author : Killian Kerlau
 * Description : Graph implementation 
 * Resources : https://docs.amd.com/r/2025.2-English/ug1079-ai-engine-kernel-coding/Creating-a-Data-Flow-Graph-Including-Kernels
 */

#pragma once
#include <adf.h>
#include "kernels.cc"

class simple_graph : public adf::graph {
private:
    adf::kernel k;

public:
    adf::input_plio in;
    adf::output_plio out;

    simple_graph() {
        k = adf::kernel::create(simple);

        in = adf::input_plio::create(adf::plio_32_bits, "data/input.txt");
        out = adf::output_plio::create(adf::plio_32_bits, "data/output.txt");
        
        adf::connect(in.out[0], k.in[0]);
        adf::connect(k.out[0], out.in[0]);

        //  executes when 128 bytes of data (32 complex samples) are collected in a buffer
        adf::dimensions(k.in[0]) = {128};
        adf::dimensions(k.out[0]) = {128};

        adf::source(k) = "kernels.cc";

        adf::runtime<ratio>(k) = 0.1;
    }
};