/******************************************************************************************
  Filename    : SecondaryBoot.c
  
  Core        : ARM Cortex-M0+
  
  MCU         : RP2040
    
  Author      : Chalandi Amine
 
  Owner       : Chalandi Amine
  
  Date        : 07.02.2023
  
  Description : Secondary bootloader bytecode for Raspberry Pi Pico
  
******************************************************************************************/

extern "C"
const unsigned char __SBL[512] __attribute__((section(".SBL"))) =
{
  0x00, 0xB5, 0x2F, 0x4B, 0x21, 0x20, 0x58, 0x60, 0x98, 0x68, 0x02, 0x21, 0x88, 0x43, 0x98, 0x60,
  0xD8, 0x60, 0x18, 0x61, 0x58, 0x61, 0x2B, 0x4B, 0x00, 0x21, 0x99, 0x60, 0x02, 0x21, 0x59, 0x61,
  0x01, 0x21, 0xF0, 0x22, 0x99, 0x50, 0x28, 0x49, 0x19, 0x60, 0x01, 0x21, 0x99, 0x60, 0x35, 0x20,
  0x00, 0xF0, 0x3E, 0xF8, 0x02, 0x22, 0x90, 0x42, 0x14, 0xD0, 0x06, 0x21, 0x19, 0x66, 0x00, 0xF0,
  0x2E, 0xF8, 0x19, 0x6E, 0x01, 0x21, 0x19, 0x66, 0x00, 0x20, 0x18, 0x66, 0x1A, 0x66, 0x00, 0xF0,
  0x26, 0xF8, 0x19, 0x6E, 0x19, 0x6E, 0x19, 0x6E, 0x05, 0x20, 0x00, 0xF0, 0x29, 0xF8, 0x01, 0x21,
  0x08, 0x42, 0xF9, 0xD1, 0x00, 0x21, 0x99, 0x60, 0x18, 0x49, 0x19, 0x60, 0x00, 0x21, 0x59, 0x60,
  0x17, 0x49, 0x18, 0x48, 0x01, 0x60, 0x01, 0x21, 0x99, 0x60, 0xEB, 0x21, 0x19, 0x66, 0xA0, 0x21,
  0x19, 0x66, 0x00, 0xF0, 0x0C, 0xF8, 0x00, 0x21, 0x99, 0x60, 0x13, 0x49, 0x11, 0x48, 0x01, 0x60,
  0x01, 0x21, 0x99, 0x60, 0x01, 0xBC, 0x00, 0x28, 0x00, 0xD1, 0x10, 0x48, 0x00, 0x47, 0x03, 0xB5,
  0x99, 0x6A, 0x04, 0x20, 0x01, 0x42, 0xFB, 0xD0, 0x01, 0x20, 0x01, 0x42, 0xF8, 0xD1, 0x03, 0xBD,
  0x02, 0xB5, 0x18, 0x66, 0x18, 0x66, 0xFF, 0xF7, 0xF2, 0xFF, 0x18, 0x6E, 0x18, 0x6E, 0x02, 0xBD,
  0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x07, 0x00, 0x00, 0x03, 0x5F, 0x00,
  0x21, 0x22, 0x00, 0x00, 0xF4, 0x00, 0x00, 0x18, 0x22, 0x20, 0x00, 0xA0, 0x01, 0x01, 0x00, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x27, 0x2A, 0x60,
  0x27, 0x48, 0x00, 0xE0, 0x00, 0x20, 0x27, 0x49, 0x88, 0x60, 0x06, 0xC8, 0x81, 0xF3, 0x08, 0x88,
  0x10, 0x47, 0x25, 0x48, 0x00, 0x68, 0x00, 0x28, 0x39, 0xD1, 0x12, 0xA4, 0x0E, 0xCC, 0x00, 0x29,
  0x02, 0xD0, 0x00, 0xF0, 0x12, 0xF8, 0xF9, 0xE7, 0x20, 0x49, 0x21, 0x4A, 0x00, 0x20, 0x00, 0xE0,
  0x01, 0xC1, 0x91, 0x42, 0xFC, 0xD1, 0x1F, 0x49, 0x88, 0x47, 0x1F, 0x49, 0x88, 0x47, 0x1F, 0x49,
  0x88, 0x47, 0x00, 0xBE, 0xFD, 0xE7, 0x01, 0xC9, 0x01, 0xC2, 0x9A, 0x42, 0xFB, 0xD3, 0x70, 0x47,
  0xF2, 0xEB, 0x88, 0x71, 0xE0, 0x27, 0x00, 0x10, 0xFC, 0x27, 0x00, 0x10, 0x64, 0x01, 0x00, 0x10,
  0x90, 0xA3, 0x1A, 0xE7, 0xFC, 0x27, 0x00, 0x10, 0xC0, 0x00, 0x00, 0x20, 0x5C, 0x0A, 0x00, 0x20,
  0x98, 0x31, 0x00, 0x10, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x04, 0x20, 0x98, 0x31, 0x00, 0x10,
  0x00, 0x10, 0x04, 0x20, 0x00, 0x10, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x70, 0x47, 0x0C, 0x48,
  0x01, 0xF0, 0xCC, 0xFB, 0x00, 0x47, 0xEF, 0xF3, 0x05, 0x80, 0xC0, 0xB2, 0x70, 0x47, 0x00, 0x00,
  0x00, 0x02, 0x00, 0x10, 0x00, 0xED, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xD0, 0x5C, 0x0A, 0x00, 0x20,
  0x24, 0x0D, 0x00, 0x20, 0xD1, 0x10, 0x00, 0x10, 0x71, 0x03, 0x00, 0x10, 0xF1, 0x11, 0x00, 0x10,
  0x57, 0x56, 0x00, 0x00, 0x06, 0x00, 0x52, 0x50, 0xAB, 0xB3, 0x60, 0x53, 0x94, 0x27, 0x00, 0x10,
  0x06, 0x00, 0x52, 0x50, 0x86, 0x1C, 0x03, 0x02, 0xA4, 0x27, 0x00, 0x10, 0x06, 0x00, 0x52, 0x50,
  0x54, 0x22, 0xA2, 0x9D, 0xAC, 0x27, 0x00, 0x10, 0x05, 0x00, 0x52, 0x50, 0xDE, 0x65, 0xF4, 0x68,
  0x98, 0x31, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
