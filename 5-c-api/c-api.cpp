#include <stdio.h>

extern "C" {
#include "../sdk/lua/src/lua.h"
#include "../sdk/lua/src/lauxlib.h"
#include "../sdk/lua/src/lualib.h"
};
   
int add(int a, int b, bool from_lua = false)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_loadfile(L, "main.lua") != LUA_OK
		|| lua_pcall(L, 0, 0, 0) != LUA_OK)
	{
		return 0;
	}

	if (lua_getglobal(L, "add") != LUA_TFUNCTION)
	{
		return 0;
	}

	if (from_lua)
	{
		if (lua_getglobal(L, "a") != LUA_TNUMBER
			|| lua_getglobal(L, "b") != LUA_TNUMBER)
		{
			return 0;
		}
	}
	else
	{
		lua_pushnumber(L, a);
		lua_pushnumber(L, b);
	}

	if (lua_pcall(L, 2, 1, 0) != LUA_OK)
	{
		return 0;
	}
	
	if (!lua_isnumber(L, -1))
	{
		return 0;
	}

	int result = (int)lua_tointeger(L, -1);
	lua_pop(L, 1);

	return result;
}

int main(int argc, char* argv[])
{
	printf("1 + 1 = %d \n", add(1, 1));
	printf("args from lua = %d \n", add(0, 0, true));

	return 0;
}