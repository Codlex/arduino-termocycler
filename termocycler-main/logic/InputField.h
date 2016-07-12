/*
 * InputField.h
 *
 *  Created on: Jul 7, 2016
 *      Author: dejanpe
 */

#ifndef TERMOCYCLER_MAIN_LOGIC_INPUTFIELD_H_
#define TERMOCYCLER_MAIN_LOGIC_INPUTFIELD_H_

namespace blah {

class InputField {
public:
	InputField();
	virtual ~InputField();

	bool isValid();
};

} /* namespace blah */

#endif /* TERMOCYCLER_MAIN_LOGIC_INPUTFIELD_H_ */
