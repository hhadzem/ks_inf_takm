Dim n, k As Integer
Dim a(100005) As Integer
Input n
Input k
For i = 1 To n
    Input a(i)
Next i

Dim trenutniBlok, najduziBlok As Long
trenutniBlok = 1
najduziBlok = 1


For i = 2 To n
    If a(i) = a(i - 1) Then
        If trenutniBlok > najduziBlok Then
            najduziBlok = trenutniBlok

        End If
        trenutniBlok = 1

    Else
        trenutniBlok = trenutniBlok + 1
    End If
Next i

If trenutniBlok > najduziBlok Then
    najduziBlok = trenutniBlok
End If
Print najduziBlok



