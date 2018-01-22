--create
v1 = vector3.create(1, 1, 1)
print(v1)

--get & set
print("before:", v1:GetX(), v1:GetY(), v1:GetZ())

v1:SetX(2.0)
v1:SetY(2.0)
v1:SetZ(2.0)
print("after:", v1:GetX(), v1:GetY(), v1:GetZ())
