#pragma once

#include <stdlib.h>
#include "BorderPainter.h"
#include "SingleBorderPainter.h"
#include "DoubleBorderPainter.h"
#include "NullBorderPainter.h"
#include "Exceptions.h"

enum class BorderType {
	sBorderPainter, DOUBLE, NONE
};

class BorderFactory {
public:
	static BorderFactory& getInstance() { // get BorderFactory object
		static BorderFactory factory;
		return factory;
	}

	const BorderPainter& getSBoarderPainter() { // get SingleBorderFactory object
		return sBorderPainter;
	}

	const BorderPainter& getDBorderPainter() { // get DoubleBorderFactory object
		return dBorderPainter;
	}

	const BorderPainter& getNull() { 
		return _null;
	}

	const BorderPainter& getBoarderPainter(BorderType b)
	{
		switch (b) {
		case BorderType::sBorderPainter:
			return sBorderPainter;
		case BorderType::DOUBLE:
			return dBorderPainter;
		case BorderType::NONE:
			return _null;
		default:
			throw WrongValue();
		}
	}

private:
	//sBorderPainterton

	BorderFactory() {};

	//border types
	const sBorderPainterBorderPainter sBorderPainter;
	const DoubleBorderPainter dBorderPainter;
	const NullBorderPainter _null;

	//exceptions
	class WrongValue : public Exceptions {
	public:
		const char* massage() const {
			return "wrong border type value";
		};
	};

};
