#!/usr/bin/env python

import example_py
import struct
import ctypes

buf = struct.pack('BBBB', 0x41, 0x42, 0x43, 0x44)

print 'python:'
print buf

e = example_py.ExampleClass()

print 'c++:'
e.printBuffer(ctypes.cast(ctypes.c_char_p(buf), ctypes.POINTER(ctypes.c_ubyte)), len(buf))
