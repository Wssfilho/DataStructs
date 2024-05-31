import math

class Point(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y
        """construtor"""
    def distancia(self, Point):
        dist = math.sqrt((self.x - Point.x)**2 + (self.y - Point.y)**2)
        return dist
    
p1 = Point(4, 9)
p2 = Point(10, 5)
print(p1.distancia(p2))