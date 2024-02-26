#include "syscall.h"

#define CONSOLE_INPUT 0
#define CONSOLE_OUTPUT 1

int len(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

int main()
{
    char *Content;
    int SocketID1, result;
    Content = "Hello Socket!\n";
    SocketID1 = SocketTCP();
    result = Connect(SocketID1, "127.0.0.1", 8081);
    Send(SocketID1, Content, len(Content));
    Receive(SocketID1, Content, len(Content));
    Write(Content,len(Content),CONSOLE_OUTPUT);
    // Read(Content, len(Content), SocketID1);
    // Write(Content, len(Content), CONSOLE_OUTPUT);
    // Close(SocketID1);
    Halt();
}