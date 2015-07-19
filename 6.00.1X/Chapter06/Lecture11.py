
class Coordinate(object):
    a = 0
    def __init__(self,x,y):
        self.x = x
        self.y = y

    def getX(self):
        # Getter method for a Coordinate object's x coordinate.
        # Getter methods are better practice than just accessing an attribute directly
        return self.x

    def getY(self):
        # Getter method for a Coordinate object's y coordinate
        return self.y

    def __str__(self):
        return '<' + str(self.getX()) + ',' + str(self.getY()) + '>'
        
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
        
    def __repr__(self):
        return 'Coordinate(' + str(self.x) + ', ' + str(self.y) + ')'

'''        
a = Coordinate(3, 5)
print a.x, a.y, a.a 
print Coordinate.a  
print a 
'''

class Queue(object):
    def __init__(self):
        self.vals = []
        
    def insert(self, e):
        self.vals.append(e)
        
    def remove(self):
        try:
            result = self.vals[0]
            self.vals.remove(result)
            return result
        except:
            raise ValueError()
            
class intSet(object):
    """An intSet is a set of integers
    The value is represented by a list of ints, self.vals.
    Each int in the set occurs in self.vals exactly once."""

    def __init__(self):
        """Create an empty set of integers"""
        self.vals = []

    def insert(self, e):
        """Assumes e is an integer and inserts e into self""" 
        if not e in self.vals:
            self.vals.append(e)

    def member(self, e):
        """Assumes e is an integer
           Returns True if e is in self, and False otherwise"""
        return e in self.vals

    def remove(self, e):
        """Assumes e is an integer and removes e from self
           Raises ValueError if e is not in self"""
        try:
            self.vals.remove(e)
        except:
            raise ValueError(str(e) + ' not found')

    def __str__(self):
        """Returns a string representation of self"""
        self.vals.sort()
        return '{' + ','.join([str(e) for e in self.vals]) + '}'
        
    def intersect(self, other):
        result = intSet()
        for e in self.vals:
            if e in other.vals:
                result.insert(e)
        return result
        
    def __len__(self):
        return len(self.vals)


vals = [1, 2, 3, 4]
print [str(e) for e in vals]
print '{' + ','.join([str(e) for e in vals]) + '}'

vals.append(5)
vals.remove(3)
print vals 

