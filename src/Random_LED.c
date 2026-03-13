#include <stdio.h> 
#include <stdlib.h>

#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))//Bit specific addressing use just for data  register. 0x3fc access to all 8bits
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))//Search for GPIODIR
#define GPIO_PORTF_PUR_R (*((volatile unsigned long*)0x40025510))//Search for GPIOPUR
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0x4002551C))//Search for GPIODEN	   //32 bit address in hex 
#define SYSCTL_RCGC2_R (*((volatile unsigned long*)0x400FE108))//Search for RCGC2  //variable name references that 32 bit address

#define GPIO_PORTF_LOCK_R (*((volatile unsigned long *)0x40025520))	//Initialize SW2 
#define GPIO_PORTF_CR_R (*((volatile unsigned long *)0x40025524))

unsigned long Input; // Input from PF4 (SW#1)
int temp; 

int randInt(int dX){
	  return rand() % dX + 1;
}

int main(void){
SYSCTL_RCGC2_R = 0x00000020; // Activate clock for Port F	-> Register 5
GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock portF
GPIO_PORTF_CR_R = 0x03;	//Allow changes to PF1 (SW1) and PF0 (SW2)
	
GPIO_PORTF_DIR_R = 0x0E; // Enable PF4 (SW1) PF0 (SW2) as input, PF3, PF2, PF1 as outputs 
GPIO_PORTF_PUR_R = 0x11; // Enable pull-up on SW1 and SW2 
GPIO_PORTF_DEN_R = 0x1F; // Enable digital I/O  

	
while(1){
	Input = GPIO_PORTF_DATA_R & 0x11; // Read SW1 & SW2 into Input 

	if((Input & 0x11) == 0)	
		GPIO_PORTF_DATA_R = 0x00;  //turn off
	else if((Input & 0x10) == 0){			// SW1 pressed, ROLL d4
		temp = randInt(4);  													 
		if(temp == 1) GPIO_PORTF_DATA_R = 0x02;        //turn RED 
		else if (temp == 2) GPIO_PORTF_DATA_R = 0x04;  //turn BLUE
		else if (temp == 3) GPIO_PORTF_DATA_R = 0x06;  //turn MAGENTA
		else if (temp == 4) GPIO_PORTF_DATA_R = 0x08;  //turn GREEN
		while((GPIO_PORTF_DATA_R & 0x10) == 0); }		  
	else if ((Input & 0x01) == 0) {                // SW2 pressed, ROLL d6
		temp = randInt(6);
		if(temp == 1) GPIO_PORTF_DATA_R = 0x02;        //turn RED 
		else if (temp == 2) GPIO_PORTF_DATA_R = 0x04;  //turn BLUE
		else if (temp == 3) GPIO_PORTF_DATA_R = 0x06;  //turn MAGENTA
		else if (temp == 4) GPIO_PORTF_DATA_R = 0x08;  //turn GREEN
		else if (temp == 5) GPIO_PORTF_DATA_R = 0x0A;  //turn YELLOW
		else if (temp == 6) GPIO_PORTF_DATA_R = 0x0C;  //turn CYAN
		while((GPIO_PORTF_DATA_R & 0x01) == 0);   }					
	else GPIO_PORTF_DATA_R = 0x00;  //turn off
} // end while
}
