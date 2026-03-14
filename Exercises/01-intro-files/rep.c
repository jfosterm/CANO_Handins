#include <stdio.h>

void displaychar(char c)
{
    printf("0x%hhX =\t'%hhu'unsigned =\t'%hhd'signed =\t'%c'char (8 bits)\n", c, c, c, c);
}

void displayshort(short c)
{
    printf("0x%hX =\t'%hu'unsigned =\t'%hd'signed =\t'%c'char (8 bits)\n", c, c, c, c);
}

int main(void)
{
    unsigned char c1 = -0x02; // 0x means we are using a hexadecimal number
    unsigned char c2 = 0x80;
    unsigned char sum = c1 + c2;
    unsigned short us1 = c1;
    signed short ss1 = (signed char)c1;
    displaychar(c1);
    displayshort(ss1);
    printf("\n");
    // Display for task 15
    displaychar(c1);
    displayshort(us1);
    // Printing characters
    displaychar(c1);
    printf("\t\t+\n"); 
    displaychar(c2);
    printf("\t\t=\n");   
    displaychar(sum);
    printf("\n\n\tConverting Hex to binary table:\n\n\
            *****************************\n\
            ** H E X ****  B I N A R Y **\n\
            **-------****--------------**\n\
            **   0   ****     0000     **\n\
            **   1   ****     0001     **\n\
            **   2   ****     0010     **\n\
            **   3   ****     0011     **\n\
            **   4   ****     0100     **\n\
            **   5   ****     0101     **\n\
            **   6   ****     0110     **\n\
            **   7   ****     0111     **\n\
            **   8   ****     1000     **\n\
            **   9   ****     1001     **\n\
            **  10   ****     1010     **\n\
            **  11   ****     1011     **\n\
            **  12   ****     1100     **\n\
            **  13   ****     1101     **\n\
            **  14   ****     1110     **\n\
            **  15   ****     1111     **\n\
            *****************************\n");
}
