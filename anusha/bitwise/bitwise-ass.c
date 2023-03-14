

//swap first byte to last byte*/
#include<stdio.h>
main()
{
unsigned int x=0xeeffffff;
x=(x&(~((0xff<<24)|(0xff<<0))))|((x&(0xff<<0))<<(24-0))|((x&(0xff<<24))>>(24-0));
printf("%x\n",x);
}



/*swap first byte to third byte*/
/*#include<stdio.h>
main()
{
unsigned int x=0x11223344;
unsigned int clr,sft1,sft2;
clr=(x&(~((0xff<<16)|(0xff<<0))));
printf("%x\n",clr);
sft1=((x&(0xff<<0))<<(16-0));
printf("%x\n",sft1);
sft2=((x&(0xff<<16))>>(16-0));
printf("%x\n",sft2);
x=(clr|sft1|sft2);
printf("%x\n",x);
}*/


/*swap first nibble to last nibble*/
/*#include<stdio.h>
main()
{
unsigned int x=0x12345678;
unsigned int clear,sft1,sft2;
clear=(x&(~((0xf<<28)|(0xf<<0))));
printf("%x\n",clear);
sft1=((x&(0xf<<0))<<(28-0));
printf("%x\n",sft1);
sft2=((x&(0xf<<28))>>(28-0));
printf("%x\n",sft2);
x=(clear|sft1|sft2);
printf("%x\n",x);
}*/


/*#include<stdio.h>
main()
{
unsigned int x;
unsigned int bit1,bit2,temp;
printf("enter the input:");
scanf("%x",&x);
printf("enter the bits to be swapped bit1:bit2(0-31):");
scanf("%d%d",&bit1,&bit2);
((bit1>=0)&&(bit1<=31))?0:(printf("invalid inputs\n"),exit(0));
((bit2>=0)&&(bit2<=31))?0:(printf("invalid inputs\n"),exit(0));
(bit1>bit2)?(temp=bit1,bit1=bit2,bit2=temp):0;
x=(x&(~((0xf<<bit2)|(0xf<<bit1))))|((x&(0xf<<bit1))<<(bit2-bit1))|((x&(0xf<<bit2))>>(bit2-bit1));
printf("%x\n",x);
}*/




