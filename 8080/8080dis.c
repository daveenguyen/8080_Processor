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
    printf("%04x "); // This prints the address
    printf("0x%02x: ", code[0]);
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
            opbytes = 2;
            break;
        case 0x07:
            printf("RLC");
            break;

        case 0x09:
            printf("DAD     B");
            break;
        case 0x0a:
            printf("LDAX    B");
            break;
        case 0x0b:
            printf("DCX     B");
            break;
        case 0x0c:
            printf("INR     C");
            break;
        case 0x0d:
            printf("DCR     C");
            break;
        case 0x0e:
            printf("MVI     C, #0x%02x", code[1]);
            opbytes = 2;
            break;
        case 0x0f:
            printf("RRC");
            break;

        case 0x11:
            printf("LXI     D, #$%02x%02x", code[2], code[1]);
            opbytes = 3;
            break;
        case 0x12:
            printf("STAX    D");
            break;
        case 0x13:
            printf("INX     D");
            break;
        case 0x14:
            printf("INR     D");
            break;
        case 0x15:
            printf("DCR     D");
            break;
        case 0x16:
            printf("MVI     D, #0x%02x", code[1]);
            opbytes = 2;
            break;
        case 0x17:
            printf("RAL");
            break;

        case 0x19:
            printf("DAD     D");
            break;
        case 0x1a:
            printf("LDAX    D");
            break;
        case 0x1b:
            printf("DCX     D");
            break;
        case 0x1c:
            printf("INR     E");
            break;
        case 0x1d:
            printf("DCR     E");
            break;
        case 0x1e:
            printf("MVI     E, #0x%02x", code[1]);
            opbytes = 2;
            break;
        case 0x1f:
            printf("RAR");
            break;
        case 0x20:
            printf("RIM");
            break;
        case 0x21:
            printf("LXI     H, #$%02x%02x", code[2], code[1]);
            opbytes = 3;
            break;
        case 0x22: // -- TODO --
            printf("SHLD    ($%02x%02x)", code[2], code[1]);
            opbytes = 3;
            break;
        case 0x23:
            printf("INX     H");
            break;
        case 0x24:
            printf("INR     H");
            break;
        case 0x25:
            printf("DCR     H");
            break;
        case 0x26:
            printf("MVI     H, #0x%02x", code[1]);
            opbytes = 2;
            break;
        case 0x27:
            printf("DAA");
            break;

        case 0x29:
            printf("DAD     H");
            break;
        case 0x2a: // -- TODO --
            printf("LHLD    ($%02x%02x)", code[2], code[1]);
            opbytes = 3;
            break;
        case 0x2b:
            printf("DCX     H");
            break;
        case 0x2c:
            printf("INR     L");
            break;
        case 0x2d:
            printf("DCR     L");
            break;
        case 0x2e:
            printf("MVI     L, #0x%02x", code[1]);
            opbytes = 2;
            break;
        case 0x2f:
            printf("CMA");
            break;
        case 0x30:
            printf("SIM");
            break;
        case 0x31:
            printf("LXI     SP, #$%02x%02x", code[2], code[1]);
            opbytes = 3;
            break;
        case 0x32: // -- TODO --
            printf("STA     ($%02x%02x)", code[2], code[1]);
            opbytes = 3;
            break;
        case 0x33:
            printf("INX     SP");
            break;
        case 0x34:
            printf("INR     M");
            break;
        case 0x35:
            printf("DCR     M");
            break;
        case 0x36:
            printf("MVI     M, #0x%02x", code[1]);
            opbytes = 2;
            break;
        case 0x37:
            printf("STC");
            break;

        case 0x39:
            printf("DAD     SP");
            break;
        case 0x3a: // -- TODO --
            printf("LDA     ($%02x%02x)", code[2], code[1]);
            opbytes = 3;
            break;
        case 0x3b:
            printf("DCX     SP");
            break;
        case 0x3c:
            printf("INR     A");
            break;
        case 0x3d:
            printf("DCR     A");
            break;
        case 0x3e:
            printf("MVI     A, #0x%02x", code[1]);
            opbytes = 2;
            break;
        case 0x3f:
            printf("CMC");
            break;
        case 0x40:
            printf("MOV     B, B");
            break;
        case 0x41:
            printf("MOV     B, C");
            break;
        case 0x42:
            printf("MOV     B, D");
            break;
        case 0x43:
            printf("MOV     B, E");
            break;
        case 0x44:
            printf("MOV     B, H");
            break;
        case 0x45:
            printf("MOV     B, L");
            break;
        case 0x46:
            printf("MOV     B, M");
            break;
        case 0x47:
            printf("MOV     B, A");
            break;
        case 0x48:
            printf("MOV     C, B");
            break;
        case 0x49:
            printf("MOV     C, C");
            break;
        case 0x4a:
            printf("MOV     C, D");
            break;
        case 0x4b:
            printf("MOV     C, E");
            break;
        case 0x4c:
            printf("MOV     C, H");
            break;
        case 0x4d:
            printf("MOV     C, L");
            break;
        case 0x4e:
            printf("MOV     C, M");
            break;
        case 0x4f:
            printf("MOV     C, A");
            break;
        case 0x50:
            printf("MOV     D, B");
            break;
        case 0x51:
            printf("MOV     D, C");
            break;
        case 0x52:
            printf("MOV     D, D");
            break;
        case 0x53:
            printf("MOV     D, E");
            break;
        case 0x54:
            printf("MOV     D, H");
            break;
        case 0x55:
            printf("MOV     D, L");
            break;
        case 0x56:
            printf("MOV     D, M");
            break;
        case 0x57:
            printf("MOV     D, A");
            break;
        case 0x58:
            printf("MOV     E, B");
            break;
        case 0x59:
            printf("MOV     E, C");
            break;
        case 0x5a:
            printf("MOV     E, D");
            break;
        case 0x5b:
            printf("MOV     E, E");
            break;
        case 0x5c:
            printf("MOV     E, H");
            break;
        case 0x5d:
            printf("MOV     E, L");
            break;
        case 0x5e:
            printf("MOV     E, M");
            break;
        case 0x5f:
            printf("MOV     E, A");
            break;
        case 0x60:
            printf("MOV     H, B");
            break;
        case 0x61:
            printf("MOV     H, C");
            break;
        case 0x62:
            printf("MOV     H, D");
            break;
        case 0x63:
            printf("MOV     H, E");
            break;
        case 0x64:
            printf("MOV     H, H");
            break;
        case 0x65:
            printf("MOV     H, L");
            break;
        case 0x66:
            printf("MOV     H, M");
            break;
        case 0x67:
            printf("MOV     H, A");
            break;
        case 0x68:
            printf("MOV     L, B");
            break;
        case 0x69:
            printf("MOV     L, C");
            break;
        case 0x6a:
            printf("MOV     L, D");
            break;
        case 0x6b:
            printf("MOV     L, E");
            break;
        case 0x6c:
            printf("MOV     L, H");
            break;
        case 0x6d:
            printf("MOV     L, L");
            break;
        case 0x6e:
            printf("MOV     L, M");
            break;
        case 0x6f:
            printf("MOV     L, A");
            break;
        case 0x70:
            printf("MOV     M, B");
            break;
        case 0x71:
            printf("MOV     M, C");
            break;
        case 0x72:
            printf("MOV     M, D");
            break;
        case 0x73:
            printf("MOV     M, E");
            break;
        case 0x74:
            printf("MOV     M, H");
            break;
        case 0x75:
            printf("MOV     M, L");
            break;
        case 0x76:
            printf("HLT");
            break;
        case 0x77:
            printf("MOV     M, A");
            break;
        case 0x78:
            printf("MOV     A, B");
            break;
        case 0x79:
            printf("MOV     A, C");
            break;
        case 0x7a:
            printf("MOV     A, D");
            break;
        case 0x7b:
            printf("MOV     A, E");
            break;
        case 0x7c:
            printf("MOV     A, H");
            break;
        case 0x7d:
            printf("MOV     A, L");
            break;
        case 0x7e:
            printf("MOV     A, M");
            break;
        case 0x7f:
            printf("MOV     A, A");
            break;
        /* ........ */
        case 0xc3:
            printf("JMP     $%02x%02x",code[2],code[1]);
            opbytes = 3;
            break;
        /* ........ */
        default:
            printf("Unsupported Opcode!");
            break;
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