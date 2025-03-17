
#include "dds_pinc.hpp"

void dds_pinc(pinc_t pinc_in, out_stream &pinc_out){

#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=pinc_in
#pragma HLS INTERFACE axis port=pinc_out
#pragma HLS PIPELINE ii=1 // Need this to ensure TVALID / TREADY stay high

	pinc_stream_data_t data;
	data.data = pinc_in;
	pinc_out.write(data);

}
