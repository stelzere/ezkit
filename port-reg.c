#define PORT_ENABLE_REG_ADDR (0x1000)

#define MAX_PORT_NUM (31)

#define ERROR (-1)
#define SUCCESS (0)

typedef unsigned long uint32;



/** @brief Sets the port_enable_reg for a given port_num
 *
 *  @param port_num the switch port number (0 <= port_num <= 31)
 *  @return SUCCESS or ERROR
 */
int
set_port_enable_reg(int port_num)
{

  uint32 volatile * const port_enable_reg = (uint32 *) PORT_ENABLE_REG_ADDR;

  if ((port_num < 0) || 
      (port_num > MAX_PORT_NUM)) {
    return ERROR;
  }

  *port_enable_reg |= (1u << port_num); // need to add lock/unlock if RMW not atomically done

  return SUCCESS;
		       
}



/** @brief Clears the port_enable_reg for a given port_num
 *
 *  @param port_num the switch port number (0 <= port_num <= 31)
 *  @return SUCCESS or ERROR
 */
int
clear_port_enable_reg(int port_num)
{

  uint32 volatile * const port_enable_reg = (uint32 *) PORT_ENABLE_REG_ADDR;

  if ((port_num < 0) || 
      (port_num > MAX_PORT_NUM)) {
    return ERROR;
  }

  *port_enable_reg &= ~(1u << port_num); // need to add lock/unlock if RMW not atomically done


  return SUCCESS;
		       
}

