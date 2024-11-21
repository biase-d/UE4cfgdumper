#ifndef _ADEFS_H_
#define _ADEFS_H_

struct ad_operand {
    /* operand type (AD_OP_*) */
    int type;
    
    /* type == AD_OP_REG */
    struct {
        /* register (AD_REG_*) */
        int rn;
        /* register size */
        int sz;
        /* is this a floating point register? */
        int fp;
        /* is this a zero register? */
        int zr;
        /* if this is a system register, sysreg holds its encoding (AD_SYSREG_*) */
        int sysreg;
        
        /* register string table, use rn for indexing */
        const char **rtbl;
    } op_reg;

    /* type == AD_OP_SHIFT */
    struct {
        /* shift type (AD_SHIFT_*) */
        int type;
        /* shift amount */
        int amt;
    } op_shift;

    /* type == AD_OP_IMM */
    struct {
        /* immediate type (AD_IMM_*) */
        int type;
        /* the bits which make up this immediate */
        long bits;
    } op_imm;
};

struct ad_insn {
    /* instruction disassembly */
    char *decoded;

    /* which top level decode group this instruction belongs to (AD_G_*) */
    int group;
    /* unique instruction ID (AD_INSTR_*) */
    int instr_id;

    /* array of decode fields, going from left to right (as per the manual) */
    int *fields;
    int num_fields;

    /* array of ad_operand structs, going from left to right (according to the disassembly) */
    struct ad_operand *operands;
    int num_operands;

    /* code condition, if any (AD_CC_*) */
    int cc;
};

static const int AD_NONE = -1;

enum {
    AD_OP_REG = 0, AD_OP_IMM, AD_OP_SHIFT, AD_OP_MEM
};

enum {
    AD_SHIFT_LSL = 0, AD_SHIFT_LSR, AD_SHIFT_ASR, AD_SHIFT_ROR, AD_SHIFT_MSL
};

enum {
    AD_IMM_INT = 0, AD_IMM_UINT, AD_IMM_LONG, AD_IMM_ULONG, AD_IMM_FLOAT
};

enum {
    AD_G_Reserved = 0, AD_G_DataProcessingImmediate, AD_G_BranchExcSys,
    AD_G_LoadsAndStores, AD_G_DataProcessingRegister,
    AD_G_DataProcessingFloatingPoint
};

enum {
    AD_CC_EQ = 0, AD_CC_NE, AD_CC_CS, AD_CC_CC, AD_CC_MI, AD_CC_PL,
    AD_CC_VS, AD_CC_VC, AD_CC_HI, AD_CC_LS, AD_CC_GE, AD_CC_LT, AD_CC_GT,
    AD_CC_LE, AD_CC_AL
};

enum {
    AD_REG_X0 = 0,
    AD_REG_X1,
    AD_REG_X2,
    AD_REG_X3,
    AD_REG_X4,
    AD_REG_X5,
    AD_REG_X6,
    AD_REG_X7,
    AD_REG_X8,
    AD_REG_X9,
    AD_REG_X10,
    AD_REG_X11,
    AD_REG_X12,
    AD_REG_X13,
    AD_REG_X14,
    AD_REG_X15,
    AD_REG_X16,
    AD_REG_X17,
    AD_REG_X18,
    AD_REG_X19,
    AD_REG_X20,
    AD_REG_X21,
    AD_REG_X22,
    AD_REG_X23,
    AD_REG_X24,
    AD_REG_X25,
    AD_REG_X26,
    AD_REG_X27,
    AD_REG_X28,
    AD_REG_X29,
    AD_REG_SP = 30,
    AD_REG_XZR = 30
};

enum {
    AD_REG_W0 = 0,
    AD_REG_W1,
    AD_REG_W2,
    AD_REG_W3,
    AD_REG_W4,
    AD_REG_W5,
    AD_REG_W6,
    AD_REG_W7,
    AD_REG_W8,
    AD_REG_W9,
    AD_REG_W10,
    AD_REG_W11,
    AD_REG_W12,
    AD_REG_W13,
    AD_REG_W14,
    AD_REG_W15,
    AD_REG_W16,
    AD_REG_W17,
    AD_REG_W18,
    AD_REG_W19,
    AD_REG_W20,
    AD_REG_W21,
    AD_REG_W22,
    AD_REG_W23,
    AD_REG_W24,
    AD_REG_W25,
    AD_REG_W26,
    AD_REG_W27,
    AD_REG_W28,
    AD_REG_W29,
    AD_REG_WSP = 30,
    AD_REG_WZR = 30
};

enum {
    AD_REG_B0 = 0,
    AD_REG_B1,
    AD_REG_B2,
    AD_REG_B3,
    AD_REG_B4,
    AD_REG_B5,
    AD_REG_B6,
    AD_REG_B7,
    AD_REG_B8,
    AD_REG_B9,
    AD_REG_B10,
    AD_REG_B11,
    AD_REG_B12,
    AD_REG_B13,
    AD_REG_B14,
    AD_REG_B15,
    AD_REG_B16,
    AD_REG_B17,
    AD_REG_B18,
    AD_REG_B19,
    AD_REG_B20,
    AD_REG_B21,
    AD_REG_B22,
    AD_REG_B23,
    AD_REG_B24,
    AD_REG_B25,
    AD_REG_B26,
    AD_REG_B27,
    AD_REG_B28,
    AD_REG_B29,
    AD_REG_B30
};

enum {
    AD_REG_H0 = 0,
    AD_REG_H1,
    AD_REG_H2,
    AD_REG_H3,
    AD_REG_H4,
    AD_REG_H5,
    AD_REG_H6,
    AD_REG_H7,
    AD_REG_H8,
    AD_REG_H9,
    AD_REG_H10,
    AD_REG_H11,
    AD_REG_H12,
    AD_REG_H13,
    AD_REG_H14,
    AD_REG_H15,
    AD_REG_H16,
    AD_REG_H17,
    AD_REG_H18,
    AD_REG_H19,
    AD_REG_H20,
    AD_REG_H21,
    AD_REG_H22,
    AD_REG_H23,
    AD_REG_H24,
    AD_REG_H25,
    AD_REG_H26,
    AD_REG_H27,
    AD_REG_H28,
    AD_REG_H29,
    AD_REG_H30
};

enum {
    AD_REG_S0 = 0,
    AD_REG_S1,
    AD_REG_S2,
    AD_REG_S3,
    AD_REG_S4,
    AD_REG_S5,
    AD_REG_S6,
    AD_REG_S7,
    AD_REG_S8,
    AD_REG_S9,
    AD_REG_S10,
    AD_REG_S11,
    AD_REG_S12,
    AD_REG_S13,
    AD_REG_S14,
    AD_REG_S15,
    AD_REG_S16,
    AD_REG_S17,
    AD_REG_S18,
    AD_REG_S19,
    AD_REG_S20,
    AD_REG_S21,
    AD_REG_S22,
    AD_REG_S23,
    AD_REG_S24,
    AD_REG_S25,
    AD_REG_S26,
    AD_REG_S27,
    AD_REG_S28,
    AD_REG_S29,
    AD_REG_S30
};

enum {
    AD_REG_D0 = 0,
    AD_REG_D1,
    AD_REG_D2,
    AD_REG_D3,
    AD_REG_D4,
    AD_REG_D5,
    AD_REG_D6,
    AD_REG_D7,
    AD_REG_D8,
    AD_REG_D9,
    AD_REG_D10,
    AD_REG_D11,
    AD_REG_D12,
    AD_REG_D13,
    AD_REG_D14,
    AD_REG_D15,
    AD_REG_D16,
    AD_REG_D17,
    AD_REG_D18,
    AD_REG_D19,
    AD_REG_D20,
    AD_REG_D21,
    AD_REG_D22,
    AD_REG_D23,
    AD_REG_D24,
    AD_REG_D25,
    AD_REG_D26,
    AD_REG_D27,
    AD_REG_D28,
    AD_REG_D29,
    AD_REG_D30
};

enum {
    AD_REG_Q0 = 0,
    AD_REG_Q1,
    AD_REG_Q2,
    AD_REG_Q3,
    AD_REG_Q4,
    AD_REG_Q5,
    AD_REG_Q6,
    AD_REG_Q7,
    AD_REG_Q8,
    AD_REG_Q9,
    AD_REG_Q10,
    AD_REG_Q11,
    AD_REG_Q12,
    AD_REG_Q13,
    AD_REG_Q14,
    AD_REG_Q15,
    AD_REG_Q16,
    AD_REG_Q17,
    AD_REG_Q18,
    AD_REG_Q19,
    AD_REG_Q20,
    AD_REG_Q21,
    AD_REG_Q22,
    AD_REG_Q23,
    AD_REG_Q24,
    AD_REG_Q25,
    AD_REG_Q26,
    AD_REG_Q27,
    AD_REG_Q28,
    AD_REG_Q29,
    AD_REG_Q30
};

enum {
    AD_REG_V0 = 0,
    AD_REG_V1,
    AD_REG_V2,
    AD_REG_V3,
    AD_REG_V4,
    AD_REG_V5,
    AD_REG_V6,
    AD_REG_V7,
    AD_REG_V8,
    AD_REG_V9,
    AD_REG_V10,
    AD_REG_V11,
    AD_REG_V12,
    AD_REG_V13,
    AD_REG_V14,
    AD_REG_V15,
    AD_REG_V16,
    AD_REG_V17,
    AD_REG_V18,
    AD_REG_V19,
    AD_REG_V20,
    AD_REG_V21,
    AD_REG_V22,
    AD_REG_V23,
    AD_REG_V24,
    AD_REG_V25,
    AD_REG_V26,
    AD_REG_V27,
    AD_REG_V28,
    AD_REG_V29,
    AD_REG_V30
};

enum {
    AD_INSTR_ADC = 0,
    AD_INSTR_ADCS,
    AD_INSTR_ADD,
    AD_INSTR_ADDG,
    AD_INSTR_ADDS,
    AD_INSTR_ADR,
    AD_INSTR_ADRP,
    AD_INSTR_AND,
    AD_INSTR_ANDS,
    AD_INSTR_ASR,
    AD_INSTR_ASRV,
    AD_INSTR_AT,
    AD_INSTR_AUTDA,
    AD_INSTR_AUTDZA,
    AD_INSTR_AUTDB,
    AD_INSTR_AUTDZB,
    AD_INSTR_AUTIA,
    AD_INSTR_AUTIZA,
    AD_INSTR_AUTIA1716,
    AD_INSTR_AUTIASP,
    AD_INSTR_AUTIAZ,
    AD_INSTR_AUTIB,
    AD_INSTR_AUTIZB,
    AD_INSTR_AUTIB1716,
    AD_INSTR_AUTIBSP,
    AD_INSTR_AUTIBZ,
    AD_INSTR_AXFLAG,
    AD_INSTR_ARM_DDI,
    AD_INSTR_B,
    AD_INSTR_BFC,
    AD_INSTR_BFI,
    AD_INSTR_BFM,
    AD_INSTR_BFXIL,
    AD_INSTR_BIC,
    AD_INSTR_BICS,
    AD_INSTR_BL,
    AD_INSTR_BLR,
    AD_INSTR_BLRAAZ,
    AD_INSTR_BLRAA,
    AD_INSTR_BLRABZ,
    AD_INSTR_BLRAB,
    AD_INSTR_BR,
    AD_INSTR_BRAAZ,
    AD_INSTR_BRAA,
    AD_INSTR_BRABZ,
    AD_INSTR_BRAB,
    AD_INSTR_BRK,
    AD_INSTR_BTI,
    AD_INSTR_CASAB,
    AD_INSTR_CASALB,
    AD_INSTR_CASB,
    AD_INSTR_CASLB,
    AD_INSTR_CASAH,
    AD_INSTR_CASALH,
    AD_INSTR_CASH,
    AD_INSTR_CASLH,
    AD_INSTR_CASP,
    AD_INSTR_CASPA,
    AD_INSTR_CASPAL,
    AD_INSTR_CASPL,
    AD_INSTR_CAS,
    AD_INSTR_CASA,
    AD_INSTR_CASAL,
    AD_INSTR_CASL,
    AD_INSTR_CBNZ,
    AD_INSTR_CBZ,
    AD_INSTR_CCMN,
    AD_INSTR_CCMP,
    AD_INSTR_CFINV,
    AD_INSTR_CFP,
    AD_INSTR_CINC,
    AD_INSTR_CINV,
    AD_INSTR_CLREX,
    AD_INSTR_CLS,
    AD_INSTR_CLZ,
    AD_INSTR_CMN,
    AD_INSTR_CMP,
    AD_INSTR_CMPP,
    AD_INSTR_CNEG,
    AD_INSTR_CPP,
    AD_INSTR_CRC32B,
    AD_INSTR_CRC32H,
    AD_INSTR_CRC32W,
    AD_INSTR_CRC32X,
    AD_INSTR_CRC32CB,
    AD_INSTR_CRC32CH,
    AD_INSTR_CRC32CW,
    AD_INSTR_CRC32CX,
    AD_INSTR_CSDB,
    AD_INSTR_CSEL,
    AD_INSTR_CSET,
    AD_INSTR_CSETM,
    AD_INSTR_CSINC,
    AD_INSTR_CSINV,
    AD_INSTR_CSNEG,
    AD_INSTR_DC,
    AD_INSTR_DCPS1,
    AD_INSTR_DCPS2,
    AD_INSTR_DCPS3,
    AD_INSTR_DMB,
    AD_INSTR_DRPS,
    AD_INSTR_DSB,
    AD_INSTR_DVP,
    AD_INSTR_EON,
    AD_INSTR_EOR,
    AD_INSTR_ERET,
    AD_INSTR_ERETAA,
    AD_INSTR_ERETAB,
    AD_INSTR_ESB,
    AD_INSTR_EXTR,
    AD_INSTR_GMI,
    AD_INSTR_HINT,
    AD_INSTR_HLT,
    AD_INSTR_HVC,
    AD_INSTR_IC,
    AD_INSTR_IRG,
    AD_INSTR_ISB,
    AD_INSTR_LDADDAB,
    AD_INSTR_LDADDALB,
    AD_INSTR_LDADDB,
    AD_INSTR_LDADDLB,
    AD_INSTR_LDADDAH,
    AD_INSTR_LDADDALH,
    AD_INSTR_LDADDH,
    AD_INSTR_LDADDLH,
    AD_INSTR_LDADD,
    AD_INSTR_LDADDA,
    AD_INSTR_LDADDAL,
    AD_INSTR_LDADDL,
    AD_INSTR_LDAPR,
    AD_INSTR_LDAPRB,
    AD_INSTR_LDAPRH,
    AD_INSTR_LDAPUR,
    AD_INSTR_LDAPURB,
    AD_INSTR_LDAPURH,
    AD_INSTR_LDAPURSB,
    AD_INSTR_LDAPURSH,
    AD_INSTR_LDAPURSW,
    AD_INSTR_LDAR,
    AD_INSTR_LDARB,
    AD_INSTR_LDARH,
    AD_INSTR_LDAXP,
    AD_INSTR_LDAXR,
    AD_INSTR_LDAXRB,
    AD_INSTR_LDAXRH,
    AD_INSTR_LDCLRAB,
    AD_INSTR_LDCLRALB,
    AD_INSTR_LDCLRB,
    AD_INSTR_LDCLRLB,
    AD_INSTR_LDCLRAH,
    AD_INSTR_LDCLRALH,
    AD_INSTR_LDCLRH,
    AD_INSTR_LDCLRLH,
    AD_INSTR_LDCLR,
    AD_INSTR_LDCLRA,
    AD_INSTR_LDCLRAL,
    AD_INSTR_LDCLRL,
    AD_INSTR_LDEORAB,
    AD_INSTR_LDEORALB,
    AD_INSTR_LDEORB,
    AD_INSTR_LDEORLB,
    AD_INSTR_LDEORAH,
    AD_INSTR_LDEORALH,
    AD_INSTR_LDEORH,
    AD_INSTR_LDEORLH,
    AD_INSTR_LDEOR,
    AD_INSTR_LDEORA,
    AD_INSTR_LDEORAL,
    AD_INSTR_LDEORL,
    AD_INSTR_LDG,
    AD_INSTR_LDGM,
    AD_INSTR_LDLARB,
    AD_INSTR_LDLARH,
    AD_INSTR_LDLAR,
    AD_INSTR_LDNP,
    AD_INSTR_LDP,
    AD_INSTR_LDPSW,
    AD_INSTR_LDR,
    AD_INSTR_LDRAA,
    AD_INSTR_LDRAB,
    AD_INSTR_LDRB,
    AD_INSTR_LDRH,
    AD_INSTR_LDRSB,
    AD_INSTR_LDRSH,
    AD_INSTR_LDRSW,
    AD_INSTR_LDSETAB,
    AD_INSTR_LDSETALB,
    AD_INSTR_LDSETB,
    AD_INSTR_LDSETLB,
    AD_INSTR_LDSETAH,
    AD_INSTR_LDSETALH,
    AD_INSTR_LDSETH,
    AD_INSTR_LDSETLH,
    AD_INSTR_LDSET,
    AD_INSTR_LDSETA,
    AD_INSTR_LDSETAL,
    AD_INSTR_LDSETL,
    AD_INSTR_LDSMAXAB,
    AD_INSTR_LDSMAXALB,
    AD_INSTR_LDSMAXB,
    AD_INSTR_LDSMAXLB,
    AD_INSTR_LDSMAXAH,
    AD_INSTR_LDSMAXALH,
    AD_INSTR_LDSMAXH,
    AD_INSTR_LDSMAXLH,
    AD_INSTR_LDSMAX,
    AD_INSTR_LDSMAXA,
    AD_INSTR_LDSMAXAL,
    AD_INSTR_LDSMAXL,
    AD_INSTR_LDSMINAB,
    AD_INSTR_LDSMINALB,
    AD_INSTR_LDSMINB,
    AD_INSTR_LDSMINLB,
    AD_INSTR_LDSMINAH,
    AD_INSTR_LDSMINALH,
    AD_INSTR_LDSMINH,
    AD_INSTR_LDSMINLH,
    AD_INSTR_LDSMIN,
    AD_INSTR_LDSMINA,
    AD_INSTR_LDSMINAL,
    AD_INSTR_LDSMINL,
    AD_INSTR_LDTR,
    AD_INSTR_LDTRB,
    AD_INSTR_LDTRH,
    AD_INSTR_LDTRSB,
    AD_INSTR_LDTRSH,
    AD_INSTR_LDTRSW,
    AD_INSTR_LDUMAXAB,
    AD_INSTR_LDUMAXALB,
    AD_INSTR_LDUMAXB,
    AD_INSTR_LDUMAXLB,
    AD_INSTR_LDUMAXAH,
    AD_INSTR_LDUMAXALH,
    AD_INSTR_LDUMAXH,
    AD_INSTR_LDUMAXLH,
    AD_INSTR_LDUMAX,
    AD_INSTR_LDUMAXA,
    AD_INSTR_LDUMAXAL,
    AD_INSTR_LDUMAXL,
    AD_INSTR_LDUMINAB,
    AD_INSTR_LDUMINALB,
    AD_INSTR_LDUMINB,
    AD_INSTR_LDUMINLB,
    AD_INSTR_LDUMINAH,
    AD_INSTR_LDUMINALH,
    AD_INSTR_LDUMINH,
    AD_INSTR_LDUMINLH,
    AD_INSTR_LDUMIN,
    AD_INSTR_LDUMINA,
    AD_INSTR_LDUMINAL,
    AD_INSTR_LDUMINL,
    AD_INSTR_LDUR,
    AD_INSTR_LDURB,
    AD_INSTR_LDURH,
    AD_INSTR_LDURSB,
    AD_INSTR_LDURSH,
    AD_INSTR_LDURSW,
    AD_INSTR_LDXP,
    AD_INSTR_LDXR,
    AD_INSTR_LDXRB,
    AD_INSTR_LDXRH,
    AD_INSTR_LSL,
    AD_INSTR_LSLV,
    AD_INSTR_LSR,
    AD_INSTR_LSRV,
    AD_INSTR_MADD,
    AD_INSTR_MNEG,
    AD_INSTR_MOV,
    AD_INSTR_MOVK,
    AD_INSTR_MOVN,
    AD_INSTR_MOVZ,
    AD_INSTR_MRS,
    AD_INSTR_MSR,
    AD_INSTR_MSUB,
    AD_INSTR_MUL,
    AD_INSTR_MVN,
    AD_INSTR_NEG,
    AD_INSTR_NEGS,
    AD_INSTR_NGC,
    AD_INSTR_NGCS,
    AD_INSTR_NOP,
    AD_INSTR_ORN,
    AD_INSTR_ORR,
    AD_INSTR_PACDA,
    AD_INSTR_PACDZA,
    AD_INSTR_PACDB,
    AD_INSTR_PACDZB,
    AD_INSTR_PACGA,
    AD_INSTR_PACIA,
    AD_INSTR_PACIZA,
    AD_INSTR_PACIA1716,
    AD_INSTR_PACIASP,
    AD_INSTR_PACIAZ,
    AD_INSTR_PACIB,
    AD_INSTR_PACIZB,
    AD_INSTR_PACIB1716,
    AD_INSTR_PACIBSP,
    AD_INSTR_PACIBZ,
    AD_INSTR_PRFM,
    AD_INSTR_PRFUM,
    AD_INSTR_PSB_CSYNC,
    AD_INSTR_PSSBB,
    AD_INSTR_RBIT,
    AD_INSTR_RET,
    AD_INSTR_RETAA,
    AD_INSTR_RETAB,
    AD_INSTR_REV,
    AD_INSTR_REV16,
    AD_INSTR_REV32,
    AD_INSTR_REV64,
    AD_INSTR_RMIF,
    AD_INSTR_ROR,
    AD_INSTR_RORV,
    AD_INSTR_SB,
    AD_INSTR_SBC,
    AD_INSTR_SBCS,
    AD_INSTR_SBFIZ,
    AD_INSTR_SBFM,
    AD_INSTR_SBFX,
    AD_INSTR_SDIV,
    AD_INSTR_SETF8,
    AD_INSTR_SETF16,
    AD_INSTR_SEV,
    AD_INSTR_SEVL,
    AD_INSTR_SMADDL,
    AD_INSTR_SMC,
    AD_INSTR_SMNEGL,
    AD_INSTR_SMSUBL,
    AD_INSTR_SMULH,
    AD_INSTR_SMULL,
    AD_INSTR_SSBB,
    AD_INSTR_ST2G,
    AD_INSTR_STADDB,
    AD_INSTR_STADDLB,
    AD_INSTR_STADDH,
    AD_INSTR_STADDLH,
    AD_INSTR_STADD,
    AD_INSTR_STADDL,
    AD_INSTR_STCLRB,
    AD_INSTR_STCLRLB,
    AD_INSTR_STCLRH,
    AD_INSTR_STCLRLH,
    AD_INSTR_STCLR,
    AD_INSTR_STCLRL,
    AD_INSTR_STEORB,
    AD_INSTR_STEORLB,
    AD_INSTR_STEORH,
    AD_INSTR_STEORLH,
    AD_INSTR_STEOR,
    AD_INSTR_STEORL,
    AD_INSTR_STG,
    AD_INSTR_STGM,
    AD_INSTR_STGP,
    AD_INSTR_STLLRB,
    AD_INSTR_STLLRH,
    AD_INSTR_STLLR,
    AD_INSTR_STLR,
    AD_INSTR_STLRB,
    AD_INSTR_STLRH,
    AD_INSTR_STLUR,
    AD_INSTR_STLURB,
    AD_INSTR_STLURH,
    AD_INSTR_STLXP,
    AD_INSTR_STLXR,
    AD_INSTR_STLXRB,
    AD_INSTR_STLXRH,
    AD_INSTR_STNP,
    AD_INSTR_STP,
    AD_INSTR_STR,
    AD_INSTR_STRB,
    AD_INSTR_STRH,
    AD_INSTR_STSETB,
    AD_INSTR_STSETLB,
    AD_INSTR_STSETH,
    AD_INSTR_STSETLH,
    AD_INSTR_STSET,
    AD_INSTR_STSETL,
    AD_INSTR_STSMAXB,
    AD_INSTR_STSMAXLB,
    AD_INSTR_STSMAXH,
    AD_INSTR_STSMAXLH,
    AD_INSTR_STSMAX,
    AD_INSTR_STSMAXL,
    AD_INSTR_STSMINB,
    AD_INSTR_STSMINLB,
    AD_INSTR_STSMINH,
    AD_INSTR_STSMINLH,
    AD_INSTR_STSMIN,
    AD_INSTR_STSMINL,
    AD_INSTR_STTR,
    AD_INSTR_STTRB,
    AD_INSTR_STTRH,
    AD_INSTR_STUMAXB,
    AD_INSTR_STUMAXLB,
    AD_INSTR_STUMAXH,
    AD_INSTR_STUMAXLH,
    AD_INSTR_STUMAX,
    AD_INSTR_STUMAXL,
    AD_INSTR_STUMINB,
    AD_INSTR_STUMINLB,
    AD_INSTR_STUMINH,
    AD_INSTR_STUMINLH,
    AD_INSTR_STUMIN,
    AD_INSTR_STUMINL,
    AD_INSTR_STUR,
    AD_INSTR_STURB,
    AD_INSTR_STURH,
    AD_INSTR_STXP,
    AD_INSTR_STXR,
    AD_INSTR_STXRB,
    AD_INSTR_STXRH,
    AD_INSTR_STZ2G,
    AD_INSTR_STZG,
    AD_INSTR_STZGM,
    AD_INSTR_SUB,
    AD_INSTR_SUBG,
    AD_INSTR_SUBP,
    AD_INSTR_SUBPS,
    AD_INSTR_SUBS,
    AD_INSTR_SVC,
    AD_INSTR_SWPAB,
    AD_INSTR_SWPALB,
    AD_INSTR_SWPB,
    AD_INSTR_SWPLB,
    AD_INSTR_SWPAH,
    AD_INSTR_SWPALH,
    AD_INSTR_SWPH,
    AD_INSTR_SWPLH,
    AD_INSTR_SWP,
    AD_INSTR_SWPA,
    AD_INSTR_SWPAL,
    AD_INSTR_SWPL,
    AD_INSTR_SXTB,
    AD_INSTR_SXTH,
    AD_INSTR_SXTW,
    AD_INSTR_SYS,
    AD_INSTR_SYSL,
    AD_INSTR_TBNZ,
    AD_INSTR_TBZ,
    AD_INSTR_TLBI,
    AD_INSTR_TSB_CSYNC,
    AD_INSTR_TST,
    AD_INSTR_UBFIZ,
    AD_INSTR_UBFM,
    AD_INSTR_UBFX,
    AD_INSTR_UDF,
    AD_INSTR_UDIV,
    AD_INSTR_UMADDL,
    AD_INSTR_UMNEGL,
    AD_INSTR_UMSUBL,
    AD_INSTR_UMULH,
    AD_INSTR_UMULL,
    AD_INSTR_UXTB,
    AD_INSTR_UXTH,
    AD_INSTR_WFE,
    AD_INSTR_WFI,
    AD_INSTR_XAFLAG,
    AD_INSTR_XPACD,
    AD_INSTR_XPACI,
    AD_INSTR_XPACLRI,
    AD_INSTR_YIELD,
    AD_INSTR_ABS,
    AD_INSTR_ADDHN,
    AD_INSTR_ADDHN2,
    AD_INSTR_ADDP,
    AD_INSTR_ADDV,
    AD_INSTR_AESD,
    AD_INSTR_AESE,
    AD_INSTR_AESIMC,
    AD_INSTR_AESMC,
    AD_INSTR_BCAX,
    AD_INSTR_BIF,
    AD_INSTR_BIT,
    AD_INSTR_BSL,
    AD_INSTR_CMEQ,
    AD_INSTR_CMGE,
    AD_INSTR_CMGT,
    AD_INSTR_CMHI,
    AD_INSTR_CMHS,
    AD_INSTR_CMLE,
    AD_INSTR_CMLT,
    AD_INSTR_CMTST,
    AD_INSTR_CNT,
    AD_INSTR_DUP,
    AD_INSTR_EOR3,
    AD_INSTR_EXT,
    AD_INSTR_FABD,
    AD_INSTR_FABS,
    AD_INSTR_FACGE,
    AD_INSTR_FACGT,
    AD_INSTR_FADD,
    AD_INSTR_FADDP,
    AD_INSTR_FCADD,
    AD_INSTR_FCCMP,
    AD_INSTR_FCCMPE,
    AD_INSTR_FCMEQ,
    AD_INSTR_FCMGE,
    AD_INSTR_FCMGT,
    AD_INSTR_FCMLA,
    AD_INSTR_FCMLE,
    AD_INSTR_FCMLT,
    AD_INSTR_FCMP,
    AD_INSTR_FCMPE,
    AD_INSTR_FCSEL,
    AD_INSTR_FCVT,
    AD_INSTR_FCVTAS,
    AD_INSTR_FCVTAU,
    AD_INSTR_FCVTL,
    AD_INSTR_FCVTL2,
    AD_INSTR_FCVTMS,
    AD_INSTR_FCVTMU,
    AD_INSTR_FCVTN,
    AD_INSTR_FCVTN2,
    AD_INSTR_FCVTNS,
    AD_INSTR_FCVTNU,
    AD_INSTR_FCVTPS,
    AD_INSTR_FCVTPU,
    AD_INSTR_FCVTXN,
    AD_INSTR_FCVTXN2,
    AD_INSTR_FCVTZS,
    AD_INSTR_FCVTZU,
    AD_INSTR_FDIV,
    AD_INSTR_FJCVTZS,
    AD_INSTR_FMADD,
    AD_INSTR_FMAX,
    AD_INSTR_FMAXNM,
    AD_INSTR_FMAXNMP,
    AD_INSTR_FMAXNMV,
    AD_INSTR_FMAXP,
    AD_INSTR_FMAXV,
    AD_INSTR_FMIN,
    AD_INSTR_FMINNM,
    AD_INSTR_FMINNMP,
    AD_INSTR_FMINNMV,
    AD_INSTR_FMINP,
    AD_INSTR_FMINV,
    AD_INSTR_FMLA,
    AD_INSTR_FMLAL,
    AD_INSTR_FMLAL2,
    AD_INSTR_FMLS,
    AD_INSTR_FMLSL,
    AD_INSTR_FMLSL2,
    AD_INSTR_FMOV,
    AD_INSTR_FMSUB,
    AD_INSTR_FMUL,
    AD_INSTR_FMULX,
    AD_INSTR_FNEG,
    AD_INSTR_FNMADD,
    AD_INSTR_FNMSUB,
    AD_INSTR_FNMUL,
    AD_INSTR_FRECPE,
    AD_INSTR_FRECPS,
    AD_INSTR_FRECPX,
    AD_INSTR_FRINT32X,
    AD_INSTR_FRINT32Z,
    AD_INSTR_FRINT64X,
    AD_INSTR_FRINT64Z,
    AD_INSTR_FRINTA,
    AD_INSTR_FRINTI,
    AD_INSTR_FRINTM,
    AD_INSTR_FRINTN,
    AD_INSTR_FRINTP,
    AD_INSTR_FRINTX,
    AD_INSTR_FRINTZ,
    AD_INSTR_FRSQRTE,
    AD_INSTR_FRSQRTS,
    AD_INSTR_FSQRT,
    AD_INSTR_FSUB,
    AD_INSTR_INS,
    AD_INSTR_LD1,
    AD_INSTR_LD1R,
    AD_INSTR_LD2,
    AD_INSTR_LD2R,
    AD_INSTR_LD3,
    AD_INSTR_LD3R,
    AD_INSTR_LD4,
    AD_INSTR_LD4R,
    AD_INSTR_MLA,
    AD_INSTR_MLS,
    AD_INSTR_MOVI,
    AD_INSTR_MVNI,
    AD_INSTR_NOT,
    AD_INSTR_PMUL,
    AD_INSTR_PMULL,
    AD_INSTR_PMULL2,
    AD_INSTR_RADDHN,
    AD_INSTR_RADDHN2,
    AD_INSTR_RAX1,
    AD_INSTR_RSHRN,
    AD_INSTR_RSHRN2,
    AD_INSTR_RSUBHN,
    AD_INSTR_RSUBHN2,
    AD_INSTR_SABA,
    AD_INSTR_SABAL,
    AD_INSTR_SABAL2,
    AD_INSTR_SABD,
    AD_INSTR_SABDL,
    AD_INSTR_SABDL2,
    AD_INSTR_SADALP,
    AD_INSTR_SADDL,
    AD_INSTR_SADDL2,
    AD_INSTR_SADDLP,
    AD_INSTR_SADDLV,
    AD_INSTR_SADDW,
    AD_INSTR_SADDW2,
    AD_INSTR_SCVTF,
    AD_INSTR_SDOT,
    AD_INSTR_SHA1C,
    AD_INSTR_SHA1H,
    AD_INSTR_SHA1M,
    AD_INSTR_SHA1P,
    AD_INSTR_SHA1SU0,
    AD_INSTR_SHA1SU1,
    AD_INSTR_SHA256H2,
    AD_INSTR_SHA256H,
    AD_INSTR_SHA256SU0,
    AD_INSTR_SHA256SU1,
    AD_INSTR_SHA512H,
    AD_INSTR_SHA512H2,
    AD_INSTR_SHA512SU0,
    AD_INSTR_SHA512SU1,
    AD_INSTR_SHADD,
    AD_INSTR_SHL,
    AD_INSTR_SHLL,
    AD_INSTR_SHLL2,
    AD_INSTR_SHRN,
    AD_INSTR_SHRN2,
    AD_INSTR_SHSUB,
    AD_INSTR_SLI,
    AD_INSTR_SM3PARTW1,
    AD_INSTR_SM3PARTW2,
    AD_INSTR_SM3SS1,
    AD_INSTR_SM3TT1A,
    AD_INSTR_SM3TT1B,
    AD_INSTR_SM3TT2A,
    AD_INSTR_SM3TT2B,
    AD_INSTR_SM4E,
    AD_INSTR_SM4EKEY,
    AD_INSTR_SMAX,
    AD_INSTR_SMAXP,
    AD_INSTR_SMAXV,
    AD_INSTR_SMIN,
    AD_INSTR_SMINP,
    AD_INSTR_SMINV,
    AD_INSTR_SMLAL,
    AD_INSTR_SMLAL2,
    AD_INSTR_SMLSL,
    AD_INSTR_SMLSL2,
    AD_INSTR_SMOV,
    AD_INSTR_SMULL2,
    AD_INSTR_SQABS,
    AD_INSTR_SQADD,
    AD_INSTR_SQDMLAL,
    AD_INSTR_SQDMLAL2,
    AD_INSTR_SQDMLSL,
    AD_INSTR_SQDMLSL2,
    AD_INSTR_SQDMULH,
    AD_INSTR_SQDMULL,
    AD_INSTR_SQDMULL2,
    AD_INSTR_SQNEG,
    AD_INSTR_SQRDMLAH,
    AD_INSTR_SQRDMLSH,
    AD_INSTR_SQRDMULH,
    AD_INSTR_SQRSHL,
    AD_INSTR_SQRSHRN,
    AD_INSTR_SQRSHRN2,
    AD_INSTR_SQRSHRUN,
    AD_INSTR_SQRSHRUN2,
    AD_INSTR_SQSHL,
    AD_INSTR_SQSHLU,
    AD_INSTR_SQSHRN,
    AD_INSTR_SQSHRN2,
    AD_INSTR_SQSHRUN,
    AD_INSTR_SQSHRUN2,
    AD_INSTR_SQSUB,
    AD_INSTR_SQXTN,
    AD_INSTR_SQXTN2,
    AD_INSTR_SQXTUN,
    AD_INSTR_SQXTUN2,
    AD_INSTR_SRHADD,
    AD_INSTR_SRI,
    AD_INSTR_SRSHL,
    AD_INSTR_SRSHR,
    AD_INSTR_SRSRA,
    AD_INSTR_SSHL,
    AD_INSTR_SSHLL,
    AD_INSTR_SSHLL2,
    AD_INSTR_SSHR,
    AD_INSTR_SSRA,
    AD_INSTR_SSUBL,
    AD_INSTR_SSUBL2,
    AD_INSTR_SSUBW,
    AD_INSTR_SSUBW2,
    AD_INSTR_ST1,
    AD_INSTR_ST2,
    AD_INSTR_ST3,
    AD_INSTR_ST4,
    AD_INSTR_SUBHN,
    AD_INSTR_SUBHN2,
    AD_INSTR_SUQADD,
    AD_INSTR_SXTL,
    AD_INSTR_SXTL2,
    AD_INSTR_TBL,
    AD_INSTR_TBX,
    AD_INSTR_TRN1,
    AD_INSTR_TRN2,
    AD_INSTR_UABA,
    AD_INSTR_UABAL,
    AD_INSTR_UABAL2,
    AD_INSTR_UABD,
    AD_INSTR_UABDL,
    AD_INSTR_UABDL2,
    AD_INSTR_UADALP,
    AD_INSTR_UADDL,
    AD_INSTR_UADDL2,
    AD_INSTR_UADDLP,
    AD_INSTR_UADDLV,
    AD_INSTR_UADDW,
    AD_INSTR_UADDW2,
    AD_INSTR_UCVTF,
    AD_INSTR_UDOT,
    AD_INSTR_UHADD,
    AD_INSTR_UHSUB,
    AD_INSTR_UMAX,
    AD_INSTR_UMAXP,
    AD_INSTR_UMAXV,
    AD_INSTR_UMIN,
    AD_INSTR_UMINP,
    AD_INSTR_UMINV,
    AD_INSTR_UMLAL,
    AD_INSTR_UMLAL2,
    AD_INSTR_UMLSL,
    AD_INSTR_UMLSL2,
    AD_INSTR_UMOV,
    AD_INSTR_UMULL2,
    AD_INSTR_UQADD,
    AD_INSTR_UQRSHL,
    AD_INSTR_UQRSHRN,
    AD_INSTR_UQRSHRN2,
    AD_INSTR_UQSHL,
    AD_INSTR_UQSHRN,
    AD_INSTR_UQSHRN2,
    AD_INSTR_UQSUB,
    AD_INSTR_UQXTN,
    AD_INSTR_UQXTN2,
    AD_INSTR_URECPE,
    AD_INSTR_URHADD,
    AD_INSTR_URSHL,
    AD_INSTR_URSHR,
    AD_INSTR_URSQRTE,
    AD_INSTR_URSRA,
    AD_INSTR_USHL,
    AD_INSTR_USHLL,
    AD_INSTR_USHLL2,
    AD_INSTR_USHR,
    AD_INSTR_USQADD,
    AD_INSTR_USRA,
    AD_INSTR_USUBL,
    AD_INSTR_USUBL2,
    AD_INSTR_USUBW,
    AD_INSTR_USUBW2,
    AD_INSTR_UXTL,
    AD_INSTR_UXTL2,
    AD_INSTR_UZP1,
    AD_INSTR_UZP2,
    AD_INSTR_XAR,
    AD_INSTR_XTN,
    AD_INSTR_XTN2,
    AD_INSTR_ZIP1,
    AD_INSTR_ZIP2,
};

enum {
    AD_SYSREG_ACTLR_EL1 = 0xc081,
    AD_SYSREG_ACTLR_EL2 = 0xe081,
    AD_SYSREG_ACTLR_EL3 = 0xf081,
    AD_SYSREG_AFSR0_EL1 = 0xc288,
    AD_SYSREG_AFSR0_EL12 = 0xea88,
    AD_SYSREG_AFSR0_EL2 = 0xe288,
    AD_SYSREG_AFSR0_EL3 = 0xf288,
    AD_SYSREG_AFSR1_EL1 = 0xc289,
    AD_SYSREG_AFSR1_EL12 = 0xea89,
    AD_SYSREG_AFSR1_EL2 = 0xe289,
    AD_SYSREG_AFSR1_EL3 = 0xf289,
    AD_SYSREG_AIDR_EL1 = 0xc807,
    AD_SYSREG_AMAIR_EL1 = 0xc518,
    AD_SYSREG_AMAIR_EL12 = 0xed18,
    AD_SYSREG_AMAIR_EL2 = 0xe518,
    AD_SYSREG_AMAIR_EL3 = 0xf518,
    AD_SYSREG_AMCFGR_EL0 = 0xde91,
    AD_SYSREG_AMCGCR_EL0 = 0xde92,
    AD_SYSREG_AMCNTENCLR0_EL0 = 0xde94,
    AD_SYSREG_AMCNTENCLR1_EL0 = 0xde98,
    AD_SYSREG_AMCNTENSET0_EL0 = 0xde95,
    AD_SYSREG_AMCNTENSET1_EL0 = 0xde99,
    AD_SYSREG_AMCR_EL0 = 0xde90,
    AD_SYSREG_AMUSERENR_EL0 = 0xde93,
    AD_SYSREG_APDAKeyHi_EL1 = 0xc111,
    AD_SYSREG_APDAKeyLo_EL1 = 0xc110,
    AD_SYSREG_APDBKeyHi_EL1 = 0xc113,
    AD_SYSREG_APDBKeyLo_EL1 = 0xc112,
    AD_SYSREG_APGAKeyHi_EL1 = 0xc119,
    AD_SYSREG_APGAKeyLo_EL1 = 0xc118,
    AD_SYSREG_APIAKeyHi_EL1 = 0xc109,
    AD_SYSREG_APIAKeyLo_EL1 = 0xc108,
    AD_SYSREG_APIBKeyHi_EL1 = 0xc10b,
    AD_SYSREG_APIBKeyLo_EL1 = 0xc10a,
    AD_SYSREG_CCSIDR2_EL1 = 0xc802,
    AD_SYSREG_CCSIDR_EL1 = 0xc800,
    AD_SYSREG_CLIDR_EL1 = 0xc801,
    AD_SYSREG_CNTFRQ_EL0 = 0xdf00,
    AD_SYSREG_CNTHCTL_EL2 = 0xe708,
    AD_SYSREG_CNTHPS_CTL_EL2 = 0xe729,
    AD_SYSREG_CNTHPS_CVAL_EL2 = 0xe72a,
    AD_SYSREG_CNTHPS_TVAL_EL2 = 0xe728,
    AD_SYSREG_CNTHP_CTL_EL2 = 0xe711,
    AD_SYSREG_CNTHP_CVAL_EL2 = 0xe712,
    AD_SYSREG_CNTHP_TVAL_EL2 = 0xe710,
    AD_SYSREG_CNTHVS_CTL_EL2 = 0xe721,
    AD_SYSREG_CNTHVS_CVAL_EL2 = 0xe722,
    AD_SYSREG_CNTHVS_TVAL_EL2 = 0xe720,
    AD_SYSREG_CNTHV_CTL_EL2 = 0xe719,
    AD_SYSREG_CNTHV_CVAL_EL2 = 0xe71a,
    AD_SYSREG_CNTHV_TVAL_EL2 = 0xe718,
    AD_SYSREG_CNTKCTL_EL1 = 0xc708,
    AD_SYSREG_CNTKCTL_EL12 = 0xc708,
    AD_SYSREG_CNTPCT_EL0 = 0xdf01,
    AD_SYSREG_CNTPS_CTL_EL1 = 0xff11,
    AD_SYSREG_CNTPS_CVAL_EL1 = 0xff12,
    AD_SYSREG_CNTPS_TVAL_EL1 = 0xff10,
    AD_SYSREG_CNTP_CTL_EL0 = 0xdf11,
    AD_SYSREG_CNTP_CTL_EL02 = 0xef11,
    AD_SYSREG_CNTP_CVAL_EL0 = 0xdf12,
    AD_SYSREG_CNTP_CVAL_EL02 = 0xef12,
    AD_SYSREG_CNTP_TVAL_EL0 = 0xdf10,
    AD_SYSREG_CNTP_TVAL_EL02 = 0xef10,
    AD_SYSREG_CNTVCT_EL0 = 0xdf02,
    AD_SYSREG_CNTVOFF_EL2 = 0xe703,
    AD_SYSREG_CNTV_CTL_EL0 = 0xdf19,
    AD_SYSREG_CNTV_CTL_EL02 = 0xef19,
    AD_SYSREG_CNTV_CVAL_EL0 = 0xdf1a,
    AD_SYSREG_CNTV_CVAL_EL02 = 0xef1a,
    AD_SYSREG_CNTV_TVAL_EL0 = 0xdf18,
    AD_SYSREG_CNTV_TVAL_EL02 = 0xef18,
    AD_SYSREG_CONTEXTIDR_EL1 = 0xc681,
    AD_SYSREG_CONTEXTIDR_EL12 = 0xee81,
    AD_SYSREG_CONTEXTIDR_EL2 = 0xe681,
    AD_SYSREG_CPACR_EL1 = 0xc082,
    AD_SYSREG_CPACR_EL12 = 0xe882,
    AD_SYSREG_CPTR_EL2 = 0xe08a,
    AD_SYSREG_CPTR_EL3 = 0xf08a,
    AD_SYSREG_CSSELR_EL1 = 0xd000,
    AD_SYSREG_CTR_EL0 = 0xd801,
    AD_SYSREG_CurrentEL = 0xc212,
    AD_SYSREG_DACR32_EL2 = 0xe180,
    AD_SYSREG_DAIF = 0xda11,
    AD_SYSREG_DBGAUTHSTATUS_EL1 = 0x83f6,
    AD_SYSREG_DBGCLAIMCLR_EL1 = 0x83ce,
    AD_SYSREG_DBGCLAIMSET_EL1 = 0x83c6,
    AD_SYSREG_DBGDTRRX_EL0 = 0x9828,
    AD_SYSREG_DBGDTRTX_EL0 = 0x9828,
    AD_SYSREG_DBGDTR_EL0 = 0x9820,
    AD_SYSREG_DBGPRCR_EL1 = 0x80a4,
    AD_SYSREG_DBGVCR32_EL2 = 0xa038,
    AD_SYSREG_DCZID_EL0 = 0xd807,
    AD_SYSREG_DISR_EL1 = 0xc609,
    AD_SYSREG_DIT = 0xda15,
    AD_SYSREG_DLR_EL0 = 0xda29,
    AD_SYSREG_DSPSR_EL0 = 0xda28,
    AD_SYSREG_ELR_EL1 = 0xc201,
    AD_SYSREG_ELR_EL12 = 0xea01,
    AD_SYSREG_ELR_EL2 = 0xe201,
    AD_SYSREG_ELR_EL3 = 0xf201,
    AD_SYSREG_ERRIDR_EL1 = 0xc298,
    AD_SYSREG_ERRSELR_EL1 = 0xc299,
    AD_SYSREG_ERXADDR_EL1 = 0xc2a3,
    AD_SYSREG_ERXCTLR_EL1 = 0xc2a1,
    AD_SYSREG_ERXFR_EL1 = 0xc2a0,
    AD_SYSREG_ERXMISC0_EL1 = 0xc2a8,
    AD_SYSREG_ERXMISC1_EL1 = 0xc2a9,
    AD_SYSREG_ERXMISC2_EL1 = 0xc2aa,
    AD_SYSREG_ERXMISC3_EL1 = 0xc2ab,
    AD_SYSREG_ERXPFGCDN_EL1 = 0xc2a6,
    AD_SYSREG_ERXPFGCTL_EL1 = 0xc2a5,
    AD_SYSREG_ERXPFGF_EL1 = 0xc2a4,
    AD_SYSREG_ERXSTATUS_EL1 = 0xc2a2,
    AD_SYSREG_ESR_EL1 = 0xc290,
    AD_SYSREG_ESR_EL12 = 0xea90,
    AD_SYSREG_ESR_EL2 = 0xe290,
    AD_SYSREG_ESR_EL3 = 0xf290,
    AD_SYSREG_FAR_EL1 = 0xc300,
    AD_SYSREG_FAR_EL12 = 0xeb00,
    AD_SYSREG_FAR_EL2 = 0xe300,
    AD_SYSREG_FAR_EL3 = 0xf300,
    AD_SYSREG_FPCR = 0xd184,
    AD_SYSREG_FPEXC32_EL2 = 0xe298,
    AD_SYSREG_FPSR = 0xd194,
    AD_SYSREG_GCR_EL1 = 0xc086,
    AD_SYSREG_GMID_EL1 = 0xcc0,
    AD_SYSREG_HACR_EL2 = 0xe08f,
    AD_SYSREG_HCR_EL2 = 0xe088,
    AD_SYSREG_HPFAR_EL2 = 0xe304,
    AD_SYSREG_HSTR_EL2 = 0xe08b,
    AD_SYSREG_ID_AA64AFR0_EL1 = 0xc02c,
    AD_SYSREG_ID_AA64AFR1_EL1 = 0xc02d,
    AD_SYSREG_ID_AA64DFR0_EL1 = 0xc028,
    AD_SYSREG_ID_AA64DFR1_EL1 = 0xc029,
    AD_SYSREG_ID_AA64ISAR0_EL1 = 0xc030,
    AD_SYSREG_ID_AA64ISAR1_EL1 = 0xc031,
    AD_SYSREG_ID_AA64MMFR0_EL1 = 0xc038,
    AD_SYSREG_ID_AA64MMFR1_EL1 = 0xc039,
    AD_SYSREG_ID_AA64MMFR2_EL1 = 0xc03a,
    AD_SYSREG_ID_AA64PFR0_EL1 = 0xc020,
    AD_SYSREG_ID_AA64PFR1_EL1 = 0xc021,
    AD_SYSREG_ID_AFR0_EL1 = 0xc00b,
    AD_SYSREG_ID_DFR0_EL1 = 0xc00a,
    AD_SYSREG_ID_ISAR0_EL1 = 0xc010,
    AD_SYSREG_ID_ISAR1_EL1 = 0xc011,
    AD_SYSREG_ID_ISAR2_EL1 = 0xc012,
    AD_SYSREG_ID_ISAR3_EL1 = 0xc013,
    AD_SYSREG_ID_ISAR4_EL1 = 0xc014,
    AD_SYSREG_ID_ISAR5_EL1 = 0xc015,
    AD_SYSREG_ID_ISAR6_EL1 = 0xc017,
    AD_SYSREG_ID_MMFR0_EL1 = 0xc00c,
    AD_SYSREG_ID_MMFR1_EL1 = 0xc00d,
    AD_SYSREG_ID_MMFR2_EL1 = 0xc00e,
    AD_SYSREG_ID_MMFR3_EL1 = 0xc00f,
    AD_SYSREG_ID_MMFR4_EL1 = 0xc016,
    AD_SYSREG_ID_PFR0_EL1 = 0xc008,
    AD_SYSREG_ID_PFR1_EL1 = 0xc009,
    AD_SYSREG_ID_PFR2_EL1 = 0xc01c,
    AD_SYSREG_IFSR32_EL2 = 0xe281,
    AD_SYSREG_ISR_EL1 = 0xc608,
    AD_SYSREG_LORC_EL1 = 0xc523,
    AD_SYSREG_LOREA_EL1 = 0xc521,
    AD_SYSREG_LORID_EL1 = 0xc527,
    AD_SYSREG_LORN_EL1 = 0xc522,
    AD_SYSREG_LORSA_EL1 = 0xc520,
    AD_SYSREG_MAIR_EL1 = 0xc510,
    AD_SYSREG_MAIR_EL12 = 0xed10,
    AD_SYSREG_MAIR_EL2 = 0xe510,
    AD_SYSREG_MAIR_EL3 = 0xf510,
    AD_SYSREG_MDCCINT_EL1 = 0x8010,
    AD_SYSREG_MDCCSR_EL0 = 0x9808,
    AD_SYSREG_MDCR_EL2 = 0xe089,
    AD_SYSREG_MDCR_EL3 = 0xf099,
    AD_SYSREG_MDRAR_EL1 = 0x8080,
    AD_SYSREG_MDSCR_EL1 = 0x8012,
    AD_SYSREG_MIDR_EL1 = 0xc000,
    AD_SYSREG_MPIDR_EL1 = 0xc005,
    AD_SYSREG_MVFR0_EL1 = 0xc018,
    AD_SYSREG_MVFR1_EL1 = 0xc019,
    AD_SYSREG_MVFR2_EL1 = 0xc01a,
    AD_SYSREG_NZCV = 0xda10,
    AD_SYSREG_OSDLR_EL1 = 0x809c,
    AD_SYSREG_OSDTRRX_EL1 = 0x8002,
    AD_SYSREG_OSDTRTX_EL1 = 0x801a,
    AD_SYSREG_OSECCR_EL1 = 0x8032,
    AD_SYSREG_OSLAR_EL1 = 0x8084,
    AD_SYSREG_OSLSR_EL1 = 0x808c,
    AD_SYSREG_PAN = 0xc213,
    AD_SYSREG_PAR_EL1 = 0xc3a0,
    AD_SYSREG_PMBIDR_EL1 = 0xc4d7,
    AD_SYSREG_PMBLIMITR_EL1 = 0xc4d0,
    AD_SYSREG_PMBPTR_EL1 = 0xc4d1,
    AD_SYSREG_PMBSR_EL1 = 0xc4d3,
    AD_SYSREG_PMCCFILTR_EL0 = 0xdf7f,
    AD_SYSREG_PMCCNTR_EL0 = 0xdce8,
    AD_SYSREG_PMCEID0_EL0 = 0xdce6,
    AD_SYSREG_PMCEID1_EL0 = 0xdce7,
    AD_SYSREG_PMCNTENCLR_EL0 = 0xdce2,
    AD_SYSREG_PMCNTENSET_EL0 = 0xdce1,
    AD_SYSREG_PMCR_EL0 = 0xdce0,
    AD_SYSREG_PMINTENCLR_EL1 = 0xc4f2,
    AD_SYSREG_PMINTENSET_EL1 = 0xc4f1,
    AD_SYSREG_PMMIR_EL1 = 0xc4f6,
    AD_SYSREG_PMOVSCLR_EL0 = 0xdce3,
    AD_SYSREG_PMOVSSET_EL0 = 0xdcf3,
    AD_SYSREG_PMSCR_EL1 = 0xc4c8,
    AD_SYSREG_PMSCR_EL12 = 0xecc8,
    AD_SYSREG_PMSCR_EL2 = 0xe4c8,
    AD_SYSREG_PMSELR_EL0 = 0xdce5,
    AD_SYSREG_PMSEVFR_EL1 = 0xc4cd,
    AD_SYSREG_PMSFCR_EL1 = 0xc4cc,
    AD_SYSREG_PMSICR_EL1 = 0xc4ca,
    AD_SYSREG_PMSIDR_EL1 = 0xc4cf,
    AD_SYSREG_PMSIRR_EL1 = 0xc4cb,
    AD_SYSREG_PMSLATFR_EL1 = 0xc4ce,
    AD_SYSREG_PMSWINC_EL0 = 0xdce4,
    AD_SYSREG_PMUSERENR_EL0 = 0xdcf0,
    AD_SYSREG_PMXEVCNTR_EL0 = 0xdcea,
    AD_SYSREG_PMXEVTYPER_EL0 = 0xdce9,
    AD_SYSREG_REVIDR_EL1 = 0xc006,
    AD_SYSREG_RGSR_EL1 = 0xc085,
    AD_SYSREG_RMR_EL1 = 0xc602,
    AD_SYSREG_RMR_EL2 = 0xe602,
    AD_SYSREG_RMR_EL3 = 0xf602,
    AD_SYSREG_RNDR = 0xd920,
    AD_SYSREG_RNDRRS = 0xd921,
    AD_SYSREG_RVBAR_EL1 = 0xc601,
    AD_SYSREG_RVBAR_EL2 = 0xe601,
    AD_SYSREG_RVBAR_EL3 = 0xf601,
    AD_SYSREG_SCR_EL3 = 0xf088,
    AD_SYSREG_SCTLR_EL1 = 0xc080,
    AD_SYSREG_SCTLR_EL12 = 0xe880,
    AD_SYSREG_SCTLR_EL2 = 0xe080,
    AD_SYSREG_SCTLR_EL3 = 0xf080,
    AD_SYSREG_SCXTNUM_EL0 = 0xde87,
    AD_SYSREG_SCXTNUM_EL1 = 0xc687,
    AD_SYSREG_SCXTNUM_EL12 = 0xee87,
    AD_SYSREG_SCXTNUM_EL2 = 0xe687,
    AD_SYSREG_SCXTNUM_EL3 = 0xf687,
    AD_SYSREG_SDER32_EL2 = 0xe099,
    AD_SYSREG_SDER32_EL3 = 0xf089,
    AD_SYSREG_SPSR_EL1 = 0xc200,
    AD_SYSREG_SPSR_EL12 = 0xea00,
    AD_SYSREG_SPSR_EL2 = 0xe200,
    AD_SYSREG_SPSR_EL3 = 0xf200,
    AD_SYSREG_SPSR_abt = 0xe219,
    AD_SYSREG_SPSR_fiq = 0xe21b,
    AD_SYSREG_SPSR_irq = 0xe218,
    AD_SYSREG_SPSR_und = 0xe21a,
    AD_SYSREG_SPSel = 0xc210,
    AD_SYSREG_SP_EL0 = 0xc208,
    AD_SYSREG_SP_EL1 = 0xe208,
    AD_SYSREG_SP_EL2 = 0xf208,
    AD_SYSREG_SSBS = 0xda16,
    AD_SYSREG_TCO = 0xda17,
    AD_SYSREG_TCR_EL1 = 0xc102,
    AD_SYSREG_TCR_EL12 = 0xe902,
    AD_SYSREG_TCR_EL2 = 0xe102,
    AD_SYSREG_TCR_EL3 = 0xf102,
    AD_SYSREG_TFSRE0_EL1 = 0xc2b1,
    AD_SYSREG_TFSR_EL1 = 0xc2b0,
    AD_SYSREG_TFSR_EL12 = 0xeab0,
    AD_SYSREG_TFSR_EL2 = 0xe2b0,
    AD_SYSREG_TFSR_EL3 = 0xf2b0,
    AD_SYSREG_TPIDRRO_EL0 = 0xde83,
    AD_SYSREG_TPIDR_EL0 = 0xde82,
    AD_SYSREG_TPIDR_EL1 = 0xc684,
    AD_SYSREG_TPIDR_EL2 = 0xe682,
    AD_SYSREG_TPIDR_EL3 = 0xf682,
    AD_SYSREG_TRFCR_EL1 = 0xc091,
    AD_SYSREG_TRFCR_EL12 = 0xe891,
    AD_SYSREG_TRFCR_EL2 = 0xe091,
    AD_SYSREG_TTBR0_EL1 = 0xc100,
    AD_SYSREG_TTBR0_EL12 = 0xe900,
    AD_SYSREG_TTBR0_EL2 = 0xe100,
    AD_SYSREG_TTBR0_EL3 = 0xf100,
    AD_SYSREG_TTBR1_EL1 = 0xc101,
    AD_SYSREG_TTBR1_EL12 = 0xe901,
    AD_SYSREG_TTBR1_EL2 = 0xe101,
    AD_SYSREG_UAO = 0xc214,
    AD_SYSREG_VBAR_EL1 = 0xc600,
    AD_SYSREG_VBAR_EL12 = 0xee00,
    AD_SYSREG_VBAR_EL2 = 0xe600,
    AD_SYSREG_VBAR_EL3 = 0xf600,
    AD_SYSREG_VDISR_EL2 = 0xe609,
    AD_SYSREG_VMPIDR_EL2 = 0xe005,
    AD_SYSREG_VNCR_EL2 = 0xe110,
    AD_SYSREG_VPIDR_EL2 = 0xe000,
    AD_SYSREG_VSESR_EL2 = 0xe293,
    AD_SYSREG_VSTCR_EL2 = 0xe132,
    AD_SYSREG_VSTTBR_EL2 = 0xe130,
    AD_SYSREG_VTCR_EL2 = 0xe10a,
    AD_SYSREG_VTTBR_EL2 = 0xe108,
    AD_SYSREG_AMEVCNTR00_EL0 = 0xdea0,
    AD_SYSREG_AMEVCNTR01_EL0 = 0xdea1,
    AD_SYSREG_AMEVCNTR02_EL0 = 0xdea2,
    AD_SYSREG_AMEVCNTR03_EL0 = 0xdea3,
    AD_SYSREG_AMEVCNTR04_EL0 = 0xdea4,
    AD_SYSREG_AMEVCNTR05_EL0 = 0xdea5,
    AD_SYSREG_AMEVCNTR06_EL0 = 0xdea6,
    AD_SYSREG_AMEVCNTR07_EL0 = 0xdea7,
    AD_SYSREG_AMEVCNTR08_EL0 = 0xdea8,
    AD_SYSREG_AMEVCNTR09_EL0 = 0xdea9,
    AD_SYSREG_AMEVCNTR010_EL0 = 0xdeaa,
    AD_SYSREG_AMEVCNTR011_EL0 = 0xdeab,
    AD_SYSREG_AMEVCNTR012_EL0 = 0xdeac,
    AD_SYSREG_AMEVCNTR013_EL0 = 0xdead,
    AD_SYSREG_AMEVCNTR014_EL0 = 0xdeae,
    AD_SYSREG_AMEVCNTR015_EL0 = 0xdeaf,
    AD_SYSREG_AMEVCNTR10_EL0 = 0xdee0,
    AD_SYSREG_AMEVCNTR11_EL0 = 0xdee1,
    AD_SYSREG_AMEVCNTR12_EL0 = 0xdee2,
    AD_SYSREG_AMEVCNTR13_EL0 = 0xdee3,
    AD_SYSREG_AMEVCNTR14_EL0 = 0xdee4,
    AD_SYSREG_AMEVCNTR15_EL0 = 0xdee5,
    AD_SYSREG_AMEVCNTR16_EL0 = 0xdee6,
    AD_SYSREG_AMEVCNTR17_EL0 = 0xdee7,
    AD_SYSREG_AMEVCNTR18_EL0 = 0xdee8,
    AD_SYSREG_AMEVCNTR19_EL0 = 0xdee9,
    AD_SYSREG_AMEVCNTR110_EL0 = 0xdeea,
    AD_SYSREG_AMEVCNTR111_EL0 = 0xdeeb,
    AD_SYSREG_AMEVCNTR112_EL0 = 0xdeec,
    AD_SYSREG_AMEVCNTR113_EL0 = 0xdeed,
    AD_SYSREG_AMEVCNTR114_EL0 = 0xdeee,
    AD_SYSREG_AMEVCNTR115_EL0 = 0xdeef,
    AD_SYSREG_AMEVTYPER00_EL0 = 0xdeb0,
    AD_SYSREG_AMEVTYPER01_EL0 = 0xdeb1,
    AD_SYSREG_AMEVTYPER02_EL0 = 0xdeb2,
    AD_SYSREG_AMEVTYPER03_EL0 = 0xdeb3,
    AD_SYSREG_AMEVTYPER04_EL0 = 0xdeb4,
    AD_SYSREG_AMEVTYPER05_EL0 = 0xdeb5,
    AD_SYSREG_AMEVTYPER06_EL0 = 0xdeb6,
    AD_SYSREG_AMEVTYPER07_EL0 = 0xdeb7,
    AD_SYSREG_AMEVTYPER08_EL0 = 0xdeb8,
    AD_SYSREG_AMEVTYPER09_EL0 = 0xdeb9,
    AD_SYSREG_AMEVTYPER010_EL0 = 0xdeba,
    AD_SYSREG_AMEVTYPER011_EL0 = 0xdebb,
    AD_SYSREG_AMEVTYPER012_EL0 = 0xdebc,
    AD_SYSREG_AMEVTYPER013_EL0 = 0xdebd,
    AD_SYSREG_AMEVTYPER014_EL0 = 0xdebe,
    AD_SYSREG_AMEVTYPER015_EL0 = 0xdebf,
    AD_SYSREG_AMEVTYPER10_EL0 = 0xdef0,
    AD_SYSREG_AMEVTYPER11_EL0 = 0xdef1,
    AD_SYSREG_AMEVTYPER12_EL0 = 0xdef2,
    AD_SYSREG_AMEVTYPER13_EL0 = 0xdef3,
    AD_SYSREG_AMEVTYPER14_EL0 = 0xdef4,
    AD_SYSREG_AMEVTYPER15_EL0 = 0xdef5,
    AD_SYSREG_AMEVTYPER16_EL0 = 0xdef6,
    AD_SYSREG_AMEVTYPER17_EL0 = 0xdef7,
    AD_SYSREG_AMEVTYPER18_EL0 = 0xdef8,
    AD_SYSREG_AMEVTYPER19_EL0 = 0xdef9,
    AD_SYSREG_AMEVTYPER110_EL0 = 0xdefa,
    AD_SYSREG_AMEVTYPER111_EL0 = 0xdefb,
    AD_SYSREG_AMEVTYPER112_EL0 = 0xdefc,
    AD_SYSREG_AMEVTYPER113_EL0 = 0xdefd,
    AD_SYSREG_AMEVTYPER114_EL0 = 0xdefe,
    AD_SYSREG_AMEVTYPER115_EL0 = 0xdeff,
    AD_SYSREG_DBGBCR0_EL1 = 0x8005,
    AD_SYSREG_DBGBCR1_EL1 = 0x800d,
    AD_SYSREG_DBGBCR2_EL1 = 0x8015,
    AD_SYSREG_DBGBCR3_EL1 = 0x801d,
    AD_SYSREG_DBGBCR4_EL1 = 0x8025,
    AD_SYSREG_DBGBCR5_EL1 = 0x802d,
    AD_SYSREG_DBGBCR6_EL1 = 0x8035,
    AD_SYSREG_DBGBCR7_EL1 = 0x803d,
    AD_SYSREG_DBGBCR8_EL1 = 0x8045,
    AD_SYSREG_DBGBCR9_EL1 = 0x804d,
    AD_SYSREG_DBGBCR10_EL1 = 0x8055,
    AD_SYSREG_DBGBCR11_EL1 = 0x805d,
    AD_SYSREG_DBGBCR12_EL1 = 0x8065,
    AD_SYSREG_DBGBCR13_EL1 = 0x806d,
    AD_SYSREG_DBGBCR14_EL1 = 0x8075,
    AD_SYSREG_DBGBCR15_EL1 = 0x807d,
    AD_SYSREG_DBGBVR0_EL1 = 0x8004,
    AD_SYSREG_DBGBVR1_EL1 = 0x800c,
    AD_SYSREG_DBGBVR2_EL1 = 0x8014,
    AD_SYSREG_DBGBVR3_EL1 = 0x801c,
    AD_SYSREG_DBGBVR4_EL1 = 0x8024,
    AD_SYSREG_DBGBVR5_EL1 = 0x802c,
    AD_SYSREG_DBGBVR6_EL1 = 0x8034,
    AD_SYSREG_DBGBVR7_EL1 = 0x803c,
    AD_SYSREG_DBGBVR8_EL1 = 0x8044,
    AD_SYSREG_DBGBVR9_EL1 = 0x804c,
    AD_SYSREG_DBGBVR10_EL1 = 0x8054,
    AD_SYSREG_DBGBVR11_EL1 = 0x805c,
    AD_SYSREG_DBGBVR12_EL1 = 0x8064,
    AD_SYSREG_DBGBVR13_EL1 = 0x806c,
    AD_SYSREG_DBGBVR14_EL1 = 0x8074,
    AD_SYSREG_DBGBVR15_EL1 = 0x807c,
    AD_SYSREG_DBGWCR0_EL1 = 0x8007,
    AD_SYSREG_DBGWCR1_EL1 = 0x800f,
    AD_SYSREG_DBGWCR2_EL1 = 0x8017,
    AD_SYSREG_DBGWCR3_EL1 = 0x801f,
    AD_SYSREG_DBGWCR4_EL1 = 0x8027,
    AD_SYSREG_DBGWCR5_EL1 = 0x802f,
    AD_SYSREG_DBGWCR6_EL1 = 0x8037,
    AD_SYSREG_DBGWCR7_EL1 = 0x803f,
    AD_SYSREG_DBGWCR8_EL1 = 0x8047,
    AD_SYSREG_DBGWCR9_EL1 = 0x804f,
    AD_SYSREG_DBGWCR10_EL1 = 0x8057,
    AD_SYSREG_DBGWCR11_EL1 = 0x805f,
    AD_SYSREG_DBGWCR12_EL1 = 0x8067,
    AD_SYSREG_DBGWCR13_EL1 = 0x806f,
    AD_SYSREG_DBGWCR14_EL1 = 0x8077,
    AD_SYSREG_DBGWCR15_EL1 = 0x807f,
    AD_SYSREG_DBGWVR0_EL1 = 0x8006,
    AD_SYSREG_DBGWVR1_EL1 = 0x800e,
    AD_SYSREG_DBGWVR2_EL1 = 0x8016,
    AD_SYSREG_DBGWVR3_EL1 = 0x801e,
    AD_SYSREG_DBGWVR4_EL1 = 0x8026,
    AD_SYSREG_DBGWVR5_EL1 = 0x802e,
    AD_SYSREG_DBGWVR6_EL1 = 0x8036,
    AD_SYSREG_DBGWVR7_EL1 = 0x803e,
    AD_SYSREG_DBGWVR8_EL1 = 0x8046,
    AD_SYSREG_DBGWVR9_EL1 = 0x804e,
    AD_SYSREG_DBGWVR10_EL1 = 0x8056,
    AD_SYSREG_DBGWVR11_EL1 = 0x805e,
    AD_SYSREG_DBGWVR12_EL1 = 0x8066,
    AD_SYSREG_DBGWVR13_EL1 = 0x806e,
    AD_SYSREG_DBGWVR14_EL1 = 0x8076,
    AD_SYSREG_DBGWVR15_EL1 = 0x807e,
    AD_SYSREG_PMEVCNTR0_EL0 = 0xdf40,
    AD_SYSREG_PMEVCNTR1_EL0 = 0xdf41,
    AD_SYSREG_PMEVCNTR2_EL0 = 0xdf42,
    AD_SYSREG_PMEVCNTR3_EL0 = 0xdf43,
    AD_SYSREG_PMEVCNTR4_EL0 = 0xdf44,
    AD_SYSREG_PMEVCNTR5_EL0 = 0xdf45,
    AD_SYSREG_PMEVCNTR6_EL0 = 0xdf46,
    AD_SYSREG_PMEVCNTR7_EL0 = 0xdf47,
    AD_SYSREG_PMEVCNTR8_EL0 = 0xdf48,
    AD_SYSREG_PMEVCNTR9_EL0 = 0xdf49,
    AD_SYSREG_PMEVCNTR10_EL0 = 0xdf4a,
    AD_SYSREG_PMEVCNTR11_EL0 = 0xdf4b,
    AD_SYSREG_PMEVCNTR12_EL0 = 0xdf4c,
    AD_SYSREG_PMEVCNTR13_EL0 = 0xdf4d,
    AD_SYSREG_PMEVCNTR14_EL0 = 0xdf4e,
    AD_SYSREG_PMEVCNTR15_EL0 = 0xdf4f,
    AD_SYSREG_PMEVCNTR16_EL0 = 0xdf50,
    AD_SYSREG_PMEVCNTR17_EL0 = 0xdf51,
    AD_SYSREG_PMEVCNTR18_EL0 = 0xdf52,
    AD_SYSREG_PMEVCNTR19_EL0 = 0xdf53,
    AD_SYSREG_PMEVCNTR20_EL0 = 0xdf54,
    AD_SYSREG_PMEVCNTR21_EL0 = 0xdf55,
    AD_SYSREG_PMEVCNTR22_EL0 = 0xdf56,
    AD_SYSREG_PMEVCNTR23_EL0 = 0xdf57,
    AD_SYSREG_PMEVCNTR24_EL0 = 0xdf58,
    AD_SYSREG_PMEVCNTR25_EL0 = 0xdf59,
    AD_SYSREG_PMEVCNTR26_EL0 = 0xdf5a,
    AD_SYSREG_PMEVCNTR27_EL0 = 0xdf5b,
    AD_SYSREG_PMEVCNTR28_EL0 = 0xdf5c,
    AD_SYSREG_PMEVCNTR29_EL0 = 0xdf5d,
    AD_SYSREG_PMEVCNTR30_EL0 = 0xdf5e,
    AD_SYSREG_PMEVCNTR31_EL0 = 0xdf5f,
    AD_SYSREG_PMEVTYPER0_EL0 = 0xdf60,
    AD_SYSREG_PMEVTYPER1_EL0 = 0xdf61,
    AD_SYSREG_PMEVTYPER2_EL0 = 0xdf62,
    AD_SYSREG_PMEVTYPER3_EL0 = 0xdf63,
    AD_SYSREG_PMEVTYPER4_EL0 = 0xdf64,
    AD_SYSREG_PMEVTYPER5_EL0 = 0xdf65,
    AD_SYSREG_PMEVTYPER6_EL0 = 0xdf66,
    AD_SYSREG_PMEVTYPER7_EL0 = 0xdf67,
    AD_SYSREG_PMEVTYPER8_EL0 = 0xdf68,
    AD_SYSREG_PMEVTYPER9_EL0 = 0xdf69,
    AD_SYSREG_PMEVTYPER10_EL0 = 0xdf6a,
    AD_SYSREG_PMEVTYPER11_EL0 = 0xdf6b,
    AD_SYSREG_PMEVTYPER12_EL0 = 0xdf6c,
    AD_SYSREG_PMEVTYPER13_EL0 = 0xdf6d,
    AD_SYSREG_PMEVTYPER14_EL0 = 0xdf6e,
    AD_SYSREG_PMEVTYPER15_EL0 = 0xdf6f,
    AD_SYSREG_PMEVTYPER16_EL0 = 0xdf70,
    AD_SYSREG_PMEVTYPER17_EL0 = 0xdf71,
    AD_SYSREG_PMEVTYPER18_EL0 = 0xdf72,
    AD_SYSREG_PMEVTYPER19_EL0 = 0xdf73,
    AD_SYSREG_PMEVTYPER20_EL0 = 0xdf74,
    AD_SYSREG_PMEVTYPER21_EL0 = 0xdf75,
    AD_SYSREG_PMEVTYPER22_EL0 = 0xdf76,
    AD_SYSREG_PMEVTYPER23_EL0 = 0xdf77,
    AD_SYSREG_PMEVTYPER24_EL0 = 0xdf78,
    AD_SYSREG_PMEVTYPER25_EL0 = 0xdf79,
    AD_SYSREG_PMEVTYPER26_EL0 = 0xdf7a,
    AD_SYSREG_PMEVTYPER27_EL0 = 0xdf7b,
    AD_SYSREG_PMEVTYPER28_EL0 = 0xdf7c,
    AD_SYSREG_PMEVTYPER29_EL0 = 0xdf7d,
    AD_SYSREG_PMEVTYPER30_EL0 = 0xdf7e,
    AD_SYSREG_PMEVTYPER31_EL0 = 0xdf7f,
};

#endif
