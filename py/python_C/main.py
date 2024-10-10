from ctypes import *
import platform
import os
import ctypes


if __name__ == "__main__":

    print(platform.architecture())
    # dll = windll.LoadLibrary("D:\\Users\\chenyingtao\\Source\\Repos\\PAT\\py\\python_C\\hello.dll")
    dll = windll.LoadLibrary("D:\\Users\\chenyingtao\\Source\\Repos\\PAT\\py\\python_C\\limp.dll")
    #  Try to locate the .so file in the same directory as this file
    _file = 'method.dll'
    _path = os.path.join(*(os.path.split(__file__)[:-1] + (_file,)))
    _mod = ctypes.cdll.LoadLibrary(_path)
    
    print(_path)    
    print("hello pyton ")
    # print(_mod)

    # func = getattr(dll, "SayHello", None)
    # func = dll.SayHello
    func = dll.HelloDLLC
    if func:
        print(func)
        func()

    # print(dll.f())

    # int gcd(int, int)
    gcd = _mod.gcd
    gcd.argtypes = (ctypes.c_int, ctypes.c_int)
    gcd.restype = ctypes.c_int

    print(gcd(2, 10))


# # int in_mandel(double, double, int)
# in_mandel = _mod.in_mandel
# in_mandel.argtypes = (ctypes.c_double, ctypes.c_double, ctypes.c_int)
# in_mandel.restype = ctypes.c_int

# # int divide(int, int, int *)
# _divide = _mod.divide
# _divide.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int))
# _divide.restype = ctypes.c_int

