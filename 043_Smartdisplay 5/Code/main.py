'''
  Für LoLin - Board
  Modifiziert von 'Micropython mit ESP32', Lektion 19, WebWetter9.py
  Erste Test für Kommunikation mit Smartdisplay
'''

from netzwerk import *
from geheim import *
from webseiten import startHTTP, log, hp, wetter
from openweathermap import *
import time
import gc
import esp
import machine

esp.osdebug(None)

wifi = WiFi()
owm = WetterService(owm_id, owm_lat, owm_lon, owm_ort, owm_land, 600)
uart = machine.UART(2,9600,rx=2,tx=15)


def zeit_text(zeit):
    return datum_zeit_text(owm.get_zeit_lokal(zeit))

def zeige_taeglich():
    wetter.add("Tägliche Entwicklung")
    for w in taeglich:
        datum = datum_text(owm.get_zeit_lokal(w.get("dt"))) 
        temp = w.get("temp").get("day")
        feuchte = w.get("humidity")
        txt = w.get("weather")[0].get("description")
        wetter.add("{}: {} Grad, {} % Luftfeuchtigkeit, {}".format(datum,temp,feuchte,txt))
    wetter.add()


def zeige_stunden():
    wetter.add("Stündliche Entwicklung")
    for w in stuendlich:
        zeit = datum_zeit_text(owm.get_zeit_lokal(w.get("dt"))) 
        temp = w.get("temp")
        feuchte = w.get("humidity")
        txt = w.get("weather")[0].get("description")
        wetter.add("{}: {} Grad, {} % Luftfeuchtigkeit, {}".format(zeit,temp,feuchte,txt))
    wetter.add()

   
def zeige_aktuell(aktuell):
    if aktuell:
        messzeit = owm.get_messzeit_text()
        
        wetter.clear()
        wetter.add("Aktuelles Wetter in {}, {}: {}".format(owm.get_ort_name(),owm.get_land(),aktuell.get("weather")[0].get("description")))
        wetter.add("Gemessen am {}".format(messzeit))
        wetter.add()
        wetter.add("Temperatur:   {} Grad".format(aktuell.get("temp")))
        wetter.add("Luftdruck:    {} hPa".format(aktuell.get("pressure")))
        wetter.add("Feuchtigkeit: {} %".format(aktuell.get("humidity")))
        wetter.add()
        wetter.add("Wind:")
        wetter.add("Geschwindigkeit: {} m/s".format(aktuell.get("wind_speed")))
        wetter.add("Richtung:        {} Grad".format(aktuell.get("wind_deg")))
        wetter.add()
       
        ort = "[ort]={}, {}\r".format(owm.get_ort_name(),owm.get_land())   
        beschreibung = "[beschreibung]={}\r".format(aktuell.get("weather")[0].get("description"))
        zeit = "[zeit]={}\r".format(messzeit)

        temp = "[temp]={}\r".format(aktuell.get("temp"))
        feuchte = "[feuchte]={}\r".format(aktuell.get("humidity"))
        druck = "[druck]={}\r".format(aktuell.get("pressure"))
    
        wind_geschw = "[wind_geschw]={}\r".format(aktuell.get("wind_speed"))
        wind_richtung = "[wind_richtung]={}\r".format(aktuell.get("wind_deg"))

        print()
        print("Senden an Display:")
        print(zeit)
        print(ort)
        print(beschreibung)
        print(temp)
        print(feuchte)
        print(druck)
        print(wind_geschw)
        print(wind_richtung)
        
        uart.write(zeit)
        uart.write(ort)
        uart.write(beschreibung)
        uart.write(temp)
        uart.write(feuchte)
        uart.write(druck)
        uart.write(wind_geschw)
        uart.write(wind_richtung)

        print("<show>")
        uart.write("<show>\r")
       

    
        
def homepage():
    ip = wifi.get_ip()
    hp.add("Die ESP32 - Wetterstation kennt momentan folgende Funktionen:")
    hp.add()
    hp.add('Das aktuelle Wetter: <a href="http://{}/wetter">http://{}/wetter</a>'.format(ip,ip))
    hp.add('Ein LOG als Debug-Hilfe beim Programmieren: <a href="http://{}/log">http://{}/log</a>'.format(ip,ip))
    

print("Mit Netzwerk verbinden ...")
log.add_log("Mit WLAN verbinden...");


if wifi.connect(wlan_ssid,wlan_passwort):
    print(wifi.get_ssid())
    print(wifi.get_ip())

    startHTTP()
    log.add_log("Mit {} verbunden, IP-Adresse {}".format(wifi.get_ssid(),wifi.get_ip()))
    homepage()
    aktuell, stuendlich, taeglich = owm.get_alle()
    log.add_log("Wetter geladen");
    zeige_aktuell(aktuell)
    zeige_stunden()
    zeige_taeglich()
    
    while True:
        time.sleep(60)
        aktuell, stuendlich, taeglich = owm.get_alle()
        zeige_aktuell(aktuell)
        
else:
   print("Kein Netzwerk gefunden!")
   log.add_log("Keine Verbindung möglich")
   log.print()

