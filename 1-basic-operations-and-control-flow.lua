a = 1.0
b = 2.0
print(a, b)

--math
print()
print("math: + - * / ^ %")
print(a + b, a - b, a * b, a / b, a ^ b, a % b)

--compare
print()
print("compare: > < >= <= == ~=")
print(a > b, a < b, a >= b, a <= b, a == b, a ~= b)

--logical
print()
print("logical: and or not", true, false, nil)
print("true and nil: ", true and nil)
print("false and nil: ", false or nil)
print("true or nil: ", true and nil)
print("flase or nil: ", false or nil)
print("not nil:", not nil)

--string concatenation
print()
print("string" .. ".." .. "concatenation")

--table constructors
print()
table = {
	"item1",
	"item2",
}
print(table, table[1], table[2])


--control flow
print()
print("control flow: if/while/repeat/for")

print("if then")
if false then
	print("if then")
elseif true then
	print("elseif then")
else
end
print("else")
print("end")


print()
print("while do end")
i = 1
while i <= 4 do
	print(i)
	i = i + 1
end

print()
print("repeat until")
i = 1
repeat
	print(i)
	i = i + 1
until i > 4

print()
print("for")
x = 0
for i = 1, 4 do
	x = x + i
	print(x)
end

print("key", "value")
for key, value in ipairs(table) do
	print(key, value)
end

print()
print("break")
x = 0
for i = 1, 4 do 
	x = x + i
	if x > 4 then
		break
	end
	print(x)
end
