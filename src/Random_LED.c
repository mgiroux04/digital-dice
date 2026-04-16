#include <stdio.h> 
#include <stdlib.h>

#define GPIO_PORTF_DATA_R (*((volatile unsigned long*)0x400253FC))//Bit specific addressing use just for data  register. 0x3fc access to all 8bits
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))//Search for GPIODIR
#define GPIO_PORTF_PUR_R (*((volatile unsigned long*)0x40025510))//Search for GPIOPUR
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0x4002551C))//Search for GPIODEN	   //32 bit address in hex 
#define SYSCTL_RCGC2_R (*((volatile unsigned long*)0x400FE108))//Search for RCGC2  //variable name references that 32 bit address
	
#define GPIO_PORTF_LOCK_R (*((volatile unsigned long *)0x40025520))	//Initialize SW2 
#define GPIO_PORTF_CR_R (*((volatile unsigned long *)0x40025524))

unsigned long Input; // Input from SW
int temp; 

int randInt(int dX);
void LED_output(int numberRolled);

int main(void){
SYSCTL_RCGC2_R |= 0x20; // Activate clock for Port F	-> Register 5
GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock portF
GPIO_PORTF_CR_R |= 0x03;	//Allow changes to PF1 (SW1) and PF0 (SW2)

GPIO_PORTF_DIR_R |= 0x0E; // Enable PF4 (SW1) as input, PF3, PF2, PF1 as outputs 
GPIO_PORTF_PUR_R |= 0x11; // Enable pull-up (inputs) PF4 (SW1): 0x10 			//PF4 (SW1) & PF0 (SW2) = 0x11
GPIO_PORTF_DEN_R |= 0x1F; // Enable digital I/O. All avalible colors: (SW1 & SW2): 0x1F
	
	
while(1){
	Input = GPIO_PORTF_DATA_R & 0x11; // Read SW1 & SW2 into Input 

	if((Input & 0x11) == 0)	
		GPIO_PORTF_DATA_R = 0x00;       //turn off
	else if((Input & 0x10) == 0){			// SW1 pressed, ROLL d4
		temp = randInt(4);  													 		
		LED_output(temp);
		while((GPIO_PORTF_DATA_R & 0x10) == 0);}		   //wait for SW1 to release 	
	else if ((Input & 0x01) == 0) {                  // SW2 pressed, ROLL d6
		temp = randInt(6);
		LED_output(temp);
		while((GPIO_PORTF_DATA_R & 0x01) == 0);   }		 //wait for SW2 to release	
	else GPIO_PORTF_DATA_R = 0x00;  //turn off
 } // end while
}

int randInt(int dX){
	  return rand() % dX + 1;
}
				
void LED_output(int numberRolled){
	if(numberRolled == 1) GPIO_PORTF_DATA_R = 0x02;        //turn RED 
	else if (numberRolled == 2) GPIO_PORTF_DATA_R = 0x04;  //turn BLUE
	else if (numberRolled == 3) GPIO_PORTF_DATA_R = 0x06;  //turn MAGENTA
	else if (numberRolled == 4) GPIO_PORTF_DATA_R = 0x08;  //turn GREEN
	else if (numberRolled == 5) GPIO_PORTF_DATA_R = 0x0A;  //turn YELLOW
	else if (numberRolled == 6) GPIO_PORTF_DATA_R = 0x0C;  //turn CYAN
}	

