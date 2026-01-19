sifra = input()

good = True
for c in sifra:
    if c != 'A' and c != 'E' and c != 'I' and c != 'O' and c != 'U':
        good = False

if good:
    print("DA")
else:
    print("NE")