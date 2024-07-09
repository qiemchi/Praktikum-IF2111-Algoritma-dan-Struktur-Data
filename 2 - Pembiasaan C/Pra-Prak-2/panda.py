x = int(input("input: "))
z = 0

for i in range(x):
  y = int(input(f"angka ke-{i+1}: "))
  z = z+y

print("Jumlah:", z)