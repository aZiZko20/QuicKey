//#include <Keyboard.h>
//
//char keyboard[6][14] = { {'E', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'B' },
//                      {'T', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 'j'       },
//                      {'C', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 'q', 'E'   },
//                      {'L', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 'R'          },
//                      {'L', 'n', 'L',     ' '     ,'R', 'M', 'R', 'F'            },
//                      {'N', 'A', 'A', '{', '(', '<', '>', ')', '}', 'N', 'N', 'A'              } };
//
//
//
///*int keyboard[6][14] = { {0xB1, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2D, 0x2B, 0xB2 },
//                      {0xB3, 0x71, 0x77, 0x65, 0x72, 0x74, 0x79, 0x75, 0x69, 0x6F, 0x70, 0x5B, 0x5D, 0x5C       },
//                      { 0xC1, 0x61, 0x73, 0x64, 0x66, 0x67, 0x68, 0x6A, 0x6B, 0x6C, 0x3B, 0x22, 0xB0   },
//                      {0x81, 0x7A, 0x78, 0x63, 0x76, 0x62, 0x6E, 0x6D, 0x2C, 0x2E, 0x2F, 0x85          },
//                      {0x80, 0x83, 0x82,     0x20     , 0x86, 0xDA, 0x84, 0xD8            },                        //FN turned to LEFT arrow button and Menu turned to UP arrow
//                      {0x00, 0x00, 0x00, 0x7B, 0x28, 0x3C, 0x3E, 0x29, 0x7D, 0x00, 0x00, 0x00              } };
//                      */
//
//int port_rows[5] = {8, 1, 4, 12, 6};
//int port_cols[15] = {15,16,14,9,10,12,13,3,2,18,19,20,21,22,23};
//
//
//
//void setup() {
//  Serial.begin(9600);
//  Keyboard.begin();
//  //initializing rows as input
//  pinMode(8, OUTPUT); //row 0 PB4
//  pinMode(1, OUTPUT); //row 4 PD3
//  pinMode(12, OUTPUT); //row 3 PD6
//  pinMode(6, OUTPUT); //row 2 PD7
//  pinMode(4, OUTPUT); //row 1 PD4
//  //initializing columns as output and enabling pull-up resistors
//  pinMode(15, INPUT_PULLUP); //column 0 PB1
//  pinMode(16, INPUT_PULLUP); //column 1 PB2
//  pinMode(14, INPUT_PULLUP); //column 2 PB3
//  pinMode(9, INPUT_PULLUP);  //column 5 PB5
//  pinMode(10, INPUT_PULLUP); //column 6 PB6
//  pinMode(5, INPUT_PULLUP); //column 7 PC6
//  pinMode(13, INPUT_PULLUP); //column 8 PC7
//  pinMode(3, INPUT_PULLUP);  //column 4 PD0
//  pinMode(2, INPUT_PULLUP);  //column 3 PD1
//  pinMode(18, INPUT_PULLUP); //column 9 PF7
//  pinMode(19, INPUT_PULLUP); //column 10 PF6
//  pinMode(20, INPUT_PULLUP); //column 11 PF5
//  pinMode(21, INPUT_PULLUP); //column 13 PF4
//  pinMode(22, INPUT_PULLUP); //column 14 PF1
//  pinMode(23, INPUT_PULLUP); //column 12 PF0
//
//
//}





#include <Keyboard.h>

/*char keyboard[6][14] = { {'E', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'B' },
                      {'T', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', 'j'       },
                      {'C', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', 'q', 'E'   },
                      {'L', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 'R'          },
                      {'L', 'n', 'L',     ' '     ,'R', 'M', 'R', 'F'            },
                      {'N', 'A', 'A', '{', '(', '<', '>', ')', '}', 'N', 'N', 'A'              } };

*/

int keyboard[6][14] = { {0xB1, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x2D, 0x2B, 0xB2 },
                      {0xB3, 0x71, 0x77, 0x65, 0x72, 0x74, 0x79, 0x75, 0x69, 0x6F, 0x70, 0x5B, 0x5D, 0x5C       },
                      { 0xC1, 0x61, 0x73, 0x64, 0x66, 0x67, 0x68, 0x6A, 0x6B, 0x6C, 0x3B, 0x22, 0xB0   },
                      {0x81, 0x7A, 0x78, 0x63, 0x76, 0x62, 0x6E, 0x6D, 0x2C, 0x2E, 0x2F, 0x85          },
                      {0x80, 0x83, 0x82,     0x20     , 0x86, 0xDA, 0x84, 0xD8            },                        //FN turned to LEFT arrow button and Menu turned to UP arrow
                      {0x00, 0x00, 0x00, 0x7B, 0x28, 0x3C, 0x3E, 0x29, 0x7D, 0x00, 0x00, 0x00              } };
                      

int port_rows[5] = {8, 4, 6, 12, 1};
int port_cols[15] = {15,16,14,2,3,9,10,5,13,18,19,20,23,21,22};

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  //initializing rows as input
  pinMode(8, OUTPUT); //row 0 PB4
  pinMode(1, OUTPUT); //row 4 PD3
  pinMode(12, OUTPUT); //row 3 PD6
  pinMode(6, OUTPUT); //row 2 PD7
  pinMode(4, OUTPUT); //row 1 PD4
  //initializing columns as output and enabling pull-up resistors
  pinMode(15, INPUT_PULLUP); //column 0 PB1
  pinMode(16, INPUT_PULLUP); //column 1 PB2
  pinMode(14, INPUT_PULLUP); //column 2 PB3
  pinMode(9, INPUT_PULLUP);  //column 5 PB5
  pinMode(10, INPUT_PULLUP); //column 6 PB6
  pinMode(5, INPUT_PULLUP); //column 7 PC6
  pinMode(13, INPUT_PULLUP); //column 8 PC7
  pinMode(3, INPUT_PULLUP);  //column 4 PD0
  pinMode(2, INPUT_PULLUP);  //column 3 PD1
  pinMode(18, INPUT_PULLUP); //column 9 PF7
  pinMode(19, INPUT_PULLUP); //column 10 PF6
  pinMode(20, INPUT_PULLUP); //column 11 PF5
  pinMode(21, INPUT_PULLUP); //column 13 PF4
  pinMode(22, INPUT_PULLUP); //column 14 PF1
  pinMode(23, INPUT_PULLUP); //column 12 PF0


}


int keypad_scan(){
  //setting all the rows to 1
  digitalWrite(8, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(4, HIGH);
  
  int i = 0;
  int j = 0;
  for(i = 0; i < 5; i++){
    //setting a row to 0
    digitalWrite(port_rows[i], LOW );
        delay(5);
        //scan through the columns to see which button is pressed.
    for(j = 0; j < 15; j++){
      if( (digitalRead(port_cols[j]) == 0 )){
        return keyboard[i][j];
      }
            
    }
    //set the row back to 1 and move on to the next row
    digitalWrite(port_rows[i], HIGH);
  }
  return 0xFFF;   //If nothing is found, return 0
}



void loop() {
  int key = keypad_scan(); 
  if(key != 0xFFF) {
    Keyboard.press(key);
    delay(50);
  }
  else {
    Keyboard.releaseAll();
  }

}
