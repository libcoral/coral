/*
 * Coral - A lightweight C++ component framework
 * See Copyright Notice in Coral.h
 */

#include <co/SemanticException.h>
#include <co/reserved/ReflectorBase.h>
#include <cassert>

namespace co {

// ------ Reflector Component ------ //

class SemanticException_Reflector : public co::ReflectorBase
{
public:
	SemanticException_Reflector()
	{
		// empty
	}

	virtual ~SemanticException_Reflector()
	{
		// empty
	}

	co::IType* getType()
	{
		return co::typeOf<co::SemanticException>::get();
	}

	co::int32 getSize()
	{
		return sizeof(co::SemanticException);
	}

	void raise( const std::string& message )
	{
		throw co::SemanticException( message );
	}
};

// ------ Reflector Creation Function ------ //

co::IReflector* __createSemanticExceptionReflector()
{
    return new SemanticException_Reflector;
}

} // namespace co
