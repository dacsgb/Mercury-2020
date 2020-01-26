#!/usr/bin/env python

import rospy
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Vector3

class Node():
    def __init__(self):
        self.speed = Vector3()
        self.speed_max = 5.0
        self.threshold = 0.1
        self.wheel_sp_pub = rospy.Publisher("/wheel_cmd",Vector3,queue_size=1)
        self.joy_sub = rospy.Subscriber("joy", Joy, self.remote_cb)
        self.rate = rospy.Rate(100)
        
    def remote_cb(self,message):
        self.speed.x = self.speed_max*(message.axes[1]-message.axes[0])
        self.speed.y = self.speed_max*(message.axes[1]+message.axes[0])
        
        if abs(self.speed.x) < self.threshold:
            self.speed.x = 0
        elif abs(self.speed.y) < self.threshold:
            self.speed.y = 0
    
    def run(self):
        while not rospy.is_shutdown():
            self.wheel_sp_pub.publish(self.speed)
            self.rate.sleep()

if __name__ == "__main__":
    rospy.init_node('llc')
    Teleop = Node()
    Teleop.run()