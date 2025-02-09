/**
 * @file HypervisorRoutines.h
 * @author Sina Karvandi (sina@rayanfam.com)
 * @brief This file contains the headers for Hypervisor Routines which have to be called by external codes
 * @details DO NOT DIRECTLY CALL VMX FUNCTIONS, instead use these routines
 * 
 * @version 0.1
 * @date 2020-04-11
 * 
 * @copyright This project is released under the GNU Public License v3.
 * 
 */
#pragma once

//////////////////////////////////////////////////
//					Functions					//
//////////////////////////////////////////////////

/**
 * @brief Set Guest Selector Registers
 * 
 * @param GdtBase 
 * @param SegmentRegister 
 * @param Selector 
 * @return BOOLEAN 
 */
BOOLEAN
HvSetGuestSelector(PVOID GdtBase, ULONG SegmentRegister, USHORT Selector);

/**
 * @brief Set Msr Bitmap
 * 
 * @param Msr 
 * @param ProcessorID 
 * @param ReadDetection 
 * @param WriteDetection 
 * @return BOOLEAN 
 */
BOOLEAN
HvSetMsrBitmap(ULONG64 Msr, INT ProcessorID, BOOLEAN ReadDetection, BOOLEAN WriteDetection);

/**
 * @brief UnSet Msr Bitmap
 * 
 * @param Msr 
 * @param ProcessorID 
 * @param ReadDetection 
 * @param WriteDetection 
 * @return BOOLEAN 
 */
BOOLEAN
HvUnSetMsrBitmap(ULONG64 Msr, INT ProcessorID, BOOLEAN ReadDetection, BOOLEAN WriteDetection);

/**
 * @brief Returns the Cpu Based and Secondary Processor Based Controls and other 
 * controls based on hardware support
 * 
 * @param Ctl 
 * @param Msr 
 * @return ULONG 
 */
ULONG
HvAdjustControls(ULONG Ctl, ULONG Msr);

/**
 * @brief Handle Cpuid
 * 
 * @param RegistersState 
 * @return VOID 
 */
VOID
HvHandleCpuid(PGUEST_REGS RegistersState);

/**
 * @brief Fill guest selector data
 * 
 * @param GdtBase 
 * @param SegmentRegister 
 * @param Selector 
 * @return VOID 
 */
VOID
HvFillGuestSelectorData(PVOID GdtBase, ULONG SegmentRegister, USHORT Selector);

/**
 * @brief Handle Guest's Control Registers Access
 * 
 * @param GuestState 
 * @return VOID 
 */
VOID
HvHandleControlRegisterAccess(PGUEST_REGS GuestState, UINT32 ProcessorIndex);

/**
 * @brief Handle Guest's Msr read
 * 
 * @param GuestRegs 
 * @return VOID 
 */
VOID
HvHandleMsrRead(PGUEST_REGS GuestRegs);

/**
 * @brief Handle Guest's Msr write
 * 
 * @param GuestRegs 
 * @return VOID 
 */
VOID
HvHandleMsrWrite(PGUEST_REGS GuestRegs);

/**
 * @brief Resume GUEST_RIP to next instruction
 * 
 * @return VOID 
 */
VOID
HvResumeToNextInstruction();

/**
 * @brief Set or unset the monitor trap flags
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetMonitorTrapFlag(BOOLEAN Set);

/**
 * @brief Set LOAD DEBUG CONTROLS on Vm-entry controls
 * 
 * @param Set Set or unset 
 * @return VOID 
 */
VOID
HvSetLoadDebugControls(BOOLEAN Set);

/**
 * @brief Set SAVE DEBUG CONTROLS on Vm-exit controls
 * 
 * @param Set Set or unset 
 * @return VOID 
 */
VOID
HvSetSaveDebugControls(BOOLEAN Set);

/**
 * @brief Reset GDTR/IDTR and other old when you do vmxoff as the patchguard 
 * will detect them left modified
 * 
 * @return VOID 
 */
VOID
HvRestoreRegisters();

/**
 * @brief Change MSR Bitmap for read
 * 
 * @param MsrMask 
 * @return VOID 
 */
VOID
HvPerformMsrBitmapReadChange(UINT64 MsrMask);

/**
 * @brief Reset MSR Bitmap for read
 * 
 * @return VOID 
 */
VOID
HvPerformMsrBitmapReadReset();

/**
 * @brief Change MSR Bitmap for write
 * 
 * @param MsrMask 
 * @return VOID 
 */
VOID
HvPerformMsrBitmapWriteChange(UINT64 MsrMask);

/**
 * @brief Reset MSR Bitmap for write
 * 
 * @return VOID 
 */
VOID
HvPerformMsrBitmapWriteReset();

/**
 * @brief Set vm-exit for rdpmc instructions
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetPmcVmexit(BOOLEAN Set);

/**
 * @brief Set vm-exit for mov-to-cr3
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetMovToCr3Vmexit(BOOLEAN Set);

/**
 * @brief Write to the exception bitmap
 * 
 * @param BitmapMask 
 * @return VOID 
 */
VOID
HvWriteExceptionBitmap(UINT32 BitmapMask);

/**
 * @brief Read the exception bitmap
 * 
 * @return UINT32 
 */
UINT32
HvReadExceptionBitmap();

/**
 * @brief Set Interrupt-window exiting
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetInterruptWindowExiting(BOOLEAN Set);

/**
 * @brief Set the nmi-Window exiting
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetNmiWindowExiting(BOOLEAN Set);

/**
 * @brief Handle Mov to Debug Registers Exitings
 * 
 * @param ProcessorIndex 
 * @param Regs 
 * @return VOID 
 */
VOID
HvHandleMovDebugRegister(UINT32 ProcessorIndex, PGUEST_REGS Regs);

/**
 * @brief Set the Mov to Debug Registers Exiting
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetMovDebugRegsExiting(BOOLEAN Set);

/**
 * @brief Set the NMI Exiting
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetNmiExiting(BOOLEAN Set);

/**
 * @brief Set bits in I/O Bitmap
 * 
 * @param Port 
 * @param ProcessorID 
 * @return BOOLEAN 
 */
BOOLEAN
HvSetIoBitmap(UINT64 Port, UINT32 ProcessorID);

/**
 * @brief Change I/O Bitmap
 * 
 * @param Port 
 * @return VOID 
 */
VOID
HvPerformIoBitmapChange(UINT64 Port);

/**
 * @brief Reset I/O Bitmap
 * 
 * @return VOID 
 */
VOID
HvPerformIoBitmapReset();

/**
 * @brief Set exception bitmap in VMCS 
 * @details Should be called in vmx-root
 * 
 * @param IdtIndex 
 * @return VOID 
 */
VOID
HvSetExceptionBitmap(UINT32 IdtIndex);

/**
 * @brief Unset exception bitmap in VMCS 
 * @details Should be called in vmx-root
 * 
 * @param IdtIndex  
 * @return VOID 
 */
VOID
HvUnsetExceptionBitmap(UINT32 IdtIndex);

/**
 * @brief Set the External Interrupt Exiting
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetExternalInterruptExiting(BOOLEAN Set);

/**
 * @brief Set the RDTSC/P Exiting
 * 
 * @param Set 
 * @return VOID 
 */
VOID
HvSetRdtscExiting(BOOLEAN Set);
