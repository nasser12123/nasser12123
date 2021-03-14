String readString;

void setup() {
  Serial.begin(9600);
  right_motor.setSpeed(255);
  left_motor.setSpeed(255);
  three_motor.setSpeed(255);
  }


void loop() 
{
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){ //forward
      right_motor.run (FORWARD);
      left_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="BACKWARD"){ //backward
      right_motor.run (BACKWARD);
      left_motor.run (BACKWARD);
      delay(500);
    }
    if (readString =="LEFT"){ //left
      right_motor.run (FORWARD);
      left_motor.run (BACKWARD);
      delay(500);
    }
    if (readString =="RIGHT"){  //right
      right_motor.run (BACKWARD);
      left_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="STOP"){  //stop
      right_motor.run (RELEASE);
      left_motor.run (RELEASE);
      delay(500);
    }
    if (readString =="RUN WATER"){  //ON Water Pump
      three_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="STOP WATER"){  //OFF Water Pump
      three_motor.run (RELEASE);
      delay(500);
    }
  
  readString="";
  }
 
}



