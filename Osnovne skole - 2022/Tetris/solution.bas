Input s1$
Input s2$

For i = 1 To 3
    If Mid$(s1$, i, 1) = "." Then
        broj_tacaka = broj_tacaka + 1
    End If
    If Mid$(s2$, i, 1) = "." Then
        broj_tacaka = broj_tacaka + 1
    End If
Next i

'ako imamo manje od 4 slobodna mjesta onda ne mozemo ni jedan tetromino staviti
'zato sto svi zauzimaju 4 mjesta
If broj_tacaka < 4 Then
    Print "NE"
    End
End If

'ako imamo vise od 4 slobodna mjesta onda zagarantovano mozemo staviti barem
'neki oblik. Uvjerite se na papiru!
If broj_tacaka > 4 Then
    Print "DA"
    End
End If

'Sada je broj tacaka sigurno tacno 4, odnosno broj taraba tacno 2
'Jedine kombinacije pozicija koje ne odgovaraju su sljedecih oblika (plus njihove rotacije i izokretanja)
'    .#.
'    .#.
'
'    i
'
'    .#.
'    #..

'ako su obje tarabe u istom redu onda je sigurno moguce smjestiti tetromino
If s1$ = "..." Or s2$ = "..." Then
    Print "DA"
    End
End If

'ukoliko nemamo taraba u sredinama onda je moguce smjestiti tetromino
If Mid$(s1$, 2, 1) = "." And Mid$(s2$, 2, 1) = "." Then
    Print "DA"
    End
End If

Print "NE"
End
