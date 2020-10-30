alf = "abcdefghijklmnopqrstuvwxyz"
perde = {"jogo", "perdi"}
n = int(input())
letras = 0
venceu = []

for i in range(n):
    frase = input()
    palavra = ""
    letras = 0
    venceu.append(0)
    for j in frase:
        if j not in alf or len(palavra) > 4:
            palavra = ""
        if j.lower() in alf:
            letras += 1
            palavra = palavra + j
        if palavra.lower() in perde:
            if letras > venceu[i]:
                venceu[i] = letras
            letras = 0
for i in range(n):
    print(venceu[i])