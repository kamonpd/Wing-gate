#define dclose 7                                          //pin to micro sw close
#define dopen 8                                           //pin to micro sw open
#define pwm 9                                             //pin to board dive motor pwm
#define a_pin 10                                          //pin to board dive motor a pin
#define b_pin 11                                          //pin to board dive motor b pin
#define sensorPin 13                                      //pin to ir sensor

int mspeed = 180;                                         //speed motor
int timee  = 600;                                         //time(ms) drop speed motor
int dropspeed = 50;                                       //drop speed motor
int count;                                                //count in loop                           
int sensorValue=0;                                        //sensor ir value 
int openValue=0;                                          //micro sw. value
int closeValue=0;                                         //micro sw. value
String command = "";                                      //recive string parameter
unsigned long timeout;                                    //working time

void setup() {
  Serial.begin(115200);                                   //set baudrate                                   
  pinMode(pwm, OUTPUT);                                   //****************
  pinMode(a_pin, OUTPUT);                                 //
  pinMode(b_pin, OUTPUT);                                 // set pinmode
  pinMode(dopen,INPUT);                                   //
  pinMode(dclose,INPUT);                                  //
  pinMode(sensorPin,INPUT);                               //****************
  delay(500);                                             //delay 500ms                             
}

void loop() { 
  timeout= millis();                                      //keep time in timeout                       
  if (Serial.available()>0){                              //if have command                        
    String mes = Serial.readString();                     //keep command in mes                    
    mes.trim();                                           //remove whitespace in string                               
    if(mes.startsWith("c")){                              //if string start with "c"                     
      mes.replace("c","");                                //remove "c" 
      command = mes;                                      //keep mes string in command
    }
  }
  count = 0;                                                    
  while(command == "open"){                               //if command = "open"   
    openValue = digitalRead(dopen);                       //keep value of dopen in openvalue     
    if(count < timee){                                    //if time of count < timee     
      analogWrite(pwm,mspeed);                            //set speed motor
      digitalWrite(a_pin,1);                              //set motor rotate
      digitalWrite(b_pin,0);
  }
    count++;                                              //increase count
    if(count > timee){                                    //if time of count > timee  
      analogWrite(pwm,mspeed-dropspeed);                  //set drop speed motor
      digitalWrite(a_pin,1);                              //set motor rotate
      digitalWrite(b_pin,0);
    }
 
    if((openValue == 1)){                                 //if door open
      digitalWrite(a_pin,0);                              //motor not work                                            
      digitalWrite(b_pin,0);      
      command = "sensor";                                 //set command = "sensor"
      count = 0;
      break;                                              //bypassing condition  
    }
 }

  while(command == "sensor"){                             //if command = "sensor"                             
    if((digitalRead(sensorPin) == 0)){                     //if sensorPin = 0
      Serial.print("success");                            //sent "succese" to computer
      command = "close";                                  //set command = "close"  
      break;                                              //bypassing condition
    }
    if(millis() - timeout > 7000){                        //if timeout > 7000 
      Serial.print("timeout");                            //sent "timeout" to computer
      command = "close";                                  //set command = "close"
      break;                                              //bypassing condition
    }
  }
  
  while(command == "close"){                              //if command = "sensor" 
    closeValue = digitalRead(dclose);                     //keep value of dclose in closeValue 
  if(count < timee){                                      //if time of count < timee  
    analogWrite(pwm,mspeed);                              //set speed motor
    digitalWrite(a_pin,0);                                //set motor rotate
    digitalWrite(b_pin,1);
  }
    count++;                                              //increase count
    if(count > timee){                                    //if time of count > timee  
    analogWrite(pwm,mspeed-dropspeed);                    //set drop speed motor
    digitalWrite(a_pin,0);                                //set motor rotate            
    digitalWrite(b_pin,1);
    } 
    if((closeValue == 1)){                                //if door close
      digitalWrite(a_pin,0);                              //motor not work
      digitalWrite(b_pin,0);
      command = "";                                       //delete message in command
      count = 0;
      break;                                              //bypassing condition
    }
  }
}
