











/************************************************************************/
/*    File Version: V1.00                                               */
/*    Date Modified: 18/12/2014                                        */
/************************************************************************/

#include "interrupt_handlers.h"

typedef void (*fp) (void);
extern void PowerON_Reset (void);
extern void stack (void);

#define EXVECT_SECT    __attribute__ ((section (".exvectors")))

const void* ExceptVectors[] EXVECT_SECT  = {
//;0xffffff80  Reserved
    (fp)0,
//;0xffffff84  Reserved
    (fp)0,
//;0xffffff88  Reserved
    (fp)0,
//;0xffffff8C  Reserved
    (fp)0,
//;0xffffff90  Reserved
    (fp)0,
//;0xffffff94  Reserved
    (fp)0,
//;0xffffff98  Reserved
    (fp)0,
//;0xffffff9C  Reserved
    (fp)0,
//;0xffffffA0  Reserved
    (fp)0xFFFFFFFF,
//;0xffffffA4  Reserved
    (fp)0xFFFFFFFF,
//;0xffffffA8  Reserved
    (fp)0xFFFFFFFF,
//;0xffffffAC  Reserved
    (fp)0xFFFFFFFF,
//;0xffffffB0  Reserved
    (fp)0,
//;0xffffffB4  Reserved
    (fp)0,
//;0xffffffB8  Reserved
    (fp)0,
//;0xffffffBC  Reserved
    (fp)0,
//;0xffffffC0  Reserved
    (fp)0,
//;0xffffffC4  Reserved
    (fp)0,
//;0xffffffC8  Reserved
    (fp)0,
//;0xffffffCC  Reserved
    (fp)0,
//;0xffffffd0  Exception(Supervisor Instruction)
    INT_Excep_SuperVisorInst,
//;0xffffffd4  Exception(Access Instruction)
    INT_Excep_AccessInst,
//;0xffffffd8  Reserved
    Dummy,
//;0xffffffdc  Exception(Undefined Instruction)
    INT_Excep_UndefinedInst,
//;0xffffffe0  Reserved
    Dummy,
//;0xffffffe4  Exception(Floating Point)
    INT_Excep_FloatingPoint,
//;0xffffffe8  Reserved
    Dummy,
//;0xffffffec  Reserved
    Dummy,
//;0xfffffff0  Reserved
    Dummy,
//;0xfffffff4  Reserved
    Dummy,
//;0xfffffff8  NMI
    INT_NonMaskableInterrupt,
};

#define FVECT_SECT    __attribute__ ((section (".fvectors")))

const void* HardwareVectors[] FVECT_SECT  = {
//;0xfffffffc  RESET
//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
    /*(void*)*/ PowerON_Reset
//;<<VECTOR DATA END (POWER ON RESET)>>
};

#define RVECT_SECT          __attribute__ ((section (".rvectors")))

const fp RelocatableVectors[] RVECT_SECT  = {
//;0x0000  Reserved
    (fp)0,
//;0x0004  Reserved
    (fp)0,
//;0x0008  Reserved
    (fp)0,
//;0x000C  Reserved
    (fp)0,
//;0x0010  Reserved
    (fp)0,
//;0x0014  Reserved
    (fp)0,
//;0x0018  Reserved
    (fp)0,
//;0x001C  Reserved
    (fp)0,
//;0x0020  Reserved
    (fp)0,
//;0x0024  Reserved
    (fp)0,
//;0x0028  Reserved
    (fp)0,
//;0x002C  Reserved
    (fp)0,
//;0x0030  Reserved
    (fp)0,
//;0x0034  Reserved
    (fp)0,
//;0x0038  Reserved
    (fp)0,
//;0x003C  Reserved
    (fp)0,
//;0x0040  BUSERR
    (fp)INT_Excep_BSC_BUSERR,
//;0x0044  Reserved
    (fp)0,
//;0x0048  RAMERR
    (fp)INT_Excep_RAM_RAMERR,
//;0x004C  Reserved
    (fp)0,
//;0x0050  Reserved
    (fp)0,
//;0x0054 FIFERR
    (fp)INT_Excep_FCU_FIFERR,
//;0x0058  Reserved
    (fp)0,
//;0x005C  FRDYI
    (fp)INT_Excep_FCU_FRDYI,
//;0x0060  Reserved
    (fp)0,
//;0x0064  Reserved
    (fp)0,
//;0x0068  SWINT2
    (fp)INT_Excep_ICU_SWINT2,

//;0x006C  SWINT
    (fp)INT_Excep_ICU_SWINT,

//;0x0070  CMI0
    (fp)INT_Excep_CMT0_CMI0,

//;0x0074  CMI1
    (fp)INT_Excep_CMT1_CMI1,

//;0x0078  CMWI0
    (fp)INT_Excep_CMTW0_CMWI0,

//;0x007C  CMWI1
    (fp)INT_Excep_CMTW1_CMWI1,

//;0x0080  D0FIFO2
    (fp)INT_Excep_USBA_D0FIFO2,

//;0x0084  D1FIFO2
    (fp)INT_Excep_USBA_D1FIFO2,

//;0x0088  D0FIFO0
    (fp)INT_Excep_USB0_D0FIFO0,

//;0x008C  D1FIFO0
    (fp)INT_Excep_USB0_D1FIFO0,
//;0x0090  Reserved
    (fp)0,
//;0x0094  Reserved
    (fp)0,
//;0x0098  SPRI0
    (fp)INT_Excep_RSPI0_SPRI0,

//;0x009C  SPTI0
    (fp)INT_Excep_RSPI0_SPTI0,

//;0x00A0  SPRI1
    (fp)INT_Excep_RSPI1_SPRI1,

//;0x00A4  SPTI1
    (fp)INT_Excep_RSPI1_SPTI1,

//;0x00A8  SPRI
    (fp)INT_Excep_QSPI_SPRI,

//;0x00AC  SPTI
    (fp)INT_Excep_QSPI_SPTI,

//;0x00B0  SBFAI
    (fp)INT_Excep_SDHI_SBFAI,

//;0x00B4  MBFAI
    (fp)INT_Excep_MMCIF_MBFAI,

//;0x00B8  SSITX0
    (fp)INT_Excep_SSI0_SSITXI0,

//;0x00BC  SSIRX0
    (fp)INT_Excep_SSI0_SSIRXI0,

//;0x00C0  SSIRTI1
    (fp)INT_Excep_SSI1_SSIRTI1,
//;0x00C4  Reserved
    (fp)0,
//;0x00C8  IDEI
    (fp)INT_Excep_SRC_IDEI,

//;0x00CC  ODFI
    (fp)INT_Excep_SRC_ODFI,

//;0x00D0  RXI0
    (fp)INT_Excep_RIIC0_RXI0,

//;0x00D4C  TXI0
    (fp)INT_Excep_RIIC0_TXI0,

//;0x00D8  RXI2
    (fp)INT_Excep_RIIC2_RXI2,

//;0x00DC TXI2
    (fp)INT_Excep_RIIC2_TXI2,
//;0x00E0  Reserved
    (fp)0,
//;0x00E4  Reserved
    (fp)0,
//;0x00E8 RXI0
    (fp)INT_Excep_SCI0_RXI0,

//;0x00EC TXI0
    (fp)INT_Excep_SCI0_TXI0,

//;0x00F0 RXI1
    (fp)INT_Excep_SCI1_RXI1,

//;0x00F4 TXI1
    (fp)INT_Excep_SCI1_TXI1,

//;0x00F8 RXI2
    (fp)INT_Excep_SCI2_RXI2,

//;0x00FC TXI2
    (fp)INT_Excep_SCI2_TXI2,

//;0x0100 IRQ0
    (fp)INT_Excep_ICU_IRQ0,

//;0x0104 IRQ1
    (fp)INT_Excep_ICU_IRQ1,

//;0x0108 IRQ2
    (fp)INT_Excep_ICU_IRQ2,

//;0x010C IRQ3
    (fp)INT_Excep_ICU_IRQ3,

//;0x0110 IRQ4
    (fp)INT_Excep_ICU_IRQ4,

//;0x0114 IRQ5
    (fp)INT_Excep_ICU_IRQ5,

//;0x0118 IRQ6
    (fp)INT_Excep_ICU_IRQ6,

//;0x011C IRQ7
    (fp)INT_Excep_ICU_IRQ7,

//;0x0120 IRQ8
    (fp)INT_Excep_ICU_IRQ8,

//;0x0124 IRQ9
    (fp)INT_Excep_ICU_IRQ9,

//;0x0128 IRQ10
    (fp)INT_Excep_ICU_IRQ10,

//;0x012C IRQ11
    (fp)INT_Excep_ICU_IRQ11,

//;0x0130 IRQ12
    (fp)INT_Excep_ICU_IRQ12,

//;0x0134 IRQ13
    (fp)INT_Excep_ICU_IRQ13,

//;0x0138 IRQ14
    (fp)INT_Excep_ICU_IRQ14,

//;0x013C IRQ15
    (fp)INT_Excep_ICU_IRQ15,

//;0x0140 RXI3
    (fp)INT_Excep_SCI3_RXI3,

//;0x0144 TXI3
    (fp)INT_Excep_SCI3_TXI3,

//;0x0148 RXI4
    (fp)INT_Excep_SCI4_RXI4,

//;0x014C TXI4
    (fp)INT_Excep_SCI4_TXI4,

//;0x0150 RXI5
    (fp)INT_Excep_SCI5_RXI5,

//;0x0154 TXI5
    (fp)INT_Excep_SCI5_TXI5,

//;0x0158 RXI6
    (fp)INT_Excep_SCI6_RXI6,

//;0x015C TXI6
    (fp)INT_Excep_SCI6_TXI6,

//;0x0160 COMPA1
    (fp)INT_Excep_LVD1_LVD1,

//;0x0164 COMPA2
    (fp)INT_Excep_LVD2_LVD2,

//;0x0168 USBR0
    (fp)INT_Excep_USB0_USBR0,
//;0x016C Reserved
    (fp)0,
//;0x0170 ALM
    (fp)INT_Excep_RTC_ALM,

//;0x0174 PRD
    (fp)INT_Excep_RTC_PRD,

//;0x0178 HSUSBR
    (fp)INT_Excep_USBA_USBAR,

//;0x017C IWUNI
    (fp)INT_Excep_IWDT_IWUNI,

//;0x0180 WUNI
    (fp)INT_Excep_WDT_WUNI,

//;0x0184 PCDFI
    (fp)INT_Excep_PDC_PCDFI,

//;0x0188 RXI7
    (fp)INT_Excep_SCI7_RXI7,

//;0x018C TXI7
    (fp)INT_Excep_SCI7_TXI7,

//;0x0190 RXIF8
    (fp)INT_Excep_SCIFA8_RXIF8,

//;0x0194 TXIF8
    (fp)INT_Excep_SCIFA8_TXIF8,

//;0x0198 RXIF9
    (fp)INT_Excep_SCIFA9_RXIF9,

//;0x019C TXIF9
    (fp)INT_Excep_SCIFA9_TXIF9,

//;0x01A0 RXIF10
    (fp)INT_Excep_SCIFA10_RXIF10,

//;0x01A4 TXIF10
    (fp)INT_Excep_SCIFA10_TXIF10,

//;0x01A8 GROUPBE0
    (fp)INT_Excep_ICU_GROUPBE0,
//;0x01AC Reserved
    (fp)0,
//;0x01B0 Reserved
    (fp)0,
//;0x01B4 Reserved
    (fp)0,
//;0x01B8 GROUPBL0
    (fp)INT_Excep_ICU_GROUPBL0,

//;0x01BC GROUPBL1
    (fp)INT_Excep_ICU_GROUPBL1,

//;0x01C0 GROUPAL0
    (fp)INT_Excep_ICU_GROUPAL0,

//;0x01C4 GROUPAL1
    (fp)INT_Excep_ICU_GROUPAL1,

//;0x01C8 RXIF11
    (fp)INT_Excep_SCIFA11_RXIF11,

//;0x01CC TXIF11
    (fp)INT_Excep_SCIFA11_TXIF11,

//;0x01D0 RXIF12
    (fp)INT_Excep_SCI12_RXI12,

//;0x01D4 TXIF12
    (fp)INT_Excep_SCI12_TXI12,

//;0x01D8 Reserved
    (fp)0,
//;0x01DC Reserved
    (fp)0,
//;0x01E0 DMAC0I
    (fp)INT_Excep_DMAC_DMAC0I,

//;0x01E4 DMAC1I
    (fp)INT_Excep_DMAC_DMAC1I,

//;0x01E8 DMAC2I
    (fp)INT_Excep_DMAC_DMAC2I,

//;0x01EC DMAC3I
    (fp)INT_Excep_DMAC_DMAC3I,

//;0x01F0 DMAC74I
    (fp)INT_Excep_DMAC_DMAC74I,

//;0x01F4 OST
    (fp)INT_Excep_OST_OST,

//;0x01F8  EXDMAC0I
    (fp)INT_Excep_EXDMAC_EXDMAC0I,

//;0x01FC  EXDMAC1I
    (fp)INT_Excep_EXDMAC_EXDMAC1I,

//;0x0200  INTB128
    (fp)INT_Excep_PERIB_INTB128,

//;0x0204 INTB129
    (fp)INT_Excep_PERIB_INTB129,

//;0x0208 INTB130
    (fp)INT_Excep_PERIB_INTB130,

//;0x020C INTB131
    (fp)INT_Excep_PERIB_INTB131,

//;0x0210 INTB132
    (fp)INT_Excep_PERIB_INTB132,

//;0x0214 INTB133
    (fp)INT_Excep_PERIB_INTB133,

//;0x0218 INTB134
    (fp)INT_Excep_PERIB_INTB134,

//;0x021C INTB135
    (fp)INT_Excep_PERIB_INTB135,

//;0x0220 INTB136
    (fp)INT_Excep_PERIB_INTB136,

//;0x0224 INTB137
    (fp)INT_Excep_PERIB_INTB137,

//;0x0228 INTB138
    (fp)INT_Excep_PERIB_INTB138,

//;0x022C INTB139
    (fp)INT_Excep_PERIB_INTB139,

//;0x0230 INTB140
    (fp)INT_Excep_PERIB_INTB140,

//;0x0234 INTB141
    (fp)INT_Excep_PERIB_INTB141,

//;0x0238 INTB142
    (fp)INT_Excep_PERIB_INTB142,

//;0x023C INTB143
    (fp)INT_Excep_PERIB_INTB143,

//;0x0240 INTB144
    (fp)INT_Excep_PERIB_INTB144,

//;0x0244 INTB145
    (fp)INT_Excep_PERIB_INTB145,

//;0x0248 INTB146
    (fp)INT_Excep_PERIB_INTB146,

//;0x024C INTB147
    (fp)INT_Excep_PERIB_INTB147,

//;0x0250 INTB148
    (fp)INT_Excep_PERIB_INTB148,

//;0x02540 INTB149
    (fp)INT_Excep_PERIB_INTB149,

//;0x0258 INTB150
    (fp)INT_Excep_PERIB_INTB150,

//;0x025C INTB151
    (fp)INT_Excep_PERIB_INTB151,

//;0x0260 INTB152
    (fp)INT_Excep_PERIB_INTB152,

//;0x0264 INTB153
    (fp)INT_Excep_PERIB_INTB153,

//;0x0268 INTB154
    (fp)INT_Excep_PERIB_INTB154,

//;0x026C INTB155
    (fp)INT_Excep_PERIB_INTB155,

//;0x0270 INTB156
    (fp)INT_Excep_PERIB_INTB156,

//;0x0274 INTB157
    (fp)INT_Excep_PERIB_INTB157,

//;0x0278 INTB158
    (fp)INT_Excep_PERIB_INTB158,

//;0x027C INTB159
    (fp)INT_Excep_PERIB_INTB159,

//;0x0280 INTB160
    (fp)INT_Excep_PERIB_INTB160,

//;0x0284 INTB161
    (fp)INT_Excep_PERIB_INTB161,

//;0x0288 INTB162
    (fp)INT_Excep_PERIB_INTB162,

//;0x028C INTB163
    (fp)INT_Excep_PERIB_INTB163,

//;0x0290 INTB164
    (fp)INT_Excep_PERIB_INTB164,

//;0x0294 PERIB INTB165
    (fp)INT_Excep_PERIB_INTB165,

//;0x0298 PERIB INTB166
    (fp)INT_Excep_PERIB_INTB166,

//;0x029C PERIB INTB167
    (fp)INT_Excep_PERIB_INTB167,

//;0x02A0 PERIB INTB168
    (fp)INT_Excep_PERIB_INTB168,

//;0x02A4 PERIB INTB169
    (fp)INT_Excep_PERIB_INTB169,

//;0x02A8 PERIB INTB170
    (fp)INT_Excep_PERIB_INTB170,

//;0x02AC PERIB INTB171
    (fp)INT_Excep_PERIB_INTB171,

//;0x02B0 PERIB INTB172
    (fp)INT_Excep_PERIB_INTB172,

//;0x02B4 PERIB INTB173
    (fp)INT_Excep_PERIB_INTB173,

//;0x02B8 PERIB INTB174
    (fp)INT_Excep_PERIB_INTB174,

//;0x02BC PERIB INTB175
    (fp)INT_Excep_PERIB_INTB175,

//;0x02C0 PERIB INTB176
    (fp)INT_Excep_PERIB_INTB176,

//;0x02C4 PERIB INTB177
    (fp)INT_Excep_PERIB_INTB177,

//;0x02C8 PERIB INTB178
    (fp)INT_Excep_PERIB_INTB178,

//;0x02CC PERIB INTB179
    (fp)INT_Excep_PERIB_INTB179,

//;0x02D0 PERIB INTB180
    (fp)INT_Excep_PERIB_INTB180,

//;0x02D4 PERIB INTB181
    (fp)INT_Excep_PERIB_INTB181,

//;0x02D8 PERIB INTB182
    (fp)INT_Excep_PERIB_INTB182,

//;0x02DC PERIB INTB183
    (fp)INT_Excep_PERIB_INTB183,

//;0x02E0 PERIB INTB184
    (fp)INT_Excep_PERIB_INTB184,

//;0x02E4 PERIB INTB185
    (fp)INT_Excep_PERIB_INTB185,

//;0x02E8 PERIB INTB186
    (fp)INT_Excep_PERIB_INTB186,

//;0x02EC PERIB INTB187
    (fp)INT_Excep_PERIB_INTB187,

//;0x02F0 PERIB INTB188
    (fp)INT_Excep_PERIB_INTB188,

//;0x02F4 PERIB INTB189
    (fp)INT_Excep_PERIB_INTB189,

//;0x02F8 PERIB INTB190
    (fp)INT_Excep_PERIB_INTB190,

//;0x02FC PERIB INTB191
    (fp)INT_Excep_PERIB_INTB191,

//;0x0300 PERIB INTB192
    (fp)INT_Excep_PERIB_INTB192,

//;0x0304 PERIB INTB193
    (fp)INT_Excep_PERIB_INTB193,

//;0x0308 PERIB INTB194
    (fp)INT_Excep_PERIB_INTB194,

//;0x030C PERIB INTB195
    (fp)INT_Excep_PERIB_INTB195,

//;0x0310 PERIB INTB196
    (fp)INT_Excep_PERIB_INTB196,

//;0x0314 PERIB INTB197
    (fp)INT_Excep_PERIB_INTB197,

//;0x0318 PERIB INTB198
    (fp)INT_Excep_PERIB_INTB198,

//;0x031C PERIB INTB199
    (fp)INT_Excep_PERIB_INTB199,

//;0x0320 PERIB INTB200
    (fp)INT_Excep_PERIB_INTB200,

//;0x0324 PERIB INTB201
    (fp)INT_Excep_PERIB_INTB201,

//;0x0328 PERIB INTB202
    (fp)INT_Excep_PERIB_INTB202,

//;0x032C PERIB INTB203
    (fp)INT_Excep_PERIB_INTB203,

//;0x0320 PERIB INTB204
    (fp)INT_Excep_PERIB_INTB204,

//;0x0334 PERIB INTB205
    (fp)INT_Excep_PERIB_INTB205,

//;0x0338 PERIB INTB206
    (fp)INT_Excep_PERIB_INTB206,

//;0x033C PERIB INTB207
    (fp)INT_Excep_PERIB_INTB207,

//;0x0340 PERIA INTA208
    (fp)INT_Excep_PERIA_INTA208,

//;0x0344 PERIA INTA209
    (fp)INT_Excep_PERIA_INTA209,

//;0x0348 PERIA INTA210
    (fp)INT_Excep_PERIA_INTA210,

//;0x034C PERIA INTA211
    (fp)INT_Excep_PERIA_INTA211,

//;0x0350 PERIA INTA212
    (fp)INT_Excep_PERIA_INTA212,

//;0x0354 PERIA INTA213
    (fp)INT_Excep_PERIA_INTA213,

//;0x0358 PERIA INTA214
    (fp)INT_Excep_PERIA_INTA214,

//;0x035C PERIA INTA215
    (fp)INT_Excep_PERIA_INTA215,

//;0x0360 PERIA INTA216
    (fp)INT_Excep_PERIA_INTA216,

//;0x0364 PERIA INTA217
    (fp)INT_Excep_PERIA_INTA217,

//;0x0368 PERIA INTA218
    (fp)INT_Excep_PERIA_INTA218,

//;0x036C PERIA INTA219
    (fp)INT_Excep_PERIA_INTA219,

//;0x0370 PERIA INTA220
    (fp)INT_Excep_PERIA_INTA220,

//;0x0374 PERIA INTA221
    (fp)INT_Excep_PERIA_INTA221,

//;0x0378 PERIA INTA222
    (fp)INT_Excep_PERIA_INTA222,

//;0x037C PERIA INTA223
    (fp)INT_Excep_PERIA_INTA223,

//;0x0380 PERIA INTA224
    (fp)INT_Excep_PERIA_INTA224,

//;0x0384 PERIA INTA225
    (fp)INT_Excep_PERIA_INTA225,

//;0x0388 PERIA INTA226
    (fp)INT_Excep_PERIA_INTA226,

//;0x038C PERIA INTA227
    (fp)INT_Excep_PERIA_INTA227,

//;0x0390 PERIA INTA228
    (fp)INT_Excep_PERIA_INTA228,

//;0x0394 PERIA INTA229
    (fp)INT_Excep_PERIA_INTA229,

//;0x0398 PERIA INTA230
    (fp)INT_Excep_PERIA_INTA230,

//;0x039C PERIA INTA231
    (fp)INT_Excep_PERIA_INTA231,

//;0x03A0 PERIA INTA232
    (fp)INT_Excep_PERIA_INTA232,

//;0x03A4 PERIA INTA233
    (fp)INT_Excep_PERIA_INTA233,

//;0x03A8 PERIA INTA234
    (fp)INT_Excep_PERIA_INTA234,

//;0x03AC PERIA INTA235
    (fp)INT_Excep_PERIA_INTA235,

//;0x03B0 PERIA INTA236
    (fp)INT_Excep_PERIA_INTA236,

//;0x04B4 PERIA INTA237
    (fp)INT_Excep_PERIA_INTA237,

//;0x03B8 PERIA INTA238
    (fp)INT_Excep_PERIA_INTA238,

//;0x03BC PERIA INTA239
    (fp)INT_Excep_PERIA_INTA239,

//;0x03C0 PERIA INTA240
    (fp)INT_Excep_PERIA_INTA240,

//;0x03C4 PERIA INTA241
    (fp)INT_Excep_PERIA_INTA241,

//;0x03C8 PERIA INTA242
    (fp)INT_Excep_PERIA_INTA242,

//;0x03CC PERIA INTA243
    (fp)INT_Excep_PERIA_INTA243,

//;0x03D0 PERIA INTA244
    (fp)INT_Excep_PERIA_INTA244,

//;0x03D4 PERIA INTA245
    (fp)INT_Excep_PERIA_INTA245,

//;0x03D8 PERIA INTA246
    (fp)INT_Excep_PERIA_INTA246,

//;0x03DC PERIA INTA247
    (fp)INT_Excep_PERIA_INTA247,

//;0x03E0 PERIA INTA248
    (fp)INT_Excep_PERIA_INTA248,

//;0x03E4 PERIA INTA249
    (fp)INT_Excep_PERIA_INTA249,

//;0x03E8 PERIA INTA250
    (fp)INT_Excep_PERIA_INTA250,

//;0x03EC PERIA INTA251
    (fp)INT_Excep_PERIA_INTA251,

//;0x03F0 PERIA INTA252
    (fp)INT_Excep_PERIA_INTA252,

//;0x03F4 PERIA INTA253
    (fp)INT_Excep_PERIA_INTA253,

//;0x03F8 PERIA INTA254
    (fp)INT_Excep_PERIA_INTA254,

//;0x03FC PERIA INTA255
    (fp)INT_Excep_PERIA_INTA255,
};

#define OFS_SPCC __attribute__ ((section (".ofs1"))) /* 0x00120040 */
#define OFS_TMEF __attribute__ ((section (".ofs2"))) /* 0x00120048 */
#define OFS_OSIC __attribute__ ((section (".ofs3"))) /* 0x00120050 */
#define OFS_REG  __attribute__ ((section (".ofs4"))) /* 0x00120060 */

const unsigned long __SPCCreg OFS_SPCC = 0xffffffff;

const unsigned long __TMEFreg OFS_TMEF = 0xffffffff;

// OSIC register (ID codes)
const unsigned long __OSISreg[4] OFS_OSIC = {
    0xffffffff,
    0xffffffff,
    0xffffffff,
    0xffffffff,
};

// TMINF register
const unsigned long __TMINFreg OFS_REG = 0xffffffff;

// MDE register (Single Chip Mode)
#ifdef __RX_BIG_ENDIAN__
const unsigned long __MDEreg OFS_REG = 0xfffffff8;    // big
#else
const unsigned long __MDEreg OFS_REG = 0xffffffff;    // little
#endif

// OFS0 register
const unsigned long __OFS0reg OFS_REG = 0xffffffff;

// OFS1 register
const unsigned long __OFS1reg OFS_REG = 0xffffffff;
