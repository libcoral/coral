/*
 * Coral - A lightweight C++ component framework
 * See Copyright Notice in Coral.h
 */

#include "LuaLauncher.h"
#include "LuaState.h"
#include <lua/Exception.h>
#include <sstream>

namespace lua {

Launcher::Launcher()
{
	// empty
}

Launcher::~Launcher()
{
	// empty
}

co::int32 Launcher::main( co::Range<std::string const> args )
{
	if( args.isEmpty() )
		throw lua::Exception( "lua.Launcher must receive a Lua script name as argument" );

	std::string filename;
	if( !LuaState::findScript( LuaState::getL(), args.getFirst(), filename ) )
		CORAL_THROW( lua::Exception, "launch script '" << args.getFirst() << "' could not be found in the path" );

	lua_State* L = LuaState::getL();
	LuaState::loadFile( L, filename );
	
	args.popFirst();
	co::int32 numArgs = static_cast<co::int32>( args.getSize() );

	for( ; args; args.popFirst() )
		LuaState::push( L, args.getFirst() );

	LuaState::call( L, numArgs, 1 );

	int resType = lua_type( L, -1 );
	co::int32 res = static_cast<co::int32>( lua_tointeger( L, -1 ) );
	lua_pop( L, 1 );

	if( resType != LUA_TNIL && resType != LUA_TNUMBER )
		CORAL_THROW( lua::Exception, "launch script '" << args.getFirst() << "' returned an illegal (non-numerical) value" );

	return res;
}

CORAL_EXPORT_COMPONENT( Launcher, Launcher );

} // namespace lua
