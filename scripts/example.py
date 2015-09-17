#!/usr/bin/env python

import example_py
import struct

buf = struct.pack('BBBB', 0x41, 0x42, 0x43, 0x44)

print 'python:', buf

e = example_py.ExampleClass()

print 'c++:', e.printBuffer(buf, 4)
