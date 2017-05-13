#ifndef TTL_H
#define TTL_H

#include <stdio>
#include <iostream>
#include <unistd>   // Used for UART
#include <fcntl>    // Used for UART
#include <termios>	// Used for UART


namespace PhysCom
{

// ***********************************************************************************
// **                        MAKE UART FOR RPI GREAT AGAIN                          **
// ***********************************************************************************
// **         Truly great class for opening the UART port on the RPi.               **
// ** - once the constructor is called the UART ports on pins 8 and 10 are setup.   **
// ** - The port stays open untill the destructor is called, then it's closed.      **
// ** - Write_uart returns a bool depending on success: 1 is success, 0 is fail.    **
// ** - Read_uart returns a string of max 255 chars, with a \0 termination          **

class physical_communication {
public:
    physical_communication();
    ~physical_communication();
    static bool write_uart(char const *string);
    char const *read_uart();

private:
    int uart0_filestream; // maybe use uint



};
} // end of namespace PhysCom


#endif // TTL_H