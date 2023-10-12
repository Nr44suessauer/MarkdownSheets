# VsCode & Platformio
![](https://hack.depta.dev/uploads/upload_314d7020e9b723d1e35b947897c27788.png)

## Installation
### 1. VSCode
![](https://hack.depta.dev/uploads/upload_3bb7c9551a88732ab577e90b7d311ef4.png)
- Ein Electron Editor von Microsoft
- Open Source und Lightweight
- Sehr gut Konfigurierbar und versatil einsetzbar
- Plugins für alle möglichen Sprachen und Tools
- Verfügbar auf Windows, Mac, Linux

Download: https://code.visualstudio.com/

### 2. Platformio Extension
![](https://hack.depta.dev/uploads/upload_ea4fa86035e278fe73d72320c1026f88.png)
1. Extensions Reiter auswählen
2. "Platformio" in der Suche eingeben
3. Platformio in den Suchergebnissen auswählen
4. Platformio installieren. VSCode startet nach der Installation neu

## Ein Projekt erstellen
1. Platformio Extension auswählen
2. PIO Home auswählen
3. Neues Projekt auswählen
![](https://hack.depta.dev/uploads/upload_9a532915a17ab2fc2e862e44b2561278.PNG)

4. Board & Framework auswählen
5. Auf Platformio warten bis das Projekt aufgesetzt wurde

## Platformio Ordnerstruktur
![](https://hack.depta.dev/uploads/upload_c5bca1067f233a19ddfeba6c2f673bc1.PNG)

1. **.pio** Ordner für Platformio. Hier lebt das Framework, Build Dateien, Libraries und mehr
2. **.vscode** Order für VSCode. Hier ist der C++ Linter sowie Extensions verlinkt. Im Normalfall muss man hier nichts ändern
3. **include** Hier können Header Dateien abgelegt werden.
4. **lib** Hier können Bibliotheken abgelegt werden
5. **src** Hier sollen C-Dateien abgelegt werden. Die main.cpp muss in diesem Ordner liegen
6. **test** Hier können Unit Tests abgelegt werden
7. **platformio.ini** Die Konfigurationsdatei für Platfomio

## platformio.ini
![](https://hack.depta.dev/uploads/upload_a582c83df56e60e0cd46c7080de2a24e.PNG)

Die platformio.ini ist die zentrale Konfiguationsdatei für das Projekt. Es können mehrere Environments (bspw. [env:esp32dev]) angelegt werden, um schnell z.B. zwischen Produktion und Debugging umzustellen. Das Dateiformat ist in Yaml, daher ist darauf zu achten das die Leerzeichen stimmen.

Mehr Info hier: https://docs.platformio.org/en/latest/projectconf/index.html
https://docs.platformio.org/en/latest/envvars.html

## Build, Debug, Upload
![](https://hack.depta.dev/uploads/upload_bae93705a813d506fdfc3dbf35b46275.PNG)

1. PIO Home - Öffnet die Platformio Startseite
2. Build - Das Projekt bauen
3. Upload - Das Projekt auf den Microcontroller laden
4. Clean - Buildfiles aufräumen
5. Test - Unit Tests starten bzw. das Environment für das Testen aufrufen
6. Serial Monitor - Serielle Kommunikation
7. Terminal - Ein Terminal mit geladenen PIO Variablen 
8. Environment - Hier kann man schnell das Environment wechseln
9. Serial Monitor Config - Einstellungen für den seriellen Monitor

Mehr Info hier: https://docs.platformio.org/en/latest/projectconf/build_configurations.html

