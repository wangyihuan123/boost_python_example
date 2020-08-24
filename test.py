from pyTest import  log_detect
from numpy import random

if __name__ == '__main__':
    image = random.random((50,20))   # Test data, (height, width) == (rows, cols)
    ret = log_detect(image)
    print(ret)

