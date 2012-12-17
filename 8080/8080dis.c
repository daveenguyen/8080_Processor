#include <stdio.h>
#include <stdlib.h>

/**
 *  @param *codebuffer is a valid pointer to 8080 assembly code
 *  @param pc is the current offset into the code
 *
 *  @return the number of bytes of the op
 */
 

int Disassemble8080Op(unsigned char *codebuffer, int pc)
{
    // '&' says pointer (*code) is set to the address of codebuffer[pc]
    unsigned char *code = &codebuffer[pc];
    unsigned char opbytes = 1;
    printf ("%04x ", code[0]);
    switch (*code)
    {
        case 0x00:
            printf("NOP");
            break;
        case 0x01:
            printf("LXI     B, #$%02x%02x", code[2], code[1]);
            opbytes = 3;
            break;
        case 0x02:
            printf("STAX    B");
            break;
        case 0x03:
            printf("INX     B");
            break;
        case 0x04:
            printf("INR     B");
            break;
        case 0x05:
            printf("DCR     B");
            break;
        case 0x06:
            printf("MVI     B, #$%02x", code[1]);
            opbytes=2;
            break;
        case 0x07:
            printf("RLC");
            break;
        case 0x08:
            printf("NOP");
            break;
        case 0x09:
            printf("");
        /* ........ */
        case 0x3e:
            printf("MVI     A, #0x%02x", code[1]);
            opbytes=2;
            break;
        /* ........ */
        case 0xc3:
            printf("JMP     $%02x%02x",code[2],code[1]);
            opbytes=3;
            break;
        /* ........ */
    }

    printf("\n");

    return opbytes;
}

int main (int argc, char**argv)
{
    FILE *f = fopen(argv[1], "rb");
    if (f==NULL)
    {
        printf("error: Couldn't open %s\n", argv[1]);
        exit(1);
    }

    // Get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    unsigned char *buffer=malloc(fsize);

    fread(buffer, fsize, 1, f);
    fclose(f);

    int pc = 0;

    while (pc < fsize)
    {
        pc += Disassemble8080Op(buffer, pc);
    }
    return 0;
}