// Generated by Haxe 4.1.5
#include <hxcpp.h>

#ifndef INCLUDED_lime_app_Application
#include <lime/app/Application.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
#endif
#ifndef INCLUDED_lime_app_Module
#include <lime/app/Module.h>
#endif
#ifndef INCLUDED_lime_app__Event_Dynamic_Void
#include <lime/app/_Event_Dynamic_Void.h>
#endif
#ifndef INCLUDED_lime_app__Event_Int_Void
#include <lime/app/_Event_Int_Void.h>
#endif
#ifndef INCLUDED_lime_system_ThreadPool
#include <lime/system/ThreadPool.h>
#endif
#ifndef INCLUDED_lime_system__ThreadPool_ThreadPoolMessage
#include <lime/system/_ThreadPool/ThreadPoolMessage.h>
#endif
#ifndef INCLUDED_lime_system__ThreadPool_ThreadPoolMessageType
#include <lime/system/_ThreadPool/ThreadPoolMessageType.h>
#endif
#ifndef INCLUDED_lime_ui_Window
#include <lime/ui/Window.h>
#endif
#ifndef INCLUDED_sys_thread_Deque
#include <sys/thread/Deque.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_b98885ed80fb7e2e_22_new,"lime.system.ThreadPool","new",0xfea2d35e,"lime.system.ThreadPool.new","lime/system/ThreadPool.hx",22,0x8993fbb2)
HX_LOCAL_STACK_FRAME(_hx_pos_b98885ed80fb7e2e_73_queue,"lime.system.ThreadPool","queue",0xd03ecc0f,"lime.system.ThreadPool.queue","lime/system/ThreadPool.hx",73,0x8993fbb2)
HX_LOCAL_STACK_FRAME(_hx_pos_b98885ed80fb7e2e_100_sendComplete,"lime.system.ThreadPool","sendComplete",0x5f287f63,"lime.system.ThreadPool.sendComplete","lime/system/ThreadPool.hx",100,0x8993fbb2)
HX_LOCAL_STACK_FRAME(_hx_pos_b98885ed80fb7e2e_113_sendError,"lime.system.ThreadPool","sendError",0xc461dede,"lime.system.ThreadPool.sendError","lime/system/ThreadPool.hx",113,0x8993fbb2)
HX_LOCAL_STACK_FRAME(_hx_pos_b98885ed80fb7e2e_126_sendProgress,"lime.system.ThreadPool","sendProgress",0x658b7657,"lime.system.ThreadPool.sendProgress","lime/system/ThreadPool.hx",126,0x8993fbb2)
HX_LOCAL_STACK_FRAME(_hx_pos_b98885ed80fb7e2e_139_runWork,"lime.system.ThreadPool","runWork",0xbaf970ba,"lime.system.ThreadPool.runWork","lime/system/ThreadPool.hx",139,0x8993fbb2)
HX_LOCAL_STACK_FRAME(_hx_pos_b98885ed80fb7e2e_156___doWork,"lime.system.ThreadPool","__doWork",0xcfdf765e,"lime.system.ThreadPool.__doWork","lime/system/ThreadPool.hx",156,0x8993fbb2)
HX_LOCAL_STACK_FRAME(_hx_pos_b98885ed80fb7e2e_173___update,"lime.system.ThreadPool","__update",0x37e4556b,"lime.system.ThreadPool.__update","lime/system/ThreadPool.hx",173,0x8993fbb2)
namespace lime{
namespace _hx_system{

void ThreadPool_obj::__construct(::hx::Null< int >  __o_minThreads,::hx::Null< int >  __o_maxThreads){
            		int minThreads = __o_minThreads.Default(0);
            		int maxThreads = __o_maxThreads.Default(1);
            	HX_GC_STACKFRAME(&_hx_pos_b98885ed80fb7e2e_22_new)
HXLINE(  38)		this->_hx___workResult =  ::sys::thread::Deque_obj::__alloc( HX_CTX );
HXLINE(  36)		this->_hx___workIncoming =  ::sys::thread::Deque_obj::__alloc( HX_CTX );
HXLINE(  31)		this->onRun =  ::lime::app::_Event_Dynamic_Void_obj::__alloc( HX_CTX );
HXLINE(  30)		this->onProgress =  ::lime::app::_Event_Dynamic_Void_obj::__alloc( HX_CTX );
HXLINE(  29)		this->onError =  ::lime::app::_Event_Dynamic_Void_obj::__alloc( HX_CTX );
HXLINE(  28)		this->onComplete =  ::lime::app::_Event_Dynamic_Void_obj::__alloc( HX_CTX );
HXLINE(  25)		this->doWork =  ::lime::app::_Event_Dynamic_Void_obj::__alloc( HX_CTX );
HXLINE(  43)		this->minThreads = minThreads;
HXLINE(  44)		this->maxThreads = maxThreads;
HXLINE(  46)		this->currentThreads = 0;
HXLINE(  49)		this->_hx___workQueued = 0;
HXLINE(  50)		this->_hx___workCompleted = 0;
            	}

Dynamic ThreadPool_obj::__CreateEmpty() { return new ThreadPool_obj; }

void *ThreadPool_obj::_hx_vtable = 0;

Dynamic ThreadPool_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< ThreadPool_obj > _hx_result = new ThreadPool_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool ThreadPool_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6de8922a;
}

void ThreadPool_obj::queue( ::Dynamic state){
            	HX_GC_STACKFRAME(&_hx_pos_b98885ed80fb7e2e_73_queue)
HXDLIN(  73)		bool _hx_tmp;
HXDLIN(  73)		bool _hx_tmp1;
HXDLIN(  73)		if (::hx::IsNotNull( ::lime::app::Application_obj::current )) {
HXDLIN(  73)			_hx_tmp1 = ::hx::IsNotNull( ::lime::app::Application_obj::current->_hx___window );
            		}
            		else {
HXDLIN(  73)			_hx_tmp1 = false;
            		}
HXDLIN(  73)		if (_hx_tmp1) {
HXDLIN(  73)			_hx_tmp = !(this->_hx___synchronous);
            		}
            		else {
HXDLIN(  73)			_hx_tmp = false;
            		}
HXDLIN(  73)		if (_hx_tmp) {
HXLINE(  75)			 ::sys::thread::Deque _hx_tmp = this->_hx___workIncoming;
HXDLIN(  75)			_hx_tmp->add( ::lime::_hx_system::_ThreadPool::ThreadPoolMessage_obj::__alloc( HX_CTX ,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::WORK_dyn(),state));
HXLINE(  76)			this->_hx___workQueued++;
HXLINE(  78)			bool _hx_tmp1;
HXDLIN(  78)			if ((this->currentThreads < this->maxThreads)) {
HXLINE(  78)				_hx_tmp1 = (this->currentThreads < (this->_hx___workQueued - this->_hx___workCompleted));
            			}
            			else {
HXLINE(  78)				_hx_tmp1 = false;
            			}
HXDLIN(  78)			if (_hx_tmp1) {
HXLINE(  80)				this->currentThreads++;
HXLINE(  81)				 ::Dynamic this1 =  ::__hxcpp_thread_create(this->_hx___doWork_dyn());
            			}
HXLINE(  84)			if (!(::lime::app::Application_obj::current->onUpdate->has(this->_hx___update_dyn()))) {
HXLINE(  86)				::lime::app::Application_obj::current->onUpdate->add(this->_hx___update_dyn(),null(),null());
            			}
            		}
            		else {
HXLINE(  91)			this->_hx___synchronous = true;
HXLINE(  92)			this->runWork(state);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ThreadPool_obj,queue,(void))

void ThreadPool_obj::sendComplete( ::Dynamic state){
            	HX_GC_STACKFRAME(&_hx_pos_b98885ed80fb7e2e_100_sendComplete)
HXLINE( 102)		if (!(this->_hx___synchronous)) {
HXLINE( 104)			 ::sys::thread::Deque _hx_tmp = this->_hx___workResult;
HXDLIN( 104)			_hx_tmp->add( ::lime::_hx_system::_ThreadPool::ThreadPoolMessage_obj::__alloc( HX_CTX ,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::COMPLETE_dyn(),state));
HXLINE( 105)			return;
            		}
HXLINE( 109)		this->onComplete->dispatch(state);
            	}


HX_DEFINE_DYNAMIC_FUNC1(ThreadPool_obj,sendComplete,(void))

void ThreadPool_obj::sendError( ::Dynamic state){
            	HX_GC_STACKFRAME(&_hx_pos_b98885ed80fb7e2e_113_sendError)
HXLINE( 115)		if (!(this->_hx___synchronous)) {
HXLINE( 117)			 ::sys::thread::Deque _hx_tmp = this->_hx___workResult;
HXDLIN( 117)			_hx_tmp->add( ::lime::_hx_system::_ThreadPool::ThreadPoolMessage_obj::__alloc( HX_CTX ,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::ERROR_dyn(),state));
HXLINE( 118)			return;
            		}
HXLINE( 122)		this->onError->dispatch(state);
            	}


HX_DEFINE_DYNAMIC_FUNC1(ThreadPool_obj,sendError,(void))

void ThreadPool_obj::sendProgress( ::Dynamic state){
            	HX_GC_STACKFRAME(&_hx_pos_b98885ed80fb7e2e_126_sendProgress)
HXLINE( 128)		if (!(this->_hx___synchronous)) {
HXLINE( 130)			 ::sys::thread::Deque _hx_tmp = this->_hx___workResult;
HXDLIN( 130)			_hx_tmp->add( ::lime::_hx_system::_ThreadPool::ThreadPoolMessage_obj::__alloc( HX_CTX ,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::PROGRESS_dyn(),state));
HXLINE( 131)			return;
            		}
HXLINE( 135)		this->onProgress->dispatch(state);
            	}


HX_DEFINE_DYNAMIC_FUNC1(ThreadPool_obj,sendProgress,(void))

void ThreadPool_obj::runWork( ::Dynamic state){
            	HX_GC_STACKFRAME(&_hx_pos_b98885ed80fb7e2e_139_runWork)
HXLINE( 141)		if (!(this->_hx___synchronous)) {
HXLINE( 143)			 ::sys::thread::Deque _hx_tmp = this->_hx___workResult;
HXDLIN( 143)			_hx_tmp->add( ::lime::_hx_system::_ThreadPool::ThreadPoolMessage_obj::__alloc( HX_CTX ,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::WORK_dyn(),state));
HXLINE( 144)			this->doWork->dispatch(state);
HXLINE( 145)			return;
            		}
HXLINE( 149)		this->onRun->dispatch(state);
HXLINE( 150)		this->doWork->dispatch(state);
            	}


HX_DEFINE_DYNAMIC_FUNC1(ThreadPool_obj,runWork,(void))

void ThreadPool_obj::_hx___doWork(){
            	HX_STACKFRAME(&_hx_pos_b98885ed80fb7e2e_156___doWork)
HXDLIN( 156)		while(true){
HXLINE( 158)			 ::lime::_hx_system::_ThreadPool::ThreadPoolMessage message = this->_hx___workIncoming->pop(true).StaticCast<  ::lime::_hx_system::_ThreadPool::ThreadPoolMessage >();
HXLINE( 160)			if (::hx::IsEq( message->type,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::WORK_dyn() )) {
HXLINE( 162)				this->runWork(message->state);
            			}
            			else {
HXLINE( 164)				if (::hx::IsEq( message->type,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::EXIT_dyn() )) {
HXLINE( 166)					goto _hx_goto_6;
            				}
            			}
            		}
            		_hx_goto_6:;
            	}


HX_DEFINE_DYNAMIC_FUNC0(ThreadPool_obj,_hx___doWork,(void))

void ThreadPool_obj::_hx___update(int deltaTime){
            	HX_GC_STACKFRAME(&_hx_pos_b98885ed80fb7e2e_173___update)
HXDLIN( 173)		if ((this->_hx___workQueued > this->_hx___workCompleted)) {
HXLINE( 175)			 ::lime::_hx_system::_ThreadPool::ThreadPoolMessage message = this->_hx___workResult->pop(false).StaticCast<  ::lime::_hx_system::_ThreadPool::ThreadPoolMessage >();
HXLINE( 177)			while(::hx::IsNotNull( message )){
HXLINE( 179)				switch((int)(message->type->_hx_getIndex())){
            					case (int)0: case (int)1: {
HXLINE( 188)						this->_hx___workCompleted++;
HXLINE( 190)						bool _hx_tmp;
HXDLIN( 190)						bool _hx_tmp1;
HXDLIN( 190)						if ((this->currentThreads > (this->_hx___workQueued - this->_hx___workCompleted))) {
HXLINE( 190)							_hx_tmp1 = (this->currentThreads > this->minThreads);
            						}
            						else {
HXLINE( 190)							_hx_tmp1 = false;
            						}
HXDLIN( 190)						if (!(_hx_tmp1)) {
HXLINE( 190)							_hx_tmp = (this->currentThreads > this->maxThreads);
            						}
            						else {
HXLINE( 190)							_hx_tmp = true;
            						}
HXDLIN( 190)						if (_hx_tmp) {
HXLINE( 193)							this->currentThreads--;
HXLINE( 194)							 ::sys::thread::Deque _hx_tmp = this->_hx___workIncoming;
HXDLIN( 194)							_hx_tmp->add( ::lime::_hx_system::_ThreadPool::ThreadPoolMessage_obj::__alloc( HX_CTX ,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::EXIT_dyn(),null()));
            						}
HXLINE( 197)						if (::hx::IsEq( message->type,::lime::_hx_system::_ThreadPool::ThreadPoolMessageType_obj::COMPLETE_dyn() )) {
HXLINE( 199)							this->onComplete->dispatch(message->state);
            						}
            						else {
HXLINE( 203)							this->onError->dispatch(message->state);
            						}
            					}
            					break;
            					case (int)3: {
HXLINE( 185)						this->onProgress->dispatch(message->state);
            					}
            					break;
            					case (int)4: {
HXLINE( 182)						this->onRun->dispatch(message->state);
            					}
            					break;
            					default:{
            					}
            				}
HXLINE( 209)				message = this->_hx___workResult->pop(false).StaticCast<  ::lime::_hx_system::_ThreadPool::ThreadPoolMessage >();
            			}
            		}
            		else {
HXLINE( 216)			bool _hx_tmp;
HXDLIN( 216)			bool _hx_tmp1;
HXDLIN( 216)			if ((this->currentThreads == 0)) {
HXLINE( 216)				_hx_tmp1 = (this->minThreads <= 0);
            			}
            			else {
HXLINE( 216)				_hx_tmp1 = false;
            			}
HXDLIN( 216)			if (_hx_tmp1) {
HXLINE( 216)				_hx_tmp = ::hx::IsNotNull( ::lime::app::Application_obj::current );
            			}
            			else {
HXLINE( 216)				_hx_tmp = false;
            			}
HXDLIN( 216)			if (_hx_tmp) {
HXLINE( 218)				::lime::app::Application_obj::current->onUpdate->remove(this->_hx___update_dyn());
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ThreadPool_obj,_hx___update,(void))


::hx::ObjectPtr< ThreadPool_obj > ThreadPool_obj::__new(::hx::Null< int >  __o_minThreads,::hx::Null< int >  __o_maxThreads) {
	::hx::ObjectPtr< ThreadPool_obj > __this = new ThreadPool_obj();
	__this->__construct(__o_minThreads,__o_maxThreads);
	return __this;
}

::hx::ObjectPtr< ThreadPool_obj > ThreadPool_obj::__alloc(::hx::Ctx *_hx_ctx,::hx::Null< int >  __o_minThreads,::hx::Null< int >  __o_maxThreads) {
	ThreadPool_obj *__this = (ThreadPool_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(ThreadPool_obj), true, "lime.system.ThreadPool"));
	*(void **)__this = ThreadPool_obj::_hx_vtable;
	__this->__construct(__o_minThreads,__o_maxThreads);
	return __this;
}

ThreadPool_obj::ThreadPool_obj()
{
}

void ThreadPool_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ThreadPool);
	HX_MARK_MEMBER_NAME(currentThreads,"currentThreads");
	HX_MARK_MEMBER_NAME(doWork,"doWork");
	HX_MARK_MEMBER_NAME(maxThreads,"maxThreads");
	HX_MARK_MEMBER_NAME(minThreads,"minThreads");
	HX_MARK_MEMBER_NAME(onComplete,"onComplete");
	HX_MARK_MEMBER_NAME(onError,"onError");
	HX_MARK_MEMBER_NAME(onProgress,"onProgress");
	HX_MARK_MEMBER_NAME(onRun,"onRun");
	HX_MARK_MEMBER_NAME(_hx___synchronous,"__synchronous");
	HX_MARK_MEMBER_NAME(_hx___workCompleted,"__workCompleted");
	HX_MARK_MEMBER_NAME(_hx___workIncoming,"__workIncoming");
	HX_MARK_MEMBER_NAME(_hx___workQueued,"__workQueued");
	HX_MARK_MEMBER_NAME(_hx___workResult,"__workResult");
	HX_MARK_END_CLASS();
}

void ThreadPool_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(currentThreads,"currentThreads");
	HX_VISIT_MEMBER_NAME(doWork,"doWork");
	HX_VISIT_MEMBER_NAME(maxThreads,"maxThreads");
	HX_VISIT_MEMBER_NAME(minThreads,"minThreads");
	HX_VISIT_MEMBER_NAME(onComplete,"onComplete");
	HX_VISIT_MEMBER_NAME(onError,"onError");
	HX_VISIT_MEMBER_NAME(onProgress,"onProgress");
	HX_VISIT_MEMBER_NAME(onRun,"onRun");
	HX_VISIT_MEMBER_NAME(_hx___synchronous,"__synchronous");
	HX_VISIT_MEMBER_NAME(_hx___workCompleted,"__workCompleted");
	HX_VISIT_MEMBER_NAME(_hx___workIncoming,"__workIncoming");
	HX_VISIT_MEMBER_NAME(_hx___workQueued,"__workQueued");
	HX_VISIT_MEMBER_NAME(_hx___workResult,"__workResult");
}

::hx::Val ThreadPool_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"onRun") ) { return ::hx::Val( onRun ); }
		if (HX_FIELD_EQ(inName,"queue") ) { return ::hx::Val( queue_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"doWork") ) { return ::hx::Val( doWork ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { return ::hx::Val( onError ); }
		if (HX_FIELD_EQ(inName,"runWork") ) { return ::hx::Val( runWork_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__doWork") ) { return ::hx::Val( _hx___doWork_dyn() ); }
		if (HX_FIELD_EQ(inName,"__update") ) { return ::hx::Val( _hx___update_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sendError") ) { return ::hx::Val( sendError_dyn() ); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxThreads") ) { return ::hx::Val( maxThreads ); }
		if (HX_FIELD_EQ(inName,"minThreads") ) { return ::hx::Val( minThreads ); }
		if (HX_FIELD_EQ(inName,"onComplete") ) { return ::hx::Val( onComplete ); }
		if (HX_FIELD_EQ(inName,"onProgress") ) { return ::hx::Val( onProgress ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__workQueued") ) { return ::hx::Val( _hx___workQueued ); }
		if (HX_FIELD_EQ(inName,"__workResult") ) { return ::hx::Val( _hx___workResult ); }
		if (HX_FIELD_EQ(inName,"sendComplete") ) { return ::hx::Val( sendComplete_dyn() ); }
		if (HX_FIELD_EQ(inName,"sendProgress") ) { return ::hx::Val( sendProgress_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"__synchronous") ) { return ::hx::Val( _hx___synchronous ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"currentThreads") ) { return ::hx::Val( currentThreads ); }
		if (HX_FIELD_EQ(inName,"__workIncoming") ) { return ::hx::Val( _hx___workIncoming ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"__workCompleted") ) { return ::hx::Val( _hx___workCompleted ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val ThreadPool_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"onRun") ) { onRun=inValue.Cast<  ::lime::app::_Event_Dynamic_Void >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"doWork") ) { doWork=inValue.Cast<  ::lime::app::_Event_Dynamic_Void >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { onError=inValue.Cast<  ::lime::app::_Event_Dynamic_Void >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"maxThreads") ) { maxThreads=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"minThreads") ) { minThreads=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onComplete") ) { onComplete=inValue.Cast<  ::lime::app::_Event_Dynamic_Void >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onProgress") ) { onProgress=inValue.Cast<  ::lime::app::_Event_Dynamic_Void >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__workQueued") ) { _hx___workQueued=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__workResult") ) { _hx___workResult=inValue.Cast<  ::sys::thread::Deque >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"__synchronous") ) { _hx___synchronous=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"currentThreads") ) { currentThreads=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__workIncoming") ) { _hx___workIncoming=inValue.Cast<  ::sys::thread::Deque >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"__workCompleted") ) { _hx___workCompleted=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ThreadPool_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("currentThreads",30,6b,26,61));
	outFields->push(HX_("doWork",fc,a6,00,1f));
	outFields->push(HX_("maxThreads",25,70,b6,bd));
	outFields->push(HX_("minThreads",f7,42,49,19));
	outFields->push(HX_("onComplete",f8,d4,7e,5d));
	outFields->push(HX_("onError",29,6a,67,09));
	outFields->push(HX_("onProgress",ec,cb,e1,63));
	outFields->push(HX_("onRun",6c,7b,6e,32));
	outFields->push(HX_("__synchronous",69,35,be,7d));
	outFields->push(HX_("__workCompleted",5a,76,64,29));
	outFields->push(HX_("__workIncoming",f7,3a,04,52));
	outFields->push(HX_("__workQueued",84,f5,b2,ef));
	outFields->push(HX_("__workResult",ae,0c,e6,28));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo ThreadPool_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(ThreadPool_obj,currentThreads),HX_("currentThreads",30,6b,26,61)},
	{::hx::fsObject /*  ::lime::app::_Event_Dynamic_Void */ ,(int)offsetof(ThreadPool_obj,doWork),HX_("doWork",fc,a6,00,1f)},
	{::hx::fsInt,(int)offsetof(ThreadPool_obj,maxThreads),HX_("maxThreads",25,70,b6,bd)},
	{::hx::fsInt,(int)offsetof(ThreadPool_obj,minThreads),HX_("minThreads",f7,42,49,19)},
	{::hx::fsObject /*  ::lime::app::_Event_Dynamic_Void */ ,(int)offsetof(ThreadPool_obj,onComplete),HX_("onComplete",f8,d4,7e,5d)},
	{::hx::fsObject /*  ::lime::app::_Event_Dynamic_Void */ ,(int)offsetof(ThreadPool_obj,onError),HX_("onError",29,6a,67,09)},
	{::hx::fsObject /*  ::lime::app::_Event_Dynamic_Void */ ,(int)offsetof(ThreadPool_obj,onProgress),HX_("onProgress",ec,cb,e1,63)},
	{::hx::fsObject /*  ::lime::app::_Event_Dynamic_Void */ ,(int)offsetof(ThreadPool_obj,onRun),HX_("onRun",6c,7b,6e,32)},
	{::hx::fsBool,(int)offsetof(ThreadPool_obj,_hx___synchronous),HX_("__synchronous",69,35,be,7d)},
	{::hx::fsInt,(int)offsetof(ThreadPool_obj,_hx___workCompleted),HX_("__workCompleted",5a,76,64,29)},
	{::hx::fsObject /*  ::sys::thread::Deque */ ,(int)offsetof(ThreadPool_obj,_hx___workIncoming),HX_("__workIncoming",f7,3a,04,52)},
	{::hx::fsInt,(int)offsetof(ThreadPool_obj,_hx___workQueued),HX_("__workQueued",84,f5,b2,ef)},
	{::hx::fsObject /*  ::sys::thread::Deque */ ,(int)offsetof(ThreadPool_obj,_hx___workResult),HX_("__workResult",ae,0c,e6,28)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *ThreadPool_obj_sStaticStorageInfo = 0;
#endif

static ::String ThreadPool_obj_sMemberFields[] = {
	HX_("currentThreads",30,6b,26,61),
	HX_("doWork",fc,a6,00,1f),
	HX_("maxThreads",25,70,b6,bd),
	HX_("minThreads",f7,42,49,19),
	HX_("onComplete",f8,d4,7e,5d),
	HX_("onError",29,6a,67,09),
	HX_("onProgress",ec,cb,e1,63),
	HX_("onRun",6c,7b,6e,32),
	HX_("__synchronous",69,35,be,7d),
	HX_("__workCompleted",5a,76,64,29),
	HX_("__workIncoming",f7,3a,04,52),
	HX_("__workQueued",84,f5,b2,ef),
	HX_("__workResult",ae,0c,e6,28),
	HX_("queue",91,8d,ea,5d),
	HX_("sendComplete",21,d2,84,c0),
	HX_("sendError",60,89,99,33),
	HX_("sendProgress",15,c9,e7,c6),
	HX_("runWork",bc,16,3a,dc),
	HX_("__doWork",1c,12,30,c7),
	HX_("__update",29,f1,34,2f),
	::String(null()) };

::hx::Class ThreadPool_obj::__mClass;

void ThreadPool_obj::__register()
{
	ThreadPool_obj _hx_dummy;
	ThreadPool_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("lime.system.ThreadPool",6c,8c,6a,1a);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(ThreadPool_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< ThreadPool_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ThreadPool_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ThreadPool_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace system
