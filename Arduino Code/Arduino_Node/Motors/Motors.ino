#include <ros.h>
#include <geometry_msgs/Vector3.h>

#define s2 1.41421356237

#define FW 0
#define RV 1

#define LM_S 13
#define LM_D 3
#define RM_S 12
#define RM_D 4

float speed[]= {0.0,0.0};
float PWM[] = {0.0,0.0};
bool dir[] = {0,0};
int scale = 5;

ros::NodeHandle  nh;

void motor_cb(const geometry_msgs::Vector3& message ){
  speed[0] = message.x;
  speed[1] = message.y;
}

ros::Subscriber<geometry_msgs::Vector3> sub("/wheel_cmd", motor_cb);

void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  convert(speed);
  drive(dir,PWM);
  nh.spinOnce();
  delay(1);
}

void convert(float vals[]){
  if(vals[0] >= 0){ dir[0] = FW;}
  else{dir[0] = RV;}
  if(vals[1] >= 0){ dir[1] = FW;}
  else{dir[1] = RV;}

  PWM[0] = map(vals[0],0, s2*scale, 0,255);
  PWM[1] = map(vals[1],0, s2*scale, 0,255);
}

void drive(bool d[], float P[]){
  digitalWrite(LM_D,d[0]);
  digitalWrite(RM_D,d[1]);
  analogWrite(LM_S,P[0]);
  analogWrite(RM_S,P[1]);
}