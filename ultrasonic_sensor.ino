/******************************************************************************************
 *    Testing of Ultrasonic Sensor
 *    
 *    Author  :   Jogesh S Nanda
 *    Date    :   29-June-2017
 *    
 *    Description   :   Testing of Ultrasonic Sensor.
 *          Type no. HC-SR04 Ultrasonic Sensor.
 *          maximum range - 4 m with 15 degree wide angle.
 *            
 *****************************************************************************************/

/******************************************************************************************
 * Global Variables
 *****************************************************************************************/
 int trig = 9;    // Trig Pin is Connected to Port 9.
 int echo = 8;    // Echo Pin is connected to Port 8.

 float distance = 0;  // Initilization of Variable for Distance.

/*******************************************************************************************
 * Function : Ultrasonic_Sensor
 * 
 * Description  :   Sends an echo signal to sensor and calculates the time taken for
 *      the echo to return back. This time difference is used to calculate the 
 *      distance between the objects. Echo pulse should be of duration min. 10us
 ******************************************************************************************/
// gives the distance from Obstracle in (cm)
float ultrasonic_sensor() {
  
  // declaration of local Variables
  unsigned long duration;      // time taken by the echo pulse
  float distance = 0;          // distance from Obstracle/ Output
  
  // Creating a Pulse for TRIG. ( min duration needed is 10 us).
  digitalWrite(trig, LOW);
  delay (10);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo, HIGH);
 
  // Calculating Distance from Time 
  distance = 0.034 * duration/2;

  return(distance);
  
}

void setup() {
  // Ultrasonic Sensor Port Initilization.
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Start the baud rate of serial plotting in arduino.
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  distance = ultrasonic_sensor();
  Serial.println(distance);
  
}
