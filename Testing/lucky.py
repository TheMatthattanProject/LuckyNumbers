import csv

begin = 1
end = 1000000

bank = list()
lbank = list()

with open('file.csv', mode='w', newline='') as file:
	fieldNames = ['x', 'luckyBankLen']
	file = csv.DictWriter(file, fieldnames=fieldNames)
	file.writeheader()
	


	for x in range(begin, end+1):
		eight = False
		six = False
		dset = str(x)

		for d in dset:
			if (d == '6'):
				six = True
			if (d == '8'):
				eight = True

		if (bool(eight) == bool(six)):
			bank.append(x)

		if (bool(eight) != bool(six)):
			lbank.append(x)

		file.writerow({'x': x, 'luckyBankLen': len(lbank)})
