#include <Servo.h>

#include <dht_nonblocking.h>

//establishing/allocating DHT sensor
#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;

DHT_nonblocking dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

Servo myServo;

void setup(){
  Serial.begin(9600);

  myServo.attach(9);
  int pos = 0;

  Serial.println("servo set up");

  float temperature;
  float humidity;

  Serial.println("waiting for sensor");
  while(dht_sensor.measure(&temperature, &humidity) != true){
    Serial.print(".");
  }

}


static bool measure_environment(float * temperature, float * humidity){
  static unsigned long measurement_timestamp = millis();

  if(millis() - measurement_timestamp >3000ul){
    if(dht_sensor.measure(temperature, humidity) == true){
      measurement_timestamp = millis();
      return(true);
    }
  }
  return(false);
}

void loop(){
  float temperature;
  float humidity;

  if(measure_environment(&temperature, &humidity)== true){
    if(humidity>=21.0 && humidity <= 26.0){
      Serial.print("T = ");
      Serial.print(temperature, 1);
      Serial.print("deg C, H = ");
      Serial.print(humidity, 1);
      Serial.println(" % ");
      myServo.write(0);
    }
    else if(humidity>=26.0 && humidity <= 41.0){
      Serial.print("T = ");
      Serial.print(temperature, 1);
      Serial.print("deg C, H = ");
      Serial.print(humidity, 1);
      Serial.println(" % ");
      myServo.write(90); 
  }
      else if(humidity>=41.0 && humidity <= 60.0){
      Serial.print("T = ");
      Serial.print(temperature, 1);
      Serial.print("deg C, H = ");
      Serial.print(humidity, 1);
      Serial.println(" % ");
      myServo.write(180); 
  }
}
}
