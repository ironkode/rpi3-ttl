#include "ttl.h"

namespace PhysCom
{


void
physical_communication::physical_communication()
{
    // Set Up UART0
    // At bootup, pins 8 and 10 are already set to UART0_TXD, UART0_RXD (ie the alt0 function) respectively

    uart0_filestream = -1; // set to -1 for error reporting


    // OPEN THE UART
    // The flags (defined in fcntl.h):
    //	Access modes (use 1 of these):
    //		O_RDONLY - Open for reading only.
    //		O_RDWR - Open for reading and writing.
    //		O_WRONLY - Open for writing only.
    //
    //	O_NDELAY / O_NONBLOCK (same function) - Enables nonblocking mode. When set read requests on the file can return immediately with a failure status
    //											if there is no input immediately available (instead of blocking). Likewise, write requests can also return
    //											immediately with a failure status if the output can't be written immediately.
    //
    //	O_NOCTTY - When set and path identifies a terminal device, open() shall not cause the terminal device to become the controlling
    //             terminal for the process.

    uart0_filestream = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);

    // Check for errors
    if (uart0_filestream == -1)
    {
        // TODO: Implement error reporting for uart errror
    }

    //CONFIGURE THE UART
    //The flags (defined in /usr/include/termios.h - see http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
    //	Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600,
    //              B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
    //	CSIZE   - CS5, CS6, CS7, CS8
    //	CLOCAL  - Ignore modem status lines
    //	CREAD   - Enable receiver
    //	IGNPAR  - Ignore characters with parity errors
    //	ICRNL   - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
    //	PARENB  - Parity enable
    //	PARODD  - Odd parity (else even)

    struct termios options; // Create struct to hold the config of the uart
    tcgetattr(uart0_filestream, &options);
    options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;		// Use 9600baud for the UART
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(uart0_filestream, TCIFLUSH);
    tcsetattr(uart0_filestream, TCSANOW, &options);

}


physical_communication::~physical_communication()
{
    close(uart0_filestream); // Closes the filestream
    delete[] uart0_filestream;
}


static bool
physical_communication::write_uart(char const *string)
{
    if (uart0_filestream!= -1) // Is filestream open?
    {
        uint8_t result = write(uart0_filestream, string, strlen(string)); // Write(interface, data, number of bytes), using shitty C function sadly enough
        tcdrain(uart0_filestream); // Block buffer untill data is written to uart
        return (result == strlen(string)) ? true : false ; //TODO: maybe some more error reporting
    }
    return false;
     // TODO: Add more error reporting, filestream isn't open
}


char const *
physical_communication::read_uart()
{
    if (uart0_filestream != -1) // Is filestream open?
    {
        unsigned char rx_buffer[256]; // Max data is 255 characters.
        uint8_t rx_length = read(uart0_filestream, rx_buffer, 255);
        if (rx_length < 0)
        {
            return -1; // error reporting, also, probably won't work
            // return -1, an error has occured
        }
        else if (rx_length == 0)
        {
            return -1; // No data waiting
        }
        else
        {
            rx_buffer[rx_length] = '\0'; // end buffer with a termination char
            return rx_buffer;            // return the data read
        }

    }
}
} // End of namespace PhysCom
