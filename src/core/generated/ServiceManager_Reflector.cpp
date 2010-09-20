/*
 * Coral - A C++ Component Framework.
 * See Copyright Notice in Coral.h
 */

#include <co/ServiceManager.h>
#include <co/DynamicProxyHandler.h>
#include <co/InterfaceType.h>
#include <co/MethodInfo.h>
#include <co/AttributeInfo.h>
#include <co/IllegalCastException.h>
#include <co/MissingInputException.h>
#include <co/IllegalArgumentException.h>
#include <co/reserved/ReflectorBase.h>
#include <sstream>
#include <cassert>

namespace co {

// ------ Proxy Interface ------ //

class ServiceManager_Proxy : public co::ServiceManager
{
public:
	ServiceManager_Proxy( co::DynamicProxyHandler* handler ) : _handler( handler )
	{
		_cookie = _handler->registerProxyInterface( co::disambiguate<co::Interface, co::ServiceManager>( this ) );
	}

	virtual ~ServiceManager_Proxy()
	{
		// empty
	}

	// co::Interface Methods:

	co::InterfaceType* getInterfaceType() { return co::typeOf<co::ServiceManager>::get(); }
	co::Component* getInterfaceOwner() { return _handler->getInterfaceOwner(); }
	const std::string& getInterfaceName() { return _handler->getProxyInterfaceName( _cookie ); }
	void componentRetain() { _handler->componentRetain(); }
	void componentRelease() { _handler->componentRelease(); }

	// co.ServiceManager Methods:

	bool getIsLazy()
	{
		co::Any res;
		_handler->handleGetAttribute( _cookie, getAttribInfo<co::ServiceManager>( 0 ), res );
		assert( res.containsObject() == false );
        return res.get< bool >();
	}

	void setIsLazy( bool __isLazy )
	{
		co::Any arg;
		arg.set< bool >( __isLazy );
		_handler->handleSetAttribute( _cookie, getAttribInfo<co::ServiceManager>( 0 ), arg );
	}

	void addService( co::InterfaceType* __serviceType, co::Interface* __serviceInstance )
	{
		co::Any res, args[2];
		args[0].set< co::InterfaceType* >( __serviceType );
		args[1].set< co::Interface* >( __serviceInstance );
		co::ArrayRange<co::Any const> range( args, 2 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 1 ), range, res );
	}

	void addServiceForType( co::InterfaceType* __serviceType, co::InterfaceType* __clientType, co::Interface* __serviceInstance )
	{
		co::Any res, args[3];
		args[0].set< co::InterfaceType* >( __serviceType );
		args[1].set< co::InterfaceType* >( __clientType );
		args[2].set< co::Interface* >( __serviceInstance );
		co::ArrayRange<co::Any const> range( args, 3 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 2 ), range, res );
	}

	void addServiceImplementation( co::InterfaceType* __serviceType, const std::string& __componentName )
	{
		co::Any res, args[2];
		args[0].set< co::InterfaceType* >( __serviceType );
		args[1].set< const std::string& >( __componentName );
		co::ArrayRange<co::Any const> range( args, 2 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 3 ), range, res );
	}

	void addServiceImplementationForType( co::InterfaceType* __serviceType, co::InterfaceType* __clientType, const std::string& __componentName )
	{
		co::Any res, args[3];
		args[0].set< co::InterfaceType* >( __serviceType );
		args[1].set< co::InterfaceType* >( __clientType );
		args[2].set< const std::string& >( __componentName );
		co::ArrayRange<co::Any const> range( args, 3 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 4 ), range, res );
	}

	co::Interface* getService( co::InterfaceType* __serviceType )
	{
		co::Any res, args[1];
		args[0].set< co::InterfaceType* >( __serviceType );
		co::ArrayRange<co::Any const> range( args, 1 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 5 ), range, res );
		assert( res.containsObject() == false );
		return res.get< co::Interface* >();
	}

	co::Interface* getServiceForInstance( co::InterfaceType* __serviceType, co::Interface* __clientInstance )
	{
		co::Any res, args[2];
		args[0].set< co::InterfaceType* >( __serviceType );
		args[1].set< co::Interface* >( __clientInstance );
		co::ArrayRange<co::Any const> range( args, 2 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 6 ), range, res );
		assert( res.containsObject() == false );
		return res.get< co::Interface* >();
	}

	co::Interface* getServiceForType( co::InterfaceType* __serviceType, co::InterfaceType* __clientType )
	{
		co::Any res, args[2];
		args[0].set< co::InterfaceType* >( __serviceType );
		args[1].set< co::InterfaceType* >( __clientType );
		co::ArrayRange<co::Any const> range( args, 2 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 7 ), range, res );
		assert( res.containsObject() == false );
		return res.get< co::Interface* >();
	}

	void removeService( co::InterfaceType* __serviceType )
	{
		co::Any res, args[1];
		args[0].set< co::InterfaceType* >( __serviceType );
		co::ArrayRange<co::Any const> range( args, 1 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 8 ), range, res );
	}

	void removeServiceForType( co::InterfaceType* __serviceType, co::InterfaceType* __clientType )
	{
		co::Any res, args[2];
		args[0].set< co::InterfaceType* >( __serviceType );
		args[1].set< co::InterfaceType* >( __clientType );
		co::ArrayRange<co::Any const> range( args, 2 );
		_handler->handleMethodInvocation( _cookie, getMethodInfo<co::ServiceManager>( 9 ), range, res );
	}

protected:
	template<typename T>
	co::AttributeInfo* getAttribInfo( co::uint32 index )
	{
		return co::typeOf<T>::get()->getMemberAttributes()[index];
	}

	template<typename T>
	co::MethodInfo* getMethodInfo( co::uint32 index )
	{
		return co::typeOf<T>::get()->getMemberMethods()[index];
	}

private:
	co::DynamicProxyHandler* _handler;
	co::uint32 _cookie;
};

// ------ Reflector ------ //

class ServiceManager_Reflector : public co::ReflectorBase
{
public:
	ServiceManager_Reflector()
	{
		// empty
	}

	virtual ~ServiceManager_Reflector()
	{
		// empty
	}

	co::Type* getType()
	{
		return co::typeOf<co::ServiceManager>::get();
	}

	co::int32 getSize()
	{
		return sizeof(co::ServiceManager);
	}

	co::Interface* newProxy( co::DynamicProxyHandler* handler )
	{
		checValidProxyHandler( handler );
		return co::disambiguate<co::Interface, co::ServiceManager>( new co::ServiceManager_Proxy( handler ) );
	}

	void getAttribute( const co::Any& instance, co::AttributeInfo* ai, co::Any& value )
	{
		co::ServiceManager* p = checkInstance( instance, ai );
		switch( ai->getIndex() )
		{
		case 0:		value.set< bool >( p->getIsLazy() ); break;
		default:	raiseUnexpectedMemberIndex();
		}
	}

	void setAttribute( const co::Any& instance, co::AttributeInfo* ai, const co::Any& value )
	{
		co::ServiceManager* p = checkInstance( instance, ai );
		switch( ai->getIndex() )
		{
		case 0:		p->setIsLazy( value.get< bool >() ); break;
		default:	raiseUnexpectedMemberIndex();
		}
		CORAL_UNUSED( p );
		CORAL_UNUSED( value );
	}

	void invokeMethod( const co::Any& instance, co::MethodInfo* mi, co::ArrayRange<co::Any const> args, co::Any& res )
	{
		co::ServiceManager* p = checkInstance( instance, mi );
		checkNumArguments( mi, args.getSize() );
		int argIndex = -1;
		try
		{
			switch( mi->getIndex() )
			{
			case 1:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					co::Interface* __serviceInstance = args[++argIndex].get< co::Interface* >();
					argIndex = -1;
					p->addService( __serviceType, __serviceInstance );
				}
				break;
			case 2:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					co::InterfaceType* __clientType = args[++argIndex].get< co::InterfaceType* >();
					co::Interface* __serviceInstance = args[++argIndex].get< co::Interface* >();
					argIndex = -1;
					p->addServiceForType( __serviceType, __clientType, __serviceInstance );
				}
				break;
			case 3:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					const std::string& __componentName = args[++argIndex].get< const std::string& >();
					argIndex = -1;
					p->addServiceImplementation( __serviceType, __componentName );
				}
				break;
			case 4:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					co::InterfaceType* __clientType = args[++argIndex].get< co::InterfaceType* >();
					const std::string& __componentName = args[++argIndex].get< const std::string& >();
					argIndex = -1;
					p->addServiceImplementationForType( __serviceType, __clientType, __componentName );
				}
				break;
			case 5:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					argIndex = -1;
					res.set< co::Interface* >( p->getService( __serviceType ) );
				}
				break;
			case 6:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					co::Interface* __clientInstance = args[++argIndex].get< co::Interface* >();
					argIndex = -1;
					res.set< co::Interface* >( p->getServiceForInstance( __serviceType, __clientInstance ) );
				}
				break;
			case 7:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					co::InterfaceType* __clientType = args[++argIndex].get< co::InterfaceType* >();
					argIndex = -1;
					res.set< co::Interface* >( p->getServiceForType( __serviceType, __clientType ) );
				}
				break;
			case 8:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					argIndex = -1;
					p->removeService( __serviceType );
				}
				break;
			case 9:
				{
					co::InterfaceType* __serviceType = args[++argIndex].get< co::InterfaceType* >();
					co::InterfaceType* __clientType = args[++argIndex].get< co::InterfaceType* >();
					argIndex = -1;
					p->removeServiceForType( __serviceType, __clientType );
				}
				break;
			default:
				raiseUnexpectedMemberIndex();
			}
		}
		catch( co::IllegalCastException& e )
		{
			if( argIndex == -1 )
				throw; // just re-throw if the exception is not related to 'args'
			raiseArgumentTypeException( mi, argIndex, e );
		}
		catch( ... )
		{
			throw;
		}
		CORAL_UNUSED( res );
	}

private:
	co::ServiceManager* checkInstance( const co::Any& instance, co::MemberInfo* member )
	{
		if( !member )
			throw co::IllegalArgumentException( "illegal null member info" );

		co::InterfaceType* myType = co::typeOf<co::ServiceManager>::get();

		// make sure that 'instance' is an instance of this type
		if( instance.getKind() != co::TK_INTERFACE ||
			!instance.getInterfaceType()->isSubTypeOf( myType ) ||
			instance.getState().data.ptr == NULL )
			CORAL_THROW( co::IllegalArgumentException, "expected a valid co::ServiceManager*, but got " << instance );

		// make sure that 'member' belongs to this type
		co::CompoundType* owner = member->getOwner();
		if( owner != myType )
			CORAL_THROW( co::IllegalArgumentException, "member '" << member->getName() << "' belongs to "
				<< owner->getFullName() << ", not to " << myType->getFullName() );

		return dynamic_cast<co::ServiceManager*>( instance.getState().data.itf );
	}
};

// ------ Reflector Creation Function ------ //

co::Reflector* __createServiceManagerReflector()
{
    return new ServiceManager_Reflector;
}

} // namespace co
