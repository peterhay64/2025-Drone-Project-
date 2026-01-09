#include <GY521.h> 
#include <Wire.h> 
#include <SoftwareSerial.h> 
#include <Servo.h> 


// dont need  pinMode for analog, I2C pins are A4 and A5. 


SoftwareSerial GyroSerial(2,7);
Servo frontRight; 
Servo frontLeft; 
Servo backRight; 
Servo backLeft;  
int lastNumber = 0; 


GY521 gyro(0x68); // Default adress for the gyro 
// SDA : Sends and recieves data 
// SCL : tells when to send and recieve data..  
const int testLight = 13; 

int throttle = 0;

void setup() {

  frontLeft.attach(8);
  backRight.attach(9); 
  frontRight.attach(10); 
  backLeft.attach(11); 
  
  delay(2000); 

  frontRight.writeMicroseconds(900); 
  frontLeft.writeMicroseconds(900); 
  backRight.writeMicroseconds(900); 
  backLeft.writeMicroseconds(900); 

  delay(3000); 

  pinMode(13, OUTPUT); 

  Wire.begin(); 
  

  
  gyro.begin(); // begin communication beween arduino and the gyroscope
  gyro.calibrate(3000); // calibrates gyro, 3 seconds to be sure 
  GyroSerial.begin(9600);
  Serial.begin(9600); 


  


}


void loop() {
  // put your main code here, to run repeatedly:
   

  if(GyroSerial.available()){
    String numberRecieved = GyroSerial.readStringUntil('\n'); 
    int numberActual = numberRecieved.toInt(); 

    if(numberActual != lastNumber){
      
      if((numberActual > 0) && (numberActual < 1000)){
        frontRight.writeMicroseconds(900); 
        frontLeft.writeMicroseconds(900); 
        backRight.writeMicroseconds(900); 
        backLeft.writeMicroseconds(900);
      }
      else if ((numberActual > 1000) && (numberActual < 5000)){
        frontRight.writeMicroseconds(950); 
        frontLeft.writeMicroseconds(950); 
        backRight.writeMicroseconds(950); 
        backLeft.writeMicroseconds(1100);
      }
      else if((numberActual > 5000) && (numberActual < 10000)){
        frontRight.writeMicroseconds(1000); 
        frontLeft.writeMicroseconds(1000); 
        backRight.writeMicroseconds(1000); 
        backLeft.writeMicroseconds(1300);
      }
      else if((numberActual > 10000) && (numberActual < 15000)){
        frontRight.writeMicroseconds(1300); 
        frontLeft.writeMicroseconds(1300); 
        backRight.writeMicroseconds(1300); 
        backLeft.writeMicroseconds(1600);
      }
      else if((numberActual > 15000) && (numberActual < 25000)){
        frontRight.writeMicroseconds(1500); 
        frontLeft.writeMicroseconds(1500); 
        backRight.writeMicroseconds(1500); 
        backLeft.writeMicroseconds(1800);
      }
      else if((numberActual > 25000)){
        frontRight.writeMicroseconds(2000); 
        frontLeft.writeMicroseconds(2000); 
        backRight.writeMicroseconds(2000); 
        backLeft.writeMicroseconds(2300);
      }else{
        frontRight.writeMicroseconds(900); 
        frontLeft.writeMicroseconds(900); 
        backRight.writeMicroseconds(900); 
        backLeft.writeMicroseconds(900);
      }
      lastNumber = numberActual;
    }

   
    

  }

  gyro.read(); // gives float values from gyroscope
  float accelX = gyro.getAccelX(); 
  float accelY = gyro.getAccelY();
  float accelZ = gyro.getAccelZ();  

  float totalAccel = sqrt(accelX*accelX + accelY*accelY + accelZ*accelZ); // calcs net (short for calcualtor) total accel due to gravity 


  GyroSerial.print(totalAccel);
  GyroSerial.print(","); 
   
  
  if(totalAccel < 0.3){
    GyroSerial.println("Falling");
  }else{
    GyroSerial.println("Stable");
  }

  
 


  delay(30); 



  
}