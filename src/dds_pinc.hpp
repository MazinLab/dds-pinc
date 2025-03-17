#include "ap_axi_sdata.h"
#include <ap_int.h>
#include "hls_stream.h"

using pinc_t = ap_uint<14>; // Phase increment value
using pinc_stream_data_t = ap_axiu<14,0,0,0>; // Output stream data format
using out_stream = hls::stream<pinc_stream_data_t>; // Output stream type

void dds_pinc(pinc_t pinc_in, out_stream &pinc_out);
