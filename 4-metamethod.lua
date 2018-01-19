--math
function add(t1, t2)
	print("add")
end

function sub(t1, t2)
	print("sub")
end

function mul(t1, t2)
	print("mul")
end

function div(t1, t2)
	print("sub")
end

function unm(t1, t2)
	print("unary_minus")
end

function mod(t1, t2)
	print("modulo")
end

function pow(t1, t2)
	print("pow")
end

--string
function concat(t1, t2)
	print("concat")
end

function tostr(t1, t2)
	print("tostring")
end

--compare
function eq(t1, t2)
	print("equal")
	return true
end

function lt(t1, t2)
	print("less than")
	return false
end

function le(t1, t2)
	print("less than or equal")
	return true
end

--table access
function index(t1, key)
	print("index access: ", key)
end

function newindex(t1, key, value)
	print("newindex update: ", key, value)
end

--metatable
metatable = {
	__add = add,
	__sub = sub,
	__mul = mul,
	__div = div,
	__unm = unm,
	__mod = mod,
	__pow = pow,

	__concat = concat,
	__tostring = tostr,

	__eq = eq,
	__lt = lt,
	__le = le,

	__index = index,
	__newindex = newindex,
}

mytable1 = { }
mytable2 = { }
setmetatable(mytable1, metatable)
setmetatable(mytable2, metatable)

mytable3 = mytable1 + mytable2
mytable3 = mytable1 - mytable2
mytable3 = mytable1 * mytable2
mytable3 = mytable1 / mytable2
mytable3 = -mytable1
mytable3 = mytable1 % mytable2
mytable3 = mytable1 ^ mytable2

print()
mytable3 = mytable1 .. mytable2
str = tostring(mytable1)

print()
local eq = mytable1 == mytable2
local lt = mytable1 < mytable2
local le = mytable1 <= mytable2

print()
local name = mytable1.name
mytable1.name = "init name"
