//==================================
// Arbeitsscript für ESP32Remote
// Das ist der Client - Code
// benötigt webSocket.js
// 17.07.2021
// Der Hobbyelektroniker
//==================================

//#region Globale Variablen, Konstanten und Objekte 
var isOn = false;
//#endregion

//#region Startcode
window.addEventListener("load",  onload);

function  onload(event) {
    initWebSocket();      // WebSocket initialisieren
    addWebSocketEvents(); // Eigene Eventhandler für WebSocket Events
    addHTMLEvents();      // Events von HTML-Elementen den Eventhandlern zuweisen
}
//#endregion

//#region Events von HTML-Elementen 
function addHTMLEvents() {
    document.getElementById('toggle_button').addEventListener('click', toggleLed);
}
 
// Eventhandler für den Click auf den Button
function toggleLed(event) {
    isOn = !isOn;
    // Den Server informieren
    if (isOn) websocket.send('ON'); else websocket.send('OFF');
}
//#endregion

//#region Eigene Eventhandler für WebSocket Events 
function addWebSocketEvents() {
    websocket.onopen    = onOpen;
    websocket.onmessage = onMessage;
}

function onOpen(event) {
    // Info über den aktuellen Zustand vom Server anfordern
    websocket.send("INFO");
}
  
function onMessage(event) {
    // Wir erhalten ON oder OFF
    isOn = (event.data == "ON");
    refreshPage();
}
//#endregion

//#region Andere Funktionen 
// Aktualisieren der Webseite
function refreshPage() {
    if (isOn) {
        document.getElementById("toggle_button").innerHTML="AUS";
        document.getElementById("imageLed").src="led_on.jpg";
    } else {
        document.getElementById("toggle_button").innerHTML="EIN";
        document.getElementById("imageLed").src="led_off.jpg";
    }
}
//#endregion
