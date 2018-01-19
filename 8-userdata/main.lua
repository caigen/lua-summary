--create
v1 = vector3.create(1, 1, 1)
print("v1:", v1)

--get & set
x, y, z = vector3.get(v1)
print(x, y, z)

ret = vector3.set(v1, 1, 2, 3)
print("set return:", ret)

x, y, z = vector3.get(v1)
print("get return:", x, y, z)

--userdata add
v2 = vector3.create(2, 2, 2)
v = vector3.add(v1, v2)
print("v:", v)
print("add return:", vector3.get(v))

