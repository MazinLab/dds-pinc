// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xdds_pinc.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XDds_pinc_CfgInitialize(XDds_pinc *InstancePtr, XDds_pinc_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XDds_pinc_Set_pinc_in(XDds_pinc *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XDds_pinc_WriteReg(InstancePtr->Control_BaseAddress, XDDS_PINC_CONTROL_ADDR_PINC_IN_DATA, Data);
}

u32 XDds_pinc_Get_pinc_in(XDds_pinc *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XDds_pinc_ReadReg(InstancePtr->Control_BaseAddress, XDDS_PINC_CONTROL_ADDR_PINC_IN_DATA);
    return Data;
}

