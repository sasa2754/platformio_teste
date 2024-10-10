#include <Arduino.h>

// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
//   Serial.println("Hello, World!");
//   delay(1000);
// }






// Código do joystick

// #include <Arduino.h>

// int eixo_X = A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
// int eixo_Y = A1; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
// int botao = 22; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)

// void setup(){
//   pinMode (botao, INPUT_PULLUP); //DEFINE A PORTA COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
//   //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
//   Serial.begin (9600); //INICIALIZA O MONITOR SERIAL
// }
// void loop(){

//     if((analogRead(eixo_X)) == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
//         Serial.println("PARA CIMA"); //IMPRIME O TEXTO NO MONITOR SERIAL
//         // Serial.println(1);
//     }else{
//           if((analogRead(eixo_X)) == 1023){ //SE LEITURA FOR IGUAL A 1023, FAZ
//               Serial.println("PARA BAIXO"); //IMPRIME O TEXTO NO MONITOR SERIAL
//               // Serial.println(3);
//           }else{
//                 if((analogRead(eixo_Y)) == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
//                   Serial.println("DIREITA"); //IMPRIME O TEXTO NO MONITOR SERIAL
//                   // Serial.println(4);
//                 }else{
//                       if((analogRead(eixo_Y)) == 1023){ //SE LEITURA FOR IGUAL A 1023, FAZ
//                           Serial.println("ESQUERDA"); //IMPRIME O TEXTO NO MONITOR SERIAL
//                           // Serial.println(2);
//                       }else{
//                             if(digitalRead(botao) == LOW){ //SE LEITURA FOR IGUAL A HIGH, FAZ
//                                Serial.println("BOTAO PRESSIONADO"); //IMPRIME O TEXTO NO MONITOR SERIAL
//                               // Serial.println(0);
//                             }  
//                       }
//                 }
//           }
//     }
//     delay(200); //INTERVALO DE 500 MILISSEGUNDOS
// }







// Código do gato

// #include <SPI.h> //INCLUSÃO DE BIBLIOTECA
// #include <MFRC522.h> //INCLUSÃO DE BIBLIOTECA

// #define SS_PIN 10 //PINO SDA
// #define RST_PIN 9 //PINO DE RESET

// MFRC522 rfid(SS_PIN, RST_PIN); //PASSAGEM DE PARÂMETROS REFERENTE AOS PINOS

// void setup() {
//   Serial.begin(9600); //INICIALIZA A SERIAL
//   SPI.begin(); //INICIALIZA O BARRAMENTO SPI
//   rfid.PCD_Init(); //INICIALIZA MFRC522
//   Serial.println("Ta rodante");
// }

// void loop() {
//   // if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) //VERIFICA SE O CARTÃO PRESENTE NO LEITOR É DIFERENTE DO ÚLTIMO CARTÃO LIDO. CASO NÃO SEJA, FAZ
//   //   return; //RETORNA PARA LER NOVAMENTE

//   /***INICIO BLOCO DE CÓDIGO RESPONSÁVEL POR GERAR A TAG RFID LIDA***/
//   String strID = "";
//   for (byte i = 0; i < 4; i++) {
//     strID +=
//     (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
//     String(rfid.uid.uidByte[i], HEX) +
//     (i!=3 ? ":" : "");
//   }
//   strID.toUpperCase();
//   /***FIM DO BLOCO DE CÓDIGO RESPONSÁVEL POR GERAR A TAG RFID LIDA***/

//   Serial.print("Identificador (UID) da tag: "); //IMPRIME O TEXTO NA SERIAL
//   Serial.println(strID); //IMPRIME NA SERIAL O UID DA TAG RFID

//   rfid.PICC_HaltA(); //PARADA DA LEITURA DO CARTÃO
//   rfid.PCD_StopCrypto1(); //PARADA DA CRIPTOGRAFIA NO PCD
// }







// Código do teclado

// #include <Keypad.h> //INCLUSÃO DE BIBLIOTECA

// const byte qtdLinhas = 4; //QUANTIDADE DE LINHAS DO TECLADO
// const byte qtdColunas = 4; //QUANTIDADE DE COLUNAS DO TECLADO

// //CONSTRUÇÃO DA MATRIZ DE CARACTERES
// char matriz_teclas[qtdLinhas][qtdColunas] = {
//   {'1','2','3','A'},
//   {'4','5','6','B'},
//   {'7','8','9','C'},
//   {'*','0','#','D'}
// };


// byte PinosqtdLinhas[qtdLinhas] = {3, 4, 5, 6}; //PINOS UTILIZADOS PELAS LINHAS
// byte PinosqtdColunas[qtdColunas] = {8, 9, 10,11}; //PINOS UTILIZADOS PELAS COLUNAS

// //INICIALIZAÇÃO DO TECLADO
// Keypad meuteclado = Keypad( makeKeymap(matriz_teclas), PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas); 

// void setup(){
//   Serial.begin(9600); //INICIALIZA A SERIAL
//   Serial.println("Aperte uma tecla..."); //IMPRIME O TEXTO NO MONITOR SERIAL
//   Serial.println(); //QUEBRA UMA LINHA NO MONITOR SERIAL
// }
  
// void loop(){
//   char tecla_pressionada = meuteclado.getKey(); //VERIFICA SE ALGUMA DAS TECLAS FOI PRESSIONADA
  
//   if (tecla_pressionada){ //SE ALGUMA TECLA FOR PRESSIONADA, FAZ
//     Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
//     Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
//   }
// }


// Sensor touch


// #include <SPI.h>
// const int pinoSensor = 2; //PINO DIGITAL UTILIZADO PELO SENSOR
 
// void setup() {
//   pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
//   Serial.begin(9600);
// }
 
// void loop() {
//   if (digitalRead(pinoSensor) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
//     Serial.println("Tem dedo");
//   }
//   else{ //SENÃO, FAZ
//     Serial.println("N tem dedo");
//   } 
//   delay(200); //INTERVALO DE 200 MILISSEGUNDOS
// }


// Sensor de vibração

#include <SPI.h>

// const int pinoSensor = 5; //PINO DIGITAL UTILIZADO PELO SENSOR

// void setup(){
//   pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
//   Serial.begin(9600);
// }

// void loop(){
//   if(digitalRead(pinoSensor) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
//     Serial.println("Vibra");
//   }else{ //SENÃO, FAZ
//     Serial.println("Não vibra");
//   }
//   delay(200);
// }



// Sensor que não sabemos

int pinoSensor = 8; //PINO DIGITAL UTILIZADO PELO SENSOR
   
void setup(){  
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  Serial.begin(9600);
}  
   
void loop(){
  if (digitalRead(pinoSensor) == LOW){ //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
    Serial.println("Não ta na frente");
  }else{//SENÃO, FAZ
    Serial.println("Ta na frente");
  }
  delay(200);
}