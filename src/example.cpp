#include "Example.h"

int main(int argc, char** argv)
{
    char buf[4];
    buf[0] = 0x41;
    buf[1] = 0x42;
    buf[2] = 0x43;
    buf[3] = 0x44;

    ExampleClass e;
    e.printBuffer(buf, 4);

    return 0;
}
