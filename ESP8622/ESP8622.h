#include <SoftwareSerial.h>
SoftwareSerial ESP(3, 2);
class ESP8622 {
  private:  
    String W = "";
    char w;
    String error;
  public:
    ESP8622();
    boolean encenderESP(boolean depurar);
    String sendData(String comando, const int timeout, boolean debug);
    void escuchar();
    boolean iniciarESP(boolean depurar);
    boolean isNotConectado(boolean depurar);
    void setError(String mensajeDeError);
    String getError();
    String getMensaje();
};
ESP8622::ESP8622() {
  Serial.begin(9600);
  ESP.begin(9600);
  
}
boolean ESP8622::encenderESP(boolean depurar){
  iniciarESP(depurar);
  if (isNotConectado(depurar)) {
    //sendData("AT+CWJAP=\"TelemaTICs\",\"Telematics305\"\r\n", 1000,depurar);
    //sendData("AT+CWJAP=\"ArphaNet\",\"Uptc2016\"\r\n",1000,depurar);
    sendData("AT+CWJAP=\"Movistar_87457016\",\"xs9gwpbu31\"\r\n", 1000, depurar);
    if (isNotConectado(depurar)){
      setError("No Conexion");
      return false;
    }
  }
  return true;
}
String ESP8622::sendData(String comando, const int timeout, boolean debug) {
  W = "";
  long int time = millis();
  ESP.print(comando);
  while ( (time + timeout) > millis()) {
    //digitalWrite(13, HIGH);
    while (ESP.available()) {
      w = ESP.read();
      if (debug) {
        Serial.print(w);
      }
      W += w;
    }
    //digitalWrite(13, LOW);
  }
  return W;
}
void ESP8622::escuchar() {
  if (ESP.available()) {
    w = ESP.read();
    Serial.print(w);
    W = W + w ;
  }
  if (Serial.available()) { // Comando
    char s = Serial.read();
    ESP.print(s);
  }
  if ( w == '\n') {
    if ( W.indexOf("GET") > 0 ) {
      Serial.print(W);
    }
    W = "" ;  w = ' ' ;
  }
}
boolean ESP8622::iniciarESP(boolean depurar) {
  sendData("AT+RST\r\n", 1000, depurar);
  return sendData("AT\r\n", 1000, depurar).indexOf("OK") > 0 & sendData("AT+CIPMUX=1\r\n", 1000, depurar).indexOf("OK") > 0 & sendData("AT+CIPSERVER=1,80\r\n", 1000, depurar).indexOf("OK") > 0;
}
boolean ESP8622::isNotConectado(boolean depurar) {
  return sendData("AT+CIFSR\r\n", 1000, depurar).indexOf("0.0.0.0") > 0;
}
void ESP8622::setError(String mensajeDeError){
  error=mensajeDeError;
}
String ESP8622::getError(){
  return error;
}
String ESP8622::getMensaje(){
  if (ESP.available()){
    w=ESP.read();
    //Serial.print(w);
    W = W + w ;
  }
  if ( w == '\n'){
    if ( W.indexOf("GET") > 0 ){
      return W;
    }
    W = "" ;  w = ' ' ;    
  }
  return "";
}

