#include <GY521.h> 
#include <Wire.h> 
#include <SoftwareSerial.h> 


// dont need  pinMode for analog, I2C pins are A4 and A5. 
SoftwareSerial GyroSerial(3,4);

GY521 gyro(0x68); // Default adress for the gyro 
// SDA : Sends and recieves data 
// SCL : tells when to send and recieve data..  
const int RXpin= 4;
const int TXpin = 3;


void setup() {




  // put your setup code here, to run once:

  Wire.begin(); 
  

  
  gyro.begin(); // begin communication beween arduino and the gyroscope
  gyro.calibrate(3000); // calibrates gyro, 3 seconds to be sure 
  GyroSerial.begin(9600);

  


}


void loop() {
  // put your main code here, to run repeatedly:
  gyro.read(); // gives float values from gyroscope 


  float accelX = gyro.getAccelX(); //acceleration on the gyro in the x y and z 
  float accelY = gyro.getAccelY();
  float accelZ = gyro.getAccelZ();  

  float totalAccel = sqrt(accelX*accelX + accelY*accelY + accelZ*accelZ); // calcs net (short for calcualtor) total accel due to gravity 

  GyroSerial.print(accelX); 
  GyroSerial.print(",");
  GyroSerial.print(accelY); 
  GyroSerial.print(",");
  GyroSerial.print(accelZ); 
  GyroSerial.print(",");  

   
  
  if(totalAccel < 0.3){
    GyroSerial.println("Falling");
  }else{
    GyroSerial.println("Stable");
  }

  
 


  delay(10); 

  //Serial.print("X Rotational Speed: "); Serial.println(gyro.getGyroX());  // These are giving the speed at which the gyroscope is rotating
  //Serial.print("Y Rotational Speed: "); Serial.println(gyro.getGyroY()); 
  //Serial.print("Z Rotational Speed: "); Serial.println(gyro.getGyroZ());  

  //Serial.print("X Acceleration : "); Serial.println(gyro.getAccelX()); // The acceleration of the gyroscope 
  //Serial.print("Y Acceleration : "); Serial.println(gyro.getAccelY());
  //Serial.print("Z Acceleration : "); Serial.println(gyro.getAccelZ());



  //print roll, pitch and yaw 

  /*Serial.print(gyro.getAngleX()); 
  Serial.print(",");
  Serial.print(gyro.getAngleY()); 
  Serial.print(",");
  Serial.println(gyro.getAngleZ()); */ 


  // print x y and z accelerations 

  
}