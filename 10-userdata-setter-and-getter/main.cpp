#include <stdio.h>

#include "lua_sdk.h"
#include "lua_vector3_lib.h"

bool run()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	luaL_requiref(L, LUA_VECTOR3_LIB_NAME, luaopen_vector3, 1);
	lua_pop(L, 1);

	if (luaL_loadfile(L, "main.lua") != LUA_OK
		|| lua_pcall(L, 0, 0, 0) != LUA_OK)
	{
		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	run();

	return 0;
}