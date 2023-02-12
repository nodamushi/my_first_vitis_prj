#include <xparameters.h>
#include <xgpio.h>

XGpio gpio;

int main()
{
  int status = XGpio_Initialize(&gpio, XPAR_GPIO_0_DEVICE_ID);
  if (status != XST_SUCCESS) {
    return 1;
  }
  XGpio_SetDataDirection(&gpio, 1, 0);
  XGpio_DiscreteWrite(&gpio, 1, 0xFF);
  return 0;
}
