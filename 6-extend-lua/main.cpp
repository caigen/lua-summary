#include <stdio.h>

extern "C" {
#include "../sdk/lua/src/lua.h"
#include "../sdk/lua/src/lauxlib.h"
#include "../sdk/lua/src/lualib.h"
};

#include "lua_mathex_lib.h"

// global function
static int log(lua_State* L)
{
	int a = (int)luaL_checkinteger(L, 1);

	printf("[log] %d\n", a);

	lua_pushboolean(L, (int)true);

	return 1;
}

bool run()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	luaL_requiref(L, LUA_MATHEX_LIB_NAME, luaopen_mathex, 1);
	lua_pop(L, 1);

	// global function
	lua_pushcfunction(L, log);
	lua_setglobal(L, "log");

	// module
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