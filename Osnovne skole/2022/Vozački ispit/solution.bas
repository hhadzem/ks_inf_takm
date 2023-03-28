Dim slen As Integer
Dim s As String

Dim ben As String
Dim ten As String
Dim zen As String

ben = "ABC"
ten = "BABC"
zen = "CCAABB"


Input slen
Input s$

Dim skor(3) As Integer


For i = 1 To slen
    If Mid$(ben, (i - 1) Mod 3 + 1, 1) = Mid$(s, i, 1) Then skor(0) = skor(0) + 1
    If Mid$(ten, (i - 1) Mod 4 + 1, 1) = Mid$(s, i, 1) Then skor(1) = skor(1) + 1
    If Mid$(zen, (i - 1) Mod 6 + 1, 1) = Mid$(s, i, 1) Then skor(2) = skor(2) + 1
Next i

Dim best As Integer
best = skor(0)
If skor(1) > best Then best = skor(1)
If skor(2) > best Then best = skor(2)
Print best
If skor(0) = best Then Print "Ben"
If skor(1) = best Then Print "Ten"
If skor(2) = best Then Print "Zen"








