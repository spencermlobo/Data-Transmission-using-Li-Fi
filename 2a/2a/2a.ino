//MORSE RECEIVER.
//In pinA0 put a light sensor (with resistance)
//Captures the light pulses from the emitter and displays the characters detected by the Serial console

int sensorPin = A0; // select the input pin for ldr
int sensorValue = 0; // variable to store the value coming from the sensor
int umbral = 600; // Above that light we consider that there is a pulse of LIGHT
int a, f; // flags


// period, the normal thing is to put 200 or 250 to be able to see it better
// With 100 it works fine. You have to look at what is in the emitting part. It has to be the same.
int punto= 250;//It is the expected duration of the point, the one of the line is 3 times the point
int raya = punto*3;
int pausa_letra = punto*3;
int pausa_palabra = raya*3;

String pulsos=""; // Coding of the detected pulses

void setup() {
Serial.begin(9600); //sets serial port for communication
}

void loop() {
long s1; //CControls the end of a pulse
long s2; //Controls the end of a letter or a word
long s3; //Control the of the message.
pulsos="";
sensorValue = analogRead(sensorPin); // read the value from the sensor
//Serial.println(sensorValue);
s2=millis();s3=millis();
while (true){
if (millis()-s3>pausa_palabra*2){Serial.println();s3=millis();}
if (millis()-s2>pausa_palabra-100){Serial.print(" ");s2=millis();}
if (millis()-s2>pausa_letra-100){ letra(pulsos);pulsos="";} // no se acabo la letra
if (analogRead(sensorPin)>umbral) {
s1=millis();
while (analogRead(sensorPin)>umbral) {
//Serial.println(analogRead(sensorPin));
};
if (millis()-s1>50){ //Se desprecia pulsos demasiado pequeños
if (millis()-s1>punto*1.25) pulsos=pulsos+'-'; else pulsos=pulsos+'.';
}
s2=millis(); s3=millis();
}
}

}

void letra(String pulsos){
if (pulsos==".-") Serial.print("a");
if (pulsos=="-...") Serial.print("b");
if (pulsos=="-.-.") Serial.print("c");
if (pulsos=="-..") Serial.print("d");
if (pulsos==".") Serial.print("e");
if (pulsos=="..-.") Serial.print("f");
if (pulsos=="--.") Serial.print("g");
if (pulsos=="....") Serial.print("h");
if (pulsos=="..") Serial.print("i");
if (pulsos==".---") Serial.print("j");
if (pulsos=="-.-") Serial.print("k");
if (pulsos==".-..") Serial.print("l");
if (pulsos=="--") Serial.print("m");
if (pulsos=="-.") Serial.print("n");
if (pulsos=="--.--") Serial.print("ñ");
if (pulsos=="---") Serial.print("o");
if (pulsos==".--.") Serial.print("p");
if (pulsos=="--.-") Serial.print("q");
if (pulsos==".-.") Serial.print("r");
if (pulsos=="...") Serial.print("s");
if (pulsos=="-") Serial.print("t");
if (pulsos=="..-") Serial.print("u");
if (pulsos=="...-") Serial.print("v");
if (pulsos==".--") Serial.print("w");
if (pulsos=="-..-") Serial.print("x");
if (pulsos=="-.--") Serial.print("y");
if (pulsos=="--..") Serial.print("z");
if (pulsos==".----") Serial.print("1");
if (pulsos=="..---") Serial.print("2");
if (pulsos=="...--") Serial.print("3");
if (pulsos=="....-") Serial.print("4");
if (pulsos==".....") Serial.print("5");
if (pulsos=="-....") Serial.print("6");
if (pulsos=="--...") Serial.print("7");
if (pulsos=="---..") Serial.print("8");
if (pulsos=="----.") Serial.print("9");
if (pulsos=="----") Serial.print("0");
if (pulsos=="..-..") Serial.print(",");
if (pulsos==".-.-.-") Serial.print(".");
if (pulsos=="-.-.-") Serial.print(";");
if (pulsos=="---...") Serial.print(":");
if (pulsos==".-.-.") Serial.print("+");
if (pulsos=="-....-") Serial.print("-");
if (pulsos=="-...-") Serial.print("=");
if (pulsos=="-..-.") Serial.print("/");
if (pulsos=="..--..") Serial.print("?");
}
