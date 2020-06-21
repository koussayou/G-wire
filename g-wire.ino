#include "DHT.h"
#define DHTPIN 8 
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
#include <GSM.h>
#define PINNUMBER "9"
GSM gsmAccess;
GSM_SMS sms;
void setup() {
  
 Serial.begin(9600);
 Serial.println("DHTxx test!");
 dht.begin();
 boolean notConnected = true;
 while(notConnected)
  {
    if(gsmAccess.begin(PINNUMBER)==GSM_READY)
      notConnected = false;
    else
    {
      Serial.println("Not connected");
      delay(1000);
    }
  }
 Serial.println("GSM initialized.");


}

}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
 
 //On verifie si la lecture a echoue, si oui on quitte la boucle pour recommencer.
 if (isnan(h) || isnan(t) || isnan(f))
 {
   Serial.println("Failed to read from DHT sensor!");
   return;
 }
 
 // Calcul de l'indice de temperature en Farenheit
 float hif = dht.computeHeatIndex(f, h);
 // Calcul de l'indice de temperature en Celsius
 float hic = dht.computeHeatIndex(t, h, false);
 
 //Affichages :
 Serial.print("Humidite: ");
 Serial.print(h);
 Serial.print(" %\t");
 Serial.print("Temperature: ");
 Serial.print(t);
 Serial.print(" *C ");
 Serial.print(f);
 Serial.print(" *F\t");
 Serial.print("Indice de temperature: ");
 Serial.print(hic);
 Serial.print(" *C ");
 Serial.print(hif);
 Serial.println(" *F");
 
      remoteNumber = 193;
      txtMsg = "fire in the hole";   
      
  sms.beginSMS(remoteNumber);
  sms.print(txtMsg);
  sms.endSMS();
  Serial.println("\nCOMPLETE!\n");
}
  }
}
