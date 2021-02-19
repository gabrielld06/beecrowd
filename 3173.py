from datetime import date
from datetime import timedelta
from math import floor
from math import ceil

x = int(input(""))

d = date(2020, 12, 21)
diasJupitier = floor(11.9 * 365.25*x)
diasSaturno = floor(29.6 * 365.25*x)
jupiter = d + timedelta(days = diasJupitier)
saturno = d + timedelta(days = diasSaturno)

print("Dias terrestres para Jupiter = " + str(diasJupitier))
if jupiter.month <= 9 :
    if jupiter.day <= 9:
        print("Data terrestre para Jupiter: "+ str(jupiter.year) + "-0" + str(jupiter.month) + "-0" + str(jupiter.day))
    else:
        print("Data terrestre para Jupiter: "+ str(jupiter.year) + "-0" + str(jupiter.month) + "-" + str(jupiter.day))
else:
    print("Data terrestre para Jupiter: "+ str(jupiter.year) + "-" + str(jupiter.month) + "-" + str(jupiter.day))

print("Dias terrestres para Saturno = " + str(diasSaturno))
if saturno.month <=9:
    if saturno.day <=9:
        print("Data terrestre para Saturno: "+ str(saturno.year) + "-0" + str(saturno.month) + "-0" + str(saturno.day))
    else:
        print("Data terrestre para Saturno: "+ str(saturno.year) + "-0" + str(saturno.month) + "-" + str(saturno.day))
else:
    print("Data terrestre para Saturno: "+ str(saturno.year) + "-" + str(saturno.month) + "-" + str(saturno.day))