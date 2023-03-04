
units = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
huns = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
thous = ["", "M", "MM", "MMM"]

num = int(input("Enter number: "))

def convert(num):
	thous_val = num // 1000
	huns_val = (num % 1000) // 100
	tens_val = ((num % 1000) % 100) // 10
	units_val = (((num % 1000) % 100) % 10)
	result = thous[thous_val] + huns[huns_val] + tens[tens_val] + units[units_val]
	return (f"The roman numeral of {num} is {result}")

if num > 3999:
	print("Constraint breached!!!")
else:
	print(convert(num))
