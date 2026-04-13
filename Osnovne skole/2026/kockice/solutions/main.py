kockicaRed1 = input()
kockicaRed2 = input()
kockicaRed3 = input()

if kockicaRed1 == "###" or kockicaRed1[0] == "#" == kockicaRed2[0]:
    print("6")
elif kockicaRed1 == "#0#":
    if kockicaRed2[1] == "#":
        print("5")
    else:
        print("4")
elif kockicaRed1 == "#00" or kockicaRed1 == "00#":
    if kockicaRed2[1] == "#":
        print("3")
    else:
        print("2")
else:
    print("1")
