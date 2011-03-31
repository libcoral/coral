/*
 * Coral - A lightweight C++ component framework
 * See Copyright Notice in Coral.h
 */

#include "ModulePartLoader_Base.h"
#include <co/Coral.h>
#include <co/IComponent.h>
#include <co/IPort.h>
#include <co/IInterface.h>

namespace lua {

void moduleRetain();
void moduleRelease();

// ------ lua.ModulePartLoader provides an interface named 'loader', of type co.IModulePartLoader ------ //

co::IInterface* ModulePartLoader_co_IModulePartLoader::getInterface()
{
	return co::typeOf<co::IModulePartLoader>::get();
}

co::IPort* ModulePartLoader_co_IModulePartLoader::getFacet()
{
	co::IComponent* component = static_cast<co::IComponent*>( co::getType( "lua.ModulePartLoader" ) );
	assert( component );
	co::IPort* facet = static_cast<co::IPort*>( component->getMember( "loader" ) );
	assert( facet );
	return facet;
}

// ------ ModulePartLoader_Base ------ //

ModulePartLoader_Base::ModulePartLoader_Base()
{
	moduleRetain();
}

ModulePartLoader_Base::~ModulePartLoader_Base()
{
	moduleRelease();
}

co::IObject* ModulePartLoader_Base::getProvider()
{
	return this;
}

void ModulePartLoader_Base::serviceRetain()
{
	incrementRefCount();
}

void ModulePartLoader_Base::serviceRelease()
{
	decrementRefCount();
}

co::IComponent* ModulePartLoader_Base::getComponent()
{
	co::IType* type = co::getType( "lua.ModulePartLoader" );
	assert( dynamic_cast<co::IComponent*>( type ) );
	return static_cast<co::IComponent*>( type );
}

co::IService* ModulePartLoader_Base::getService( co::IPort* port )
{
	checkValidPort( port );
	co::IService* res = NULL;
	switch( port->getIndex() )
	{
	case 0:		res = co::disambiguate<co::IService, co::IModulePartLoader>( this ); break;
	default:	raiseUnexpectedPortIndex();
	}
	return res;
}

void ModulePartLoader_Base::setService( co::IPort* receptacle, co::IService* service )
{
	checkValidReceptacle( receptacle );
	raiseUnexpectedPortIndex();
	CORAL_UNUSED( service );
}

} // namespace lua
