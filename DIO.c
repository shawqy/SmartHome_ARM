#include "DIO.h"


// Toggle Function 


void DIO_FlipPort (Port port_index, uint8 pins_mask) {
    switch (port_index) {
        // Port A
        case 0 : GPIO_PORTA_DATA_R = GPIO_PORTA_DATA_R ^ pins_mask;
        break ;

        // Port B
        case 1 : GPIO_PORTB_DATA_R = GPIO_PORTB_DATA_R ^ pins_mask;
        break ;

        // Port C
        case 2 : GPIO_PORTC_DATA_R = GPIO_PORTC_DATA_R ^ pins_mask;
				break ;

        // Port D
        case 3 : GPIO_PORTD_DATA_R = GPIO_PORTD_DATA_R ^ pins_mask;      
        break ;

        // Port E
        case 4 : GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R ^ pins_mask; 
        break ;
        
        // Port F 
        case 5 : GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R ^ pins_mask;  
        break ;
   
        
    }

}

//write_Port

void DIO_WritePort(Port port_index , uint8 pins_mask, DIO_LevelType pin_level){
		switch (port_index) {
        // Port A
				//check for the value of pin_level
        case 0 : if(pin_level){
					GPIO_PORTA_DATA_R |= pins_mask; //if high set the required pins by pins_mask
				} 
				else{
							GPIO_PORTA_DATA_R &= ~(pins_mask);//if low clear the required pins by pins_mask
				}
        break ;

        // Port B
        case 1 : if(pin_level){
					GPIO_PORTB_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTB_DATA_R &= ~(pins_mask);
				}
        break ;

        // Port C
        case 2 : if(pin_level){
					GPIO_PORTC_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTC_DATA_R &= ~(pins_mask);
				}
				break ;

        // Port D
        case 3 : if(pin_level){
					GPIO_PORTD_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTD_DATA_R &= ~(pins_mask);
				} 
        break ;

        // Port E
        case 4 : if(pin_level){
					GPIO_PORTE_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTE_DATA_R &= ~(pins_mask);
				}
        break ;
        
        // Port F 
        case 5 : if(pin_level){
					GPIO_PORTF_DATA_R |= pins_mask;
				} 
				else{
							GPIO_PORTF_DATA_R &= ~(pins_mask);
				}  
        break ;
   
        
    }
  }
	//DIO_ReadPort
/*Return the value of the pins selected by
pins_masks in the port selected by port_index*/
uint8 DIO_ReadPort (Port port_index, uint8 pins_mask) {
    switch (port_index) {
	
        // Port A
        case 0 : return GPIO_PORTA_DATA_R & pins_mask;
    

        // Port B
        case 1 : return  GPIO_PORTB_DATA_R & pins_mask;
       

        // Port C
        case 2 : return GPIO_PORTC_DATA_R & pins_mask;
				

        // Port D
        case 3 : return GPIO_PORTD_DATA_R & pins_mask;      
       

        // Port E
        case 4 : return GPIO_PORTE_DATA_R & pins_mask; 
        
        
        // Port F 
        case 5 : return GPIO_PORTF_DATA_R & pins_mask;  
       
		
		}
		
	}

	
