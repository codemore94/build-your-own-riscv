#include <femtorv32.h>

void femtosoc_tty_init() {
   uint32_t devices = CONFIGWORDS[CONFIGWORD_DEVICES];
      /* default mode is UART */
   if(devices & CONFIGWORD_DEVICE_SSD1351) {
      /* If OLED screen is configured, redirect output to it */    
      GL_tty_init();
   } else if(devices & CONFIGWORD_DEVICE_MAX7219) {
      /* else if LED matrix is configured, redirect output to it */           
      MAX7219_tty_init();
   }
}
