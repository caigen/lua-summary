--Single line comment.
--[[
	Block comment.
--]]
print("hello world")


--types
type1 = nil
type2 = true or false
type3 = 1
type4 = "one"

type5 = {
	"table"
}
type6 = function()
	print("function type")
end
type7 = coroutine.create(
	function()
		print("thread type")	
	end
)
type8 = "userdata from C"

print(type(type1) .. ", "
	.. type(type2) .. ", "
	.. type(type3) .. ", "
	.. type(type4) .. ", "
	.. type(type5) .. ", "
	.. type(type6) .. ", "
	.. type(type7) .. ", "
	.. type8)
