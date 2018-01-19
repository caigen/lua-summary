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
	__index = inner_table,
	__newindex = inner_table,
}

table1 = { }
setmetatable(table1, metatable)
print(table1, table1.x, table1.y, table1.z, table1.msg, table1:msg())

table2 = { }
setmetatable(table2, metatable)
print(table2, table2.x, table2.y, table2.z, table2.msg, table2:msg())

print("change table1 only")
table1.x = 2
table1.y = 2
table1.z = 2
table1.msg = 
	function()
		return "updated"
	end

print(table1, table1.x, table1.y, table1.z, table1.msg, table1:msg())
print(table2, table2.x, table2.y, table2.z, table2.msg, table2:msg())
