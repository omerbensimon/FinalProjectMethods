#pragma once

#include <stdlib.h>
#include "../Painters/BorderPainter.h"
#include "../Painters/singelBorderPainter.h"
#include "../Painters/DoubleBorderPainter.h"
#include "../Painters/NullBorderPainter.h"
#include "../Common/Exceptions.h"

enum class BorderType {
	SINGEL, DOUBLE, NONE
};

class BorderFactory {
public:
	static BorderFactory& getInstance() {
		static BorderFactory factory;
		return factory;
	}

	const BorderPainter& getSingel() {
		return _singel;
	}

	const BorderPainter& getDouble() {
		return _double;
	}

	const BorderPainter& getNull() {
		return _null;
	}

	const BorderPainter& getBorderPainter(BorderType b)
	{
		switch (b) {
		case BorderType::SINGEL:
			return _singel;
		case BorderType::DOUBLE:
			return _double;
		case BorderType::NONE:
			return _null;
		default:
			throw WrongValue();
		}
	}

private:
	//singelton

	BorderFactory() {};

	//border types
	const SingelBorderPainter _singel;
	const DoubleBorderPainter _double;
	const NullBorderPainter _null;

	//exceptions
	class WrongValue : public Exceptions {
	public:
		const char* massage() const {
			return "wrong border type value";
		};
	};

};


