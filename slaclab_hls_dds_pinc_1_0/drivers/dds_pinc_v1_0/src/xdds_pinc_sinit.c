// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.1 (64-bit)
// Tool Version Limit: 2023.05
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xdds_pinc.h"

extern XDds_pinc_Config XDds_pinc_ConfigTable[];

XDds_pinc_Config *XDds_pinc_LookupConfig(u16 DeviceId) {
	XDds_pinc_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XDDS_PINC_NUM_INSTANCES; Index++) {
		if (XDds_pinc_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XDds_pinc_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XDds_pinc_Initialize(XDds_pinc *InstancePtr, u16 DeviceId) {
	XDds_pinc_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XDds_pinc_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XDds_pinc_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

