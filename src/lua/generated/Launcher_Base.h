/*
 * Coral - A C++ Component Framework.
 * See Copyright Notice in Coral.h
 */

#ifndef _LUA_LAUNCHER_BASE_H_
#define _LUA_LAUNCHER_BASE_H_

#include <lua/ILauncher.h>
#include <co/reserved/ComponentBase.h>

namespace lua {

//! lua.Launcher provides an interface named 'launcher', of type lua.ILauncher
class Launcher_lua_ILauncher : public lua::ILauncher
{
public:
	virtual co::InterfaceType* getInterfaceType();
	virtual const std::string& getInterfaceName();
};

/*!
	Inherit from this class to implement the component 'lua.Launcher'.
 */
class Launcher_Base : public co::ComponentBase,
	public Launcher_lua_ILauncher
{
public:
	Launcher_Base();
	virtual ~Launcher_Base();

	// co::Interface Methods:
	virtual co::Component* getInterfaceOwner();
	virtual void componentRetain();
	virtual void componentRelease();

	// co::Component Methods:
	virtual co::ComponentType* getComponentType();
	virtual co::Interface* getInterface( co::InterfaceInfo* );
	virtual void bindInterface( co::InterfaceInfo*, co::Interface* );
};

} // namespace lua

#endif // _LUA_LAUNCHER_BASE_H_