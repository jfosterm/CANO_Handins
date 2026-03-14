#include <stdio.h>
// The main function will be executed when we run the program
int main(void)
{
// Declaring the variables
char c = 1;
short s = 1;
int i = 1;
long l = 1;
long long ll = 1;
// Declaring the pointers to the variables:
char *cptr = &c;
short *sptr = &s;
int *iptr = &i;
long *lptr = &l;
long long *llptr = &ll;
// Char type
printf("Size of a char type is %zu byte or %zu bits.\n", sizeof(c), sizeof(c)*8);
printf("Size of a char type pointer value is %p.\n", cptr);
printf("Size of a char pointer type size is %zu byte or %zu bits.\n\n", sizeof(cptr), sizeof(cptr)*8);
// Short type
printf("Size of a short type is %zu byte or %zu bits.\n", sizeof(s), sizeof(s)*8);
printf("Size of a short type pointer value address is %p \n", sptr);
printf("Size of a short pointer type is %zu byte or %zu bits.\n\n", sizeof(sptr), sizeof(sptr)*8);
// Long type
printf("Size of a long type is minimum %zu byte or %zu bits.\n", sizeof(l), sizeof(l)*8);
printf("Size of a long pointer type value is minimum %p bits.\n", lptr);
printf("Size of a long pointer type is minimum %zu byte or %zu bits.\n\n", sizeof(lptr), sizeof(lptr)*8);
// Long long type
printf("Size of a long long type is %zu byte or %zu bits.\n", sizeof(ll), sizeof(ll)*8);
printf("Size of a long long pointer type value is %p.\n", llptr);
printf("Size of a long long type pointer is %zu byte or %zu bits.\n\n", sizeof(llptr), sizeof(llptr)*8);
// Int type
printf("Size of a int type is %zu byte or %zu bits.\n", sizeof(i), sizeof(i)*8);
printf("Size of a int type is %p \n", iptr);
printf("Size of a int type is %zu byte or %zu bits.\n\n", sizeof(iptr), sizeof(iptr)*8);

// Task 3, manipulate via pointers
printf("Before manipulation: integer value = %d\n", i);
*iptr= *iptr+1;
printf("after manipulation: integer value = %d\n", i);

}
