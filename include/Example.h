#ifndef EXAMPLECLASS_H_
#define EXAMPLECLASS_H_

#include <cstdio>

class ExampleClass
{
public:
    ExampleClass() {}
    virtual ~ExampleClass() {}

    void printBuffer(char* buffer, unsigned int length)
    {
        for (unsigned int i = 0; i < length; ++i)
        {
            printf("%c", buffer[i]);
        }

        printf("\n");
    }
};

#endif
