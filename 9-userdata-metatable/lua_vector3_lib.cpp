#include "lua_sdk.h"

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

static int GetX(lua_State* L)
{
	vector3* pv = to_vector3(L);

	lua_pushnumber(L, pv->x);
	return 1;
}

static int GetY(lua_State* L)
{
	vector3* pv = to_vector3(L);

	lua_pushnumber(L, pv->y);
	return 1;
}

static int GetZ(lua_State* L)
{
	vector3* pv = to_vector3(L);

	lua_pushnumber(L, pv->z);
	return 1;
}

static int SetX(lua_State* L)
{
	vector3* pv = to_vector3(L);
	pv->x = (float)lua_tonumber(L, 2);

	lua_pushboolean(L, true);
	return 1;
}

static int SetY(lua_State* L)
{
	vector3* pv = to_vector3(L);
	pv->y = (float)lua_tonumber(L, 2);

	lua_pushboolean(L, true);
	return 1;
}

static int SetZ(lua_State* L)
{
	vector3* pv = to_vector3(L);
	pv->z = (float)lua_tonumber(L, 2);

	lua_pushboolean(L, true);
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

/*
** methods for vector3 object
*/
static const luaL_Reg vector3lib_meta[] = 
{
	{"GetX", GetX},
	{"GetY", GetY},
	{"GetZ", GetZ},
	{"SetX", SetX},
	{"SetY", SetY},
	{"SetZ", SetZ},
	{NULL, NULL}
};
  
static void create_meta(lua_State* L)
{
	luaL_newmetatable(L, LUA_VECTOR3);
	lua_pushvalue(L, -1);
	lua_setfield(L, -2, "__index");
	luaL_setfuncs(L, vector3lib_meta, 0);
	lua_pop(L, 1);
}

int luaopen_vector3(lua_State* L)
{
	luaL_newlib(L, vector3lib);
	create_meta(L);

	return 1;
}