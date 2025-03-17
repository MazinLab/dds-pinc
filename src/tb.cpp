#include <stdio.h>
#include <dds_pinc.hpp>


int main() {

   // inputs
    pinc_t inc1 = 1023;
    pinc_t inc2 = 4;

   // output
    out_stream pinc_out;
    pinc_t output;

    printf("HLS AXI-Lite to AXI-Stream Phase Increment Player\n");
    printf("first phase increment: 1023, second phase increment: 4\n");
    printf("Beginning tests: \n\n");

   // first check, write first value, should get first value
    dds_pinc(inc1, pinc_out);
    output=pinc_out.read().data;

    printf("TEST1: AXI-Lite input: %d, AXI-Stream output: %d\n", inc1, output);
    if (output.to_uint() == inc1) {
    	printf("success!\n");
    } else{
    	printf("fail :'( output does not match expected input\n");
    	return 1;
    }

    // second check, write new value, read out new value
    dds_pinc(inc2, pinc_out);
    output=pinc_out.read().data;

    printf("TEST 2: AXI-Lite input: %d, AXI-Stream output: %d \n", inc2, output);
    if (output.to_uint() == inc2) {
    	printf("success!\n");
    } else{
    	printf("fail :'( output does not match expected input\n");
    	return 1;
    }

    // third check, write second value to axi4-lite reg again, output should still be pinc2 value
    dds_pinc(inc2, pinc_out);
    output=pinc_out.read().data;

    printf("TEST 3: AXI-Lite input: %d, AXI-Stream output: %d\n", inc2, output);\
    if (output.to_uint() == inc2) {
    	printf("success!\n");
    } else{
    	printf("fail :'( output does not match expected input\n");
    	return 1;
    }

    printf("ALL TESTS PASSED! :)\n");
    return 0;

    }
