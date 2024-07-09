x = int(input("Mau berapa angka: "))
z = 1

for i in range(x):
  y = int(input(f"angka ke-{i+1}: "))
  z = z*y

print("Jumlah kalinya:", z)