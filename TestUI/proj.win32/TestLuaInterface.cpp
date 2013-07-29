#include "TestLuaInterface.h"
#include<stdio.h>

extern "C"{
#include "tolua++.h"
#include "tolua_fix.h"
}

void TestLuaInterface::print(const char* msg)
{
	printf("TestLuaInterface print: %s", msg);
}
void TestLuaInterface::staticPrint(const char* msg)
{
	printf("staticPrint %s", msg);
}


int tolua_TestLuaInterface_print(lua_State* L)
{
	TestLuaInterface* o = (TestLuaInterface*) tolua_tousertype(L, 1, NULL);
	char* msg = (char*) tolua_tousertype(L, 2, NULL);
	if(o && msg)
	{
		o->print(msg);
	}
	return 1;
}

int tolua_TestLuaInterface_staticPrint(lua_State* L)
{
	return 1;
	char* msg = (char*) tolua_tousertype(L, 2, NULL);
	if(msg)
	{
		TestLuaInterface::staticPrint(msg);
	}
	else
	{
		printf("msg is null");
	}
	return 1;
}

TOLUA_API int tolua_TestLuaInterface_open(lua_State* L)
{
	tolua_open(L);
	tolua_usertype(L, "TestLuaInterface");
	tolua_module(L, NULL, 0);

	tolua_beginmodule(L,NULL);
		tolua_cclass(L, "TestLuaInterface", "TestLuaInterface", "", NULL);
		tolua_beginmodule(L,"TestLuaInterface");
			tolua_function(L, "print", tolua_TestLuaInterface_print);
			tolua_function(L, "staticPrint", tolua_TestLuaInterface_staticPrint);
		tolua_endmodule(L);
	tolua_endmodule(L);
	return 1;
}
