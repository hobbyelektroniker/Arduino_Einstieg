//==================================
// Script zur WebSocket - Verwendung
// Diese Datei muss normalerweise
// nicht verändert werden.
// 17.07.2021
// Der Hobbyelektroniker
//==================================

//#region Globale Variablen, Konstanten und Objekte 
var websocket;
//#endregion

//#region Initialisierung und Default - Eventhandler ====
function initWebSocket() {
    var gateway = `ws://${window.location.hostname}/ws`;
    console.log(gateway)
    websocket = new WebSocket(gateway);
    websocket.onopen    = onWebSocketOpen;
    websocket.onclose   = onWebSocketClose;
    websocket.onmessage = onWebSocketMessage;
}

// Default - Eventhandler
function onWebSocketOpen(event) {
    console.log("WebSocket Open");
}
  
function onWebSocketClose(event) {
    console.log("WebSocket Close");
    // Bei Verbindungsverlust nach 2 Sekunden
    // neue Verbindungsaufnahme versuchen
    setTimeout(initWebSocket, 2000);
}

function onWebSocketMessage(event) {
    console.log("WebSocket Message: " + event.data);
}
//#endregion

