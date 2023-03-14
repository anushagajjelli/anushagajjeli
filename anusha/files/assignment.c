/*#include<stdio.h>
main()
{
unsigned int x=0x12345678;
printf("first byte %x\n",(x&0xff));
printf("second byte %x\n",((x>>8)&0xff));
printf("third byte %x\n",((x>>16)&0xff));
printf("fourth byte %x\n",((x>>24)&0xff));
}*/



/*wap to extract byte by byte from 4bytes*/
/*#include<stdio.h>
main()
{
unsigned int x=0x12345678;
unsigned char y;
y=x;
printf("%x\n",y);
y=x>>8;
printf("%x\n",y);
y=x>>16;
printf("%x\n",y);
y=x>>24;
printf("%x\n",y);
}*/


/*wap to extract 2bytes from 4bytes*/

/*#include<stdio.h>
main()
{
unsigned int x=0x12345678;
unsigned short int y;
y=x;
printf("%x\n",y);
y=x>>16;
printf("%x\n",y);
}*/

/*wap to extract 4bytes from 8bytes*/
#include<stdio.h>
main()
{
unsigned long int x=0x1122334455667788;
unsigned int y;
y=x;
printf("%x\n",y);
y=x>>32;
printf("%x\n",y);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
