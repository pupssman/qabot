'''
Created on Dec 26, 2012

@author: pupssman
'''

import nxt


class Sonar:
    def __init__(self, brick):
        self.brick = brick
        self.motor = nxt.motor.Motor(brick, nxt.motor.PORT_A)
        self.sensor = nxt.sensor.Ultrasonic(brick, nxt.sensor.PORT_1)

    def scan(self):
        self.motor.turn(-30, 360)
        for _ in xrange(36):
            self.motor.turn(10, 60)
            self.motor.turn(-10, 50)
            print self.sensor.get_sample()


def main():
    sonar = Sonar(nxt.locator.find_one_brick())
    sonar.scan()

if __name__ == '__main__':
    main()
