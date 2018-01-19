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
		   
	return 1;
}

static int set(lua_State* L)
{
	vector3* pv = (vector3*)lua_touserdata(L, 1);
	pv->x = (float)luaL_checknumber(L, 2);
	pv->y = (float)luaL_checknumber(L, 3);
	pv->z = (float)luaL_checknumber(L, 4);

	return 0;
}

static int get(lua_State* L)
{
	vector3* pv = (vector3*)lua_touserdata(L, 1);
	
	lua_pushnumber(L, pv->x);
	lua_pushnumber(L, pv->y);
	lua_pushnumber(L, pv->z);

	return 3;
}

static int add(lua_State* L)
{
	vector3* pv1 = (vector3*)lua_touserdata(L, 1);
	vector3* pv2 = (vector3*)lua_touserdata(L, 2);

	vector3* pv = (vector3*)lua_newuserdata(L, sizeof(vector3));
	pv->x = pv1->x + pv2->x;
	pv->y = pv1->y + pv2->y;
	pv->z = pv1->z + pv2->z;

	return 1;
}

/*
** functions for 'vector3' library
*/
static const luaL_Reg vector3lib[] = 
{
	{"create", create},
	{"set", set},
	{"get", get},
	{"add", add},
	{NULL, NULL}
};

int luaopen_vector3(lua_State* L)
{
	luaL_newlib(L, vector3lib);

	return 1;
}