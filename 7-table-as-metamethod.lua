inner_table = {
	x = 1,
	y = 1,
	z = 1,
	msg = 
		function() 
			return "ok"
		end,
}

metatable = {
	__index = inner_table
}

table1 = { }
setmetatable(table1, metatable)
print(table1.x, table1.y, table1.z, table1.msg, table1:msg())

