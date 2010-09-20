/*
 * Coral - A C++ Component Framework.
 * See Copyright Notice in Coral.h
 */

#ifndef _CO_TYPECOMPONENT_BASE_H_
#define _CO_TYPECOMPONENT_BASE_H_

#include <co/Type.h>
#include <co/reserved/ComponentBase.h>

namespace co {

//! co.TypeComponent provides an interface named 'type', of type co.Type
class TypeComponent_co_Type : public co::Type
{
public:
	virtual co::InterfaceType* getInterfaceType();
	virtual const std::string& getInterfaceName();
};

/*!
	Inherit from this class to implement the component 'co.TypeComponent'.
 */
class TypeComponent_Base : public co::ComponentBase,
	public TypeComponent_co_Type
{
public:
	TypeComponent_Base();
	virtual ~TypeComponent_Base();

	// co::Interface Methods:
	virtual co::Component* getInterfaceOwner();
	virtual void componentRetain();
	virtual void componentRelease();

	// co::Component Methods:
	virtual co::ComponentType* getComponentType();
	virtual co::Interface* getInterface( co::InterfaceInfo* );
	virtual void bindInterface( co::InterfaceInfo*, co::Interface* );
};

} // namespace co

#endif // _CO_TYPECOMPONENT_BASE_H_
