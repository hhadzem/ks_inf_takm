import sys
from functools import cmp_to_key

input = sys.stdin.readline


def parse_mec(line):
    # Format: timA - timB - timC : a - b - c
    parts = line.split()
    # parts: [timA, '-', timB, '-', timC, ':', a, '-', b, '-', c]
    timA = parts[0]
    timB = parts[2]
    timC = parts[4]
    a = int(parts[6])
    b = int(parts[8])
    c = int(parts[10])
    return timA, timB, timC, a, b, c


def uporedi_prosjek_domacih_fragova(lijevi, desni):
    if lijevi['brojDomacihUtakmica'] == 0 and desni['brojDomacihUtakmica'] == 0:
        return 0
    if lijevi['brojDomacihUtakmica'] == 0:
        return -1
    if desni['brojDomacihUtakmica'] == 0:
        return 1
    lijeva_strana = lijevi['H'] * desni['brojDomacihUtakmica']
    desna_strana = desni['H'] * lijevi['brojDomacihUtakmica']
    if lijeva_strana < desna_strana:
        return -1
    if lijeva_strana > desna_strana:
        return 1
    return 0


def isti_kriteriji_rangiranja(lijevi, desni):
    if lijevi['P'] != desni['P']:
        return False
    if lijevi['D'] != desni['D']:
        return False
    if lijevi['F'] != desni['F']:
        return False
    if lijevi['W'] != desni['W']:
        return False
    if lijevi['X'] != desni['X']:
        return False
    if (lijevi['F'] - lijevi['H']) != (desni['F'] - desni['H']):
        return False
    return uporedi_prosjek_domacih_fragova(lijevi, desni) == 0


def bolji_po_kriterijima(lijevi, desni):
    if lijevi['P'] != desni['P']:
        return -1 if lijevi['P'] > desni['P'] else 1
    if lijevi['D'] != desni['D']:
        return -1 if lijevi['D'] > desni['D'] else 1
    if lijevi['F'] != desni['F']:
        return -1 if lijevi['F'] > desni['F'] else 1
    if lijevi['W'] != desni['W']:
        return -1 if lijevi['W'] > desni['W'] else 1
    if lijevi['X'] != desni['X']:
        return -1 if lijevi['X'] > desni['X'] else 1
    gost_lijevi = lijevi['F'] - lijevi['H']
    gost_desni = desni['F'] - desni['H']
    if gost_lijevi != gost_desni:
        return -1 if gost_lijevi > gost_desni else 1
    cmp = uporedi_prosjek_domacih_fragova(lijevi, desni)
    if cmp != 0:
        return 1 if cmp < 0 else -1
    if lijevi['ime'] < desni['ime']:
        return -1
    if lijevi['ime'] > desni['ime']:
        return 1
    return 0


def novi_tim(ime):
    return {'ime': ime, 'P': 0, 'F': 0, 'A': 0, 'D': 0, 'W': 0, 'H': 0, 'X': 0, 'brojDomacihUtakmica': 0}


def primijeni_mec(timovi, indeksi_timova, timA, timB, timC, a, b, c):
    iA = indeksi_timova[timA]
    iB = indeksi_timova[timB]
    iC = indeksi_timova[timC]

    timovi[iA]['F'] += a
    timovi[iB]['F'] += b
    timovi[iC]['F'] += c

    timovi[iA]['A'] += b + c
    timovi[iB]['A'] += a + c
    timovi[iC]['A'] += a + b

    timovi[iA]['D'] = timovi[iA]['F'] - timovi[iA]['A']
    timovi[iB]['D'] = timovi[iB]['F'] - timovi[iB]['A']
    timovi[iC]['D'] = timovi[iC]['F'] - timovi[iC]['A']

    timovi[iA]['H'] += a
    timovi[iA]['brojDomacihUtakmica'] += 1

    rezultati = [(a, 0), (b, 1), (c, 2)]
    rezultati.sort(key=lambda x: -x[0])
    maksimum = rezultati[0][0]
    srednji = rezultati[1][0]
    minimum = rezultati[2][0]
    idx = [iA, iB, iC]

    if maksimum == srednji == minimum:
        timovi[idx[0]]['P'] += 2
        timovi[idx[1]]['P'] += 2
        timovi[idx[2]]['P'] += 2
    elif maksimum == srednji:
        timovi[idx[rezultati[0][1]]]['P'] += 3
        timovi[idx[rezultati[1][1]]]['P'] += 3
    elif srednji == minimum:
        timovi[idx[rezultati[0][1]]]['P'] += 4
        timovi[idx[rezultati[1][1]]]['P'] += 1
        timovi[idx[rezultati[2][1]]]['P'] += 1
    else:
        timovi[idx[rezultati[0][1]]]['P'] += 4
        timovi[idx[rezultati[1][1]]]['P'] += 2

    if maksimum > srednji:
        lokalni_pobjednik = rezultati[0][1]
        pobjednik = timovi[idx[lokalni_pobjednik]]
        pobjednik['W'] += 1
        if maksimum >= 2 * minimum:
            pobjednik['X'] += 1


def main():
    broj_timova = int(input())
    imena_timova = [input().strip() for _ in range(broj_timova)]

    broj_utakmica = int(input())
    mecevi = []
    for _ in range(broj_utakmica):
        mecevi.append(parse_mec(input()))

    indeksi_timova = {ime: i for i, ime in enumerate(imena_timova)}
    timovi = [novi_tim(ime) for ime in imena_timova]

    for mec in mecevi:
        primijeni_mec(timovi, indeksi_timova, *mec)

    timovi.sort(key=cmp_to_key(bolji_po_kriterijima))

    treba_razigravanje = False
    for i in range(1, len(timovi)):
        if isti_kriteriji_rangiranja(timovi[i - 1], timovi[i]):
            treba_razigravanje = True
            break

    if treba_razigravanje:
        print("Potrebno je razigravanje!")
    else:
        for tim in timovi:
            print(tim['ime'], tim['P'])


main()
