
long number = 0; //declear the variables
int first_digit = 0;
int second_digit = 0;
int third_digit = 0;
int fourth_digit = 0;
int timer_event = 0;
int CA_1 = 6;
int CA_2 = 2;
int CA_3 = 1;
int CA_4 = 0;
int clk = 3;
int latch = 4;
int data = 5;
int count = 0;
int digits[4] ;
int CAS[4] = {CA_1, CA_2, CA_3, CA_4};
byte numbers[10] {B11111100, B01100000, B11011010, B11110010, B01100110, B10110110, B10111110, B11100000, B11111110, B11110110};
//byte combinations for each number 0-9
void setup() {
  Serial.begin(9600); //serial start and pin config
  pinMode(CA_1, OUTPUT);
  pinMode(CA_2, OUTPUT);
  pinMode(CA_3, OUTPUT);
  pinMode(CA_4, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  digitalWrite(CA_1, HIGH);
  digitalWrite(CA_2, HIGH);
  digitalWrite(CA_3, HIGH);
  digitalWrite(CA_4, HIGH);
  Serial.println("please Enter a number from 0 to 9999");
}

void loop() {
  

      break_number(1234L);
      delay(1000);

}

void break_number(long num) { // seperate the input number into 4 single digits

  first_digit = num / 1000;
  digits[0] = first_digit;

  int first_left = num - (first_digit * 1000);
  second_digit = first_left / 100;
  digits[1] = second_digit;
  int second_left = first_left - (second_digit * 100);
  third_digit = second_left / 10;
  digits[2] = third_digit;
  fourth_digit = second_left - (third_digit * 10);
  digits[3] = fourth_digit;

}

void display_number() { //scanning

  cathode_high(); //black screen
  digitalWrite(latch, LOW); //put the shift register to read
  shiftOut(data, clk, LSBFIRST, numbers[digits[count]]); //send the data
  digitalWrite(CAS[count], LOW); //turn on the relevent digit
  digitalWrite(latch, HIGH); //put the shift register to write mode


  count++; //count up the digit
  if (count == 4) { // keep the count between 0-3
    count = 0;
  }


}

void cathode_high() { //turn off all 4 digits

  digitalWrite(CA_1, HIGH);
  digitalWrite(CA_2, HIGH);
  digitalWrite(CA_3, HIGH);
  digitalWrite(CA_4, HIGH);
}
