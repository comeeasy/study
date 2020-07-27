import sys as s

print("sys.argv => {0} {1}".format(type(s.argv), s.argv))

for i, val in enumerate(s.argv) :
    print("sys.argv[{0}] => {1}".format(i, val))

''' 결과
    sys.argv => <class 'list'> ['sys-module.py', '1', '2', '3']                         
    sys.argv[0] => sys-module.py                                                        
    sys.argv[1] => 1                                                                    
    sys.argv[2] => 2                                                                    
    sys.argv[3] => 3
'''