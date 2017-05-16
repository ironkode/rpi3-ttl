# rpi3-ttl
// ***********************************************************************************
// **                        MAKE UART FOR RPI GREAT AGAIN                          **
// ***********************************************************************************
// **         Truly great class for using the UART port on the RPi.                 **
// **                                                                               **
// ** - once the constructor is called the UART ports on pins 8 and 10 are setup.   **
// ** - The port stays open untill the destructor is called, then it's closed.      **
// ** - Write_uart returns a bool depending on success: 1 is success, 0 is fail.    **
// ** - Read_uart returns a string of max 255 chars, with a \0 termination          **
// **                                                                               **
// ***********************************************************************************
