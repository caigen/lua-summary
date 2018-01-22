#include "lua_sdk.h"
#include <string.h>

struct vector3
{
	float x;
	float y;
	float z;
};

#define LUA_VECTOR3 "vector3"
#define to_vector3(L) ((vector3*)luaL_checkudata(L, 1, LUA_VECTOR3))

static int create(lua_State* L)
{
	float x = (float)luaL_checknumber(L, 1);
	float y = (float)luaL_checknumber(L, 2);
	float z = (float)luaL_checknumber(L, 3);

	vector3* pv = (vector3*)lua_newuserdata(L, sizeof(vector3));
	pv->x = x;
	pv->y = y;
	pv->z = z;
	
	luaL_getmetatable(L, LUA_VECTOR3);
	lua_setmetatable(L, -2);

	return 1;
}

static int Index(lua_State* L)
{
	vector3* pv = to_vector3(L);
	const char* key = lua_tostring(L, 2);

	if (strcmp(key, "x") == 0)
	{
		lua_pushnumber(L, pv->x);
	}
	else if (strcmp(key, "y") == 0)
	{
		lua_pushnumber(L, pv->y);
	}
	else if (strcmp(key, "z") == 0)
	{
		lua_pushnumber(L, pv->z);
	}
	else
	{
		lua_pushnumber(L, 0.0F);
	}

	return 1;
}

static int NewIndex(lua_State* L)
{
	vector3* pv = to_vector3(L);
	const char* key = lua_tostring(L, 2);
	float value = lua_tonumber(L, 3);

	if (strcmp(key, "x") == 0)
	{
		pv->x = value;
		lua_pushboolean(L, true);
	}
	else if (strcmp(key, "y") == 0)
	{
		pv->y = value;
		lua_pushboolean(L, true);
	}
	else if (strcmp(key, "z") == 0)
	{
		pv->z = value;
		lua_pushboolean(L, true);
	}
	else
	{
		lua_pushboolean(L, false);
	}

	return 1;
}

/*
** functions for 'vector3' library
*/
static const luaL_Reg vector3lib[] = 
{
	{"create", create},
	{NULL, NULL}
};

static void create_meta(lua_State* L)
{
	luaL_newmetatable(L, LUA_VECTOR3);

	// set metamethod of metatable
	lua_pushcfunction(L, Index);
	lua_setfield(L, -2, "__index");

	lua_pushcfunction(L, NewIndex);
	lua_setfield(L, -2, "__newindex");

	lua_pop(L, 1);
}

int luaopen_vector3(lua_State* L)
{
	luaL_newlib(L, vector3lib);
	create_meta(L);

	return 1;
}