import serial
import time
import mysql.connector

ser = serial.Serial('COM3', 9600, timeout=1) #Conexão com o serial
con = mysql.connector.connect(host='paparella.com.br', database='paparell_iot', user='paparell_iot', password='senai2024') #Conexão com o banco
if con.is_connected(): #Vendo se conectou no banco msm
    db_info = con.get_server_info()
    print("Conectado, versão: ", db_info)
    cursor = con.cursor()
    cursor.execute("select database();")
    linha = cursor.fetchone()
    print("Conectado ao banco de dados ", linha)
    
    
time.sleep(2) #Um tempinho pq ninguém é de ferro


cont = 10 #ler o serial
for i in range(cont):
    line = ser.readline()
    string_data = line.decode('utf-8')
    print(string_data)
    
    # Inserir no banco
    sql = "INSERT INTO bosch (nome_aluno, nome_sensor, valor_sensor) VALUES (%s, %s, %s)"
    val = ("Sabrina", "Sensor de ta no meio", string_data)
    cursor.execute(sql, val)
    
    
    # cursor.execute("DELETE FROM bosch WHERE nome_aluno = 'Sabrina'")
    

# Mostrar as tabelas
cursor.execute("SHOW TABLES")
for i in cursor:
    print("Minhas tabelas: ", i)
    
    

con.commit()

print(cursor.rowcount, "Dados gravados")

# Mostrar td q tem no banco
cursor.execute("SELECT * FROM bosch")

myresult = cursor.fetchall() # N sei

for i in myresult:
    print(i)


 # Fechar o serial
