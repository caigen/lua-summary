extern "C" {
#include "../sdk/lua/src/lua.h"
#include "../sdk/lua/src/lauxlib.h"
#include "../sdk/lua/src/lualib.h"
};

static int add(lua_State* L)
{
	int a = (int)luaL_checkinteger(L, 1);
	int b = (int)luaL_checkinteger(L, 2);
	
	lua_pushinteger(L, a + b);

	return 1;
}

static const luaL_Reg mathexlib[] = 
{
	{"add", add},
	{NULL, NULL}
};

int luaopen_mathex(lua_State* L)
{
	luaL_newlib(L, mathexlib);

	return 1;
}