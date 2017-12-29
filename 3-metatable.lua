function print_table(t)
	print(t)

	for key, value in pairs(t) do
		print(key, value)
	end
end

--tables
table1 = {
	"item1"
}

table2 = {
	"item2"
}

print("table1, table2: ")
print_table(table1)
print_table(table2)

--metamethod
function add(t1, t2)
	table = { }

	local i = 1
	for key, value in pairs(t1) do
		table[i] = value
		i = i + 1
	end

	for key, value in pairs(t2) do
		table[i] = value
		i = i + 1
	end

	return table
end

--metatable
print()
print("metatable: ")
metatable = {
	__add = add
}
print_table(metatable)

--metatable test
print()
print("table1 + table2: ")
setmetatable(table1, metatable)
print_table(table1 + table2)

print()
print("table2 + table1: ")
print_table(table2 + table1)

print()
print("table1 + table1: ")
print_table(table1 + table1)

print()
print("table2 + table2: should be error ")
print_table(table2 + table2)
