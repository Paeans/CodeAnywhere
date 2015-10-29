import random
def genEven():
    '''
    Returns a random even number x, where 0 <= x < 100
    '''
    return random.randint(0, 49) * 2
    
def deterministicNumber():
  '''
  Deterministically generates and returns an even number between 9 and 21
  '''
  random.seed(0)
  return random.randint(5, 10) * 2

def stochasticNumber():
    '''
    Stochastically generates and returns a uniformly distributed even number between 9 and 21
    '''
    return int(random.uniform(5, 11)) * 2
    
print(genEven())
print(deterministicNumber())