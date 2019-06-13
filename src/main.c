#include <atmel/port.h>

int main(void)
{
  SystemInit();

  PM->APBBMASK.reg |= PM_APBBMASK_PORT;

  PORT->Group[0].OUTSET.reg = PORT_PA09;
  PORT->Group[0].DIRSET.reg = PORT_PA09;

  while (1) {
    PORT->Group[0].OUTTGL.reg = PORT_PA09;
  }
}
