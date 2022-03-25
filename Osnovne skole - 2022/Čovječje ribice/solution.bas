Input a1, a2, b1, b2, c1, c2
Input A, B, C

For i = 1 To 64000
    If A = a1 And B = b1 And C = c1 Then
        Print i - 1
        End
    End If
    A = A + 1
    A = A Mod (a1 + a2)
    B = B + 1
    B = B Mod (b1 + b2)
    C = C + 1
    C = C Mod (c1 + c2)
Next i

Print -1
