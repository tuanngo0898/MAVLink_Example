#include <stdio.h>
#include <fcntl.h>   /* File Control Definitions            */
#include <termios.h> /* POSIX Terminal Control Definitions  */
#include <unistd.h>  /* UNIX Standard Definitions 	        */ 
#include <errno.h>   /* ERROR Number Definitions            */

/* This assumes you have the mavlink headers on your include path
 or in the same folder as this source file */
#include <mavlink.h>

#define SERIAL_PORT         "/dev/ttyS1"    /* Change /dev/ttyUSB0 to the one corresponding to your system */
#define SERIAL_BAUD         B9600

void main(void)
{
    int fd;/*File Descriptor*/
		
    printf("\n +----------------------------------+");
    printf("\n |    Serial Port MAVLink Receive   |");
    printf("\n +----------------------------------+");

    /*------------------------------- Opening the Serial Port -------------------------------*/
    /* O_RDWR   - Read/Write access to serial port        */
    /* O_NOCTTY - No terminal will control the process    */
    /* O_NDELAY - Non Blocking Mode, do not care about the status of DCD line,open() returns immediatly */ 
    fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY | O_NDELAY);	
                                       							
    if(fd == -1)						/* Error Checking */
        printf("\n  Error in opening %s", SERIAL_PORT);
    else
        printf("\n  Open %s successfully", SERIAL_PORT);

	
    /*---------- Setting the Attributes of the serial port using termios structure --------- */
    struct termios SerialPortSettings;	/* Create the structure                          */
    tcgetattr(fd, &SerialPortSettings);	/* Get the current attributes of the Serial port */
    cfsetispeed(&SerialPortSettings,B9600); /* Set Read  Speed as 9600                       */
    cfsetospeed(&SerialPortSettings,B9600); /* Set Write Speed as 9600                       */
    
    SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
    SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
    SerialPortSettings.c_cflag &= ~CSIZE;	 /* Clears the mask for setting the data size             */
    SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */
	
    SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
    SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */ 
		
		
    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */

    SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

	if((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
		printf("\n  ERROR ! in Setting attributes to %s", SERIAL_PORT);
	else
        printf("\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none");
			
	/*------------------------------- Write data to serial port -----------------------------*/

	mavlink_message_t msg;
	mavlink_status_t status;
    int bytes_received = 0;

    char recv_chr;
    int i;
    while(1){
        i = read(fd, &recv_chr, 1);
        if( i==1) bytes_received++;
        if (mavlink_parse_char(MAVLINK_COMM_0, recv_chr, &msg, &status))
	    {
		    printf("\n  Received packet: SYS: %d, COMP: %d, LEN: %d, MSG ID: %d", msg.sysid, msg.compid, msg.len, msg.msgid);
            break;
	    }
    }

    printf("\n  Receive %d bytes from %s", bytes_received, SERIAL_PORT);
    printf("\n");

	close(fd);/* Close the Serial port */
}
