// C++ code
//

const int led = 9;
const int button = 2;
int mode = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), interrupt_button, FALLING);
}

void slow_blink(){
  
  Serial.println("slow_blink");
  analogWrite(led, 255);
  delay(5000);
  analogWrite(led, 0);
  delay(5000);

}

void fast_blink(){
  Serial.println("fast_blink");
  analogWrite(led, 255);
  delay(500);
  analogWrite(led, 0);
  delay(500);

}

void change_brightness(){
  Serial.println("change_brightness");
  for(int i=0; i<255;i++){analogWrite(led, i);delay(10);}
  for(int i=255; i>0;i--){analogWrite(led, i);;delay(10);}
    
}

void interrupt_button(){
  Serial.print("Interrupt");
  if(mode == 2){mode = 0;}
  else{mode+=1;}
  //Serial.println(mode);
  //delay(250);
}

void loop()
{
  Serial.println(mode);
  if(mode==2){
    change_brightness();
  }
  else if(mode==1){
   fast_blink();
  }
  else if(mode==0){
   slow_blink();
  }

}