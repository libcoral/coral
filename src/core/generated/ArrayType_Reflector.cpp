/*
 * Coral - A lightweight C++ component framework
 * See Copyright Notice in Coral.h
 */

#include <co/reserved/ReflectorBase.h>
#include <cassert>

namespace co {

// The following two functions are implemented by CORAL_EXPORT_COMPONENT()
co::int32 __ArrayType_getSize();
co::IObject* __ArrayType_newInstance();

// ------ Reflector Component ------ //

class ArrayType_Reflector : public co::ReflectorBase
{
public:
	ArrayType_Reflector()
	{
		// empty
	}

	virtual ~ArrayType_Reflector()
	{
		// empty
	}

	co::IType* getType()
	{
		return co::getType( "co.ArrayType" );
	}

	co::int32 getSize()
	{
		return __ArrayType_getSize();
	}

	co::IObject* newInstance()
	{
		co::IObject* component = __ArrayType_newInstance();
		assert( component->getComponentType()->getFullName() == "co.ArrayType" );
		return component;
	}
};

// ------ Reflector Creation Function ------ //

co::IReflector* __createArrayTypeReflector()
{
    return new ArrayType_Reflector;
}

} // namespace co
