--function
print("function")
function sum(...)
	print("unpack{...} :", unpack({...}))

	local s = 0
	for i, v in ipairs{...} do
		s = s + v
	end

	return s
end

s = sum(1, 2, 3)
print("sum(...)", s)


--closure
print()
print("closure")
function counter()
	local num = 0

	return 
		function()
			num = num + 1
			return num
		end
end

c1 = counter()
print(c1, c1(), c1(), c1())

print(counter())
print(counter())
print(counter())
print(counter()(), counter()(), counter()())
