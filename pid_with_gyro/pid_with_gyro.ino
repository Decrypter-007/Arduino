
#include<Wire.h>
#include<Servo.h>
long accel_rawY, accel_rawZ, accel_rawX;
float gForceY, gForceZ, gForceX;
int degreeAngle_Y;

float total_angleY;

double Kp = 40;
double Ki = 0;
double Kd =25;

int delta_time, T=20;

long gyro_rawY, gyro_rawX, gyro_rawZ;
float rotY, rotX,rot;
int  error_prev,thrust;
unsigned long total_error;
void setupMPU();
void recordAccelData();
void recordGyroData();

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
  
  rot=0;
delay(3000);
  
  
  



}

void loop() {


  


  Time = millis();
 

 
  delta_time = Time - time_prev;
 
for(int i=0;i<50;i=i+1)
  { 
   recordGyroRegisters();
   processGyroData();
   rot=rot+rotX;
  }
   rotX=rot/50;
    total_angleY=total_angleY+rotX*delta_time/1000;
  rot=rotX;

 
  
 


  int  error =total_angleY-set_point; 
  int  delta_error = error-error_prev; //for derivative part
  total_error += error;             //for integration part

  
  

    control_signal = Kp*error +Ki*delta_time* total_error / 1000 +Kd*delta_error* 1000/ delta_time;
   
    error_prev=error;

 
  
   

  thrust =  control_signal / 6 + 1070;




  if (thrust <= 2000 && thrust >= 1000)
  {
    servo.writeMicroseconds(thrust);
  }
    if (thrust > 2000)
    {
      servo.writeMicroseconds(2000);

    }


  Serial.println(total_angleY);
  
   time_prev=Time;
 delay(T);
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
  rotX = gyro_rawX / 131.0 + 1.66;
  rotY = gyro_rawY / 131.0 + 1.5;
}
