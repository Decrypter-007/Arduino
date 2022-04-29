#include<Wire.h>
#include<Servo.h>
long accel_rawY, accel_rawZ, accel_rawX;
float gForceY, gForceZ, gForceX;
int degreeAngle_Y, total_angleY;

double Kp = 30;
double Ki = 0;
double Kd =0.1;

int delta_time;

long gyro_rawY, gyro_rawX, gyro_rawZ;
float rotY, rotX;
int  error_prev,thrust;
unsigned long total_error;
void setupMPU();
void recordAccelData();
void recordGyroData();
int T = 50, limit = 180;
unsigned long time_prev,Time;
int set_point = 20;

float control_signal;
void recordAccelRegisters();
void recordGyroRegisters();
void processGyroData();
void processAccelData();
Servo servo;
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  time_prev = 0;
  setupMPU();
  
  servo.attach(3);
  recordAccelRegisters();
  recordGyroRegisters();
  gForceX = accel_rawX / 16384.0;
  gForceY = accel_rawY / 16384.0;
  gForceZ = accel_rawZ / 16384.0;
  total_angleY = atan(gForceY / gForceZ) * 180 / 3.14;
  
  servo.writeMicroseconds(1000);
  
  

  
 delay(3000);



}

void loop() {


  


  Time = millis();
 

 
  delta_time = Time - time_prev;

   recordAccelRegisters();
   recordGyroRegisters();
   processGyroData();
   processAccelData();
   
   degreeAngle_Y = atan(gForceY / gForceZ) * 180 / 3.14;
   
   
   
   
    
    
 Serial.println(degreeAngle_Y);
 


  int  error =total_angleY-set_point; //for proportional part
  int  delta_error = error-error_prev; //for derivative part
  total_error += error;             //for integration part

  if (delta_time > T) {
  

    control_signal = Kp*error + Ki*T* total_error / 1000 + Kd*delta_error* 1000/ T;
    time_prev=Time;
    error_prev=error;

  }
  
   

  thrust =  control_signal / 6 + 1070;




  if (thrust <= 2000 && thrust >= 1000)
  {
    servo.writeMicroseconds(thrust);
  }
    if (thrust > 2000)
    {
      servo.writeMicroseconds(2000);

    }
   if(thrust<0)
   {
    
  servo.writeMicroseconds(2000);
    
    }
}

void setupMPU() {
  Wire.beginTransmission(0b1101000);
  Wire.write(0x6B);
  Wire.write(0b00000000);
  Wire.endTransmission();

  Wire.beginTransmission(0b1101000);
  Wire.write(0x1C);
  Wire.write(0b00000000);
  Wire.endTransmission();

  Wire.beginTransmission(0b1101000);
  Wire.write(0x1B);
  Wire.write(0b00000000);
  Wire.endTransmission();
}

void recordAccelRegisters() {
  Wire.beginTransmission(0b1101000);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000, 6);
  while (Wire.available() < 6);

  accel_rawX = Wire.read() << 8 | Wire.read();
  accel_rawY = Wire.read() << 8 | Wire.read();
  accel_rawZ = Wire.read() << 8 | Wire.read();
  processAccelData();
}

void processAccelData() {

  gForceX = accel_rawX / 16384.0;
  gForceY = accel_rawY / 16384.0;
  gForceZ = accel_rawZ / 16384.0;

}

void recordGyroRegisters() {

  Wire.beginTransmission(0b1101000);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000, 6);
  while (Wire.available() < 6);
  gyro_rawX = Wire.read() << 8 | Wire.read();
  gyro_rawY = Wire.read() << 8 | Wire.read();
  gyro_rawZ = Wire.read() << 8 | Wire.read();
  processGyroData();
}

void processGyroData()
{
  rotX = gyro_rawX / 131.0 + 1.5;
  rotY = gyro_rawY / 131.0 + 1.5;
}
