/*
 * Coral - A lightweight C++ component framework
 * See Copyright Notice in Coral.h
 */

#include "Enum_Base.h"
#include <co/Coral.h>
#include <co/IComponent.h>
#include <co/IPort.h>
#include <co/IInterface.h>

namespace co {

// ------ co.Enum provides an interface named 'type', of type co.IEnum ------ //

co::IInterface* Enum_co_IEnum::getInterface()
{
	return co::typeOf<co::IEnum>::get();
}

co::IPort* Enum_co_IEnum::getFacet()
{
	co::IComponent* component = static_cast<co::IComponent*>( co::getType( "co.Enum" ) );
	assert( component );
	co::IPort* facet = static_cast<co::IPort*>( component->getMember( "type" ) );
	assert( facet );
	return facet;
}

// ------ Enum_Base ------ //

Enum_Base::Enum_Base()
{
	// empty
}

Enum_Base::~Enum_Base()
{
	// empty
}

co::IObject* Enum_Base::getProvider()
{
	return this;
}

void Enum_Base::serviceRetain()
{
	incrementRefCount();
}

void Enum_Base::serviceRelease()
{
	decrementRefCount();
}

co::IComponent* Enum_Base::getComponent()
{
	co::IType* type = co::getType( "co.Enum" );
	assert( dynamic_cast<co::IComponent*>( type ) );
	return static_cast<co::IComponent*>( type );
}

co::IService* Enum_Base::getService( co::IPort* port )
{
	checkValidPort( port );
	co::IService* res = NULL;
	switch( port->getIndex() )
	{
	case 0:		res = co::disambiguate<co::IService, co::IEnum>( this ); break;
	default:	raiseUnexpectedPortIndex();
	}
	return res;
}

void Enum_Base::setService( co::IPort* receptacle, co::IService* service )
{
	checkValidReceptacle( receptacle );
	raiseUnexpectedPortIndex();
	CORAL_UNUSED( service );
}

} // namespace co
