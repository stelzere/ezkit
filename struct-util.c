
typedef unsigned char uchar;


/** @brief Sets a field in the structure passed
 *
 *  @param structure Pointer to the structure
 *  @param struct_id Integer id for the structure
 *  @param field_offset Starting offset of the field in the structure, in bytes
 *  @param value Pointer to the value to be set in the field
 *  @param length The length of the value passed, in bytes
 *  @return SUCCESS or ERROR
 */
int
set_struct_field(void *structure,
		 int struct_id, 
		 int field_offset, 
		 void *value, 
		 int length)
{
  if (!structure || !value)
    return ERROR;
      

  memcpy (((uchar *)structure) + field_offset, value, length);
  return 0;
}



/** @brief Gets a field in the structure passed
 *
 *  @param structure Pointer to the structure
 *  @param struct_id Integer id for the structure
 *  @param field_offset Starting offset of the field in the structure, in bytes
 *  @param value Pointer to the value to receive the field value
 *  @param length The length of the field value passed, in bytes
 *  @return SUCCESS or ERROR
 */
int
get_struct_field(void *structure,
		 int struct_id, 
		 int field_offset, 
		 void *value, 
		 int length)
{
  if (!structure || !value)
    return ERROR;

  memcpy (value, ((uchar *)structure) + field_offset, length);
  return 0;
}

