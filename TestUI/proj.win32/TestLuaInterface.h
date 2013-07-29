#ifndef __TESTLUAINTERFACT_H
#define __TESTLUAINTERFACT_H

#include<stdio.h>
#include"tolua++.h";

class TestLuaInterface
{
public:
	static void staticPrint(const char* msg);
	void print(const char* msg);
};


int tolua_TestLuaInterface_open(lua_State* L);
#endif//__TESTLUAINTERFACT_H