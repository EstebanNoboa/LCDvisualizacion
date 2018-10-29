/*
 * ........LCD visualizacion.........
 * NOMBRE: Esteban Noboa
 * FECHA: 29/10/2018
 */
 */
 #include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);//RS,EN,D4,D5,D6,D7 (pines del LCD a utilizarce)
  char vec[7] { 'M','E','N','S','A','J','E'}; //vector de jueg
 int tamano;
 int i=0;
 int j=0;
 
void setup() {
   lcd.begin(16, 2); //inicializar pantalla lcd
  Serial.begin(9600); //para comunicacion serial
  Serial.println("INGRESE PALABRA: "); // esto se imprime en la pantalla
}

void loop() {
lcd.setCursor(0,0); //palabra en movimiento
lcd.print(analogRead(0));
for(;i<7;i++){ //ciclo for
lcd.setCursor(i,0); //ubicacion del cursor para escritura
lcd.print(vec[i]); //impresion del vec (vector)
delay(200); //demora de cada palabra en pantalla
}

if(Serial.available()>0){
  String dato =Serial.readString(); //obtener en string el dato ingresado
  tamano=dato.length(); //determinar el tamaño de la palabra
  Serial.println(dato); //impresion del dato
  Serial.println(tamano); // se tiene en cuenta el tamano
  char vector[tamano+1];////crear el vetor tipo char tamano+1
  dato.toCharArray(vector,tamano+1);  //asignar el String al vector
 
  for(;i<tamano+1;i++){ //ciclo for
    Serial.println(vector[i]); //imprimir el vector i
    }
    i=0;
  Serial.println(dato.indexOf('R',0)); //buscar caracteres indexOf==determinar tamano y si existe esa palabra
  
  for(;i<16+tamano;i++){
    lcd.clear();
    lcd.setCursor(i-tamano,0);

    if(i<18){
    for(;j<tamano;j++){
      lcd.print(vector[j]);
      delay(200);
    }
      }
      if(i>18)
      lcd.setCursor(j,0);
      j=0;
      Serial.println(i);
      
    }
  }
}
