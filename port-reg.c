#define PORT_ENABLE 0x1000

int
set_port_reg(int port_num, int val)
{
  if ((port_num < 0) || 
      (port_num > 31) ||
      (val < 0) ||
      (val > 1)) {
    return -1; // or assert
  }

		       
}
