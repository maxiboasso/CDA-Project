#include "spimcore.h"


/* ALU */
/* 10 Points */
void ALU(unsigned A,unsigned B,char ALUControl,unsigned *ALUresult,char *Zero)
{

}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
    if (PC % 4 != 0){ // word alignment check
        return 1; //halt
    }

    *instruction = Mem[PC >> 2]; // mem not an array of words but bytes

    return 0;

}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    // bits 31-26
    *op = (instruction >> 26) & 0x3F; 

    // bits 25-21
    *r1 = (instruction >> 21) & 0x1F;  

    // bits 20-16
    *r2 = (instruction >> 16) & 0x1F; 

    // bits 15-11
    *r3 = (instruction >> 11) & 0x1F;  

    // bits 5-0
    *funct = instruction & 0x3F;  

    // bits 15-0
    *offset = instruction & 0xFFFF;  

    // jump address, regardless of instruction type (bits 25-0)
    *jsec = instruction & 0x03FFFFFF;  
}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{

}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    if (offset & 0x8000) {  // if negative

        *extended_value = offset | 0xFFFF0000;  // fill with 1s
    } else {

        *extended_value = offset;  // fill with 0s
    }
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}

