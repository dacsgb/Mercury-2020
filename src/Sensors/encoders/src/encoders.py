#!/usr/bin/env python

import RPIO

import rospy
from encoders.msg import Counts

class ENCODER():
    def __init__(self,pin):
        self.pin = pin
        self.count = 0
        RPIO.add_interrupt_callback(self.pin, self.callback, edge='rising', pull_up_down=RPIO.PUD_OFF, threaded_callback=True, debounce_timeout_ms=None)
    
    def callback(self):
        self.count += 1

class Node():
    def __init__(self,channel_A,channel_B):
        self.counts_pub = rospy.Publisher('/counts',Counts,queue_size=1)
        self.rate = rospy.Rate(100)
        self.message = Counts()
        self.A = channel_A
        self.B = channel_B

    def fill_msg(self)
        self.message.time = rospy.get_time()
        self.message.A = self.A.count
        self.message.B = self.B.count

    def run(self):
        while not rospy.is_shutdown():
            self.fill_msg()
            self.counts_pub.publish(self.message)
            self.rate.sleep()

if __name__ == '__main__':
    A = ENCODER(12)
    B = ENCODER(13)
    node = Node(A,B)
    node.run()