#define F_CPU 16000000UL
#define BPS 9600
#define BaudRate ((F_CPU)/(BPS*16UL)-1)
#include <avr/io.h>
#include <util/delay.h>


//char keypad[4][4] ={{'1','2','3','A'},
//					{'4','5','6','B'},
//					{'7','8','9','C'},
//					{'*','0','#','D'}};



//some rows have less than 14 columns, might affect the functionality of the keyboard
char keyboard[6][14] = { {'ESC', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'BKSPC' },
                      {'TAB', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\ '       },
                      {'CAPS', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', ' quote ', 'ENTR'   },
                      {'LSHIFT', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 'RSHIFT'          },
                      {'LCTRL', 'WIN', 'LALT',     ' '     ,'RALT', 'MENU', 'RCTRL', 'FN'            },
                      {'NA', 'NA', 'NA', '{', '(', '<', '>', ')', '}', 'NA', 'NA', 'NA'              } };

int port_rows[6] = {0, 1, 4, 5, 6, 7};
int port_cols[14] = {0, 1, 2, 3, 4, 5, 6, 6, 7, 0, 1, 2, 3, 5};

//initializing the USART protocol
void usart_init(){
	UBRR0H = (BaudRate>>8); //shifting the baud rate to the right 8 bits gives us the leftmost 8 bits and stores them in UBRR0H
	UBRR0L = BaudRate;  //gets the first 8 bits from the baud rate and stores them in UBRR0L
	UCSR0B |= (1<<TXEN0) | (1<<RXEN0);  //enables both transmission and reception
	UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01); //sets it to 8-bit data format
	//USBC is already 0, which corresponds to 1 stop bit
}

//Transmits the data
void usart_transmit(char data){
	while(!(UCSR0A & (1<<UDRE0))); //checks if buffer is empty and then loads it with data
	UDR0 = data;
}

//sets rows to outputs and columns to inputs and enables pull-up resistors on input.
void keypad_init(){
	//rows (output)
	DDRF |= (1<<DDF0); //row 5
    DDRF |= (1<<DDF1); //row 4
    DDRF |= (1<<DDF4); //row 3
    DDRF |= (1<<DDF5); //row 2
    DDRF |= (1<<DDF6); //row 1
    DDRF |= (1<<DDF7); //row 0

	//columns (input)
	DDRB &= ~(1<<DDB0); //col 0
	DDRB &= ~(1<<DDB1); //col 1
	DDRB &= ~(1<<DDB2); //col 2
	DDRB &= ~(1<<DDB3); //col 3
    DDRB &= ~(1<<DDB4); //col 9
    DDRB &= ~(1<<DDB5); //col 10
    DDRB &= ~(1<<DDB6); //col 11
    DDRC &= ~(1<<DDC6); //col 12
    DDRC &= ~(1<<DDC7); //col 13
    DDRD &= ~(1<<DDD0); //col 4
    DDRD &= ~(1<<DDD1); //col 5
    DDRD &= ~(1<<DDD2); //col 6
    DDRD &= ~(1<<DDD3); //col 7
    DDRD &= ~(1<<DDD5); //col 8
    
	//enables pull-up resistors
	PORTB |= (1<<PORTB0); //col 0
	PORTB |= (1<<PORTB1); //col 1
	PORTB |= (1<<PORTB2); //col 2
	PORTB |= (1<<PORTB3); //col 3
    PORTB |= (1<<PORTB4); //col 9
    PORTB |= (1<<PORTB5); //col 10
    PORTB |= (1<<PORTB6); //col 11
    PORTC |= (1<<PORTC6); //col 12
    PORTC |= (1<<PORTC7); //col 13
    PORTD |= (1<<PORTD0); //col 4
    PORTD |= (1<<PORTD1); //col 5
    PORTD |= (1<<PORTD2); //col 6
    PORTD |= (1<<PORTD3); //col 7
    PORTD |= (1<<PORTD5); //col 8
}

//scans which key is being pressed
char keypad_scan(){
	//setting all the rows to 1
	PORTF |= (1<<PORTF0);
	PORTF |= (1<<PORTF1);
	PORTF |= (1<<PORTF4);
	PORTF |= (1<<PORTF5);
    PORTF |= (1<<PORTF6);
    PORTF |= (1<<PORTF7);
	
	uint8_t i = 0;
	uint8_t j = 0;
	for(i = 0; i < 6; i++){
		//setting a row to 0
		PORTF &= ~(1 << port_rows[i] );
        _delay_us(5);
        //scan through the columns to see which button is pressed.
		for(j = 0; j < 14; j++){
			if( (PINB & (1 << port_cols[j]) ) == 0 )
                return keyboard[ port_rows[i] ] [ port_cols[j] ];
            
            else if( (PIND & port_cols[j]) ) == 0)
                return keyboard[ port_rows[i] ] [ port_cols[j] ];
            
            else if( (PINB & (1 << port_cols[j]) ) == 0 )
                return keyboard[ port_rows[i] ] [ port_cols[j] ];
		}
		//set the row back to 1 and move on to the next row
		PORTF |= (1 << port_rows[i] );
	}
	return 0;		//If nothing is found, return 0
}

int main(void){
	usart_init();
	keypad_init();
	char data;

	while (1){
		data = keypad_scan();
		if(data != 0){
			usart_transmit(data);
			_delay_ms(500);			//to avoid debouncing
		}
	}
	return 0;
}
