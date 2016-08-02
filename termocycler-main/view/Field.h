/*
 * Field.h
 *
 *  Created on: Aug 2, 2016
 *      Author: dejanpe
 */

#ifndef TERMOCYCLER_MAIN_VIEW_FIELD_H_
#define TERMOCYCLER_MAIN_VIEW_FIELD_H_

#define newField(thermocycler_p, field_name, value, value_type, x_p, y_p, write_code)                       \
  ({                                                                    \
	class              field_name :                                      \
	  public Field                                                           \
	{                                                                   \
	  Thermocycler* thermocycler;                                       \
	  value_type lastValue = (value_type) -113;                                             \
	  public:                                                           \
	  field_name(Thermocycler* thermocycler, int x, int y) : Field(x, y) {                            \
         this->thermocycler = thermocycler;                             \
      }                                                                 \
	  void update() {                                            \
    	value_type newValue = value;                             \
        bool isDirty = newValue != lastValue;                    \
        this->lastValue = newValue;                               \
        if (isDirty) {                                            \
        	LCD::getInstance()->printBig(value, this->x, this->y);    \
        }                                                             \
	  }                                                                \
      write_code; \
	};                                                                  \
	new field_name(thermocycler_p, x_p, y_p);                                               \
  })

#define newReadonlyField(thermocycler_p, field_name, value, value_type, x_p, y_p)                       \
  (newField(thermocycler_p, field_name, value, value_type, x_p, y_p, virtual void processDigit(int digit){ }))

#define newWritableField(thermocycler_p, field_name, value, value_type, x_p, y_p)                       \
  (newField(thermocycler_p, field_name, value, value_type, x_p, y_p, virtual void processDigit(int digit){ \
		value = value * 10 + digit; \
   }))


class Field {
public:
	Field(int x, int y);
	virtual ~Field();
	virtual void update() = 0;
	virtual void processDigit(int digit) = 0;
protected:
	int x;
	int y;

};

#endif /* TERMOCYCLER_MAIN_VIEW_FIELD_H_ */
