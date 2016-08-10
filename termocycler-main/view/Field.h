/*
 * Field.h
 *
 *  Created on: Aug 2, 2016
 *      Author: dejanpe
 */

#include <stdint.h>

#ifndef TERMOCYCLER_MAIN_VIEW_FIELD_H_
#define TERMOCYCLER_MAIN_VIEW_FIELD_H_

#define newField(thermocycler_p, field_name, value, value_type, x_p, y_p, write_code, writable, validate_p)                       \
  ({                                                                    \
	class              field_name :                                      \
	  public Field                                                           \
	{                                                                   \
	  Thermocycler* thermocycler;                                       \
	  value_type lastValue = (value_type) -113;                                             \
	  bool force = false;												\
	  public:                                                           \
	  field_name(Thermocycler* thermocycler, int x, int y) : Field(x, y) {                            \
         this->thermocycler = thermocycler;                             \
      }                                                                 \
	  void update() {                                            \
    	value_type newValue = value;                             \
        bool isDirty = newValue != lastValue;                    \
        this->lastValue = newValue;                               \
        if (isDirty || this->force) {                                            \
        	this->force = false;									\
        	LCD::getInstance()->printBig(value, this->x, this->y);    \
        }                                                             \
	  }                                                                \
	  void forceRedraw() {												\
		  this->force = true;											\
	  }																	\
      write_code; 														\
      	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  	  \
	  bool isWritable() {												\
		  return writable;												\
	  }																	\
	  validate_p \
	};                                                                  \
	new field_name(thermocycler_p, x_p, y_p);                                               \
  })

#define newStringField(thermocycler_p, field_name, value, x_p, y_p)                      \
  (newField(thermocycler_p, field_name, value, char*, x_p, y_p, virtual void processDigit(int digit){ }  \
   virtual void processDelete() {} , false, bool validate() {}))

#define newReadonlyField(thermocycler_p, field_name, value, value_type, x_p, y_p, min_value, max_value)                       \
  (newField(thermocycler_p, field_name, value, value_type, x_p, y_p, virtual void processDigit(int digit){ }  \
   virtual void processDelete() {} , false, bool validate() {\
       bool isValid = min_value <= value && value <= max_value; \
       if (!isValid) {\
    	   error("ERROR: %d - %d", min_value, max_value); \
       } \
       return isValid; \
   }))

#define newWritableField(thermocycler_p, field_name, value, value_type, x_p, y_p, min_value, max_value)                       \
  (newField(thermocycler_p, field_name, value, value_type, x_p, y_p, virtual void processDigit(int digit){ \
	    int64_t newValue = value;                \
	    newValue *= 10; \
		newValue += digit; \
        if (newValue > 30000) {                                      \
        	error("overflowed");								\
			return;												\
        }                                                        \
		value = newValue; \
   } \
   virtual void processDelete() {\
     value = value / 10; \
   },true, bool validate() {\
       bool isValid = min_value <= value && value <= max_value; \
       if (!isValid) {\
    	   error("ERROR: %d - %d", min_value, max_value); \
       } \
       return isValid; \
   }))


class Field {
public:
	Field(int x, int y);
	virtual ~Field();
	virtual void update() = 0;
	virtual void processDigit(int digit) = 0;
	virtual void forceRedraw() = 0;
	virtual bool isWritable() = 0;
	virtual void processDelete() = 0;
	virtual bool validate() = 0;
protected:
	int x;
	int y;

};

#endif /* TERMOCYCLER_MAIN_VIEW_FIELD_H_ */
