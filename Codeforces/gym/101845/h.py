from datetime import *
ano = raw_input();


comeco = date((1867 + int(ano)) % 400, 9, 22);

dias = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']

print (dias[comeco.isoweekday()-1])
