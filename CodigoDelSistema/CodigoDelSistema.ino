int BotonIs =2;
int BotonDe =3;
int BotonFreno =4;
int BotonLuzDelantero =5;

int LuzIsquierda =6;
int LuzDerecha =7;
int LuzFreno =8;
int LuzDelantero =9;

//Variables inicializadas

int Pulso1 =0;
int Pulso2 =0;
int Pulso3 =0;

int Pulso4 =0;
int lecturaBoton =0;
bool ledEncendido = false;
bool LuzDelanteraEncendida = false;

int Contador1 =0;
int Contador2 =0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(BotonIs,INPUT);
  pinMode(BotonIs, INPUT_PULLUP); // Botón Is con resistencia de pull-up interna
  attachInterrupt(digitalPinToInterrupt(BotonIs), myISR_Is, RISING); // Interrupción en flanco de subida (cuando BotonIs se presiona)

  pinMode(BotonDe, INPUT_PULLUP); // Botón De con resistencia de pull-up interna
  attachInterrupt(digitalPinToInterrupt(BotonDe), myISR_De, RISING); // Interrupción en flanco de subida (cuando BotonDe se presiona)

  /* pinMode(BotonLuzDelantero, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BotonLuzDelantero), myISR_BotonLuzDelantero, RISING);*/

  pinMode(BotonFreno,INPUT);
  pinMode(BotonLuzDelantero,INPUT);

  pinMode(LuzIsquierda,OUTPUT);
  pinMode(LuzDerecha,OUTPUT);
  pinMode(LuzFreno,OUTPUT);
  pinMode(LuzDelantero,OUTPUT);
}


void loop() {

  //Pulso1 = digitalRead(BotonIs);
  //Pulso2 = digitalRead(BotonDe);
  Pulso3 = digitalRead(BotonFreno);
  Pulso4 = digitalRead(BotonLuzDelantero);
  //1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
  // //CASO1 AQUI ESTA EL CODIGO PARA MI LUZ ISQUIERDA
  if (Pulso1==HIGH)
  {
    for(Contador1;Contador1<5;Contador1++){
    digitalWrite(LuzIsquierda,HIGH);
    delay(300);
    digitalWrite(LuzIsquierda,LOW);
    delay(300);
      if (Pulso2==HIGH){
        Contador1=5;
      }
      
    }
    Contador1 =0;
    Pulso1=LOW;
  }

  // CASO 2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
    // CASO2 AQUI ESTA EL CODIGO PARA MI LUZ ISQUIERDA
if(Pulso2==HIGH)
   {
  for(Contador2;Contador2<5;Contador2++)
       {
       digitalWrite(LuzDerecha,HIGH);
       delay(300);
       digitalWrite(LuzDerecha,LOW);
       delay(300);
       if (Pulso1==HIGH){
        Contador2=5;
      }
       }
  Contador2 =0;
  Pulso2=LOW;
    }

    //CASO3 333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
    //CASO3 LUZ DE FRENO
 if(digitalRead(4)==LOW){              // leera lo que le llegue al pin 5 y lo comapara con un valor 0 o LOW
     digitalWrite(LuzFreno,HIGH);                // mandara un valor alto HIGH o 5 v 
    }  
      else{                               // si la condicion no se cumple entonces ara lo que esta dentro de las llaves
      digitalWrite(LuzFreno,LOW);                // mandamos un valor 0 v o LOW al pin 3
      }  


     // CASO4 44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
      //CASO4 PARA CONTROLAR LA LUZ DELANTERA. 
  Pulso4 = digitalRead(BotonLuzDelantero);
// Este if verifica si el botón ha sido presionado (flanco de bajada)
  if (lecturaBoton == LOW && Pulso4 == HIGH) {  
    ledEncendido = !ledEncendido;   // Cambiar el estado del LED

    // Actualizar el estado del LED
    if (ledEncendido) {
      digitalWrite(LuzDelantero, HIGH); // Encender el LED
    } else {
      digitalWrite(LuzDelantero, LOW);  // Apagar el LED
    }
  }
  Pulso4 = lecturaBoton;   // Guardar el estado actual del botón
    
    //EL SIGUIENTE CODIGO PUEDO USAR TAMBIEN PARA ESTE CASO 4 SOLO SI MI ARDUINO TUBIESE MAS DE 2 INTERRUPCIONES 
    //digitalWrite(LuzDelantero,Pulso4);
    
}


//AQUI ESTAN MIS INTERRUPCIONES...........................................................................................................................................................................................
// Función de interrupción para BotonIs
void myISR_Is() {
  Pulso1 = HIGH;
}

// Función de interrupción para BotonDe
void myISR_De() {
  Pulso2 = HIGH;
}
// Función de interrupción para BotonDeLuzDelantero
/*void myISR_BotonLuzDelantero() {
 Pulso4 = !Pulso4;
 
}*/