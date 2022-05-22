# Le code de la vitrine

## Intro

Si les drivers sont utilisés, alors l'EventsDriver qui leurs sont associer doit toujours voir sa function "processEvents" être appeller réculièrement. Donc le code ne doit en finalité contenir aucune fonctions bloquante. Par example le driver "StepMotorDriver" définie a vrais l'état des pin du moteur mais pour ne pas bruler le moteur il y a un event qui remet a faux cette pin apres un certein delay. Donc si la fonction "processEvents" de l'EventsDriver n'est pas appeller régulièrement alors l'event qui permet de remettre la pin a faux n'est pas appeller ou peut être appeller trop tard.

## L'EventsDriver:

C'est une classe utiliser presque partout dans les fichier source et qui permet de plus facilement géré les différent composant en "parallèle". Le principe est de stocker une liste d'évènement et qui sont exécuter soit une fois a un moment précis dans le future ou alors de manière répéter avec un intervalle de temps précis.

Pour enregistrer un nouveau évènement il y a la fonction "EventsDriver::addEvent(event_callback_t callback, void* data, uint32_t interval, bool ontime)" avec:
- 'ontime' qui indique si l'événement doit être retiré de la liste d'évènement juste apres sont exécution (s'exécute qu'une seul fois).
- 'callback' qui est la fonction a invoquer quand l'évènement est déclancher (sont prototype doit être : "void myCallback(void* data)" avec - 'data' les donné passer dans l'appelle a 'EventsDriver::addEvent').
- 'data' qui est un pointer a passer au callback lorsqu'il est invoquer.
- 'interval' ou peut aussi être interprété 'delay' et s'exprime en millisecondes.

### Fonctions:
```cpp
    EventsDriver();
    event_t addEvent(event_callback_t callback, void* data, uint32_t interval, bool ontime);

    // Verifie pour chaque events s'il doit être execute et execute sont callback millis() > event_to_test.timestamp.
    // Retourne le timestamp du prochaine évenement a executer (le timestamp actuelle est retourner par la fonction Arduino "millis")
    uint32_t processEvents();
```


## Catégorie des fichiers sources:

### Drivers
Ce sont tous les fichiers (et classes) terminant par "Driver.h". Le bute des ces classes est de fournir un moyen plus simple et flexible de manipuler les composants. Il faut instancier un classe pour chaque composant et en générale, le constructeur de la classe prend en argument les pins et l'EventsDriver et parfois d'autre paramètres selon le composant.
Chaque driver a une fonction 'init()' qui doit être appeller une unique fois dans la fonction global "setup".

### Tests
Ce sont tous les fichiers (et classes) terminant par "Test.h". Le bute de ces classes est de tester les composants. Chaque classe a une fonction membre "loop" et "setup" qui doivent respectivement être appeler dans les fonction global "loop" et "setup". Le constructeur des classes Test prend en générale l'EventsDriver.

### Les fichiers "Main"
- Le fichier "Vitrine.ino" contient le code executer par l'Arduino (donc contient les fonction global "setup" et "loop"). Ce fichier doit faire appelle soit au fonction du fichier "Main.h" ou "MainTest.h".
- Le fichier "MainTest.h" contient le code de test de la vitrine.
- Le fichier "Main.h" contient le code principale de la vitrine.


## Les différents drivers et leur methods (sauf 'init()' qui est présent sur tous les drivers):

### LedStripDriver:
```cpp
	// Ici la couleur dans les arguments des fonction est exprimer comme un nombre (par example l'on peut noter '0xFF0000' qui est rouge).
	LedStripDriver(EventsDriver eventsDriver, int pin, int number_of_leds);
	void setLedColor(int pos, uint32_t color); // Defini la couleur de la led a la position 'pos' (commence a 0 et est inférieur au nombre de leds)
	void setAllColor(uint32_t color);
	void update(); // Update the led color for real (send data to the led strip)
	void disable(); // Turn of the led strip (power off all the leds)
	void enable(); // Turn on the led strip (power on all led and update leds to the current colors)
```

### StepMotorDriver:
```cpp
	StepMotorDriver(EventsDriver eventsDriver, int nb_of_step_per_rotation, int pinA, int pinB, int pinC, int pinD);
	void setSpeed(int speed); // Set the rotation speed in RPM
	void start(); // Start a non stop rotation
	void stop(); // Stop any kind of rotation
	void step(); // Just do one step
	void steps(int nb_of_step); // Do 'nb_of_step' steps and stop
```

### ButtonDriver:
```cpp
	// L'avantage de ce driver est qu'il permet agit comme un condensateur en dérivation avec  le button.
	// Donc les micro impulsions ne mette pas l'état du bouton a haut.
	ButtonDriver(EventsDriver eventsDriver, int pin, bool pullup = false);
	bool getState(); // Get the button state ('HIGH'/'true' if pressed or 'LOW'/'false' otherwise)
```

### ServoDriver:
```cpp
	ServoDriver(EventsDriver eventsDriver, int pin);
	void setSpeed(int speed); // The the rotation speed in RPM
	void setAngle(int angle); // Set the servo angle in degree
	void setRawAngle(int angle); // Set the servo raw angle (take same argument than https://www.arduino.cc/reference/en/libraries/servo/writemicroseconds/)
```
